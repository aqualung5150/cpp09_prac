#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void print(T& arr)
{
    for (typename T::iterator it = arr.begin(); it != arr.end(); it++) 
        std::cout << *it << " ";
    std::cout << '\n';
}

template <typename LongArray>
class PmergeMe
{
private:
    LongArray _array;
public:
    PmergeMe()
    {
    }

    PmergeMe(const std::vector<std::string>& input)
    {
        long n;

        for (std::vector<std::string>::const_iterator it = input.begin(); it != input.end(); ++it)
        {
            n = std::strtol((*it).c_str(), NULL, 10);
            if (n <= 0)
            {
                std::cout << "Error" << std::endl;
                exit(1);
            }
            _array.push_back(n);
        }
    }

    PmergeMe(const PmergeMe& p)
    {
        _array = p._array;
    }

    ~PmergeMe()
    {
    }

    PmergeMe& operator=(const PmergeMe& p)
    {
        if (this == &p)
            return *this;
        
        _array = p._array;

        return *this;
    }

    // getter
    LongArray& getArray()
    {
        return _array;
    }

    /////// SORT ////////////
    void insertionSort(typename LongArray::iterator& first, typename LongArray::iterator& last)
    {
        for (typename LongArray::iterator it = first + 1; it != last; ++it)
        {        
            // Searching the upper bound, i.e., first 
            // element greater than *it from beginning
            typename LongArray::iterator const insertion_point = 
                    std::upper_bound(first, it, *it);
            
            // Shifting the unsorted part
            std::rotate(insertion_point, it, it+1);
        }
    }

    void merge(typename LongArray::iterator& first, typename LongArray::iterator& middle, typename LongArray::iterator& last)
    {
        int RSIZE = std::distance(middle, last);
        int LIDX = 0;
        int RIDX = 0;

        while (RIDX < RSIZE)
        {
            if (middle[RIDX] > first[LIDX])
            {
                LIDX++;
            }
            else
            {
                std::rotate(first + LIDX, middle + RIDX, middle + RIDX + 1);
                RIDX++;
            }
        }
    }

    void mysort(typename LongArray::iterator& first, typename LongArray::iterator& last)
    {
        typename LongArray::iterator middle;

        if (std::distance(first, last) > 5)
        {
            middle = first + (std::distance(first, last) / 2);
            mysort(first, middle);
            mysort(middle, last);
            merge(first, middle, last);
        }
        else
            insertionSort(first, last);
    }
};

#endif