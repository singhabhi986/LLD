#include <VehicleType.hpp>

class ParkingUnit {
    int id;
    bool isOccupied;
    VehicleType type; // Type of vehicle this unit can accommodate

    public:
        ParkingUnit(int id, VehicleType type) : id(id), isOccupied(false), type(type) {}

        bool occupy() {
            if (!isOccupied) {
                isOccupied = true;
                return true;
            }
            return false;
        }

        void vacate() {
            isOccupied = false;
        }

        bool isOccupied() const {
            return isOccupied;
        }
};