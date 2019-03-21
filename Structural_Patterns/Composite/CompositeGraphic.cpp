#include <vector>
#include <iostream>     // std::out
#include <memory>       // std::auto_ptr
#include <algorithm>    // std::for_each 

using namespace std;

class Graphic 
{
    public:
        virtual void print() const = 0;
        virtual ~Graphic() {}
};


class Ellipse : public Graphic 
{
    public:
        void print() const {
            cout << "Ellipse \n";
        }
};

class CompositeGraphic : public Graphic 
{
    public: 
        void print() const {
            for (Graphic * a : graphicList_) {
                a->print();
            }
        }

        void add(Graphic *aGraphic) {
            graphicList_.push_back(aGraphic);
        }

    private:
        vector<Graphic*> graphicList_;
};


int main() {
    // Initialize four ellipses
    unique_ptr<Ellipse> ellipse_1(new Ellipse());
    unique_ptr<Ellipse> ellipse_2(new Ellipse());
    unique_ptr<Ellipse> ellipse_3(new Ellipse());
    unique_ptr<Ellipse> ellipse_4(new Ellipse());

    // Initialize three composite graphics
    unique_ptr<CompositeGraphic> graphic_1(new CompositeGraphic());
    unique_ptr<CompositeGraphic> graphic_2(new CompositeGraphic());
    unique_ptr<CompositeGraphic> graphicMngr(new CompositeGraphic());

    // Composes the graphics
    graphic_1->add(ellipse_1.get());
    graphic_1->add(ellipse_2.get());
    graphic_1->add(ellipse_3.get());

    graphic_2->add(ellipse_4.get());

    graphicMngr->add(graphic_1.get());
    graphicMngr->add(graphic_2.get());


    // Print graphics
    graphicMngr->print();

    return 0;
}