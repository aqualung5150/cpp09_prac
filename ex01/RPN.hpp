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
    bool invalid_input(std::string input)
    {
        std::stringstream in;
        std::string line;
        int flag;

        // First two integer
        if(!isdigit(input[0]) || !isdigit(input[2]))
            return true;

        in.str(input);
        line = "";

        std::getline(in, line, ' '); // Skip first integer

        flag = 0;
        while(std::getline(in, line, ' '))
        {
            if(line.length() != 1)
                return true;
            else if(!isdigit(line[0]) && line[0] != '+' && line[0] != '-' && line[0] != '*' && line[0] != '/')
                return true;

            if(isdigit(line[0]))
                ++flag;
            else
                --flag;
            // To prevent three occurrences in a row
            if(flag > 2 || flag < 0)
                return true;
        }
        if(flag != 0)
            return true;
        return false;
    }

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
            if(invalid_input(input))
            {
                std::cout << "Error" << std::endl;
                exit(1);
            }

            if(isdigit(line[0]))
                _s.push(std::strtol(line.c_str(), NULL, 10));
            else
            {        
                b = _s.top();
                _s.pop();
                a = _s.top();
                _s.pop();

                if(line[0] == '+')
                    _s.push(a + b);
                else if(line[0] == '-')
                    _s.push(a - b);
                else if(line[0] == '*')
                    _s.push(a * b);
                else if(line[0] == '/')
                    _s.push(a / b);
            }
        }
        if(line != "")
            return _s.top();
        return 0;
    }
};

#endif