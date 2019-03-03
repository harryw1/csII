#ifndef OWL_H_
#define OWL_H_

#include "Standard.h"
using namespace std;

class Owl : public Standard
{
public:

    Owl();

    Owl(string a_Name, string a_TimeStamp, double a_Weight, string a_Id);

    string get_id()
    {
        return this->id;
    };

    void print_info();

private:
    string id;
};
#endif