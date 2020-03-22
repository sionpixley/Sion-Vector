#include "sion-vector.h"


template<class type>
sion::vector<type>::vector()
{
    max_length = 10;
    length = 0;
    elements = (type*)(std::malloc(max_length * sizeof(type)));
}

template<class type>
sion::vector<type>::vector(const sion::vector<type>& obj)
{
    max_length = obj.max_length;
    length = obj.length;
    elements = (type*)(std::malloc(max_length * sizeof(type)));
    size_t i = 0;
    for(; i < length; i += 1)
    {
        elements[i] = obj.elements[i];
    }
}

template<class type>
sion::vector<type>::~vector()
{
    std::free(elements);
}

template<class type>
int sion::vector<type>::push_back(type item)
{
    try
    {
        if(length == max_length)
        {
            max_length *= 2;
            elements = (type*)(std::realloc(elements, max_length * sizeof(type)));
            elements[length] = item;
            length += 1;
            return 0;
        }
        else
        {
            elements[length] = item;
            length += 1;
            return 0;
        }
    }
    catch(...)
    {
        return 1;
    }
}

template<class type>
type sion::vector<type>::pop_back()
{
    if(length == 0)
    {
        type t;
        return t;
    }
    else
    {
        type t = elements[length - 1];
        length -= 1;
        return t;
    }
}

template<class type>
size_t sion::vector<type>::size()
{
    return length;
}

template<class type>
int sion::vector<type>::clear()
{
    try
    {
        std::free(elements);
        max_length = 10;
        length = 0;
        elements = (type*)(std::malloc(max_length * sizeof(type)));
        return 0;
    }
    catch(...)
    {
        return 1;
    }
}

template<class type>
void sion::vector<type>::sort()
{
    std::sort(begin(), end());
}

template<class type>
void sion::vector<type>::sort(std::string mode)
{
    std::transform(mode.begin(), mode.end(), mode.begin(), ::tolower);
        
    if(mode == "asc")
    {
        std::sort(begin(), end());
    }
    else if(mode == "desc")
    {
        std::sort(begin(), end(), std::greater<type>());
    }
    else
    {
        throw std::invalid_argument("Please use a valid argument: asc or desc");
    }
}

template<class type>
sion::vector<type> sion::vector<type>::sorted()
{
    vector<type> v = *this;
    std::sort(v.begin(), v.end());
    return v;
}

template<class type>
sion::vector<type> sion::vector<type>::sorted(std::string mode)
{
    std::transform(mode.begin(), mode.end(), mode.begin(), ::tolower);
    
    if(mode == "asc")
    {
        vector<type> v = *this;
        std::sort(v.begin(), v.end());
        return v;
    }
    else if(mode == "desc")
    {
        vector<type> v = *this;
        std::sort(v.begin(), v.end(), std::greater<type>());
        return v;
    }
    else
    {
        throw std::invalid_argument("Please use a valid argument: asc or desc");
    }
}

template<class type>
void sion::vector<type>::reverse()
{
    std::reverse(begin(), end());
}

template<class type>
sion::vector<type> sion::vector<type>::reversed()
{
    vector<type> v = *this;
    std::reverse(v.begin(), v.end());
    return v;
}

template<class type>
type* sion::vector<type>::begin()
{
    return elements;
}

template<class type>
type* sion::vector<type>::end()
{
    return elements + length;
}

/*
 template<class type>
 type* sion::vector<type>::rbegin()
 {
    return elements + length;
 }
 */

/*
 template<class type>
 type* sion::vector<type>::rend()
 {
    return elements;
 }
 */

template<class type>
sion::vector<type>& sion::vector<type>::operator =(const sion::vector<type>& obj)
{
    if(this != &obj)
    {
        std::free(elements);
        max_length = obj.max_length;
        length = obj.length;
        elements = (type*)(std::malloc(max_length * sizeof(type)));
        size_t i = 0;
        for(; i < length; i += 1)
        {
            elements[i] = obj.elements[i];
        }
    }
    return *this;
}

template<class type>
type& sion::vector<type>::operator [](size_t index)
{
    if((index >= length) || (index < 0))
    {
        throw std::out_of_range("Index out of bounds.");
    }
    else
    {
        return elements[index];
    }
}

