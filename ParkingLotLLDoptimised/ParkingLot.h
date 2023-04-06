#include <bits/stdc++.h>
using namespace std;

class ParkingLot
{

private:
    int MAX_SIZE = 0;    // stores the no of cars in parking lot
    int currentCars = 0; // stores number of cars currently parked in parking lot

    bool isFull()
    {
        if (currentCars == MAX_SIZE)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (currentCars == 0 && MAX_SIZE != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    set<int> available;             // stores available slots initially n;
    set<int> unavailable;           // initially 0
    map<int, set<int>> ageToSlotNo; // (age -> [slotnumber],regNo) <int,pair<vector<Int>,string>>
    set<pair<int, string>> ageToregNo;
    map<string, int> regToSlot;                  // (regno -> [slotnumber]) <string,vector<Int>>>
    map<int, pair<int, string>> slotToAgeAndReg; // (slotno ->(age,registration_no))
    map<int, set<string>> getMultipleRegistrationNumberFromAge;
    // If a slot is available for parking then slots[i]=0, else slot[i]=1 that is not available for parking

    map<int, pair<string, int>> slotDetails; // we will map car registration number and driver age with slot number

    /*
    Note:All the below methods are implemented in ParkingLot.cpp
    */
    void createParkingLot(int n); // create Parking Lot with n slots

    void park(string regNo, int age); // method to park a car at given slot with reg no and driver's age

    void getSlotNumbersFromAge(int age); // method to get slot numbers from the age

    void getSlotNumbersFromRegno(string regNo); // method to get slot numbers from where car with given regNumber is parked

    void getRegistrationNumberFromAge(int age); // method to get registration number of all cars parked by driver of given age;

    void leave(int slotNo); // method to vacate a slot
};