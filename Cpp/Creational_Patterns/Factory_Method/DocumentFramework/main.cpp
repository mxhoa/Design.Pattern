#include <iostream>
#include "MyApplication.h"

int main()
{
    MyApplication myApp;

    myApp.NewDocument("foo");
    myApp.NewDocument("bar");

    myApp.ReportDocs();

    return 0;
}
