#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    string vehicleID, manufacturer, model;
    int year;
    static int totalVehicles;

public:
    Vehicle()
    {
        vehicleID = ""; manufacturer = ""; model = ""; year = 0;totalVehicles++;
    }
    Vehicle(string id, string mfg, string mdl, int yr)
    {
        vehicleID = id;
        manufacturer = mfg;
        model = mdl;
        year = yr;
        totalVehicles++;
    }
    ~Vehicle()
    {
        totalVehicles--;
    }

    string getVehicleID()
    {
        return vehicleID;
    }
    void setVehicleID(string id)
    {
        vehicleID = id;
    }

    static int getTotalVehicles()
    {
        return totalVehicles;
    }

    void displayInfo()
    {
        cout << "ID: " << vehicleID << " | " << manufacturer << " " << model << " (" << year << ")" << endl;
    }
};
int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
protected:
    string fuelType;
public:
    Car() : Vehicle()
    {
        fuelType = "";
    }
    Car(string id, string mfg, string mdl, int yr, string fuel)
        : Vehicle(id, mfg, mdl, yr)
    {
        fuelType = fuel;
    }

    void displayInfo()
    {
        Vehicle::displayInfo();
        cout << "Fuel: " << fuelType << endl;
    }
};

class ElectricCar : public Car
{
protected:
    double batteryCapacity;
public:
    ElectricCar() : Car()
    {
        batteryCapacity = 0;
    }
    ElectricCar(string id, string mfg, string mdl, int yr, string fuel, double battery) : Car(id, mfg, mdl, yr, fuel)
    {
        batteryCapacity = battery;
    }

    void displayInfo()
    {
        Car::displayInfo();
        cout << "Battery: " << batteryCapacity << "kWh" << endl;
    }
};

class Sedan : public Car
{
public:
    Sedan() : Car() 
    {}
    Sedan(string id, string mfg, string mdl, int yr, string fuel) : Car(id, mfg, mdl, yr, fuel)
    {}

    void displayInfo()
    {
        cout << "Type: Sedan" << endl;
        Car::displayInfo();
    }
};

class SUV : public Car
{
public:
    SUV() : Car()
    {}
    SUV(string id, string mfg, string mdl, int yr, string fuel) : Car(id, mfg, mdl, yr, fuel)
    {}

    void displayInfo()
    {
        cout << "Type: SUV" << endl;
        Car::displayInfo();
    }
};

class VehicleRegistry
{
private:
    Vehicle* vehicles[50];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle(Vehicle* v)
    {
        if (count < 50)
        {
            vehicles[count] = v;
            count++;
            cout << "✓ Vehicle added successfully!" << endl;
        }
        else 
        {
            cout << "Registry Full!" << endl;
        }
    }

    void displayAll()
    {
        cout << "\n=== VEHICLE REGISTRY (Total: " << Vehicle::getTotalVehicles() << ") ===" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "\n" << (i+1) << ". " << endl;
            vehicles[i]->displayInfo();
        }
    }

    void searchByID(string id)
    {
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << "\n✓ Found Vehicle: " << endl;
                vehicles[i]->displayInfo();
                return;
            }
        }
        cout << "✗ Vehicle ID '" << id << "' not found." << endl;
    }
};

int main()
{
    VehicleRegistry registry;
    int choice;

    cout << "Vehicle Registry System" << endl;

    do
    {
        cout << "\n1. Add Car  \n2. Add ElectricCar  \n3. Add Sedan  \n4. Add SUV  \n5. View All  \n6. Search by ID  \n7. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string id, mfg, model, fuel; int year;
            cout << "ID: "; cin >> id;
            cout << "Manufacturer: "; cin >> mfg;
            cout << "Model: "; cin >> model;
            cout << "Year: "; cin >> year;
            cout << "Fuel: "; cin >> fuel;
            Car* c = new Car(id, mfg, model, year, fuel);
            registry.addVehicle(c);
        }
        else if (choice == 2)
        {
            string id, mfg, model, fuel; int year; double battery;
            cout << "ID: "; cin >> id;
            cout << "Manufacturer: "; cin >> mfg;
            cout << "Model: "; cin >> model;
            cout << "Year: "; cin >> year;
            cout << "Fuel: "; cin >> fuel;
            cout << "Battery(kWh): "; cin >> battery;
            ElectricCar* ec = new ElectricCar(id, mfg, model, year, fuel, battery);
            registry.addVehicle(ec);
        }
        else if (choice == 3)
        {
            string id, mfg, model, fuel; int year;
            cout << "ID: "; cin >> id;
            cout << "Manufacturer: "; cin >> mfg;
            cout << "Model: "; cin >> model;
            cout << "Year: "; cin >> year;
            cout << "Fuel: "; cin >> fuel;
            Sedan* s = new Sedan(id, mfg, model, year, fuel);
            registry.addVehicle(s);
        }
        else if (choice == 4)
        {
            string id, mfg, model, fuel; int year;
            cout << "ID: "; cin >> id;
            cout << "Manufacturer: "; cin >> mfg;
            cout << "Model: "; cin >> model;
            cout << "Year: "; cin >> year;
            cout << "Fuel: "; cin >> fuel;
            SUV* suv = new SUV(id, mfg, model, year, fuel);
            registry.addVehicle(suv);
        }
        else if (choice == 5)
        {
        registry.displayAll();
        }
        else if (choice == 6)
        {
            string id; cout << "Enter ID: "; cin >> id;
            registry.searchByID(id);
        }
        else if (choice == 7)
        {
            cout << "session ended."<< endl;
        }

    } while (choice != 7);

    return 0;
}