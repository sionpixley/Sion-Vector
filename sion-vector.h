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
        size_t max_size;
        size_t size;
        
    public:
        vector()
        {
            max_size = 10;
            size = 0;
            elements = (type*)(std::malloc(max_size * sizeof(type)));
        }
        
        ~vector()
        {
            std::free(elements);
        }
        
        int push_back(type item)
        {
            try
            {
                if(size == max_size)
                {
                    max_size *= 2;
                    elements = (type*)(std::realloc(elements, max_size * sizeof(type)));
                    elements[size] = item;
                    size += 1;
                    return 0;
                }
                else
                {
                    elements[size] = item;
                    size += 1;
                    return 0;
                }
            }
            catch(...)
            {
                return 1;
            }
        }
        
        size_t length()
        {
            return size;
        }
        
        type pop_back()
        {
            if(size == 0)
            {
                type t;
                return t;
            }
            else
            {
                type t = elements[size - 1];
                elements[size - 1] = NULL;
                size -= 1;
                return t;
            }
        }
        
        type& operator[](size_t index)
        {
            if(index >= size)
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
