#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string& csvFile)
{
    std::ifstream inputFile;
    std::string line;
    std::string date;
    std::string exchange_rate;
    std::stringstream inputString;
    double d;

    inputFile.open(csvFile); // if(err)
    line = "";
    getline(inputFile, line); // Skip to store first line
    while (getline(inputFile, line))
    {
        inputString.str(line);

        getline(inputString, date, ',');
        getline(inputString, exchange_rate, '\n');
        d = std::strtod(exchange_rate.c_str(), NULL);

        _database.insert(std::pair<std::string, double>(date, d));

        inputString.clear();
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& b)
{
    // Use overloaded assignment operator of std::map (deep copy)
    _database = b._database;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& b)
{
    if(this == &b)
        return *this;
    
    // Use overloaded assignment operator of std::map (deep copy)
    _database = b._database;

    return *this;
}

// void exchange(std::string& inputFile)
// {

// }
