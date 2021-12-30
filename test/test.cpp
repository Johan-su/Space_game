#ifdef _WIN32
    #define _CRT_SECURE_NO_WARNINGS // stop annoying deprecated warnings on windows.
#else

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
    std::system(command);
    return 0;
}

char buffer[2048];
char tmpbuffer[2048];

int run_test(const char *function)
{
    memset(buffer, 0, 2048);
    //dir test.exe 1> myoutput.txt 2>&1
    strcat(buffer, __FILE__);

    buffer[strlen(buffer) - 8] = '\0';

    strcat(buffer, "../build/");

    strcpy(tmpbuffer, buffer);

    strcat(buffer, "Space_game_test.exe ");
    strcat(buffer, "-TS ");
    strcat(buffer, function);
    strcat(buffer, " 1>");
    strcat(buffer, "output_");
    strcat(buffer, function);
    strcat(buffer, ".txt");
    strcat(buffer, " 2>&1");

    cmd_echo(buffer);

    memset(buffer, 0, 2048);


    strcat(buffer, "move /Y "); //TODO(johan) probably check if file already exists
    strcat(buffer, tmpbuffer);
    strcat(buffer, "output_");
    strcat(buffer, function);
    strcat(buffer, ".txt");
    strcat(buffer, " ");

    strcat(buffer, __FILE__);

    buffer[strlen(buffer) - 8] = '\0';

    strcat(buffer, "tests/");



    cmd_echo(buffer);




    return 0;
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
        // add if i want anything special.
        return;
    }
    if(!strcmp(arg, "r"))
    {
        // add if i want anything special.        
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
    char namebuffer[1024];
    memset(namebuffer, 0, 1024);

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
                    std::cout << "[Note] running " << argv[i] << "\n";
                    int return_code = run_test(argv[i]);
                    if(return_code)
                    {

                    }
                    std::cout << "[Note] program exited with " << return_code << " return_code\n"; 
                }
            }
        }
        if(argv[i][0] == '-')
        {
            if(argv[i][1] == 'T' && argv[i][2] == 'S')
            {
                tsflag = true;
            }
            if(argv[i][1] == 'r')
            {
                rflag = true;
            }
            nextflag = true;
        }
    }

    return 0;
}
