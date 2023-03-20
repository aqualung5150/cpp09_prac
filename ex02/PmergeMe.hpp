#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

#include <iostream>

template<typename T>
void print(T arr)
{
    for (typename T::iterator it = arr.begin(); it != arr.end(); it++) 
        std::cout << *it << " ";
    std::cout << '\n';
}

class PmergeMe
{
private:
    std::vector<unsigned long> _v;
    std::deque<unsigned long> _d;
public:
    PmergeMe()
    {
    }

    PmergeMe(char** argv)
    {
        for(int i = 1; argv[i]; ++i)
        {
            _v.push_back(std::strtoul(argv[i], NULL, 10));
            _d.push_back(std::strtoul(argv[i], NULL, 10));
        }
    }

    std::vector<unsigned long>& getV()
    {
        return _v;
    }

    std::deque<unsigned long>& getD()
    {
        return _d;
    }

    /////// SORT ////////////
    template<typename Iterator>
    void insertionSort(Iterator& first, Iterator& last)
    {
        for (Iterator it = first + 1; it != last; ++it)
        {        
            // Searching the upper bound, i.e., first 
            // element greater than *it from beginning
            Iterator const insertion_point = 
                    std::upper_bound(first, it, *it);
            
            // Shifting the unsorted part
            std::rotate(insertion_point, it, it+1);
        }
    }

    //merge
    template<typename Iterator>
    void merge(Iterator& first, Iterator& middle, Iterator& last)
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

    template <typename Iterator>
    void mysort(Iterator& first, Iterator& last)
    {
        Iterator middle;

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