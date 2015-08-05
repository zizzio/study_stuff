
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <stdio.h>


#define max(a,b)    (((a) > (b)) ? (a) : (b))

using namespace std;

struct l_num_t
{
    struct params_t
    {
        params_t(): base_size(5)
                  , max_size(1000000000)
                  , max_base(pow(10., base_size))
        {
        }
        size_t base_size;
        size_t max_size;
        int    max_base;
    };
    typedef std::vector<int> l_num_v;

    explicit l_num_t(string s);

public:
    void l_num_t::print(int len);
    friend ostream& operator << (std::ostream & os, l_num_t& lnum);
    friend l_num_t operator + (l_num_t& num1, l_num_t& num2);

public:
    static const params_t params;
    l_num_v number;
    int length;
};


l_num_t::params_t const l_num_t::params = l_num_t::params_t();

l_num_t::l_num_t(string s)
{
    length = 0;
    int head = 0;

    for (int i = (int)s.length(); i > 0; i -= params.base_size)
        if (i < params.base_size)
        {
            int nm = atoi(s.substr(0, i).c_str());
            if (nm != 0)
                number.push_back(nm);
        }
        else
        {
            int nm = atoi(s.substr(i - params.base_size, params.base_size).c_str());
            number.push_back(nm);
        }
    length = (number.size() - 1) * l_num_t::params.base_size;

    head = number.back();
    while ((head /= 10) > 0)
        ++length;
    ++length;
}

void l_num_t::print(int len)
{
//     char buffer[5];
//     char buffer2[5];
// 
//     sprintf(buffer, "%s%d%s", "%0", params.base_size, "d");
// 
//     int empty_blocks = len / params.base_size - number.size();
// 
//     int first_block_len = len % params.base_size;
//     
//     if (len <= length)
//         first_block_len = 0;
//     else if (len % params.base_size == 0)
//         first_block_len = params.base_size;
//     
//     for (int i = 0; i < empty_blocks; ++i)
//     {
//         printf(buffer, 0);
//     }
//     sprintf(buffer2, "%s%d%s", "%0", first_block_len, "d");   
// 
//     if (len > length && len % params.base_size != 0)
//     {
//         printf(buffer2, 0);
//         sprintf(buffer2, "%s%d%s", "%0", params.base_size, "d");
//     }
// 
//     printf(buffer2, number.empty() ? 0 : number.back());
//     
//     for (int i = (int)number.size() - 2; i >= 0; --i)
//         printf(buffer, number[i]);

    char *format = "%d";
    char zero_format[20];
    sprintf(zero_format, "%s%d%s", "%0", len - length, "d");

    if ( len - length > 0)
        printf(zero_format, 0);

    printf(format, number.empty() ? 0 : number.back());
    
    for (int i = (int)number.size() - 2; i >= 0; --i)
        printf(format, number[i]);
    printf("\n");
}

ostream& operator << (std::ostream & os, l_num_t& lnum)
{
    bool fl = lnum.number.empty();
    os << (fl ? 0 : lnum.number.back()); 
    for (int i=(int)lnum.number.size() - 2; i >= 0; --i)
        os << setfill('0') << setw(l_num_t::params.base_size) << lnum.number[i];
    return os;
}

l_num_t operator + (l_num_t& num1, l_num_t& num2)
{
    l_num_t num = num1;
    num.length = 0;
    int head = 0;

    int carry = 0;
    for (size_t i = 0; i < max(num.number.size(), num2.number.size()) || carry; ++i) {
        if (i == num.number.size())
            num.number.push_back(0);

        num.number[i] += (carry + ((i < num2.number.size()) ? num2.number[i] : 0));

        carry = num.number[i] >= l_num_t::params.max_base;
        if (carry) 
            num.number[i] -= l_num_t::params.max_base;
    }
    num.length = (num.number.size() - 1) * l_num_t::params.base_size;

    head = num.number.back();
    while ((head /= 10) > 0)
        ++num.length;
    ++num.length;
    return num;
}
