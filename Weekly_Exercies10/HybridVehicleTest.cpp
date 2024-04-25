#include <iostream>
#include "HybridVehicleHierarchy.cpp" 
using namespace std;

void testElectricVehicle() {
    cout << "Testing Electric Vehicle Functions:" << endl;
    Electric electric(1500, 0.2); // Weight, Efficiency
    electric.start();
    electric.stop();
    double electricCost = electric.calculateCostOfFuel(100);
    cout << "Cost of fuel for Electric vehicle: $" << electricCost << endl;
}

void testGasolineVehicle() {
    cout << "\nTesting Gasoline Vehicle Functions:" << endl;
    Gasoline gasoline(1500, 30); // Weight, MPG
    gasoline.start();
    gasoline.stop();
    double gasolineCost = gasoline.calculateCostOfFuel(100);
    cout << "Cost of fuel for Gasoline vehicle: $" << gasolineCost << endl;
}

void testHybridVehicle() {
    cout << "\nTesting Hybrid Vehicle Functions:" << endl;
    Hybrid hybrid(1500, 0.2, 30); // Weight, Electric Efficiency, MPG
    hybrid.start();
    hybrid.stop();
    double hybridCost = hybrid.calculateCostOfFuel(100);
    cout << "Cost of fuel for Hybrid vehicle: $" << hybridCost << endl;
}

void testPolymorphism() {
    cout << "\nTesting Polymorphism:" << endl;
    Vehicle* vehiclePtr;
    
    Electric electric(1500, 0.2); // Weight, Efficiency
    Gasoline gasoline(1500, 30); // Weight, MPG
    Hybrid hybrid(1500, 0.2, 30); // Weight, Electric Efficiency, MPG
    
    vehiclePtr = &electric;
    vehiclePtr->start();
    vehiclePtr->stop();
    double electricCost = vehiclePtr->calculateCostOfFuel(100);
    cout << "Cost of fuel for Electric vehicle: $" << electricCost << endl;

    vehiclePtr = &gasoline;
    vehiclePtr->start();
    vehiclePtr->stop();
    double gasolineCost = vehiclePtr->calculateCostOfFuel(100);
    cout << "Cost of fuel for Gasoline vehicle: $" << gasolineCost << endl;

    vehiclePtr = &hybrid;
    vehiclePtr->start();
    vehiclePtr->stop();
    double hybridCost = vehiclePtr->calculateCostOfFuel(100);
    cout << "Cost of fuel for Hybrid vehicle: $" << hybridCost << endl;
}

int main() {
    testElectricVehicle();
    testGasolineVehicle();
    testHybridVehicle();
    testPolymorphism();
    
    return 0;
}
