#include<iostream>
using namespace std;

class Animal
{
    public:
        void sound()
        {
            cout << "Animal sound\n";
        }
};

class Dog : public Animal
{
    public:
        void sound()
        {
            cout << "Dog barks\n";
        }
};

int main()
{
    Animal* a = new Dog();
    a->sound();
}