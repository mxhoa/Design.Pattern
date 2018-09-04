#include <iostream>
#include <string>
#include "MyDocument.h"


class Application
{
private:
    int _index;
    /*Framework uses Document's base class */
    Document *_docs[10];
public:
    Application();
    /* The client will call this "entry point" of the framework */
    void NewDocument(std::string name);
    void OpenDocument();
    void ReportDocs();
    /* Framework declares a "hole" for the client to customize */
    virtual Document *CreateDocument(std::string ) = 0;
};
