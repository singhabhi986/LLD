#include <Vehicle.hpp>
#include <memory>

class Reciept {
    int RecieptId;
    int TicketId;
    int amount;
    time_t entryTime;
    time_t exitTime;
    std::shared_ptr<Vehicle> vehicle;

    public:
        Reciept(int recieptId, int ticketId, int amt, time_t entryT, time_t exitT, std::shared_ptr<Vehicle> vehicle)
            : RecieptId(RecieptId), TicketId(ticketId), amount(amt), entryTime(entryT), exitTime(exitT), vehicle(vehicle) {}
};