#include "VanishingCabinet.h"

#include <iostream>

VanishingCabinet::VanishingCabinet()
    : Delivery()
{
    this->weight = 0.0;
    this->id = "";
}

VanishingCabinet::VanishingCabinet(string a_Name, string a_Timestamp, double a_Weight, string a_Id)
    : Delivery(a_Name, a_Timestamp)
{
    this->weight = a_Weight;
    this->id = a_Id;
}

void VanishingCabinet::print_info()
{
    cout << "Sender name: " << get_sender_name() << endl;
    cout << "Timestamp: " << get_time_stamp() << endl;
    cout << "Weight (kg): " << get_weight() << endl;
    cout << "ID: " << this->id << endl;
}