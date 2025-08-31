// Sum.hpp
// declare the sum function to return the sum of elements of serial (list & vector) and map containers
//
// author: amandeep singh gujral

#ifndef Sum_hpp
#define Sum_hpp

#include <iostream>
#include <map>

// sum declaration for serial containers
template <typename T>
double Sum(const T &container);

// sum declaration for sum of values of map
template <typename K, typename V>
double Sum(const std::map<K, V> &container);

// sum declaration to calculate sum between two iterators of serial containers
template <typename T>
double Sum(typename T::const_iterator start, typename T::const_iterator end);

// sum declaration to calculate sum between two iterators of map
template <typename K, typename V>
double Sum(typename std::map<K, V>::const_iterator start, typename std::map<K, V>::const_iterator end);

// sum defination for serial containers vector and list
template <typename T>
double Sum(const T &container)
{
    double result = 0;
    typename T::const_iterator i;
    for (i = container.begin(); i != container.end(); i++)
    {
        result += *i;
    }
    return result;
}

// sum defination for map
template <typename K, typename V>
double Sum(const std::map<K, V> &container)
{
    double result = 0;
    typename std::map<K, V>::const_iterator i;
    for (i = container.begin(); i != container.end(); i++)
    {
        result += i->second;
    }

    return result;
}

// sum defination to calculate sum between two iterators of serial containers
template <typename T>
double Sum(typename T::const_iterator start, typename T::const_iterator end)
{
    double result = 0;
    typename T::const_iterator i;
    for (i = start; i != end; i++)
    {
        result += *i;
    }

    return result;
}

// sum defination to calculate sum between two iterators of map
template <typename K, typename V>
double Sum(typename std::map<K, V>::const_iterator start, typename std::map<K, V>::const_iterator end)
{
    double result = 0;
    typename std::map<K, V>::const_iterator i;
    for (i = start; i != end; i++)
    {
        result += i->second;
    }
    return result;
}

#endif