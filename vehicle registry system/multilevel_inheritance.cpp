#include <iostream>
using namespace std;

class GrandParent
{
    public:
        void showGP()
        {
            cout << "GrandParent class\n";
        }
};

class Parent : public GrandParent
{
    public:
        void showParent()
        {
            cout << "Parent class\n";
        }
};

class Child : public Parent
{
    public:
        void showChild()
        {
            cout << "Child class\n";
        }
};

int main()
{
    Child obj;
    obj.showGP();
    obj.showParent();
    obj.showChild();
    return 0;
}
