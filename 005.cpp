// 005.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<stack>
using namespace std;

void clearPar(string &str)
{
	int n = str.size();
	if (str[0] == '('&&str[n - 1] == ')')
	{
		stack<char> s;
		for (int i = 1; i < n - 1; i++)
		{
			if (str[i] == '(')
				s.push(str[i]);
			if (str[i] == ')')
			{
				if (s.empty())
					return;
				else if (s.top() != '(')
					return;
				else
					s.pop();
			}
		}
		if (s.empty())
		{
			str.erase(0, 1);
			str.erase(str.size() - 1, 1);
		}
		else
			return;
	}
}

int main()
{
	string str;
	cin >> str;
	clearPar(str);
	cout << str;
	system("pause");
    return 0;
}

