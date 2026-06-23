/****************************************************************
In the campus shuttle bus scene, there are three main objects: Passenger, Engine, and ShuttleBus.
 A Passenger represents one rider, and name is the passenger's name. An Engine represents the bus engine and has only two states, ON and OFF. 
A ShuttleBus represents the whole bus. It manages all Passenger objects currently on board and decides whether the bus is moving according to START and STOP operations.
The rules are as follows. Initially, the bus has no passengers and the engine is OFF, which means the bus is stopped. 
BOARD name and EXIT name are allowed only when the bus is stopped. If the bus is moving, both BOARD and EXIT must keep the state unchanged and output Bus is moving.
If the passenger named name is already on the bus and BOARD name is issued again, nothing changes.
If EXIT name is issued for someone not on the bus, nothing changes. If the bus is full, a new BOARD name should output Bus is full. 
If START is issued when there are no passengers on the bus, output Bus is empty. STATUS outputs the current number of passengers and the engine state.
You must solve this problem using object-oriented programming. At minimum, use classes to describe Passenger, Engine, and ShuttleBus, 
and let ShuttleBus handle BOARD, EXIT, START, STOP, and STATUS through member functions. Do not write the whole solution using only scattered variables and ordinary functions.
Input. The first line contains two integers N and Q, the bus capacity and the number of operations.
The next Q lines each contain one of the following operations: BOARD name, EXIT name, START, STOP, or STATUS.

Output one line for each operation.
For BOARD, output name boarded if successful. Output Bus is moving if the bus is moving, name already on bus if the passenger is already on board, or Bus is full if the bus is full.
For EXIT, output name exited if successful. Output Bus is moving if the bus is moving, or name not on bus if the passenger is not on the bus.
For START, output Bus started if successful. Output Bus already moving if the bus is already moving, or Bus is empty if there are no passengers.
For STOP, output Bus stopped if successful, or Bus already stopped if the bus is already stopped.
For STATUS, output Passengers: X, Engine: Y, where Y is ON or OFF.
Sample Input 1
2 9
STATUS
BOARD Amy
BOARD Bob
START
STATUS
BOARD Carl
STOP
EXIT Amy
STATUS
Sample Output 
Passengers: 0, Engine: OFF
Amy boarded
Bob boarded
Bus started
Passengers: 2, Engine: ON
Bus is moving
Bus stopped
Amy exited
Passengers: 1, Engine: OFF
 *************************************************************/
#include <iostream>
#include <unordered_set>
#include <string>

class Passenger {
public:
    std::string name;
    explicit Passenger(const std::string& n) : name(n) {}
};

class Engine {
public:
    enum State { ON, OFF };
private:
    State state;
public:
    Engine() : state(OFF) {}
    void setState(State s) { state = s; }
    bool isOn() const { return state == ON; }
    std::string getStateStr() const { return state == ON ? "ON" : "OFF"; }
};

class ShuttleBus {
    int capacity;
    std::unordered_set<std::string> passengers;
    Engine engine;

public:
    explicit ShuttleBus(int cap) : capacity(cap) {}

    void board(const std::string& name) {
        if (engine.isOn())          { std::cout << "Bus is moving\n"; return; }
        if (passengers.count(name)) { std::cout << name << " already on bus\n"; return; }
        if ((int)passengers.size() >= capacity) { std::cout << "Bus is full\n"; return; }
        passengers.insert(name);
        std::cout << name << " boarded\n";
    }

    void exit_(const std::string& name) {
        if (engine.isOn())           { std::cout << "Bus is moving\n"; return; }
        if (!passengers.count(name)) { std::cout << name << " not on bus\n"; return; }
        passengers.erase(name);
        std::cout << name << " exited\n";
    }

    void start() {
        if (engine.isOn())           { std::cout << "Bus already moving\n"; return; }
        if (passengers.empty())      { std::cout << "Bus is empty\n"; return; }
        engine.setState(Engine::ON);
        std::cout << "Bus started\n";
    }

    void stop() {
        if (!engine.isOn()) { std::cout << "Bus already stopped\n"; return; }
        engine.setState(Engine::OFF);
        std::cout << "Bus stopped\n";
    }

    void status() const {
        std::cout << "Passengers: " << passengers.size()
                  << ", Engine: " << engine.getStateStr() << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q; std::cin >> N >> Q;
    ShuttleBus bus(N);

    for (int i = 0; i < Q; ++i) {
        std::string op; std::cin >> op;
        if      (op == "BOARD")  { std::string n; std::cin >> n; bus.board(n); }
        else if (op == "EXIT")   { std::string n; std::cin >> n; bus.exit_(n); }
        else if (op == "START")  { bus.start(); }
        else if (op == "STOP")   { bus.stop(); }
        else                     { bus.status(); }
    }
    return 0;
}