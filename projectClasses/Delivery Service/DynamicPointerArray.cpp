#include <iostream>
#include <string>
#include <stdlib.h>
#include "DynamicPointerArray.h"

template<typename T>
DynamicPointerArray<T>::DynamicPointerArray()
{
    m_NumItems = 0;
    m_Size = DEFAULT_SIZE;
    m_Array = new T*[m_Size];
}

template<typename T>
int DynamicPointerArray<T>::get_size()
{
    return this -> m_Size;
}

template<typename T>
void DynamicPointerArray<T>::append(T* a_Item)
{
    // Resize the array if necessary
    resize();

    insert(a_Item, m_NumItems);
}

template<typename T>
void DynamicPointerArray<T>::prepend(T* a_Item)
{
    // Resize the array if necessary
    resize();

    insert(a_Item, 0);
}

template<typename T>
void DynamicPointerArray<T>::insert(T* a_Item, int a_Index)
{
    if (a_Index > m_NumItems || a_Index < 0)
    {
        std::cout << "Invalid call to DynamicPointerArray<T>::insert(...), index out of bounds" << std::endl;
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
void DynamicPointerArray<T>::remove(int a_Index)
{
    if (a_Index > (m_NumItems - 1) || a_Index < 0)
    {
        std::cout << "Invalid call to DynamicPointerArray<T>::remove(...), index out of bounds" << std::endl;
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
void DynamicPointerArray<T>::remove_all()
{
    delete[] m_Array;
    
    m_NumItems = 0;
    m_Size = DEFAULT_SIZE;
    m_Array = new T*[m_Size];
}

template<typename T>
void DynamicPointerArray<T>::print_array()
{
    if (m_NumItems == 0)
    {
        std::cout << "Empty array :(" << std::endl;
        return;
    }

    for (int i = 0; i < m_NumItems; i++)
    {
        std::cout << "Item " << i << ":" << std::endl;
        m_Array[i]->print_info();
        std::cout << std::endl;
    }
}

template<typename T>
void DynamicPointerArray<T>::resize()
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
void DynamicPointerArray<T>::grow_array()
{
    unsigned int newSize;
    newSize = ((m_Size * 100) / 64);
    m_Size = newSize;
    T** newArray = new T*[m_Size];
    copy_array(newArray);
    std::cout << "new size: " << newSize << std::endl;
    std::cout << "m_size: " << m_Size << std::endl;
}

template<typename T>
void DynamicPointerArray<T>::shrink_array()
{
    unsigned int newSize;
    newSize = ((m_Size * 100) / 64);
    m_Size = newSize;
    T** newArray = new T*[m_Size];
    copy_array(newArray);
    std::cout << "new size: " << newSize << std::endl;
    std::cout << "m_size: " << m_Size << std::endl;
}

template<typename T>
void DynamicPointerArray<T>::copy_array(T** newArray)
{
    for(int i = 0; i < m_NumItems; i++)
    {
        newArray[i] = m_Array[i];
    }
    delete[] m_Array;

    m_Array = newArray;
}

template<typename T>
double DynamicPointerArray<T>::report_percent()
{
    double percent_full;
    percent_full = m_NumItems * 100 / m_Size;
    return percent_full;
}