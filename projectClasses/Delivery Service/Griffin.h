#ifndef GRIFFIN_H_
#define GRIFFIN_H_

#include "Standard.h"
using namespace std;

class Griffin : public Standard
{
public:
    
    Griffin();

    Griffin(string a_Name, string a_Timestamp, double a_Weight, string a_Id);

    string get_id()
    {
        return this->id;
    }

    void print_info();

private:
    string id;
};
#endif