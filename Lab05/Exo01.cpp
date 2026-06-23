/******************************************************************************
In the smart parking lot scene, there are three main objects: Car, Gate, and ParkingLot. 
A Car represents one vehicle and should at least store its plate number. A Gate represents the entrance gate and has only two states,
OPEN and CLOSED. A ParkingLot represents the whole parking lot. It manages all Car objects currently inside and determines the Gate state according 
to the current number of cars and the capacity limit.The rules are as follows. Initially, the parking lot is empty.
If the current number of cars is smaller than the capacity limit, the Gate should be considered OPEN.
When the number of cars becomes equal to the capacity limit, the Gate should be considered CLOSED. 
ARRIVE plate means that a car with plate number plate tries to enter the lot. If that car is already inside, nothing changes.
If the lot is full, nothing changes and you should output Lot full. LEAVE plate means that the car with plate number plate tries to leave the lot.
If that car is not inside, nothing changes and you should output not found. STATUS outputs the current number of cars and the gate state.
You must solve this problem using object-oriented programming. At minimum, use classes to describe Car, Gate, and ParkingLot, and 
let ParkingLot handle ARRIVE, LEAVE, and STATUS through member functions. Do not write the whole solution using only scattered variables and ordinary functions.
The first line contains two integers N and Q, the parking lot capacity and the number of operations.
The next Q lines each contain one of the following operations: ARRIVE plate, LEAVE plate, or STATUS.
Output one line for each operation.
For ARRIVE, output plate parked if the car enters successfully, plate already inside if the car is already inside, or Lot full if the lot is full.
For LEAVE, output plate left if the car leaves successfully, or plate not found if the car is not inside.
For STATUS, output Cars: X, Gate: Y, where Y is either OPEN or CLOSED.

Sample Input 
3 8
STATUS
ARRIVE CAR001
ARRIVE CAR002
STATUS
ARRIVE CAR003
ARRIVE CAR004
LEAVE CAR002
STATUS
Sample Output 1
Cars: 0, Gate: OPEN
CAR001 parked
CAR002 parked
Cars: 2, Gate: OPEN
CAR003 parked
Lot full
CAR002 left
Cars: 2, Gate: OPEN

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;
class Car {
private:
    string plate;

public:
    Car() {} 
    Car(string p) {
        plate = p;
    }

    string getPlate() const {
        return plate;
    }
};

class Gate {
private:
    string state;

public:
    Gate() {
        state = "OPEN";
    }

    void setState(string s) {
        state = s;
    }

    string getState() const {
        return state;
    }
};

class ParkingLot {
private:
    int capacity;
    int count;        
    Car* cars;        
    Gate gate;

    int findCar(string plate) {
        for (int i = 0; i < count; i++) {
            if (cars[i].getPlate() == plate) {
                return i;
            }
        }
        return -1;
    }
    
    void updateGate() {
        if (count < capacity)
            gate.setState("OPEN");
        else
            gate.setState("CLOSED");
    }

public:
    ParkingLot(int cap) {
        capacity = cap;
        count = 0;
        cars = new Car[capacity]; 
    }

 
    ~ParkingLot() {
        delete[] cars;
    }

   
    void arrive(string plate) {
        if (findCar(plate) != -1) {
            cout << plate << " already inside" << endl;
            return;
        }

        if (count == capacity) {
            cout << "Lot full" << endl;
            return;
        }

        cars[count] = Car(plate); // add at end
        count++;

        updateGate();
        cout << plate << " parked" << endl;
    }

    // LEAVE
    void leave(string plate) {
        int index = findCar(plate);

        if (index == -1) {
            cout << plate << " not found" << endl;
            return;
        }

        // Shift left to remove car
        for (int i = index; i < count - 1; i++) {
            cars[i] = cars[i + 1];
        }

        count--;

        updateGate();
        cout << plate << " left" << endl;
    }

    // STATUS
    void status() {
        cout << "Cars: " << count
             << ", Gate: " << gate.getState() << endl;
    }
};


int main() {
    int N, Q;
    cin >> N >> Q;

    ParkingLot lot(N);

    while (Q--) {
        string command;
        cin >> command;

        if (command == "ARRIVE") {
            string plate;
            cin >> plate;
            lot.arrive(plate);
        }
        else if (command == "LEAVE") {
            string plate;
            cin >> plate;
            lot.leave(plate);
        }
        else if (command == "STATUS") {
            lot.status();
        }
    }

    return 0;
}


