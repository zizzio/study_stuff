#include "stdafx.h"
#include "longnumbers.h"
using namespace std;

void read_input(string &s1, string&s2, int len)
{
    string s;
    for (int i = 0; i < len; ++i)
    {
        cin >> s;
        s1 += s;
        cin >> s;
        s2 += s;
    }
}
int main()
{
    string s1, s2;
    int len;
    cin >> len;
    read_input(s1, s2, len);
    l_num_t num1(s1);
    l_num_t num2(s2);
    //l_num_t num1("05500000");
    //l_num_t num2("977800000");
    //num1.print(7);
    //num2.print(8);

    (num1 + num2).print(len);
    //system("pause");
}

