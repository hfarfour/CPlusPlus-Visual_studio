
#include <iostream>
using namespace std;


class rectangle
{
private:
    float length;
    float width;
public:
    void setLength(float l)
    {
        if (l >= 0)
            length = l;
        else

            cout << "enter just positive numbers only" << endl;
    }

    float getLength()
    {
        return length;
    }

    void setWidth(float w)
    {
        if (w >= 0)
            width = w;
        else

            cout << "enter just positive numbers only" << endl;
    }
    float getWidth()
    {
        return width;
    }

    float getArea()
    {
        return length * width;
    }
};


int main()
{
    rectangle box;
    box.setLength(40.5);
    box.setWidth(30.6);
    cout << "the regtangle area is " << box.getArea() << endl;
}
