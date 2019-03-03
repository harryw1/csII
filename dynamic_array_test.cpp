#include <iostream>
using namespace std;

#define SIZE 3

int main()
{

    int number_of_deliveries = 3;
    int array_size = 0;

    string *name_of_sender = new string[SIZE];
    string *shipping_type = new string[SIZE];
    string *id = new string[SIZE];
    double *weight = new double[SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        name_of_sender[i] = 1;
        shipping_type[i] = 1;
        id[i] = 1;
        weight[i] = 1;
    }

    for(int i = 0; i < SIZE; i++)
    {
        cout << name_of_sender[i] << endl;
        cout << shipping_type[i] << endl;
        cout << id[i] << endl;
        cout << weight[i] << endl;
    }

    //calculate new size of array
    int temp_array_size = 0;
    temp_array_size = (array_size * 100 / 62);
    array_size = temp_array_size;
    //create new dynamic arrays of necessary size
    string *name_temp_array = new string[array_size];
    string *shipping_temp_array = new string[array_size];
    string *id_temp_array = new string[array_size];
    double *weight_temp_array = new double[array_size];
    //fill new arrays with info from old arrays
    for(int i = 0; i < number_of_deliveries; i++)
    {
        name_temp_array[i] = name_of_sender[i];
        shipping_temp_array[i] = shipping_type[i];
        id_temp_array[i] = id[i];
        weight_temp_array[i] = weight[i];
    }
    //print temp arrays
    for(int i = 0; i < number_of_deliveries; i++)
    {
        cout << name_temp_array[i] << endl;
        cout << shipping_temp_array[i] << endl;
        cout << id_temp_array[i] << endl;
        cout << weight_temp_array[i] << endl;
    }
    //free memory of old arrays
    delete [] name_of_sender;
    delete [] shipping_type;
    delete [] id;
    delete [] weight;
    //change pointers of new old arrays
    name_of_sender = name_temp_array;
    shipping_type = shipping_temp_array;
    id = id_temp_array;
    weight = weight_temp_array;
    //null temp array pointers
    name_temp_array = NULL;
    shipping_temp_array = NULL;
    id_temp_array = NULL;
    weight_temp_array = NULL;

}