#include <iostream>
using namespace std;

class Student {
    int age;
    public:
        void setAge(int a)
        { 
            age = a;
        }
        int getAge()
        {
            return age;
        }
};

int main()
{
    Student s;
    s.setAge(21); 
    cout << "Age: " << s.getAge() << endl;
    return 0;
}
