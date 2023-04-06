#include <bits/stdc++.h>
#include "ParkingLot.h"
using namespace std;

void ParkingLot ::createParkingLot(int n)
{

    if (n <= 0)
    {
        cout << "Invalid total slot cases count";
    }
    else
    {
        this->MAX_SIZE = n;
        for (int i = 1; i <= n; i++)
        {
            available.insert(i);
        }
        cout << "Created parking of " << n << " slots" << endl;
    }
}

// [unavailabe,available] map also check mapping for below
// (age -> [slotnumber],regNo) <map,pair<vector<Int>,string>>
// (regno -> [slotnumber]) <map,vector<Int>>>
// (slotno ->(age,registration_no))
void ParkingLot ::park(string regNo, int age)
{

    int vacantSlot;
    if (this->MAX_SIZE == 0)
    {
        cout << "Sorry parking is not created or the size of lot is 0" << endl;
    }
    else if (isFull())
    {
        cout << "Sorry parking is full" << endl;
    }
    else
    {

        // find first vacant slot to entry to the entry point
        int nearestAvailable = *available.begin();
        available.erase(available.begin());
        unavailable.insert(nearestAvailable);

        regToSlot[regNo] = nearestAvailable;
        slotToAgeAndReg.insert({nearestAvailable, {age, regNo}});
        ageToSlotNo[age].insert(nearestAvailable);
        ageToregNo.insert({age, regNo});
        getMultipleRegistrationNumberFromAge[age].insert(regNo);
        this->currentCars++; // increase the no of car Parked
        slotDetails.insert(make_pair(nearestAvailable, make_pair(regNo, age)));
        cout << "Car details with registration number \" " << regNo << "\" has been parked at slot number " << nearestAvailable << endl;
    }
}

// (age -> [slotnumber],regNo) <map,pair<vector<Int>,string>>
void ParkingLot ::getSlotNumbersFromAge(int age)
{

    if (this->MAX_SIZE == 0)
    {
        cout << "Sorry parking is not created or the size of lot is 0" << endl;
        return;
    }

    if (ageToSlotNo[age].size() == 0)
    {
        cout << "No slot found" << endl;
        return;
    }

    auto it = ageToSlotNo[age];

    for (auto x = it.begin(); x != it.end(); x++)
    {
        cout << *x << " ";
    }

    cout << endl;
}

// (regno -> [slotnumber]) <map,vector<Int>>>

void ParkingLot ::getSlotNumbersFromRegno(string regNo)
{

    if (this->MAX_SIZE == 0)
    {
        cout << "Sorry parking is not created or the size of lot is 0" << endl;
        return;
    }

    if (regToSlot.find(regNo) == regToSlot.end())
    {
        cout << "No slot found" << endl;
        return;
    }

    cout << regToSlot[regNo] << endl;
}

// (age -> [slotnumber],regNo)
void ParkingLot ::getRegistrationNumberFromAge(int age)
{

    if (this->MAX_SIZE == 0)
    {
        cout << "Sorry parking is not created or the size of lot is 0" << endl;
        return;
    }

    if (ageToSlotNo[age].size() == 0)
    {
        cout << "" << endl;
        return;
    }

    auto it = getMultipleRegistrationNumberFromAge[age];

    for (auto x = it.begin(); x != it.end(); x++)
    {
        cout << *x << " ";
    }

    cout << endl;
}

// [available,unavailable]
void ParkingLot ::leave(int slotNo)
{

    if (this->MAX_SIZE == 0)
    {
        cout << "Sorry parking is not created or the size of lot is 0" << endl;
        return;
    }

    else if (isEmpty())
    {
        cout << "Parking lot is empty" << endl;
    }

    else if (slotDetails.find(slotNo) == slotDetails.end())
    {

        cout << "Slot is already empty with that vehicle , enter the correct value" << endl;
    }

    else
    {

        string regNo = slotDetails[slotNo].first;
        int age = slotDetails[slotNo].second;
        slotDetails.erase(slotNo); // erase car details from map
        this->currentCars--;
        unavailable.erase(slotNo);
        available.insert(slotNo);
        slotToAgeAndReg.erase(slotNo);
        ageToregNo.erase({age, regNo});
        regToSlot.erase(regNo);
        ageToSlotNo[age].erase(slotNo);
        getMultipleRegistrationNumberFromAge[age].erase(regNo);
        cout << "Slot number " << slotNo << " vacated, the car with vehicle registration \"" << regNo << "\"left the space , the driver of the car was age " << age << endl;
    }
}
