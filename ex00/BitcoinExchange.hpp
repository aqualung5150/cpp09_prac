#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> _database;
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& csvFile);
    BitcoinExchange(const BitcoinExchange& b);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& b);

    int exchange(std::string& line);
    
    // Functions for test
    void testClear()
    {
        _database.clear();
    }

    void testPrint()
    {
        std::map<std::string, double>::iterator it;

        it = _database.begin();
        while(it != _database.end())
        {
            std::cout << it->first << " | " << std::setprecision(std::numeric_limits<double>::digits10) << it->second << std::endl;
            ++it;
        }
    }
};

#endif