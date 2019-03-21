#include <iostream>
#include "Document.h"

class MyDocument : public Document
{
public:
    MyDocument(std::string fn) : Document(fn) {}
    void Open() override;
    void Close() override;
};
