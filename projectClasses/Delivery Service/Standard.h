#ifndef STANDARD_H_
#define STANDARD_H_

#include "Delivery.h"
using namespace std;

class Standard : public Delivery
{
public: 

    double get_weight()
    {
        return this->weight;
    }

    void set_weight(double a_Weight);

    virtual void print_info();

//protected:

    Standard();

    Standard(string a_Name, string a_Timestamp, double a_Weight);

private:

    double weight;
};
#endif