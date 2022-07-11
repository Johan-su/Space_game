#ifdef _WIN32
    #define _CRT_SECURE_NO_WARNINGS // stop annoying deprecated warnings on windows.
    #include "Windows.h"
#endif
#ifdef __linux__
    #include "unistd.h"
#endif

#include <iostream>
#include <cstdlib>
#include <memory>
#include <unordered_map>
#include <functional>
#include "string.h"
#include <string>
#include <cstring>

#include "./tests/memory_double_init.hpp"
#include "./tests/memory_alloc.hpp"
#include "./tests/ecs_view_test.hpp"

// TESTS:
#define TESTLIST(X) \
X(memory_double_init) \
X(memory_alloc) \
X(ecs_view_test) \



#define TESTF(var)\
{#var, var::test},

std::unordered_map<std::string, std::function<int()> > str_to_func = 
{ 
TESTLIST(TESTF)
};

#undef TESTF

char tmp_path[512];
char path_to_exe[512];
char echo_buffer[4096];

char buffer[512];
char exe_name[512];
char path_to_test_file[512];

char str_buffer[512];

int cmd_echo(const char *c1 = "", const char *c2 = "", const char *c3 ="", const char *c4 ="", const char *c5 ="", const char *c6 ="", const char *c7 ="", const char *c8 ="", const char *c9 ="", const char *c10 ="", const char *c11 ="", const char *c12 ="", const char *c13 ="", const char *c14 ="", const char *c15 ="")
{
    memset(echo_buffer, 0, 4096);
    strcat(echo_buffer, c1);
    strcat(echo_buffer, c2);
    strcat(echo_buffer, c3);
    strcat(echo_buffer, c4);
    strcat(echo_buffer, c5);
    strcat(echo_buffer, c6);
    strcat(echo_buffer, c7);
    strcat(echo_buffer, c8);
    strcat(echo_buffer, c9);
    strcat(echo_buffer, c10);
    strcat(echo_buffer, c11);
    strcat(echo_buffer, c12);
    strcat(echo_buffer, c13);
    strcat(echo_buffer, c14);
    strcat(echo_buffer, c15);
    std::cout << "[CMD] " << echo_buffer << "\n";
    return std::system(echo_buffer);
}

int64_t strrfind(char s, char *buf)
{
    int64_t index = -1;
    size_t buf_len = strlen(buf);
    for(int64_t i = buf_len - 1; i > 0 ; --i)
    {
        if (*(buf + i) == s)
        {
            index = i;
            break;
        }
    }
    return index;
}

int64_t strfind(char s, char *buf)
{
    int64_t index = -1;
    size_t buf_len = strlen(buf);
    for(int64_t i = 0; i < buf_len ; ++i)
    {
        if (*(buf + i) == s)
        {
            index = i;
            break;
        }
    }
    return index;
}

void str_rev(char *buf)
{
    memset(str_buffer, 0, 512);
    size_t buf_len = strlen(buf);
    size_t j = strlen(buf) - 1;
    for(size_t i = 0; i < buf_len; ++i)
    {
        *(str_buffer + i) = *(buf + j);
        --j;
    }
    str_buffer[strlen(str_buffer)] = '\0';
    strcpy(buf, str_buffer);
}



void set_path_to_test_file()
{

    memset(path_to_test_file, 0, 512);

    strcat(path_to_test_file, __FILE__);

    int64_t firstslash = strrfind('/', path_to_test_file);


    path_to_test_file[firstslash + 1] = '\0';
}



#ifdef _WIN32


void set_tmp_path()
{
    strcat(tmp_path, getenv("TEMP"));
    strcat(tmp_path, "\\");
}



void set_path_to_exe(const char *program)
{
    memset(exe_name, 0, 512);
    memset(path_to_exe, 0, 512);

    strcat(exe_name, program);
    str_rev(exe_name);
    size_t firstslash = strcspn(exe_name, "\\");
    exe_name[firstslash] = '\0';
    str_rev(exe_name);
    GetModuleFileName(NULL, path_to_exe, 512); // only works on windows
    path_to_exe[strlen(path_to_exe)- strlen(exe_name)] = '\0'; 
}


void move_file(const char *dst_path, const char *src_path)
{
    cmd_echo("move /Y ", src_path, " ", dst_path);
}



void delete_file(const char* src_path)
{
    cmd_echo("del /F /Q ", src_path);
}


#endif

#ifdef __linux__


void set_tmp_path()
{
    strcat(tmp_path, "/var/tmp/");
}

void set_path_to_exe(const char *program)
{
    memset(exe_name, 0, 512);
    memset(path_to_exe, 0, 512);

    strcat(exe_name, program);

    str_rev(exe_name);
    #ifdef _WIN32
    size_t firstslash = strrfind('\', exe_name);
    #endif

    #ifdef __linux__
    size_t firstslash = strfind('/', exe_name);

    #endif

    exe_name[firstslash] = '\0';
    str_rev(exe_name);
    readlink("/proc/self/exe", path_to_exe, 512);
    auto exe_name_len = strlen(exe_name);
    path_to_exe[strlen(path_to_exe) - exe_name_len ] = '\0'; 
}


void move_file(const char *dst_path, const char *src_path)
{
    cmd_echo("mv -f ", src_path, " ", dst_path);
}


void delete_file(const char* src_path)
{
    cmd_echo("rm -f ", src_path);
}

#endif





#define BUFFER_SIZE 8192



char stdout_old[BUFFER_SIZE];
char stdout_new[BUFFER_SIZE];
char stdout_diff[BUFFER_SIZE];

int run_test(const char *function, const char *program)
{
    std::cout << "[Note] running " << function << "\n";

    int return_code = cmd_echo("cd ", tmp_path, " && ", path_to_exe, exe_name, " -TS ", function, " 1>output_", function, ".txt 2>&1");

    std::cout << "[Note] program exited with " << "exit code: " << return_code << "\n"; 

    memset(buffer, 0, 512);

    strcat(buffer, path_to_test_file);
    strcat(buffer, "tests/");
    strcat(buffer, "output_");
    strcat(buffer, function);
    strcat(buffer, ".txt");

    int diff = -1;

    FILE *fp = fopen(buffer, "r");
    if (!fp)
    {
        std::cout << "[WARNING] no test file found -- Skipping test\n";

        memset(buffer, 0, 512);
        strcat(buffer, tmp_path);
        strcat(buffer, "output_");
        strcat(buffer, function);
        strcat(buffer, ".txt");

        delete_file(buffer);
        return 0;
    }
    fclose(fp);

    // file exists
    
        #ifdef _WIN32
        cmd_echo("cd ", tmp_path, " && ", "fc output_", function, ".txt", " ", path_to_test_file, "tests/", "output_", function, ".txt", "> diff_.txt");
        #endif

        #ifdef __linux__
        cmd_echo("cd ", tmp_path, " && ", "diff -q output_", function, ".txt", " ", path_to_test_file, "tests/", "output_", function, ".txt", "> diff_.txt");
        #endif

        memset(stdout_diff, 0, BUFFER_SIZE);

        memset(buffer, 0, 512);

        strcat(buffer, tmp_path);
        strcat(buffer, "diff_.txt");

    FILE *fpDiff = fopen(buffer, "r");
    if (fpDiff)
    {
        fread(stdout_diff, BUFFER_SIZE, 1, fpDiff);
        fclose(fpDiff);
    }
    #ifdef _WIN32
    size_t firstnewline = 0;
    for(size_t i = 0; i < strlen(stdout_diff); ++i)
    {
        if (stdout_diff[i] == '\n')
        {
            firstnewline = i;
            break;
        }
    }
    str_rev(stdout_diff);
    stdout_diff[strlen(stdout_diff) - firstnewline] = '\0';
    str_rev(stdout_diff);
    diff = strcmp(stdout_diff, "\nFC: no differences encountered\n\n");
    #endif

    #ifdef __linux__
    diff = strcmp(stdout_diff, "");
    #endif
    




    if (diff)
    {
        memset(buffer, 0 , 512);
        memset(stdout_new, 0, BUFFER_SIZE);
        memset(stdout_old, 0, BUFFER_SIZE);

        strcat(buffer, tmp_path);
        strcat(buffer, "output_");
        strcat(buffer, function);
        strcat(buffer, ".txt");

        FILE *fp_new = fopen(buffer, "r");
        if (fp_new)
        {
            fread(stdout_new, 1, BUFFER_SIZE, fp_new);
            fclose(fp_new);
        }
        memset(buffer, 0 , 512);
        strcat(buffer, path_to_test_file);
        strcat(buffer, "tests/");
        strcat(buffer, "output_");
        strcat(buffer, function);
        strcat(buffer, ".txt");

        FILE *fp_old = fopen(buffer, "r");
        if (fp_old)
        {
            fread(stdout_old, 1, BUFFER_SIZE, fp_old);
            fclose(fp_old);
        }
        std::cout << "[ERROR]: test " << function << " failed\n"
        << "expected:\n" << stdout_old << "\n"
        << "got:\n" << stdout_new << std::endl;
    }
    else
    {
        memset(buffer, 0, 512);
        strcat(buffer, tmp_path);
        strcat(buffer, "diff_.txt");
        delete_file(buffer);

        memset(buffer, 0, 512);
        strcat(buffer, tmp_path);
        strcat(buffer, "output_");
        strcat(buffer, function);
        strcat(buffer, ".txt");

        delete_file(buffer);

    }

    return 0;
}

int update_test(const char *function)
{
    std::cout << "[Note] updating " << function << "\n";
    memset(buffer, 0, 512);

    strcat(buffer, "cd ");
    strcat(buffer, tmp_path);
    strcat(buffer, " && ");
    strcat(buffer, path_to_exe);
    strcat(buffer, exe_name);
    strcat(buffer, " -TS ");
    strcat(buffer, function);
    strcat(buffer, " 1>output_");
    strcat(buffer, function);
    strcat(buffer, ".txt 2>&1");

    cmd_echo(buffer);

    char dst[512];
    char src[512];
    memset(dst, 0, 512);
    memset(src, 0, 512);

    strcat(dst, path_to_test_file);
    strcat(dst, "tests/");

    strcat(src, tmp_path);
    strcat(src, "output_");
    strcat(src, function);
    strcat(src, ".txt");


    move_file(dst, src);

    return 0;
}

int run_function(std::function<int()> func)
{
    return func();
}



void usage(const char *program)
{

    std::cerr << "USAGE: [-TS function] [-r/-u] function for " << program << "\n"
    << "-TS is used for for internal functions\n"
    << "-r runs all tests\n"
    << "-u updates all tests\n"
    << "no parameters runs this usage\n";
    exit(1);
}

char test_buffer[512];
char rtest_buffer[512];
int main(int argc, char *argv[])
{
    (void)argc;
    set_tmp_path();

    char *program = *argv++;
    char *arg;
    char *flag;
    set_path_to_exe(program);
    set_path_to_test_file();
    if (*argv == nullptr) usage(program);
    flag = *argv++;
    if (*argv == nullptr) // only flag run all test files.
    {
        if (flag[0] != '-') usage(program);
        if (flag[1] == 'T' && flag[2] == 'S')
        {
            usage("TS"); // -TS flag requires function argument
        }
        else if (flag[1] == 'r')
        {
            for(auto & it: str_to_func) // runs all tests
            {
                run_test(it.first.c_str(), program);
            }
            return 0;  
        }
        else if (flag[1] == 'u')
        {
            for(auto & it: str_to_func) // updates all tests
            {
                update_test(it.first.c_str());
            }
            return 0;  
        }
        else if (flag[1] == 'l')
        {
            std::cout << "Test list: " << "\n";
            for(auto & pair : str_to_func)
            {
                std::cout <<  pair.first << "\n";
            }
        }
        else { usage(program); }
    }
    else
    {
        arg = *argv++;
        int it = 0;
        for(auto &pair : str_to_func)
        {
            if (arg == pair.first)
            {
                break;
            }
            ++it;
        }
        if (it == str_to_func.size())
        {
            std::cout << "[ERROR] test not found" << "\n";
            exit(1);
        }
        if (flag[0] != '-') usage(program);
        if (flag[1] == 'T' && flag[2] == 'S')
        {
            exit(run_function(str_to_func[arg]));
        }
        else if (flag[1] == 'r')
        {
            run_test(arg, program);
        }
        else if (flag[1] == 'u')
        {
            update_test(arg);
        }
        else { usage(program); }
    }


    return 0;
}
