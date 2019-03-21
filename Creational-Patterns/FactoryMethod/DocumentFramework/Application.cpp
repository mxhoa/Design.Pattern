#include "Application.h"

Application::Application()
{
    _index = 0;
}

void Application::NewDocument(std::string name)
{
    std::cout << "Application: NewDocument()" << std::endl;

    /* Framework calls the "hole" reserved for client customization */
    _docs[_index] = CreateDocument(name);
    _docs[_index++]->Open();
}

void Application::ReportDocs()
{
    std::cout << "Application : ReportDocs()" << std::endl;
    for (int i = 0; i < _index; i++)
    {
        std::cout << "  " << _docs[i]->GetName() << std::endl;
    }
}