#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>

class RPN
{
private:
    std::stack<long> _stack;
public:
    RPN();
    RPN(const RPN& r);
    ~RPN();
    RPN& operator=(const RPN& r);
    
    long calc(const std::string& input);
};

#endif