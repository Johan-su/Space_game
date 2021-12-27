#include <iostream>
//#include <unistd.h>
#include <cstdlib>
//#include <syscall.h>
#include <cstring>
#include <string>

bool testFile(const char *filepath)
{
    char cmds[200];
    strcat(cmds, "echo ");
    strcat(cmds, filepath);
    strcat(cmds, "| > output_");
    strcat(cmds, filepath);
    strcat(cmds, "_.txt");
    system(cmds);
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



























int main(int argc, char **argv)
{
    auto test = testFile("random/path");


    return 0;
}