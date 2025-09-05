#include <iostream>
using namespace std;

class Base
{
    public:
        void showBase()
        {
            cout << "Base class\n";
        }
};

class Derived1 : public Base
{
    public:
        void showD1()
        {
            cout << "Derived1 class\n";
        }
};

class Derived2 : public Base
{
    public:
        void showD2()
        {
            cout << "Derived2 class\n";
        }
};

int main()
{
    Derived1 d1;
    Derived2 d2;
    d1.showBase();
    d1.showD1();
    d2.showBase();
    d2.showD2();
    return 0;
}
