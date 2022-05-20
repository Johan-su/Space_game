#pragma once



typedef void Application_handle;


namespace Application
{
    Application_handle *create_application(const char *pwd);
    void destroy_application(Application_handle *app);


}