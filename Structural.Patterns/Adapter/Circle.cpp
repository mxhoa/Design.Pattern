#include <iostream>

using namespace std;

class CircleClient 
{
public:
    virtual void draw() = 0;
};

class CircleAdaptee 
{
public:
    CircleAdaptee(float x, float y, float R)
    {
        x1 = x;
        y1 = y;
        R1 = R;

        std::cout <<  "Circle Adaptee draw " << std::endl;
        std::cout << "Toa do goc tren trai (" << x1 << "," << y1 << ") Ban kinh = " << R1 << std::endl;
    }
protected:
    float x1;
    float y1;
    float R1;
};

class CircleAdapter : public CircleClient, private CircleAdaptee
{
public:
    CircleAdapter(float x, float y, float R) : CircleAdaptee(x, y, R) {}
    virtual void draw()
    {
        std::cout << "Circle Client draw " << std::endl;
        std::cout << "Tam I (" << x1 + R1 << "," << y1 + R1 << ") Ban kinh R = " << R1 << std::endl;
    }
};

int main()
{
    CircleClient *cir = new CircleAdapter(1.2, 3.3, 7);
    cir->draw();
    return 0;
}
