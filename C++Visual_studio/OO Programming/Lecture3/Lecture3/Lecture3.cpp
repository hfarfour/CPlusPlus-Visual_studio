#include<string>
#include <iostream>
using namespace std;

class shape
{
public:
    virtual void draw() = 0;
};

class square : public shape
{
public:

    int side;
    square(int s) : side(s)
     { }
    virtual void draw()
    {
        cout << "square , side = " << side << endl;
    }
};

class circle : public shape
{
public:
    int  radius;
    circle(int r) : radius (r)
    {  }
    virtual void draw()
    {
        cout << "circle  , radius  = " << radius<< endl;
    }
};                                                                      
//class grahpicEditor
//{
//public:
//    void drawshape(shape* t)                             // questionhere
//    {
//        t->draw();
//    }
//};
int main()
{

    shape* TG;
    square s(5);
    circle c(1);
    TG = &s;
    TG->draw();
    TG = & c;
    TG->draw();

  /* square* r = new  square(5);
    circle* c = new circle(1); 
    grahpicEditor g;
    g.drawshape(r);
    g.drawshape(c);*/
}