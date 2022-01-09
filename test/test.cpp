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
void set_tmp_path()
{
    strcat(tmp_path, getenv("TEMP"));
    strcat(tmp_path, "\\");
}

char echo_buffer[4096];
int cmd_echo(const char *c1 = "", const char *c2 = "", const char *c3 ="", const char *c4 ="", const char *c5 ="", const char *c6 ="", const char *c7 ="", const char *c8 ="", const char *c9 ="", const char *c10 ="", const char *c11 ="", const char *c12 ="")
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
    std::cout << "[CMD] running " << echo_buffer << "\n";
    return std::system(echo_buffer);
}

char buffer[512];
char exe_name[512];
char path_to_exe[512];
char path_to_test_file[512];

void strrev(char *buffer)
{
    size_t j = strlen(buffer);
    for(size_t i = 0; i < strlen(buffer); ++i)
    {
        buffer[i] = buffer[j];
        --j;
    }
    buffer[strlen(buffer) + 1] = '\0';
}


void set_path_to_exe(const char *program)
{
    memset(exe_name, 0, 512);
    memset(path_to_exe, 0, 512);

    strcat(exe_name, program);
    strrev(exe_name);
    size_t firstslash = strcspn(exe_name, "\\");
    exe_name[firstslash] = '\0';
    strrev(exe_name);
#ifdef _WIN32
    GetModuleFileName(NULL, path_to_exe, 512); // only works on windows
#endif
    readlink()
#ifdef __linux__

#endif
    path_to_exe[strlen(path_to_exe)- strlen(exe_name)] = '\0'; 
}
void set_path_to_test_file()
{
    memset(path_to_test_file, 0, 512);

    strcat(path_to_test_file, __FILE__);
   strrev(path_to_test_file);
    size_t firstslash10 = strcspn(path_to_test_file, "/");
   strrev(path_to_test_file);
    path_to_test_file[strlen(path_to_test_file) - firstslash10] = '\0';
}

void move_file(const char *dst_path, const char *src_path)
{
    cmd_echo("move /Y ", src_path, " ", dst_path);
}

void delete_file(const char* src_path)
{
    cmd_echo("del /F /Q ", src_path);
}


char stdout_old[2048];
char stdout_new[2048];
char stdout_diff[2048];

int run_test(const char *function, const char *program)
{
    std::cout << "[Note] running " << function << "\n";

    int return_code = cmd_echo("cd %TEMP% && ", path_to_exe, exe_name, " -TS ", function, " 1>output_", function, ".txt 2>&1");

    std::cout << "[Note] program exited with " << return_code << " return_code\n"; 

    memset(buffer, 0, 512);

    strcat(buffer, path_to_test_file);
    strcat(buffer, "tests/");
    strcat(buffer, "output_");
    strcat(buffer, function);
    strcat(buffer, ".txt");

    FILE *fp = fopen(buffer, "r");

    int diff = -1;
    if(fp) // file exists
    {
        cmd_echo("cd %TEMP% && fc output_", function, ".txt", " ", path_to_test_file, "tests/", "output_", function, ".txt", "> diff_.txt");

        memset(stdout_diff, 0, 2048);

        memset(buffer, 0, 512);

        strcat(buffer, tmp_path);
        strcat(buffer, "diff_.txt");

        FILE *fpDiff = fopen(buffer, "r");
        if(fpDiff)
        {

            fread(stdout_diff, 2048, 1, fpDiff);

            fclose(fpDiff);
        }
        size_t firstnewline = 0;
        for(int i = 0; i < strlen(stdout_diff); ++i)
        {
            if(stdout_diff[i] == 10)
            {
                firstnewline = i;
                break;
            }
        }
        strrev(stdout_diff);
        stdout_diff[strlen(stdout_diff) - firstnewline] = '\0';
        strrev(stdout_diff);
        diff = strcmp(stdout_diff, "\nFC: no differences encountered\n\n");

        fclose(fp);
    }




    if(diff)
    {
        memset(buffer, 0 , 512);
        strcat(buffer, tmp_path);
        strcat(buffer, "output_");
        strcat(buffer, function);
        strcat(buffer, ".txt");

        FILE *fp_new = fopen(buffer, "r");
        if(fp_new)
        {
            fread(stdout_new, 1, 2048, fp_new);
            fclose(fp_new);
        }
        memset(buffer, 0 , 512);
        strcat(buffer, path_to_test_file);
        strcat(buffer, "tests/");
        strcat(buffer, "output_");
        strcat(buffer, function);
        strcat(buffer, ".txt");

        FILE *fp_old = fopen(buffer, "r");
        if(fp_old)
        {
            fread(stdout_old, 1, 2048, fp_old);
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

    strcat(buffer, "cd %TEMP% && ");
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



void usage(const char *program, const char *arg = "")
{
    if(!strcmp(arg, "TS"))
    {
        // add for special usage.
        exit(1);
    }
    if(!strcmp(arg, "r"))
    {
        // add for special usage.        
        exit(1);
    }

    std::cerr << "USAGE: [-TS function] [-r/-u] function for " << program << "\n"
    << "-TS is used for for internal functions\n"
    << "-r runs all tests\n"
    << "-u updates all tests\n"
    << "no parameters runs this usage\n";
    exit(1);
}


int main(int argc, char *argv[])
{
    set_tmp_path();

    char *program = *argv++;
    char *arg;
    char *flag;
    set_path_to_exe(program);
    set_path_to_test_file();
    if(*argv == nullptr) usage(program);
    flag = *argv++;
    if(*argv == nullptr) // only flag run all test files.
    {
        if(flag[0] != '-') usage(program);
        if(flag[1] == 'T' && flag[2] == 'S')
        {
            usage("TS"); // -TS flag requires function argument
        }
        else if(flag[1] == 'r')
        {
            for(auto & it: str_to_func) // runs all tests
            {
                auto return_code = run_test(it.first.c_str(), program);
            }
            return 0;  
        }
        else if(flag[1] == 'u')
        {
            for(auto & it: str_to_func) // updates all tests
            {
                auto return_code = update_test(it.first.c_str());
            }
            return 0;  
        }
        else if(flag[1] == 'l')
        {
            std::cout << "Printing test list: " << "\n";
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
        for(auto & pair : str_to_func)
        {
            if(arg == pair.first)
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
        if(flag[0] != '-') usage(program);
        if(flag[1] == 'T' && flag[2] == 'S')
        {
            exit(run_function(str_to_func[arg]));
        }
        else if(flag[1] == 'r')
        {
            run_test(arg, program);
        }
        else if(flag[1] == 'u')
        {
            update_test(arg);
        }
        else { usage(program); }
    }


    return 0;
}
