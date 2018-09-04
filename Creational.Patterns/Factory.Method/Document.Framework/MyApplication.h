#include <iostream>
#include "Application.h"

class MyApplication: public Application
{
public:
    MyApplication();

    /*  Client defines Framework's "hole" */
    Document *CreateDocument(std::string fn);
};