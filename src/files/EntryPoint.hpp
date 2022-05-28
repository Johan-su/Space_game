#pragma once
#include "../files/Real.hpp"

/*

define init, clean in your application

*/
void init(Application_handle *app);
void clean(Application_handle *app);

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
    Application_handle *app = Application::create_application(pwd);
    // game_data *game = Game::create_context();

    init(app);
    clean(app);

    Application::destroy_application(app);
    app = NULL;

    return 0;
}