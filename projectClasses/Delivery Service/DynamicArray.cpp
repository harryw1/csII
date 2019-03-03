#include <iostream>
#include <string>
#include <stdlib.h>
#include "DynamicArray.h"

template<typename T>
DynamicArray<T>::DynamicArray()
{
    m_NumItems = 0;
    m_Size = DEFAULT_SIZE;
    m_Array = new T[m_Size];
}

template<typename T>
void DynamicArray<T>::append(T a_Item)
{
    // Resize the array if necessary
    resize();

    insert(a_Item, m_NumItems);
}

template<typename T>
void DynamicArray<T>::prepend(T a_Item)
{
    // Resize the array if necessary
    resize();

    insert(a_Item, 0);
}

template<typename T>
void DynamicArray<T>::insert(T a_Item, int a_Index)
{
    if (a_Index > m_NumItems || a_Index < 0)
    {
        std::cout << "Invalid call to DynamicArray<T>::insert(...), index out of bounds" << std::endl;
        return;
    }

    resize();

    for (int i = (m_NumItems - 1); i >= a_Index; i--)
    {
        m_Array[i + 1] = m_Array[i];
    }

    m_Array[a_Index] = a_Item;
    m_NumItems++;
}

template<typename T>
void DynamicArray<T>::remove(int a_Index)
{
    if (a_Index > (m_NumItems - 1) || a_Index < 0)
    {
        std::cout << "Invalid call to DynamicArray<T>::remove(...), index out of bounds" << std::endl;
        return;
    }

    resize();

    for (int i = a_Index; i < (m_NumItems - 1); i++)
    {
        m_Array[i] = m_Array[i + 1];
    }

    m_NumItems--;
}

template<typename T>
void DynamicArray<T>::remove_all()
{
    delete[] m_Array;
    
    m_NumItems = 0;
    m_Size = DEFAULT_SIZE;
    m_Array = new T[m_Size];
}

template<typename T>
void DynamicArray<T>::print_array()
{
    if (m_NumItems == 0)
    {
        std::cout << "Empty array :(" << std::endl;
        return;
    }

    for (int i = 0; i < m_NumItems; i++)
    {
        std::cout << "Item [" << i << "]:  " << m_Array[i] << std::endl;
    }
}

template<typename T>
void DynamicArray<T>::rotate(int a_Rotation)
{
    // 0 would mean no rotation
    if (a_Rotation == 0)
    {
        return;
    }

    // Shifting to the left is the same as shifting to the right n - r times
    if (a_Rotation < 0)
    {
        a_Rotation = m_NumItems + a_Rotation - 1;
    }

    a_Rotation = a_Rotation % m_NumItems;

    T *newArray = new T[m_Size];
    int numLoops = 0;

    // std::cout << "m_Size = " << m_Size << " m_NumItems = " << m_NumItems << " a_Rotation = " << a_Rotation << std::endl;

    for (int i = 0; i < (m_NumItems - a_Rotation); i++)
    {
        //std::cout << "[i + a_Rotation] = " << (i + a_Rotation) << " i = " << i << std::endl;
        
        newArray[i + a_Rotation] = m_Array[i];
        numLoops = i + 1;
    }

    int j = 0;
    for (int i = numLoops; j < (m_NumItems - numLoops); i++, j++)
    {
        //std::cout << i << " " << j << std::endl;
        newArray[j] = m_Array[i];

    }

    delete[] m_Array;
    m_Array = newArray;
}

template<typename T>
void DynamicArray<T>::reverse()
{
    T *newArray = new T[m_Size];
    for (int i  = 0; i < m_NumItems; i++)
    {
        newArray[i] = m_Array[(m_NumItems - 1) - i];
    }

    delete[] m_Array;
    m_Array = newArray;
}

template<typename T>
void DynamicArray<T>::random_shuffle()
{
    T* arrayCopy = new T[m_Size];
    int arrayCopyNumItems = m_NumItems;
    for(int i = 0; i < m_NumItems; i++)
    {
        arrayCopy[i] = m_Array[i];
    }

    int randomIndex;
    bool breakCondition;

    for(int i = 0; i < m_NumItems; i++)
    {
        //std::cout << "array copy num items: " << arrayCopyNumItems << std::endl;
        randomIndex = (rand() % arrayCopyNumItems);
        //std::cout << "random index: " << randomIndex << std::endl;
        m_Array[i] = arrayCopy[randomIndex];

        //deletes the random index we just pulled from the copy array
        for (int i = randomIndex; i < (arrayCopyNumItems - 1); i++)
        {
            arrayCopy[i] = arrayCopy[i + 1];
        }
        arrayCopyNumItems--;
    }

    delete[] arrayCopy;
}

template<typename T>
void DynamicArray<T>::resize()
{
    if ((m_NumItems / m_Size) > 64)
    {
        grow_array();
    }

    if ((m_Size > DEFAULT_SIZE) && (m_NumItems / m_Size < 50))
    {
        shrink_array();
    }

    // Else do nothing
}

template<typename T>
void DynamicArray<T>::grow_array()
{
    unsigned int newSize;
    newSize = ((m_Size * 100) / 64);
    m_Size = newSize;
    T* newArray = new T[m_Size];
    copy_array(newArray);
    std::cout << "new size: " << newSize << std::endl;
    std::cout << "m_size: " << m_Size << std::endl;
}

template<typename T>
void DynamicArray<T>::shrink_array()
{
    unsigned int newSize;
    newSize = ((m_Size * 100) / 64);
    m_Size = newSize;
    T* newArray = new T[m_Size];
    copy_array(newArray);
    std::cout << "new size: " << newSize << std::endl;
    std::cout << "m_size: " << m_Size << std::endl;
}

template<typename T>
void DynamicArray<T>::copy_array(T*newArray)
{
    for(int i = 0; i < m_NumItems; i++)
    {
        newArray[i] = m_Array[i];
    }
    delete[] m_Array;

    m_Array = newArray;
}

template<typename T>
double DynamicArray<T>::report_percent()
{
    double percent_full;
    percent_full = ((m_NumItems/m_Size) * 100);
    return percent_full;
}