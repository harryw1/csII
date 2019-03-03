/* add all your includes here */
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

#define SIZE 3

//displays the menu
void print_menu(int &user_choice, int &selection_return, string *&name_of_sender, string *&shipping_type, double *&weight, string *&id, int &number_of_deliveries, int &array_size);

//gets the menu selection from the user
size_t get_selection(int &user_choice, int &selection_return, string *&name_of_sender, string *&shipping_type, double *&weight, string *&id, int &number_of_deliveries, int &array_size);

//adds a new delivery
void schedule_new_delivery(string *&name_of_sender, string *&shipping_type, double *&weight, string *&id, int &number_of_deliveries, int &array_size);

//generates a random 5 digit number
void generate_id(string *&id, int &number_of_deliveries);

//displays all deliveries
void display_all(string *&name_of_sender, string *&shipping_type, double *&weight, string *&id, int number_of_deliveries);

//displays eliveries of chossen type
void display_type(string *&name_of_sender, string *&shipping_type, double *&weight, string *&id, int number_of_deliveries);

//fill name array
void assign_name(string *&name_of_sender, int &number_of_deliveries);

//fill shipping array
void assign_shipping(string *&shipping_type, double *&weight, int &number_of_deliveries);

//fill weight array
void assign_weight(double *&weight, int &number_of_deliveries);

//displays the percent fullness of the arrays
void report_size(int array_size, int number_of_deliveries);

//grows the arrays to the necessary size and moves the data
void grow_array(int &array_size, int number_of_deliveries, string *&name_of_sender, string *&shipping_type, double *&weight, string *&id);

//shrink array if necessary when removing an item from the delivery list
void shrink_array(int &array_size, int number_of_deliveries, string *&name_of_sender, string *&shipping_type, double *&weight, string *&id);

//asks the user which delivery they want to remove based on its id
//checks if we need to resize the array when we remove this delivery by doing the same math shrink_array but w/ (num_deliv-1)
//shrinks the array if necessary
//moves the last item in the delivery list to that location (or, if the one to remove is the last delivery) and decrement the num_deliv count
void remove_delivery(int &array_size, int number_of_deliveries, string *&name_of_sender, string *&shipping_type, double *&weight, string *&id);

int main()
{

    //seed random for use in id function
    srand(time(0));
    //dynamic arrays with size array_size
    int array_size = SIZE;
    string *name_of_sender = new string[array_size];
    string *shipping_type = new string[array_size];
    double *weight = new double[array_size];
    string *id = new string[array_size];
    //variables for use in functions
    int number_of_deliveries = 0;
    int user_choice = 0;
    int selection_return = 0;
    //print menu called for first time starts program
    do{

        while(user_choice !=6){
            print_menu(user_choice, selection_return, name_of_sender, shipping_type, weight, id, number_of_deliveries, array_size);
            if(selection_return == 1)
            {
              schedule_new_delivery(name_of_sender, shipping_type, weight, id, number_of_deliveries, array_size);
              number_of_deliveries++;
            }
            if(selection_return == 2)
            {
              remove_delivery(array_size, number_of_deliveries, name_of_sender, shipping_type, weight, id);
              number_of_deliveries--;
            }
            if(selection_return == 3)
            {
              display_all(name_of_sender, shipping_type, weight, id, number_of_deliveries);
            }
            if(selection_return == 4)
            {
              display_type(name_of_sender, shipping_type, weight, id, number_of_deliveries);
            }
            if(selection_return == 5)
            {
              report_size(array_size, number_of_deliveries);
            }
            if(selection_return == 6)
            {
                cout << endl;
                cout << "Thank you for choosing HOGWARTS." << endl;
                cout << endl;
            }
            //cout << "NUMBER OF DELIVERIES: " << number_of_deliveries << endl;
        }
    }while(user_choice != 1 && user_choice != 2 && user_choice != 3 && user_choice != 4 && user_choice !=5 && user_choice !=6);

}

