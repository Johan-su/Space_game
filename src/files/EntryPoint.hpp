#pragma once
#include "Application/Application.hpp"

/*

define init, clean in your application

*/


void init(Application_data *app, const char *pwd);
void clean(Application_data *app);

int main(int argc, char *argv[])
{   
    const char *exe = *argv++;
    (void)exe;
    const char *pwd;
    if(argc > 1)
    {
        pwd = *argv++;
    }
    else
    {
        pwd = "./";
    }


    Application_data *app = Application::create_application(pwd);

    init(app, pwd);
    clean(app);

    Application::destroy_application(app);
    app = NULL;

    return 0;
}