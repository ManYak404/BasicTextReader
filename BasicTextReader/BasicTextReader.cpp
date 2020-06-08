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
#include <vector>
using namespace std;

vector<string> number;
string line;

vector<string> splitString(string txt, string delimiter)
{
	vector<string> answer;
	string token;
	ifstream myfile(txt);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//string curChar;
			int curCharIndex = 0;
			int lengthOfString = 0;
			int startOfString = 0;
			//while (curCharIndex < line.size())
			//{
			//	curChar=line.at(curCharIndex);
			//	if (curChar == delimiter)
			//	{

			//	}
			//}
			// argument redefines curChar while also checking that line.find was able to fine a delimiter
			while ((curCharIndex = line.find(delimiter, curCharIndex)) !=string::npos)
			{
				lengthOfString = curCharIndex - startOfString;
				answer.push_back(line.substr(curCharIndex, 1));
				startOfString = curCharIndex + delimiter.size();
				curCharIndex = curCharIndex + 1;
			}
		}
		myfile.close();
		return answer;
	}

	else cout << "Unable to open file";
}

int split(string txt, int r1, int r2)
{
	int c2 = 0;
	int c1 = 0;
	if (r1 > r2)
	{
		c2 = r1;
		c1 = r2;
	}
	else
	{
		c1 = r1;
		c2 = r2;
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
			while (i < c1)
			{
				curChar=line.find(delimiter,curChar)+1;
				i++;
			}
			string token1 = line.substr(curChar, 1);
			while (i < c2)
			{
				curChar = line.find(delimiter,curChar)+1;
				i++;
			}
			string token2 = line.substr(curChar, 1);
			int row = stoi(token1) + stoi(token2);
			sum = sum + row;
			//cout << token1;
			//cout << token2;
			//cout << line << "/n";
			//int i = stoi(line);
			//sum = sum + i;
			//line << "/n";
		}
		myfile.close();
		return sum;
//		cout << sum;
	}

	else cout << "Unable to open file";
}

int main() 
{
	ofstream Output("Fourier.txt");
	int c1 = 0;
	int c2 = 0;
	string txt;
//	cout << "Type the name of a file"
	cout << "Type a number: ";
	cin >> c1;
	cout << "Type another number: ";
	cin >> c2;
	Output << split("example.txt", c1, c2);
	cout << split("example.txt", c1, c2);
	number=splitString("example.txt", "		");
	int i = 0;
	while(i<number.size())
	{
		cout << number.at(i)<<"/n";
		i++;
	}
	Output.close();
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
