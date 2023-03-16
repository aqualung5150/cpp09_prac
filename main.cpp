#include "BitcoinExchange.hpp"
#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> m;

    m.insert(std::pair<std::string, int>("2023-01-01", 1));
    m.insert(std::pair<std::string, int>("2023-02-01", 2));
    m.insert(std::pair<std::string, int>("2023-03-01", 3));

    //no data (return m.end())
    std::cout << greatest_less(m, "2022-01-01")->first << std::endl;
    
    std::cout << greatest_less(m, "2023-01-01")->first << std::endl;
    std::cout << greatest_less(m, "2023-01-05")->first << std::endl;
    std::cout << greatest_less(m, "2023-02-01")->first << std::endl;
    std::cout << greatest_less(m, "2023-02-28")->first << std::endl;
    std::cout << greatest_less(m, "2023-03-28")->first << std::endl;
    std::cout << greatest_less(m, "2030-03-28")->first << std::endl;

    return 0;
}