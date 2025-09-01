// IsSmaller.hpp
// declare the IsSmaller functor to be used in algorithms like count_if(), etc.
//
// author: amandeep singh gujral

#ifndef IsSmaller_hpp
#define IsSmaller_hpp

namespace ADSINGH
{
    namespace FUNCTION_OBJECT
    {
        template <typename T>
        class IsSmaller
        {
        private:
            T threshold;

        public:
            IsSmaller();
            IsSmaller(const T threshold_value);
            IsSmaller(const IsSmaller<T> &source);
            virtual ~IsSmaller();

            IsSmaller<T> &operator=(const IsSmaller<T> &source);
            bool operator()(const T &value) const;
        };
    }
}

#ifndef IsSmaller_cpp
#include "IsSmaller.cpp"
#endif

#endif