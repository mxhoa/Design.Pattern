#include "MyApplication.h"

MyApplication::MyApplication()
{
    std::cout << "MyApplication: ctor " << std::endl;
}

Document* MyApplication::CreateDocument(std::string fn)
{
    std::cout << "  MyApplication: CreateDocument() " << std::endl;
    return new MyDocument(fn);
}