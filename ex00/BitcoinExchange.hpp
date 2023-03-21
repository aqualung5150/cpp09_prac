#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

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
};

#endif