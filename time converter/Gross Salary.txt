#include <iostream>
using namespace std;

int main() {
    float baseSalary, hraPercent, daPercent, taPercent;
    float hra, da, ta, grossSalary;
    cout << "Enter Base Salary: ";
    cin >> baseSalary;

    cout << "Enter HRA percentage: ";
    cin >> hraPercent;

    cout << "Enter DA percentage: ";
    cin >> daPercent;

    cout << "Enter TA percentage: ";
    cin >> taPercent;

    hra = (hraPercent / 100) * baseSalary;
    da = (daPercent / 100) * baseSalary;
    ta = (taPercent / 100) * baseSalary;

    grossSalary = baseSalary + hra + da + ta;
    cout << "\nGross Salary = " << grossSalary << endl;

    return 0;
}
