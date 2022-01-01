#ifdef _WIN32
    #define _CRT_SECURE_NO_WARNINGS // stop annoying deprecated warnings on windows.
#endif

#include <iostream>
#include <cstdlib>
#include <memory>
#include <unordered_map>
#include <functional>
#include "string.h"
#include <string>



// TESTS:
#include "./tests/ComponentManager_test.hpp"



std::unordered_map<std::string, std::function<int()> > str_to_func = 
{ 
{"ComponentManager_test", ComponentManager_test::test}




};




int cmd_echo(const char *command)
{
    std::cout << "[CMD] running " << command << "\n";
    return std::system(command);
}

char buffer[512];
char exe_name[512];
char path_to_exe[512];
char path_to_test_file[512];


void set_path_to_exe(const char *exe_location)
{
    memset(exe_name, 0, 512);
    memset(path_to_exe, 0, 512);

    strcat(exe_name, exe_location);
    _strrev(exe_name);
    size_t firstslash = strcspn(exe_name, "\\");
    exe_name[firstslash] = '\0';
    _strrev(exe_name);

    strcat(path_to_exe, exe_location);
    path_to_exe[strlen(exe_location) - strlen(exe_name)] = '\0'; 
}
void set_path_to_test_file()
{
    memset(path_to_test_file, 0, 512);

    strcat(path_to_test_file, __FILE__);
    _strrev(path_to_test_file);
    size_t firstslash10 = strcspn(path_to_test_file, "/");
    _strrev(path_to_test_file);
    path_to_test_file[strlen(path_to_test_file) - firstslash10] = '\0';
}

char mvbuffer[512];
void move_file(const char* dst_path, const char* src_path)
{
    memset(mvbuffer, 0, 512);

    strcat(mvbuffer, "move /Y ");
    strcat(mvbuffer, src_path);
    strcat(mvbuffer, " ");
    strcat(mvbuffer, dst_path);

    cmd_echo(mvbuffer);

    memset(mvbuffer, 0, 512);
}

char delbuffer[512];
void delete_file(const char* src_path)
{
    memset(delbuffer, 0, 512);

    strcat(delbuffer, "del /F /Q");
    strcat(delbuffer, src_path);

    cmd_echo(delbuffer);

    memset(delbuffer, 0, 512);
}

char stdout_buffer[2048];

int run_test(const char *function)
{
    std::cout << "[Note] running " << function << "\n";


    memset(buffer, 0, 512);

    strcat(buffer, "cd ");
    strcat(buffer, path_to_exe);
    strcat(buffer, " && ");

    strcat(buffer, exe_name);
    strcat(buffer, " -TS ");
    strcat(buffer, function);
    strcat(buffer, " 1>");
    strcat(buffer, "output_");
    strcat(buffer, function);
    strcat(buffer, ".txt");
    strcat(buffer, " 2>&1");

    int return_code = cmd_echo(buffer);

    std::cout << "[Note] program exited with " << return_code << " return_code\n"; 

    memset(buffer, 0, 512);

    FILE *fp = fopen(path_to_test_file, "r");

    int diff;
    if(fp)
    {
        strcat(buffer, "cd ");
        strcat(buffer, path_to_exe);
        strcat(buffer, " && ");
        strcat(buffer, "fc /L ");
        strcat(buffer, "output_");
        strcat(buffer, function);

        strcat(buffer, " ");
        strcat(buffer, path_to_test_file);
        strcat(buffer, "output_");
        strcat(buffer, function);
        strcat(buffer, "> diff_.txt");

        cmd_echo(buffer);

        memset(stdout_buffer, 0, 2048);

        FILE *fpDiff = fopen("diff_.txt", "r");
        if(fpDiff)
        {

            fread(stdout_buffer, 1, 2048, fpDiff);
            fclose(fpDiff);
        }

        diff = strcmp(stdout_buffer, "FC: no differences encountered");

        fclose(fp);
    }


    memset(buffer, 0, 512);

    char dst[512];
    memset(dst, 0, 512);

    strcat(dst, path_to_exe);
    strcat(dst, "output_");
    strcat(dst, function);
    strcat(dst, ".txt");

    char src[512];
    memset(src, 0, 512);

    strcat(src, path_to_test_file);
    strcat(src, "tests/");

    move_file(dst, src);




    return diff;
}

int update_test(const char *function)
{

    return 0;
}

int run_function(std::function<int()> func)
{
    return func();
}


bool load_test_output(const char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    if(!fp)
    {
        return 1;
    }
    //fscanf(fp, ); //TODO finish

    fclose(fp);
    return 0;
}


void usage(const char *arg = "")
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

    std::cout << "USAGE: Space_Game_test.exe [-TS function] [-r/-u] function\n"
    << "-TS is used for for internal functions\n"
    << "-r runs all tests\n"
    << "-u updates all tests"
    << "no parameters runs this usage\n";
    exit(1);
}


int main(int argc, char *argv[])
{
    set_path_to_exe(argv[0]);
    set_path_to_test_file();


    if(argc < 2) usage();

    bool tsflag = false;
    bool rflag = false;
    bool uflag = false;
    bool argflag = false;
    std::string funcstr;

    for(uint32_t i = 1; i < argc; ++i)
    {
        if(argflag)
        {
            argflag = false;
            if(argc == i + 1)
            {
                for(auto& it : str_to_func)
                {
                    if(strcmp(argv[i], it.first.c_str()) == 0 )
                    {

                        funcstr = argv[i][0];
                        break;
                    }
                }
                if(tsflag)
                {
                    exit(run_function(str_to_func[argv[i]]));
                }
                else if(rflag)
                {
                    run_test(funcstr.c_str());
                }
                else if(uflag)
                {
                    update_test(funcstr.c_str());
                }
                else
                {
                    usage();
                }
                tsflag = false;
                rflag = false;
                uflag = false;
            }
            else
            {
                assert(false, "only single flag -$FLAG$ {argument}");
            } 
        }
        if(argv[i][0] == '-')
        {
            if(argv[i][1] == 'T' && argv[i][2] == 'S')
            {
                tsflag = true;
            }
            else if(argv[i][1] == 'r')
            {
                rflag = true;
            }
            else if(argv[i][1] == 'u')
            {
                uflag = true;
            }
            else
            {
                usage();
            }
            argflag = true;
        }
    }

    if(tsflag)
    {
        assert(false, "-TS flag with no argument");
    }
    else if(rflag)
    {
        for(auto & it: str_to_func)
        {
            auto return_code = run_test(it.first.c_str());
        }  
    }
    else if(uflag)
    {
        for(auto & it: str_to_func)
        {
            auto return_code = update_test(it.first.c_str());
        }  
    }
    else
    {
        usage();
        
    }

    return 0;
}
