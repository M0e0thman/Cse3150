#include <iostream>

using namespace std;

// Base class
class Vehicle {
protected:
    double weight;
public:
    Vehicle(double w) : weight(w) {}
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual double calculateCostOfFuel(double miles) = 0;
    virtual ~Vehicle() {}
};

// Electric Vehicle
class Electric : virtual public Vehicle {
protected:
    double efficiency;
public:
    Electric(double w, double e) : Vehicle(w), efficiency(e) {}
    void start() override { cout << "Electric vehicle starting..." << endl; }
    void stop() override { cout << "Electric vehicle stopping..." << endl; }
    double calculateCostOfFuel(double miles) override {
        cout << "Calculating cost of fuel for Electric vehicle..." << endl;
        return miles / efficiency;
    }
};

// Gasoline Vehicle
class Gasoline : virtual public Vehicle {
protected:
    double mpg;
public:
    Gasoline(double w, double m) : Vehicle(w), mpg(m) {}
    void start() override { cout << "Gasoline vehicle starting..." << endl; }
    void stop() override { cout << "Gasoline vehicle stopping..." << endl; }
    double calculateCostOfFuel(double miles) override {
        cout << "Calculating cost of fuel for Gasoline vehicle..." << endl;
        return miles / mpg;
    }
};

// Hybrid Vehicle
class Hybrid : public Electric, public Gasoline {
public:
    Hybrid(double w, double e, double m) : Vehicle(w), Electric(w, e), Gasoline(w, m) {}
    void start() override { Electric::start(); }
    void stop() override { Gasoline::stop(); }
    double calculateCostOfFuel(double miles) override {
        cout << "Calculating cost of fuel for Hybrid vehicle..." << endl;
        return (Electric::calculateCostOfFuel(miles) + Gasoline::calculateCostOfFuel(miles)) / 2;
    }
};

int main() {
    Hybrid hybrid(1500, 0.2, 30); // Weight, Electric efficiency, Gasoline mpg

    hybrid.start();
    hybrid.stop();

    cout << "Cost of fuel for Hybrid vehicle: $" << hybrid.calculateCostOfFuel(100) << endl;

    return 0;
}

