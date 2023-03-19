#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <sstream>
#include <string>
#include <iostream>

class RPN
{
private:
    std::stack<long> _s;
public:
    RPN();
    RPN(const RPN& r);
    ~RPN();
    RPN& operator=(const RPN& r);
    
    long calc(const std::string& input);
};

#endif