#include <iostream>
#include <string>

/**
 * @brief Abstract base class declared by framework
 * 
 */
class Document
{
private:
    std::string name;
public:
    Document(std::string fn);
    virtual void Open() = 0;
    virtual void Close() = 0;
    std::string GetName();
};