void print_menu(int &user_choice, int &selection_return, string *&name_of_sender, string *&shipping_type, double *&weight, string *&id, int &number_of_deliveries, int &array_size)
{

  do{
    	cout << endl;
        cout << setfill(' ');
      cout << "Please select from the following choices: " << endl;
      cout << setw(12) << right << "(1)" << " Schedule a new delivery" << endl;
      cout << setw(12) << right << "(2)" << " Remove a delivery" << endl;
      cout << setw(12) << right << "(3)" << " Display all scheduled deliveries" << endl;
      cout << setw(12) << right << "(4)" << " Display deliveries by type" << endl;
      cout << setw(12) << right << "(5)" << " Report" << endl;
      cout << setw(12) << right << "(6)" << " Exit" << endl;
      cout << "~~~~~~~~~~~~~~" << endl;
        cout << "Selection: ";
      cin >> user_choice;
      if(user_choice != 1 && user_choice != 2 && user_choice != 3 && user_choice != 4 && user_choice != 5 && user_choice != 6)
      {
      cout << endl;
      cout << "Please enter a valid selection." << endl;
      cout << endl;
      }
    }while(user_choice != 1 && user_choice != 2 && user_choice != 3 && user_choice != 4 && user_choice != 5 && user_choice != 6);
    selection_return = get_selection(user_choice, selection_return, name_of_sender, shipping_type, weight, id, number_of_deliveries, array_size);

}

size_t get_selection(int &user_choice, int &selection_return, string *&name_of_sender, string *&shipping_type, double *&weight, string *&id, int &number_of_deliveries, int &array_size)
{

  if(user_choice == 1)
  {
  return 1;
  }
  if(user_choice == 2)
  {
  return 2;
  }
  if(user_choice == 3)
  {
  return 3;
  }
  if(user_choice == 4)
  {
  return 4;
  }
  if(user_choice == 5)
  {
  return 5;
  }
  if(user_choice == 6)
  {
  return 6;
  }

}

void schedule_new_delivery(string *&name_of_sender, string *&shipping_type, double *&weight, string *&id, int &number_of_deliveries, int &array_size)
{
    double percent_full;
    percent_full = (100 * number_of_deliveries / array_size);
    if(percent_full >= 62)
    {
        grow_array(array_size, number_of_deliveries, name_of_sender, shipping_type, weight, id);
    }
    assign_name(name_of_sender, number_of_deliveries);

    assign_weight(weight, number_of_deliveries);

    assign_shipping(shipping_type, weight, number_of_deliveries);

    generate_id(id, number_of_deliveries);

}

void assign_name(string *&name_of_sender, int &number_of_deliveries)
{

    //asks the user for a name for the delivery
    string delivery_name;
    cout << endl;
    cout << "Please enter the name of the package receipient: ";
    cin.ignore();
    getline(cin, delivery_name);
    //places that name into the name array at position num of deliv
    name_of_sender[number_of_deliveries] = delivery_name;

}

void assign_shipping(string *&shipping_type, double *&weight, int &number_of_deliveries)
{

    //asks the user if they want standard or non standard shipping
    char shipping_choice;
    do{
        cout << endl;
        cout << "Standard or Non-standard shipping? (Y/N): ";
        cin >> shipping_choice;
        if(shipping_choice != 'y' && shipping_choice != 'Y' && shipping_choice != 'n' && shipping_choice != 'N')
        {
            cout << endl;
            cout << "Please enter a valid selection (Y/N)" << endl;
            cout << endl;
        }
    }while(shipping_choice != 'y' && shipping_choice != 'Y' && shipping_choice != 'n' && shipping_choice != 'N');

    //based on weight and choice, places specific type of shipping into array
    if(((shipping_choice == 'y' || shipping_choice == 'Y') && weight[number_of_deliveries] < 1.58))
    {
        shipping_type[number_of_deliveries] = "Standard (Owl)";
    }
    if(((shipping_choice == 'y' || shipping_choice == 'Y') && weight[number_of_deliveries] >= 1.58))
    {
        shipping_type[number_of_deliveries] = "Standard (Griffin)";
    }
    if(shipping_choice == 'n' || shipping_choice == 'N')
    {
        shipping_type[number_of_deliveries] = "Non-standard (Vanishing Cabinet)";
    }

}

