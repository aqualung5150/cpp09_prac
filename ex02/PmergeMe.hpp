#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void printElements(T& arr)
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
        int rightArraySize = std::distance(middle, last);
        int leftArrayIndex = 0;
        int rightArrayIndex = 0;

        while (rightArrayIndex < rightArraySize)
        {
            if (middle[rightArrayIndex] > first[leftArrayIndex])
                leftArrayIndex++;
            else
            {
                std::rotate(first + leftArrayIndex, middle + rightArrayIndex, middle + rightArrayIndex + 1);
                rightArrayIndex++;
            }
        }
    }

    void mergeInsertionSort(typename LongArray::iterator& first, typename LongArray::iterator& last)
    {
        typename LongArray::iterator middle;

        if (std::distance(first, last) > 5)
        {
            middle = first + (std::distance(first, last) / 2);
            mergeInsertionSort(first, middle);
            mergeInsertionSort(middle, last);
            merge(first, middle, last);
        }
        else
            insertionSort(first, last);
    }
};

#endif