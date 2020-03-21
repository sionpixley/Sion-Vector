#ifndef SION_VECTOR_H
#define SION_VECTOR_H

#include <string>
#include <algorithm>


using std::cout;
using std::cin;
using std::endl;

namespace sion
{
    template<class type>
    class vector
    {
    private:
        type* elements;
        size_t max_length;
        size_t length;
        
    public:
        using iterator = type*;
        
        vector()
        {
            max_length = 10;
            length = 0;
            elements = (type*)(std::malloc(max_length * sizeof(type)));
        }
        
        vector(vector<type>& obj)
        {
            length = obj.size();
            max_length = length * 2;
            elements = (type*)(std::malloc(max_length * sizeof(type)));
            size_t i = 0;
            for(; i < obj.size(); i += 1)
            {
                elements[i] = obj[i];
            }
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
                length -= 1;
                return t;
            }
        }
        
        int clear()
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
        
        void sort()
        {
            std::sort(begin(), end());
        }
        
        void sort(std::string mode)
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
        
        vector<type> sorted()
        {
            vector<type> v = *this;
            std::sort(v.begin(), v.end());
            return v;
        }
        
        vector<type> sorted(std::string mode)
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
        
        type* begin()
        {
            return elements;
        }
        
        type* end()
        {
            return elements + length;
        }
        
        type* rbegin()
        {
            /*if(length == 0)
            {
                return elements;
            }
            else
            {
                return elements + length;
            }*/
            return elements + length;
        }
        
        type* rend()
        {
            /*if(length == 0)
            {
                return elements;
            }
            else
            {
                return elements - 1;
            }*/
            return elements;
        }
        
        vector<type> operator =(vector<type>& rhs)
        {
            vector<type> v(&rhs);
            return v;
        }
        
        type& operator [](size_t index)
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
    };
}

#endif // SION_VECTOR_H

