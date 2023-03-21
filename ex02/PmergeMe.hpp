#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>

template<typename T>
void print(T arr)
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

    PmergeMe(char** argv)
    {
        for(int i = 1; argv[i]; ++i)
            _array.push_back(std::strtol(argv[i], NULL, 10));
    }

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

    //merge
    void merge(typename LongArray::iterator& first, typename LongArray::iterator& middle, typename LongArray::iterator& last)
    {
        // int n1 = std::distance(first, middle) + 1;
        int n2 = std::distance(middle, last);
        int LIDX = 0;
        int RIDX = 0;

        for (;RIDX < n2;)
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

    void print()
    {
        for (typename LongArray::iterator it = _array.begin(); it != _array.end(); it++) 
            std::cout << *it << " ";
        std::cout << '\n';
    }

};

#endif