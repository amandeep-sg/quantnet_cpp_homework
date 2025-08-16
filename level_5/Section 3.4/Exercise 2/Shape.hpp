// Shape.hpp
// program to declare the Shape base class constructor, copy constructor, destructor
// operator= overload, getter and ToString member functions
//
// author: amandeep singh gujral

#ifndef Shape_hpp
#define Shape_hpp

#include <string>

namespace ADSINGH
{
    namespace CAD
    {
        class Shape
        {
        private:
            int id;

        public:
            Shape();                    // default constructor
            Shape(const Shape &source); // copy constructor
            ~Shape();           // destructor

            Shape &operator=(const Shape &source); // operator= overload

            const int ID() const;         // return the id of the shape instance
            std::string ToString() const; // ToString to return string output ex. "ID: 123"
        };
    }
}

#endif