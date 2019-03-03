#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <set>
#include "Delivery.h"
#include "Standard.h"
#include "Owl.h"
#include "Griffin.h"
#include "VanishingCabinet.h"
#include "DynamicPointerArray.cpp"
using namespace std;

#define SIZE 5

string generate_timestamp();
string generate_id(int type);

int main()
{
    /*    DynamicPointerArray<Delivery> dArrray;
    dArrray.append(new Owl("Owl", "10:00", 2.1, "xd"));
    dArrray.print_array();*/

    // delclares a double pointer array (my class) that will contain delivery pointers
    DynamicPointerArray<Delivery> objectArray;

    int menuSelection;

    while (true)
    {
        cout << "~~~~~~~~~~~~~~~~" << endl;
        cout << "Delivery Service" << endl;
        cout << "----------------" << endl;
        cout << setw(8) << "1. " << setw(2) << "Create a new delivery" << endl;
        cout << setw(8) << "2. " << setw(2) << "Remove a delivery" << endl;
        cout << setw(8) << "3. " << setw(2) << "Save deliveries to a file" << endl;
        cout << setw(8) << "4. " << setw(2) << "Load deliveries from a file" << endl;
        cout << setw(8) << "5. " << setw(2) << "Print all deliveries" << endl;
        cout << setw(8) << "6. " << setw(2) << "Print deliveries by type" << endl;
        cout << setw(8) << "7. " << setw(2) << "Report" << endl;
        cout << setw(8) << "8. " << setw(2) << "Exit" << endl;
        cout << "~~~~~~~~~~~~~~~~" << endl;
        cout << "Please make a selection: ";
        cin >> menuSelection;
        if (menuSelection < 1 || menuSelection > 8)
        {
            cout << "Out of bounds. Please make a valid selection (1-10)." << endl;
        }
        else
        {
            if (menuSelection == 1)
            {
                // timestamp is the first thing generated when creating a new delivery
                string shippingTime;
                shippingTime = generate_timestamp();
                string shippingName;
                cout << endl;
                cout << "Please enter a sender name: ";
                cin.ignore();
                getline(cin, shippingName);
                char shippingChoice;
                do
                {
                    cout << endl;
                    cout << "Standard shipping? (Y/N): ";
                    cin >> shippingChoice;
                } while (shippingChoice != 'y' && shippingChoice != 'Y' && shippingChoice != 'n' && shippingChoice != 'N');
                if (shippingChoice == 'y' || shippingChoice == 'Y')
                {
                    // creating a standard type delivery, asks for weight to determine owl/griffin and then calls generate id
                    double shippingWeight;
                    do
                    {
                        cout << endl;
                        cout << "Enter package weight (kg): ";
                        cin >> shippingWeight;
                    } while (shippingWeight <= 0);
                    if (shippingWeight <= 1.58)
                    {
                        string shippingId;
                        shippingId = generate_id(1);
                        objectArray.append(new Owl(shippingName, shippingTime, shippingWeight, shippingId));
                    }
                    else
                    {
                        string shippingId;
                        shippingId = generate_id(2);
                        objectArray.append(new Griffin(shippingName, shippingTime, shippingWeight, shippingId));
                    }
                }
                else
                {
                    // nonstandard shipping
                    double shippingWeight;
                    do
                    {
                        cout << endl;
                        cout << "Enter package weight (kg): ";
                        cin >> shippingWeight;
                    } while (shippingWeight <= 0);
                    string shippingId;
                    shippingId = generate_id(3);
                    objectArray.append(new VanishingCabinet(shippingName, shippingTime, shippingWeight, shippingId));
                }
            }
            if (menuSelection == 2)
            {
                int removeIndex;
                do
                {
                    cout << endl;
                    cout << "Please enter an index to remove: ";
                    cin >> removeIndex;
                } while(removeIndex < 0 || removeIndex > (objectArray.get_size()));
                objectArray.remove(removeIndex);
            }
            if (menuSelection == 5)
            {
                cout << endl;
                objectArray.print_array();
            }
            if (menuSelection == 7)
            {
                cout << endl;
                cout << "The array is: " << objectArray.report_percent() << "% full." << endl;
                cout << endl;
            }
            if (menuSelection == 8)
            {
                cout << endl;
                cout << "Exiting..." << endl;
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}

string generate_timestamp()
{
    //time since 1970 in seconds with time_t data type
    time_t rawtime;
    //pointer to a time structure with identifier timeinfo
    struct tm *timeinfo;
    //call of memberfunction time with the reference of rawtime
    time(&rawtime);
    //setting time info equal to the result of using member function localtime on rawtime
    timeinfo = localtime(&rawtime);
    //converts timeinfo into a string and returns it
    return asctime(timeinfo);
}

string generate_id(int type)
{
    if (type == 1)
    {
        int id_num;
        string temp_id = "o";
        for (int i = 0; i < 3; i++)
        {
            id_num = rand() % 10;
            char c;
            c = '0' + id_num;
            temp_id.append(1, c);
        }
        return temp_id;
    }
    if (type == 2)
    {
        int id_num;
        string temp_id = "g";
        for (int i = 0; i < 7; i++)
        {
            id_num = rand() % 10;
            char c;
            c = '0' + id_num;
            temp_id.append(1, c);
        }
        return temp_id;
    }
    if (type == 3)
    {
        int id_num;
        string temp_id = "";
        for (int i = 0; i < 8; i++)
        {
            id_num = rand() % 10;
            char c;
            c = '0' + id_num;
            temp_id.append(1, c);
        }
        temp_id.append(1, '-');
        for (int i = 0; i < 8; i++)
        {
            id_num = rand() % 10;
            char c;
            c = '0' + id_num;
            temp_id.append(1, c);
        }
        return temp_id;
    }
}