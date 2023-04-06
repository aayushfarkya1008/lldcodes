#include <bits/stdc++.h>
#include "ParkingLot.h"

using namespace std;

int main()
{

    freopen("input.txt", "r", stdin);
    ParkingLot parkinglot;
    string command;

    while (cin >> command)
    {
        /* code */
        if (command == "Create_parking_lot")
        {
            int n;
            cin >> n;
            parkinglot.createParkingLot(n);
        }
        else if (command == "Park")
        {
            string regno, driverage;
            int age;
            cin >> regno >> driverage >> age;
            parkinglot.park(regno, age);
        }
        else if (command == "Slot_numbers_for_driver_of_age")
        {
            int age;
            cin >> age;
            parkinglot.getSlotNumbersFromAge(age);
        }
        else if (command == "Slot_number_for_car_with_number")
        {
            string regno;
            cin >> regno;
            parkinglot.getSlotNumbersFromRegno(regno);
        }

        else if (command == "Vehicle_registration_number_for_driver_of_age")
        {
            int age;
            cin >> age;
            parkinglot.getRegistrationNumberFromAge(age);
        }

        else if (command == "Leave")
        {
            int slotNo;
            cin >> slotNo;
            parkinglot.leave(slotNo);
        }
    }

    return 0;
}