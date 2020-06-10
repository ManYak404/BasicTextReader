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
//#include "BasicTextReader.h"
using namespace std;

vector<string>* splitString(string txt, string delimiter)
{
	string line = txt;
	vector<string>* answer=new vector<string>;
	int curCharIndex = 0;
	int lengthOfString = 0;
	int startOfString = 0;
	// argument redefines curCharIndex while also checking that line.find was able to find a delimiter
	while ((curCharIndex = line.find(delimiter, curCharIndex)) !=string::npos)
	{
		lengthOfString = curCharIndex - startOfString;
		answer->push_back(line.substr(startOfString, lengthOfString));
		startOfString = curCharIndex + delimiter.size(); // nona
		curCharIndex = curCharIndex + delimiter.size();
	}
	lengthOfString = line.size() - startOfString;
	answer->push_back(line.substr(startOfString, lengthOfString));
	return answer;
}

int split(string txt, int r1, int r2)
{
	string line;
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
		cout << sum;
	}

	else cout << "Unable to open file";
	return 0;
}

int run()
{
	ifstream myfile("example.txt");
	vector<string>* number;
	string line;
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
	cout << "\n";

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			number = splitString(line, "	");
			int i = 0;
			while (i < number->size())
			{
				cout << number->at(i) << "\n";
				i++;
			}
			if (number) 
			{
				delete number;
				number = NULL;
			}
		}
	}
	else cout << "Unable to open file";

	myfile.close();
	Output.close();
	return 0;
}

bool TestSplitString()
{
	vector<string>correctAnswer = { "a", "b" };
	vector<string>* currentAnswer = NULL;
	currentAnswer = splitString("a b", " ");
	//static_assert(currentAnswer==correctAnswer);

	if (currentAnswer) {
		delete currentAnswer;
		currentAnswer = NULL;
	}
	return true;
}

int main() 
{
	run();
//	TestSplitString();
}
