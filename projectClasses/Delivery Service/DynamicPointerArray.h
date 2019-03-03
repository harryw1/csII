#ifndef DYNAMICPOINTERARRAY_H_
#define DYNAMICPOINTERARRAY_H_

template <typename T>
class DynamicPointerArray
{
public:
    DynamicPointerArray();

    // append an items to the array
    void append(T* a_Item);

    // prepend an item to the array
    void prepend(T* a_Item);

    // insert a_Item at a_Index
    void insert(T* a_Item, int a_Index);

    // remove an item from a_index
    void remove(int a_Index);

    // removes all elements from the array
    void remove_all();

    // Shifts all elements of the array a_Rotation positions
    void rotate(int a_Rotation);

    //reverses the order of the elements in the list
    void reverse();

    // randomly shuffles the elements of the array
    void random_shuffle();

    // prints all elemetns of the array
    void print_array();

    // returns the percent full of the array
    double report_percent();

    // returns size for testing out of bounds in remove()
    int get_size();


private:
    // The default size of an empty array
    static const unsigned int DEFAULT_SIZE = 10;

    // Holds the item count
    int m_NumItems;

    // Holds the current size of the array
    int m_Size;

    // The actual array that holds the items
    T** m_Array;

    // tests whether or not  we need to resize
    void resize();

    // grow and shrink array are essentially the same: could change into just one function later
    void grow_array();

    void shrink_array();

    // takes contents from a and puts them into b,
    // moves a pointer to b
    // frees up b
    void copy_array(T** newArray);
};
#endif