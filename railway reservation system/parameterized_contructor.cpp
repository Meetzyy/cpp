#include <iostream>
using namespace std;

class Parameter
{
    int a;
    public:
        Parameter(int a)
        {
            cout<<a<<endl;
            cout << "Parameterized constructor called!" << endl;
        }
};

int main()
{
    Parameter obj(21);
    return 0;
}
