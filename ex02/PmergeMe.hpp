#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>

class PmergeMe
{
private:
    std::vector<unsigned long> _v;
public:
    PmergeMe()
    {
    }

    PmergeMe(char** argv)
    {
        for(int i = 1; argv[i]; ++i)
            _v.push_back(std::strtoul(argv[i], NULL, 10));
    }

    std::vector<unsigned long>& getV()
    {
        return _v;
    }

    /////// SORT ////////////
    template<typename Iterator>
    void insertionSort(Iterator& first, Iterator& last)
    {
        for (Iterator it = first + 1; it != last; it++)
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
    /*
    */

    // void sort(int first, int last)
    // {
    //     int middle;

    //     last = _v.size() - 1;
    //     if (last > 5)
    //     {
    //         middle = last / 2;
    //         sort(first, middle);
    //         sort(middle + 1, last);
    //         merge(first, middle, last);
    //     }
    //     else
    //         insertionSort(first, last);
    // }

};

#endif