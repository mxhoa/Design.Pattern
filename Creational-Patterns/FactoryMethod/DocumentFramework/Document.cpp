#include "Document.h"

Document::Document(std::string fn)
{
    name = fn;
}

std::string Document::GetName()
{
    return name;
}