// BasicTextReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

string line;

int split(string txt, int r1, int r2)
{
	if (r1 >= r2)
	{
		return -1;
	}
	string token1;
	string token2;
	int sum = 0;
	ifstream myfile(txt);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			int curChar = 0;
			string delimiter = "	";
			int i = 0;
			while (i < r1)
			{
				curChar=line.find(delimiter,curChar)+1;
				i++;
			}
			string token1 = line.substr(curChar, 1);
			while (i < r2)
			{
				curChar = line.find(delimiter,curChar)+1;
				i++;
			}
			string token2 = line.substr(curChar, 1);
			int row = stoi(token1) + stoi(token2);
			sum = sum + row;
			//			cout << token1;
			//			cout << token2;
			//			cout << line << "/n";
			//			int i = stoi(line);
			//			sum = sum + i;
			//			line << "/n";
		}
		myfile.close();
		return sum;
//		cout << sum;
	}

	else cout << "Unable to open file";
}

int main() 
{
	cout << split("example.txt", 0, 1);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
