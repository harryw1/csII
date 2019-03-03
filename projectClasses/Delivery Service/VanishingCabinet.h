#ifndef VANISHINGCABINET_H_
#define VANISHINGCABINET_H_

#include "Delivery.h"
using namespace std;

class VanishingCabinet : public Delivery
{
public:

    VanishingCabinet();

    VanishingCabinet(string a_Name, string a_Timestamp, double a_Weight, string a_Id);

    inline double get_weight()
    {
        return this->weight;
    }

    inline void set_weight(double a_Weight)
    {
        this->weight = a_Weight;
    }

    inline string get_id()
    {
        return this->id;
    }

    void print_info();

private:

    double weight;
    string id;
};
#endif