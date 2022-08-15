#pragma once
#include "Real.hpp"
/*

define init, clean in your application

*/


void init();
void clean();

int main(int argc, char *argv[])
{   
    Application_data *app = Application::create_application();

    init();
    clean();

    Application::destroy_application(app);
    app = nullptr;

    return 0;
}
