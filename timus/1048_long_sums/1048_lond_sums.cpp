// democrathy.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "longnumbers.h"
using namespace std;

void read_input(string &s1, string&s2)
{
    string s;
    int len;
    cin >> len;
    for (int i = 0; i < len; ++i)
    {
        cin >> s;
        s1 += s;
        cin >> s;
        s2 += s;
    }
}
int _tmain(int argc, _TCHAR* argv[])
{
    l_num_t num1("0997856785995");
    l_num_t num2("9887567856778");
    num1.print(30);
    num2.print(30);
    (num1 + num2).print(30);
    system("pause");
}

