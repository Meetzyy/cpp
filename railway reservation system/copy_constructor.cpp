#include <iostream>
using namespace std;

class Student
{
    int age;
    public:
        Student(int a)
        {
            age = a;
        }
        Student(const Student &obj)
        {
            age = obj.age;
        }
        void display()
        {
            cout << "Age: " << age << endl;
        }
};

int main()
{
    Student s1(20);
    Student s2 = s1;
    s2.display();
    return 0;
}
