#include <iostream>
#include <string>
#define MAX_SEATS 100

using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats;

public:
    Flight(const string& num, const string& dep, const string& arr, int cap)
        : flightNumber(num), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    bool bookSeat() {
        if (bookedSeats >= capacity) return false;
        bookedSeats++;
        return true;
    }

    bool cancelSeat() {
        if (bookedSeats <= 0) return false;
        bookedSeats--;
        return true;
    }

    string getFlightNumber() const { return flightNumber; }
    string getDeparture() const { return departure; }
    string getArrival() const { return arrival; }
    int getCapacity() const { return capacity; }
    int getBookedSeats() const { return bookedSeats; }
    int getAvailableSeats() const { return capacity - bookedSeats; }
};

class Passenger {
private:
    string id;
    string name;
    Flight* flight;
    bool hasBooking;
    bool isUpgraded;

public:
    Passenger(const string& passengerId, const string& passengerName, 
              Flight* flt)
        : id(passengerId), name(passengerName), flight(flt), 
          hasBooking(false), isUpgraded(false) {}

    bool bookFlight() {
        if (!flight) {
            cout << "No flight assigned to passenger" << endl;
            return false;
        }

        if (hasBooking) {
            cout << name << " already has a booking on flight " 
                 << flight->getFlightNumber() << endl;
            return false;
        }

        if (flight->bookSeat()) {
            hasBooking = true;
            cout << name << " successfully booked flight " 
                 << flight->getFlightNumber() << endl;
            return true;
        }
        
        cout << "No available seats on flight " << flight->getFlightNumber() << endl;
        return false;
    }

    bool cancelBooking() {
        if (!flight) {
            cout << "No flight assigned to passenger" << endl;
            return false;
        }

        if (!hasBooking) {
            cout << name << " has no booking to cancel on flight " 
                 << flight->getFlightNumber() << endl;
            return false;
        }

        if (flight->cancelSeat()) {
            hasBooking = false;
            isUpgraded = false;
            cout << name << " successfully cancelled flight " 
                 << flight->getFlightNumber() << endl;
            return true;
        }

        cout << "Cancellation failed for " << name << endl;
        return false;
    }

    bool upgradeSeat() {
        if (!flight) {
            cout << "No flight assigned to passenger" << endl;
            return false;
        }

        if (!hasBooking) {
            cout << name << " has no booking to upgrade on flight " 
                 << flight->getFlightNumber() << endl;
            return false;
        }

        if (isUpgraded) {
            cout << name << " already has an upgraded seat on flight " 
                 << flight->getFlightNumber() << endl;
            return false;
        }

        isUpgraded = true;
        cout << name << " successfully upgraded on flight " 
             << flight->getFlightNumber() << endl;
        return true;
    }

    void displayStatus() const {
        cout << "\nPassenger: " << name << " (ID: " << id << ")\n";
        if (flight) {
            cout << "Flight: " << flight->getFlightNumber() << " from " 
                 << flight->getDeparture() << " to " << flight->getArrival() << endl;
            cout << "Status: " << (hasBooking ? "Booked" : "Not Booked");
            if (hasBooking && isUpgraded) cout << " (Upgraded)";
            cout << endl;
            cout << "Flight capacity: " << flight->getBookedSeats() << "/" 
                 << flight->getCapacity() << " seats taken\n";
        } else {
            cout << "No flight assigned\n";
        }
    }

    string getId() const { return id; }
    string getName() const { return name; }
    Flight* getFlight() const { return flight; }
    void setFlight(Flight* flt) { flight = flt; }
};

int main() {
    Flight nycToLax("AA123", "New York", "Los Angeles", 3);
    Flight laxToChi("UA456", "Los Angeles", "Chicago", 200);

    Passenger john("P100", "John Doe", &nycToLax);
    Passenger jane("P101", "Jane Smith", &nycToLax);
    Passenger bob("P102", "Bob Johnson", &laxToChi);

    john.bookFlight();
    jane.bookFlight();
    bob.bookFlight();

    Passenger alice("P103", "Alice Brown", &nycToLax);
    alice.bookFlight();

    john.upgradeSeat();
    alice.upgradeSeat();

    jane.cancelBooking();
    jane.cancelBooking();

    john.displayStatus();
    jane.displayStatus();
    bob.displayStatus();
    alice.displayStatus();

    cout << "\nChanging John's flight to LAX-CHI\n";
    john.cancelBooking();
    john.setFlight(&laxToChi);
    john.bookFlight();
    john.displayStatus();

    return 0;
}
