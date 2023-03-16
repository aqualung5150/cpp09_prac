#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

// template<typename T>
// typename T::const_iterator greatest_less(T const &m, typename T::key_type const &k) {
//     typename T::const_iterator it = m.upper_bound(k);
//     if(it != m.begin()) {
//         return --it;
//     }
//     return m.end();
// }

// template<typename T>
// typename T::iterator greatest_less(T &m, typename T::key_type const &k) {
//     typename T::iterator it = m.upper_bound(k);
//     if(it != m.begin()) {
//         return --it;
//     }
//     return m.end();
// }

// void setDB(std::map<std::string, double> &database, const std::string &csv)
// {
//     std::ifstream inputFile;
//     std::string line;
//     std::string date;
//     std::string exchange_rate;
//     std::stringstream inputString;
//     double i;

//     inputFile.open(csv); // if(err)
//     line = "";
//     getline(inputFile, line); // Skip to store first line
//     while (getline(inputFile, line))
//     {
//         inputString.str(line);

//         getline(inputString, date, ',');
//         getline(inputString, exchange_rate, '\n');
//         i = std::strtod(exchange_rate.c_str(), NULL);

//         database.insert(std::pair<std::string, double>(date, i));

//         inputString.clear();
//     }
// }

////////////////

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

    // void exchange(std::string& inputFile);


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