void assign_weight(double *&weight, int &number_of_deliveries)
{

    double package_weight;
    cout << endl;
    cout << "Please enter the weight of the package in kilograms: ";
    cin >> package_weight;

    weight[number_of_deliveries] = package_weight;

}

void generate_id(string *&id, int &number_of_deliveries)
{

    int id_num;
    for(int i = 0; i < 5; i++)
    {
        id_num = rand() % 10;
        char c;
        c = '0' + id_num;
        //cout << "INSIDE GENERATE ID" << s << endl;
        id[number_of_deliveries].append(1,c);
    }

}

void display_all(string *&name_of_sender, string *&shipping_type, double *&weight, string *&id, int number_of_deliveries)
{

    for(int i = 0; i < number_of_deliveries; i++)
    {
        cout << "[" << i << "]:" << "[ID:" << id[i] << "] - " << name_of_sender[i] << " - " << shipping_type[i] << " - " << weight[i] << "kg" << endl;
    }

}

void display_type(string *&name_of_sender, string *&shipping_type, double *&weight, string *&id, int number_of_deliveries)
{
    //asks the user which delivery to display
    char type_display;
    string search_type;
    cout << endl;
    do{
        cout << "Display which deliveries (1) Owl, (2) Griffin, (3) Vanishing Cabinet: ";
        cin >> type_display;
        if(type_display != '1' && type_display != '2' && type_display != '3')
        {
            cout << endl;
            cout << "Please enter a valid choice (1), (2), (3)" << endl;
            cout << endl;
        }
    }while(type_display != '1' && type_display != '2' && type_display != '3');

    //sets the search string
    if(type_display == '1')
    {
        search_type = "Standard (Owl)";
    }
    if(type_display == '2')
    {
        search_type = "Standard (Griffin)";
    }
    if(type_display == '3')
    {
        search_type = "Non-standard (Vanishing Cabinet)";
    }

    //compares the values in the shipping type array to the search string
    //prints the arrays if the shipping type array and the search string match
    for(int i = 0; i < number_of_deliveries; i++)
    {
        if(shipping_type[i] == search_type)
        cout << "[" << i << "]:" << "[ID:" << id[i] << "] - " << name_of_sender[i] << " - " << shipping_type[i] << " - " << weight[i] << "kg" << endl;
    }

}

void report_size(int array_size, int number_of_deliveries)
{

    double percent_full;
    percent_full = (100 * number_of_deliveries / array_size);

    cout << endl;
    cout << "The arrays are " << percent_full << "% full." << endl;
    cout << endl;

}

void grow_array(int &array_size, int number_of_deliveries, string *&name_of_sender, string *&shipping_type, double *&weight, string *&id)
{

    double test_percentage;
    test_percentage = (100 * number_of_deliveries / array_size);
    if(number_of_deliveries == 2)
    {
        array_size = 4;
        string *n_t_array = new string[array_size];
        string *s_t_array = new string[array_size];
        string *i_t_array = new string[array_size];
        double *w_t_array = new double[array_size];

        for(int i = 0; i < number_of_deliveries; i++)
        {
            n_t_array[i] = name_of_sender[i];
            s_t_array[i] = shipping_type[i];
            i_t_array[i] = id[i];
            w_t_array[i] = weight[i];
        }

        delete [] name_of_sender;
        delete [] shipping_type;
        delete [] id;
        delete [] weight;

        name_of_sender = n_t_array;
        shipping_type = s_t_array;
        id = i_t_array;
        weight = w_t_array;

        n_t_array = NULL;
        s_t_array = NULL;
        i_t_array = NULL;
        w_t_array = NULL;

    }
    else if(test_percentage >= 62)
    {
        array_size = ((array_size * 100) / 62 );
        string *n_t_array = new string[array_size];
        string *s_t_array = new string[array_size];
        string *i_t_array = new string[array_size];
        double *w_t_array = new double[array_size];

        for(int i = 0; i < number_of_deliveries; i++)
        {
            n_t_array[i] = name_of_sender[i];
            s_t_array[i] = shipping_type[i];
            i_t_array[i] = id[i];
            w_t_array[i] = weight[i];
        }

        delete [] name_of_sender;
        delete [] shipping_type;
        delete [] id;
        delete [] weight;

        name_of_sender = n_t_array;
        shipping_type = s_t_array;
        id = i_t_array;
        weight = w_t_array;

        n_t_array = NULL;
        s_t_array = NULL;
        i_t_array = NULL;
        w_t_array = NULL;

    }

}

