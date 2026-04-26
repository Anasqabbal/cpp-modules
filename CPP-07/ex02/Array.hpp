#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>
#include <stdlib.h>
#include <sstream>

template <typename T> class Array
{
    T *arr;
    unsigned int ASize;
    public:
    Array(void);
    ~Array(void);
    Array(const Array &obj);

    Array(unsigned int n);
    T           &operator[](int ind);
    const T     &operator[](int ind) const;
    Array<T>    &operator=(const Array<T> &obj) const;
    unsigned int size() const;
};

/*
    - construction with no parameter                                                                    DONE
    - construction with n as unsigned int parameter                                                     DONE
    - construction with copy and assignement operator                                                   ON WORK 50%...
    -  use the operator [] to allocate the memory                                                       DONE.
    - accessing elements with subscript operator []                                                     DONE.
    - accessing element out of bounds throwing exeption (in my case just I exit, you MUST correct it)   DONE
    - member function size that retuns the number of elements inside the array.                         DONE

*/

//construction with no parameter 
template<typename T>
 Array<T>::Array(void)
{
    arr = new T [1];
    arr[0] = T();
    ASize = 1;
}

template <typename T>
Array<T>::Array(const Array<T> &obj)
{
    if (obj.size())
    {
        ASize = obj.size();
        arr = new T [obj.size()];
        for (unsigned int i = 0; i < obj.size(); i++)
            arr[i] = obj.arr[i];
    }
    else
        arr = 0;
}

template<typename T> 
Array<T>::~Array(void)
{
    delete [] arr;
}

template<typename T>
unsigned int Array<T>::size(void) const
{
    return ASize;
}

// construction with unsigned int
template<typename T>
Array<T>::Array(unsigned int n)
{
    if (n)
    {
        arr = new T [n];
        for (unsigned int i = 0; i < n ; i++)
            arr[i] = T();
        ASize = n;
    }
    else
        arr = 0;
}



template<typename T>
T& Array<T>::operator[](int ind)
{
    if (ind < 0 || ind >= (int)ASize || ASize == 0)
        throw std::out_of_range("index is out of bounds");
    return arr[ind];
}

template<typename T>
const T& Array<T>::operator[](int ind) const
{
    if (ind < 0 || ind >= (int)ASize || ASize == 0)
        throw std::out_of_range("index is out of bounds");
    return arr[ind];
}



template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &obj) const
{
    delete [] arr;

    std::cout << "delete the old one" << std::endl;
    arr = new T [obj.size()];
    for (unsigned int i = 0; i < obj.size(); i++)
        arr[i] = obj.arr[i];
    ASize = obj.size();
    return arr;
}

#endif