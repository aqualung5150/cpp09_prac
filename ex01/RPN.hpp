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
    long calc(const std::string& input)
    {
        std::stringstream in;
        std::string line;
        long a;
        long b;

        in.str(input);
        line = "";
        while(std::getline(in, line, ' '))
        {
            // if(invalid)
            
            if(isdigit(line[0]))
                _s.push(std::strtol(line.c_str(), NULL, 10));
            else
            {
                a = _s.top();
                _s.pop();
                b = _s.top();
                _s.pop();

                if(line[0] == '+')
                    _s.push(b + a);
                else if(line[0] == '-')
                    _s.push(b - a);
                else if(line[0] == '*')
                    _s.push(b * a);
                else if(line[0] == '/')
                    _s.push(b / a);
            }
        }
        if(line != "")
            return _s.top();
        return 0;
    }
};

#endif