#ifndef DELIVERY_H_
#define DELIVERY_H_
#include <string>
using namespace std;

class Delivery
{
public:
    
    string get_time_stamp()
    {
        return this->timestamp;
    }

    string get_sender_name()
    {
        return this->sender_name;
    }

    void set_name(string a_Name)
    {
        this->sender_name = a_Name;
    }

    virtual void print_info();

protected:

    Delivery();

    Delivery(string a_Name, string a_Timestamp);

private:

    string sender_name;
    string timestamp;
};
#endif