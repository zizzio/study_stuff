// 1002_phone_numbers.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "vocabulary.h"

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
	return 0;
}

