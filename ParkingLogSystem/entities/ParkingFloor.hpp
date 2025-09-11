#include <vector>
#include <ParkingUnit.hpp>

class parkingFloor {
    int floorId;
    int capacity;
    std::vector<ParkingUnit> parkingUnits; // Vector of parking units on this floor
};