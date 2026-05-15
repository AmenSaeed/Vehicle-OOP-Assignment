#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string model;
    string registerationNumber;
    int speed;
    double fuelCapacity;
    double fuelConsumption;
public:
    Vehicle(string m, string rn, int sp, double fca, double fco) {
        if (fco <= 0)
            throw 1;
        model = m;
        registerationNumber = rn;
        speed = sp;
        fuelCapacity = fca;
        fuelConsumption = fco;
    }
    double fuelNeeded(double distance) {
        if (distance < 0)
            throw 1;
        return distance * fuelConsumption;
    }

    double fuelNeeded(double distance, double extraLoad) {
        if (distance < 0)
            throw 1;
        return distance * fuelConsumption * extraLoad;
    }

    double distanceCovered(int t) {
        return speed * t;
    }
    void display() {
        cout << "Model: " << model << endl;
        cout << "Registeration Number: " << registerationNumber << endl;
        cout << "Speed: " << speed << endl;
        cout << "Fuel Capacity: " << fuelCapacity << endl;
        cout << "Fuel Consumption: " << fuelConsumption << endl;
    }
};


class Truck : public Vehicle{
private:
    double cargoWeightLimit;
public:
    Truck(string m, string rn, int sp, double fca, double fco ,double cwl) : Vehicle(m ,rn ,sp ,fca ,fco) {
        if (cwl < 0)
            throw 1;
        cargoWeightLimit = cwl;
    }
    void setCargo(double cwl) {
        if (cwl < 0)
            throw 1;
        cargoWeightLimit = cwl;
    }

    double getCargo() {
        return cargoWeightLimit;
    }

    void display() {
        Vehicle::display();
        cout << "Cargo Weight Vehicle: " << cargoWeightLimit << endl;
        cout << "----------------------------" << endl; //deh 3shan enta ragel mo7taram

    }
};


class Bus : public Vehicle{
private:
    int numberOfPassengers;
public:
    Bus(string m, string rn, int sp, double fca, double fco,int NOP) : Vehicle( m,  rn,  sp,  fca,  fco) {
        if (NOP < 0 || NOP > 100)
            throw 1;
        numberOfPassengers = NOP;
    }

    void setNumber(int NOP) {
        if (numberOfPassengers < 0 || NOP > 100)
            throw 1;
        numberOfPassengers = NOP;
    }
    double getNumber() {
        return numberOfPassengers;
    }
    void display() {
        Vehicle::display();
        cout << "Number of Passengers: " << numberOfPassengers << endl;
        cout << "----------------------------" << endl;
    }

};


int main() {
    try {
        // ===== Vehicle =====
        Vehicle v("Toyota", "ABC-123", 120, 50.0, 0.08);
        v.display();
        cout << "Fuel needed (100km): " << v.fuelNeeded(100) << " L" << endl;
        cout << "Fuel needed (100km, load 1.2): " << v.fuelNeeded(100, 1.2) << " L" << endl;
        cout << "Distance in 3h: " << v.distanceCovered(3) << " km" << endl;
        cout << "----------------------------" << endl;

        // ===== Truck =====
        Truck t("Volvo", "TRK-456", 90, 200.0, 0.15, 5000.0);
        t.display();
        cout << "Fuel needed (200km): " << t.fuelNeeded(200) << " L" << endl;
        cout << "Fuel needed (200km, load 1.5): " << t.fuelNeeded(200, 1.5) << " L" << endl;
        cout << "----------------------------" << endl;

        // ===== Bus =====
        Bus b("Mercedes", "BUS-789", 80, 150.0, 0.12, 45);
        b.display();
        cout << "Fuel needed (50km): " << b.fuelNeeded(50) << " L" << endl;
        cout << "----------------------------" << endl;

    } catch (...) {
        cout << "An error occurred!" << endl;
    }

return 0;
}