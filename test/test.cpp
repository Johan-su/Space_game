#ifdef _WIN32
    #define _CRT_SECURE_NO_WARNINGS // stop annoying deprecated warnings on windows.
#endif

#include <iostream>
//#include <unistd.h>
#include <cstdlib>
//#include <syscall.h>
#include <memory>
#include <unordered_map>
#include <functional>
#include <cstring>
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

int run_test(char *exe_location, const char *function)
{
    std::cout << "[Note] running " << function << "\n";
    memset(exe_name, 0, 512);
    memset(path_to_exe, 0, 512);

    strcat(exe_name, exe_location);
    _strrev(exe_name);
    size_t firstslash = strcspn(exe_name, "\\");
    exe_name[firstslash] = '\0';
    _strrev(exe_name);

    strcat(path_to_exe, exe_location);
    path_to_exe[strlen(exe_location) - strlen(exe_name)] = '\0'; 

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

    auto return_code = cmd_echo(buffer);

    std::cout << "[Note] program exited with " << return_code << " return_code\n"; 

    memset(buffer, 0, 512);


    strcat(buffer, "move /Y "); //TODO(johan) probably check if file already exists
    strcat(buffer, path_to_exe);
    strcat(buffer, "output_");
    strcat(buffer, function);
    strcat(buffer, ".txt");
    strcat(buffer, " ");


    strcat(path_to_test_file, __FILE__);
    _strrev(path_to_test_file);
    size_t firstslash10 = strcspn(path_to_test_file, "/");
    _strrev(path_to_test_file);
    path_to_test_file[strlen(path_to_test_file) - firstslash10] = '\0';

    strcat(buffer, path_to_test_file);    

    strcat(buffer, "tests/");



    cmd_echo(buffer);




    return return_code;
}

int run_function(std::function<int()> func)
{
    return func();
}









bool testFile(const char *filepath)
{
    char cmds[200];
    strcat(cmds, "echo ");
    strcat(cmds, filepath);
    strcat(cmds, " | > output_");
    strcat(cmds, filepath);
    strcat(cmds, "_.txt");
    cmd_echo(cmds);
    return 0;
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

bool testFiles(const char *dirpath)
{
    char cmds[1000];
    strcat(cmds, "cd dirpath &&");
    strcat(cmds, " ");




    return 0;
}



void usage(const char *arg = "")
{
    if(!strcmp(arg, "TS"))
    {
        // add for special usage.
        return;
    }
    if(!strcmp(arg, "r"))
    {
        // add for special usage.        
        return;
    }

    std::cout << "USAGE: Space_Game_test.exe [-TS function] [-r]\n"
    << "-TS is used for for internal functions\n"
    << "-r runs all tests\n"
    << "no parameters runs this usage\n";
}


int main(int argc, char *argv[])
{


    if(argc < 2) usage();

    bool tsflag = false;
    bool rflag = false;
    bool nextflag = false;

    for(uint32_t i = 1; i < argc; ++i)
    {
        if(nextflag)
        {
            nextflag = false;
            if(argv[i][0] == '-')
            {
               if(tsflag) usage("TS");
               if(rflag) usage("r");  
            } 
            else
            {
                if(tsflag)
                {
                    exit(run_function(str_to_func[argv[i]]));
                }
                if(rflag)
                {
                    for(auto& it: str_to_func)
                    {
                        auto return_code = run_test(argv[0], it.first.c_str());
                    }
                }
            }
        }
        if(argv[i][0] == '-')
        {
            if(argv[i][1] == 'T' && argv[i][2] == 'S')
            {
                tsflag = true;
            }
            if(argv[i][1] == 'r' && argc != i)
            {
                rflag = true;
            }
            nextflag = true;
        }
    }

    return 0;
}
