#include "Config.hpp"

#include <stdlib.h>
#include <stdio.h>

#include <string.h>


static int set_value(config_data *settings, const char *var, uint16_t val)
{
    if (strcmp(var, "screen_width") == 0)
    {
        printf("NOTE: %s = %du\n", var, val);
        settings->screen_width = val;
    } 
    else if (strcmp(var, "screen_height") == 0)
    {
        printf("NOTE: %s = %du\n", var, val);
        settings->screen_height = val;
    }
    else if (strcmp(var, "FPS_target") == 0)
    {
        printf("NOTE: %s = %du\n", var, val);
        settings->FPS_target = val;
    }
    else
    {
        fprintf(stderr, "ERROR: unrecognized variable name: %s\n", var);
        return -1;
    }

    return 0;
}


static void substring(char *buf1, char *buf2, const char *str , const char divider)
{
    int64_t pos = -1;
    for(size_t i = 0; i < strlen(str); ++i)
    {
        if (str[i] == divider)
        {
            pos = i;
            break;
        }
    }

    size_t sub_size1 = pos;
    size_t sub_size2 = strlen(str) - pos - 1;

    memcpy(buf1, str, sizeof(char) * sub_size1);
    memcpy(buf2, &str[pos + 1], sizeof(char) * sub_size2);

    buf1[pos] = '\0';
    buf2[sub_size2] = '\0';
}


void Config::init(config_data *settings, const char *config_path)
{
    char var_name[128];
    char var_value[128];
    char line[128];

    FILE *fp = fopen(config_path, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "ERROR: Failed to open file: %s\n", config_path);
        return;
    }
    
    while(fscanf(fp, "%s", line) != EOF)
    {
        substring(var_name, var_value, line, '=');
        set_value(settings, var_name, atoi(var_value));
            
        // memset(var_name, 0, 128);
        // memset(var_value, 0, 128);
        // memset(line, 0, 128);
    }
    

    if (fclose(fp) != 0)
    {
        fprintf(stderr, "ERROR: failed to close file, closing program");
        exit(1);
    }
}