void remove_delivery(int &array_size, int number_of_deliveries, string *&name_of_sender, string *&shipping_type, double *&weight, string *&id)
{

  double test_percentage;
  test_percentage = ((100 * (array_size)) / array_size);
  if(test_percentage <= 64)
    shrink_array(array_size, number_of_deliveries, name_of_sender, shipping_type, weight, id);

  //prints all the deliveries to make it easier to read
  cout << endl;
  display_all(name_of_sender, shipping_type, weight, id, number_of_deliveries);
  cout << endl;

  string delivery_to_remove;
  bool exists = false;
  int delivery_location = 0;
  //asks the user which delivery they want to remove bassed on id
  do{

    cout << "Which delivery do you want to remove? (EX: If you want to remove delivery [12345], type 12345): ";
    cin.ignore();
    getline(cin, delivery_to_remove);
    for(int i = 0; i < number_of_deliveries; i++)
    {

      if(id[i] == delivery_to_remove)
      {
        exists = true;
        //cout << "INSIDE DELIVERY EXISTS FUNCTION: DELIVERY EXISTS." << endl;
        delivery_location = i;
        //cout << "INSIDE DELIVERY EXISTS FUNCTION: DELIVERY LOCATION: " << delivery_location << endl;
        break;
      }

    }

    if(exists == false)
    {

      cout << endl;
      cout << "Please enter a valid ID." << endl;
      cout << endl;

    }

  }while(exists == false);

  if(id[number_of_deliveries - 1] == delivery_to_remove)
  {
    cout << "Delivery with ID[" << id[number_of_deliveries - 1] << "] has been removed." << endl;
    /*number_of_deliveries--;
    array_size--;*/
  }
  else
  {
    cout << "Delivery with ID[" << id[delivery_location] << "] has been removed." << endl;
    id[delivery_location] = id[number_of_deliveries - 1];
    name_of_sender[delivery_location] = name_of_sender[number_of_deliveries - 1];
    shipping_type[delivery_location] = shipping_type[number_of_deliveries - 1];
    weight[delivery_location] = weight[number_of_deliveries - 1];
    /*number_of_deliveries--;
    array_size--;*/
  }

}

void shrink_array(int &array_size, int number_of_deliveries, string *&name_of_sender, string *&shipping_type, double *&weight, string *&id)
{

  array_size = (((array_size - 1) * 100) / 62 );
  string *n_t_array = new string[array_size];
  string *s_t_array = new string[array_size];
  string *i_t_array = new string[array_size];
  double *w_t_array = new double[array_size];

  for(int i = 0; i < number_of_deliveries; i++)
  {
    n_t_array[i] = name_of_sender[i];
    s_t_array[i] = shipping_type[i];
    i_t_array[i] = id[i];
    w_t_array[i] = weight[i];
  }

  delete [] name_of_sender;
  delete [] shipping_type;
  delete [] id;
  delete [] weight;

  name_of_sender = n_t_array;
  shipping_type = s_t_array;
  id = i_t_array;
  weight = w_t_array;

  n_t_array = NULL;
  s_t_array = NULL;
  i_t_array = NULL;
  w_t_array = NULL;

}
