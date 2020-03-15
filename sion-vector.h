#ifndef SION_VECTOR_H
#define SION_VECTOR_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

namespace sion
{
    template<typename type>
    class vector
    {
    private:
        type* elements;
        size_t max_length;
        size_t length;
        
    public:
        vector()
        {
            max_length = 10;
            length = 0;
            elements = (type*)(std::malloc(max_length * sizeof(type)));
        }
        
        ~vector()
        {
            std::free(elements);
        }
        
        int push_back(type item)
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
        
        size_t size()
        {
            return length;
        }
        
        type pop_back()
        {
            if(length == 0)
            {
                type t;
                return t;
            }
            else
            {
                type t = elements[length - 1];
                elements[length - 1] = NULL;
                length -= 1;
                return t;
            }
        }
        
        int clear()
        {
            try
            {
                if(length == 0)
                {
                    return 0;
                }
                else
                {
                    size_t i = 0;
                    for(; i < length; i += 1)
                    {
                        elements[i] = NULL;
                    }
                    max_length = 10;
                    length = 0;
                    return 0;
                }
            }
            catch(...)
            {
                return 1;
            }
        }
        
        type operator=(type rhs[])
        {
            sion::vector<type> temp;
            size_t rhs_size = sizeof(*rhs) / sizeof(type);
            size_t i = 0;
            for(; i < rhs_size; i += 1)
            {
                temp.push_back(rhs[i]);
            }
            return temp;
        }
        
        type& operator[](size_t index)
        {
            if(index >= length)
            {
                cout << "Error. Out of bounds." << endl;
                exit(-1);
            }
            else
            {
                return elements[index];
            }
        }
    };
}

#endif // SION_VECTOR_H
