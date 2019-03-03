#include "Standard.h"
#include <iostream>

Standard::Standard() 
    : Delivery()
{
    this->weight = 0.0;
}

Standard::Standard(string a_Name, string a_Timestamp, double a_Weight)
    : Delivery(a_Name, a_Timestamp)
{
    this->weight = a_Weight;
}

void Standard::print_info()
{
    cout << "STANDARD PRINT INFO" << endl;
    return;
}
