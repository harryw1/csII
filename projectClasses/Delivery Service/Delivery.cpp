#include "Delivery.h"
#include <iostream>

Delivery::Delivery()
{
    this->sender_name = "";
    this->timestamp = "";
}

Delivery::Delivery(string a_Name, string a_Timestamp)
{
    this->sender_name = a_Name;
    this->timestamp = a_Timestamp;
}

void Delivery::print_info()
{
    cout << "DELIVERY PRINT INFO" << endl;
    return;
}