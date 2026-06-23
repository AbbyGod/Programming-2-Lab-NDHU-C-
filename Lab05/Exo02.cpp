/******************************************************************************
In the library study room scene, there are four main objects: Student, Lamp, StudyRoom, and Library.
A Student represents one student using a study room, and name is the student's name. A Lamp represents the room light and has only two states, ON and OFF. 
A StudyRoom represents one study room, and at most one Student can use it at a time. A Library represents the whole library system and may manage all study rooms.
The rules are as follows. Initially, all rooms are empty and all lights are OFF. ENTER room name means that the student whose name is name tries to enter room room. 
If the room is empty, that student successfully uses the room and the room light becomes ON. If the room is already occupied, nothing changes. 
LEAVE room means that the student currently using room leaves it. If the room is already empty, nothing changes. 
STATUS room reports whether the room is empty or occupied by which student, and also reports the lamp state. 
SUMMARY reports how many rooms are currently occupied and how many are empty.
You must solve this problem using object-oriented programming. At minimum, use classes to describe Student, Lamp, StudyRoom, and Library, 
and let Library or StudyRoom handle ENTER, LEAVE, STATUS, and SUMMARY through member functions. 
Do not write the whole solution using only scattered variables and ordinary functions.
The first line contains two integers R and Q, the number of study rooms and the number of operations. Room numbers are from 1 to R.
The next Q lines each contain one of the following operations: ENTER room name, LEAVE room, STATUS room, or SUMMARY.
Output one line for each operation.
For ENTER, output Room r occupied by name if the room becomes occupied, or Room r is occupied if the room is already in use.
For LEAVE, output Room r released if the room becomes empty, or Room r is already empty if it was empty before.
For STATUS, output either Room r: empty, Lamp: OFF or Room r: name, Lamp: ON.
For SUMMARY, output Occupied: X, Empty: Y.
Sample Input 
3 8
SUMMARY
ENTER 1 Amy
STATUS 1
ENTER 1 Bob
ENTER 2 Bob
SUMMARY
LEAVE 1
STATUS 1
Sample Output 
Occupied: 0, Empty: 3
Room 1 occupied by Amy
Room 1: Amy, Lamp: ON
Room 1 is occupied
Room 2 occupied by Bob
Occupied: 2, Empty: 1
Room 1 released
Room 1: empty, Lamp: OFF

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Student{
    private:
      string name;
    public Student(){
        name = "";
    }
    Student(string s){
        name = n;
    }
    string getName() const {
        return name;
    }
};
class Lamp{
    private:
      string state;
    public:
      Lamp(){
          state = "OFF"
      }
      void turnOn(){
          state = "ON";
      }
      void turnOff(){
          state = "OFF";
      }
      string getstate const(){
          return state;
      }
}
class StudyRoom{
    private:
      Student student;
      bool occupied;
      Lamp lamp;
    public:
      StudyRoom(){
          occupied = false;
      }
    void enter(int roomNumber, string name){
        if (occupied){
            couut << "Room " << roomNumber << "is occupied" << endl;
        } else {
            student = Student(name);
            occupied = true;
            lamp.turnOn();
            cout << "Room " << roomNumber << "is occupied by " << name << endl;
        }
    }
    void leave(int roomNumber){
        if (!occupied){
            cout << "Room " << roomNumber << "empty, Lamp: OFF" << endl;
        } else {
            cout << "Room " << roomNumber << ":" << student.getName() << ", Lamp: ON" << endl;
        }
    }
    bool isOccupied() const{
        return occupied;
    }
};

class Library{
  private:
    int totalRoom;
    StudyRoom* rooms;
};

int main(){
    
    
    #include <iostream>
#include <string>
using namespace std;

// -------------------- Student --------------------
class Student {
private:
    string name;

public:
    Student() {
        name = "";
    }

    Student(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }
};

// -------------------- Lamp --------------------
class Lamp {
private:
    string state; // "ON" or "OFF"

public:
    Lamp() {
        state = "OFF";
    }

    void turnOn() {
        state = "ON";
    }

    void turnOff() {
        state = "OFF";
    }

    string getState() const {
        return state;
    }
};

// -------------------- StudyRoom --------------------
class StudyRoom {
private:
    Student student;   // current student
    bool occupied;
    Lamp lamp;

public:
    StudyRoom() {
        occupied = false;
    }

    // ENTER
    void enter(int roomNumber, string name) {
        if (occupied) {
            cout << "Room " << roomNumber << " is occupied" << endl;
        } else {
            student = Student(name);
            occupied = true;
            lamp.turnOn();
            cout << "Room " << roomNumber << " occupied by " << name << endl;
        }
    }

    // LEAVE
    void leave(int roomNumber) {
        if (!occupied) {
            cout << "Room " << roomNumber << " is already empty" << endl;
        } else {
            occupied = false;
            lamp.turnOff();
            cout << "Room " << roomNumber << " released" << endl;
        }
    }

    // STATUS
    void status(int roomNumber) {
        if (!occupied) {
            cout << "Room " << roomNumber << ": empty, Lamp: OFF" << endl;
        } else {
            cout << "Room " << roomNumber << ": "
                 << student.getName()
                 << ", Lamp: ON" << endl;
        }
    }

    bool isOccupied() const {
        return occupied;
    }
};

// -------------------- Library --------------------
class Library {
private:
    int totalRooms;
    StudyRoom* rooms; // dynamic array

public:
    Library(int R) {
        totalRooms = R;
        rooms = new StudyRoom[R]; // create R rooms
    }

    ~Library() {
        delete[] rooms;
    }

    void enterRoom(int r, string name) {
        rooms[r - 1].enter(r, name);
    }

    void leaveRoom(int r) {
        rooms[r - 1].leave(r);
    }

    void statusRoom(int r) {
        rooms[r - 1].status(r);
    }

    void summary() {
        int occupiedCount = 0;

        for (int i = 0; i < totalRooms; i++) {
            if (rooms[i].isOccupied()) {
                occupiedCount++;
            }
        }

        cout << "Occupied: " << occupiedCount
             << ", Empty: " << (totalRooms - occupiedCount)
             << endl;
    }
};

// -------------------- MAIN --------------------
int main() {
    int R, Q;
    cin >> R >> Q;

    Library lib(R);

    while (Q--) {
        string command;
        cin >> command;

        if (command == "ENTER") {
            int room;
            string name;
            cin >> room >> name;
            lib.enterRoom(room, name);
        }
        else if (command == "LEAVE") {
            int room;
            cin >> room;
            lib.leaveRoom(room);
        }
        else if (command == "STATUS") {
            int room;
            cin >> room;
            lib.statusRoom(room);
        }
        else if (command == "SUMMARY") {
            lib.summary();
        }
    }

    return 0;
}
    
    return 0;
}