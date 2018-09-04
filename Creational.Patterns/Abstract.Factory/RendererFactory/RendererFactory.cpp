#include <iostream>
#include <string>

class Renderer
{
public:
    virtual ~Renderer(){};
    virtual void RenderIt() = 0;
};

class OpenGLRenderer : public Renderer
{
public:
    void RenderIt() 
    {
        std::cout << "OpenGL render\n";
    }
};

class DirectXRenderer : public Renderer 
{
public:
    void RenderIt()
    {
        std::cout << "DirectX Renderer\n";
    }
};

class RenderFactory
{
public:
    Renderer *createRenderer(const std::string &type)
    {
        if (type == "opengl")
            return new OpenGLRenderer();
        else if (type == "directx")
            return new DirectXRenderer();
        else 
            return NULL;
    }
};

int main()
{
    RenderFactory *factory = new RenderFactory();
    factory->createRenderer("opengl")->RenderIt();
    factory->createRenderer("directx")->RenderIt();

    return 0;
}