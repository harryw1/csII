#include "Griffin.h"
#include <iostream>

Griffin::Griffin()
    : Standard()
{
    this->id = "";
}

Griffin::Griffin(string a_Name, string a_Timestamp, double a_Weight, string a_Id)
    : Standard(a_Name, a_Timestamp, a_Weight)
{
    this->id = a_Id;
}

void Griffin::print_info()
{
    cout << "Sender name: " << get_sender_name() << endl;
    cout << "Timestamp: " << get_time_stamp() << endl;
    cout << "Weight (kg): " << get_weight() << endl;
    cout << "ID: " << this->id << endl;
}