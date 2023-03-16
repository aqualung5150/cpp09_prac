#include "BitcoinExchange.hpp"
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

int main()
{
    std::map<std::string, std::string> m;
    std::string line;
    std::string date;
    std::string exchange_rate;
    std::stringstream inputString;
    // int n;
    std::ifstream inputFile;

    inputFile.open("data.csv");
    line = "";
    getline(inputFile, line);
    while (getline(inputFile, line))
    {
        inputString.str(line);

        getline(inputString, date, ',');
        getline(inputString, exchange_rate);

        m.insert(std::pair<std::string, std::string>(date, exchange_rate));

        inputString.clear();
    }

    // while(!fs.eof())
    // {
    //     getline(fs, date, ',');
    //     getline(fs, exchange_rate, ',');
    //     // ssInt.str(exchange_rate);
    //     // ssInt >> n;
        
    //     std::cout << date << "|" << exchange_rate << std::endl;
    //     // m.insert(std::pair<std::string, std::string>(date, exchange_rate));
    // }

    std::map<std::string, std::string>::iterator it;

    it = m.begin();
    while(it != m.end())
    {
        std::cout << it->first << " | " << it->second << std::endl;
        ++it;
    }

    // m.insert(std::pair<std::string, int>("2023-01-01", 1));
    // m.insert(std::pair<std::string, int>("2023-02-01", 2));
    // m.insert(std::pair<std::string, int>("2023-03-01", 3));

    //no data (return m.end())
    // std::cout << greatest_less(m, "date")->first << std::endl;
    
    // std::cout << greatest_less(m, "2023-01-01")->first << std::endl;
    // std::cout << greatest_less(m, "2023-01-05")->first << std::endl;
    // std::cout << greatest_less(m, "2023-02-01")->first << std::endl;

    return 0;
}