#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string model;
    string regNumber;
    int speed;
    double fuelCapacity;
    double fuelConsumption;

public:
    Vehicle(string m, string r, int s, double cap, double cons) {
        model = m;
        regNumber = r;
        speed = s;
        fuelCapacity = cap;
        try {
            if (cons <= 0)
                throw("Wrong numbers");
            fuelConsumption = cons;
        } catch (const char* msg) {
            cout << msg << endl;
        }
    }

    double fuelNeeded(double distance) {
        try {
            if (distance < 0)
                throw("Distance should be positive");
            return distance * fuelConsumption;
        } catch (const char* msg) {
            cout << msg << endl;
            return 0;
        }
    }

    double fuelNeeded(double distance, double extraLoad) {
        try {
            if (distance < 0)
                throw("Distance should be positive");
            return (distance * fuelConsumption) + (extraLoad * 0.017);
        } catch (const char* msg) {
            cout << msg << endl;
            return 0;
        }
    }

    double distanceCovered(double time) {
        return speed * time;
    }

    double distanceCovered(double time, double r) {
        return speed * time;
    }

    virtual void display() {
        cout << "Model: " << model << " RegNum: " << regNumber << " Speed: " << speed << endl;
    }
};

class Truck : public Vehicle {
private:
    double cargoWeightLimit;

public:
    Truck(string m, string r, int s, double cap, double cons, double weight) 
        : Vehicle(m, r, s, cap, cons) {
        try {
            if (weight < 0)
                throw("Weight can't be negative");
            cargoWeightLimit = weight;
        } catch (const char* msg) {
            cout << msg << endl;
        }
    }

    void setCargoWeightLimit(double weight) {
        cargoWeightLimit = weight;
    }

    double getCargoWeightLimit() {
        return cargoWeightLimit;
    }

    void display() {
        Vehicle::display();
        cout << "Cargo Weight Limit: " << cargoWeightLimit << " kg" << endl;
    }
};

class Bus : public Vehicle {
private:
    int numOfPassengers;

public:
    Bus(string m, string r, int s, double cap, double cons, int np) 
        : Vehicle(m, r, s, cap, cons) {
        try {
            if (np < 0 || np > 100)
                throw("We can't move");
            numOfPassengers = np;
        } catch (const char* msg) {
            cout << msg << endl;
        }
    }

    void display() {
        Vehicle::display();
        cout << "Number of Passengers: " << numOfPassengers << endl;
    }
};

int main() {
    try {
        Vehicle v1("Aston Martin", "HAZ-425", 250, 45, 0.064);
        Truck t1("Hyundai", "HAZ-173", 110, 25, 0.23, 7000);
        Bus b1("Toyota", "HAZ-2007", 95, 30, 0.1, 70);

        cout << "Vehicle details: "; 
        v1.display();
        
        cout << "Truck details: ";
        t1.display();

        cout << "Bus details: ";
        b1.display();

        cout << "Fuel needed for 150KM: " << v1.fuelNeeded(150) << endl;
        cout << "Fuel with extra load: " << v1.fuelNeeded(150, 200) << endl;
        
        v1.fuelNeeded(-80);

    } catch (const char* msg) {
        cout << msg << endl;
    }

    cout << "The Program is continued" << endl;
    return 0;
}