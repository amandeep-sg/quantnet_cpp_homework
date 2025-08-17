// Shape.hpp
// program to declare the Shape base class constructor, copy constructor, destructor
// operator= overload, getter and virtual ToString member functions
// declare Draw, a pure virtual member function
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
            virtual ~Shape();           // destructor

            Shape &operator=(const Shape &source); // operator= overload

            const int ID() const;                 // return the id of the shape instance
            virtual std::string ToString() const; // ToString to return string output ex. "ID: 123"
            virtual void Draw() = 0;              // pure virtual member function
        };
    }
}

#endif