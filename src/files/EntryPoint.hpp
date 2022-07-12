#pragma once
#include "Real.hpp"
/*

define init, clean in your application

*/


void init(const char *pwd);
void clean();

int main(int argc, char *argv[])
{   
    const char *exe = *argv++;
    (void)exe;
    const char *pwd;
    if (argc > 1)
    {
        pwd = *argv++;
    }
    else
    {
        pwd = "./";
    }


    Application_data *app = Application::create_application(pwd);

    init(pwd);
    clean();

    Application::destroy_application(app);
    app = NULL;

    return 0;
}
