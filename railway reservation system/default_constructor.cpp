#include <iostream>
using namespace std;

class Default
{
    public:
        Default ()
        {
            cout << "Default constructor called!" << endl;
        }
};

int main()
{
    Default obj;
    return 0;
}
