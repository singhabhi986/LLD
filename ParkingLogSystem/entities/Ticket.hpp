#include <memory>
#include <Vehicle.hpp>

class Ticket {
    int ticketId;
    int parkingSpotId;
    time_t entryTime;
    std::shared_ptr<Vehicle> vehicle; // Shared ownership of Vehicle

    public:
        Ticket(int id, int spotId, time_t time, std::shared_ptr<Vehicle> veh)
            : ticketId(id), parkingSpotId(spotId), entryTime(time), vehicle(veh) {}
};