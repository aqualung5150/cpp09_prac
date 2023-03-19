#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>

class PmergeMe
{
private:
    std::vector<unsigned long> _v;
public:
    PmergeMe();
    PmergeMe(const char** argv)
    {
        for(int i = 1; argv[i]; ++i)
            push_back(std::strtoul(argv[i].c_str, NULL, 10));
    }
    /////// SORT ////////////

    // insertionSort
    /*
    while(_v[i] < compare)
    {
        --it;
    }
    if (it != compare)
    {
        _v.insert(it, _v[i])
        _v.erase(i)
    }
    */

    // void insertionSort(int first, int last)
    // {
    //     for(int i = first; i < last - 1; ++i)
    //     {
    //         int j = i + 1;
    //         std::vector<unsigned long>::iterator it = _v.begin() + i;
    //         while(j > p && _v[j] < it)
    //     }
    // }

    //merge
    /*
    */

    void sort(int first, int last)
    {
        int middle;

        last = _v.size() - 1;
        if (last > 5)
        {
            middle = last / 2;
            sort(first, middle);
            sort(middle + 1, last);
            merge(first, middle, last);
        }
        else
            insertionSort(first, last);
    }

}

#endif