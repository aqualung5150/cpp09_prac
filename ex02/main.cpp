// #include "PmergeMe.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

void insertionSort(std::vector<int> &vec)
{
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {        
        // Searching the upper bound, i.e., first 
        // element greater than *it from beginning
        std::vector<int>::iterator const insertion_point = 
                std::upper_bound(vec.begin(), it, *it);
          
        // Shifting the unsorted part
        std::rotate(insertion_point, it, it+1);        
    }
}
  
// Function to print the array
void print(std::vector<int> vec)
{
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) 
        std::cout << *it << " ";
    std::cout << '\n';
}
  
// Driver code
int main()
{
    std::vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(6);


    insertionSort(arr);    
    print(arr);
}

// int main(int argc, char** argv)
// {
//     if (argc < 2) //err
//         return 1;

//     PmergeMe a(argv);

//     return 0;
// }