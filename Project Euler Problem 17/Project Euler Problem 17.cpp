// Project Euler Problem 17.cpp : Defines the entry point for the console application.
//
//If the numbers 1 to 5 are written out in words: one, two, three, four, five, then 
//  there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
//  If all the numbers from 1 to 1000 (one thousand) inclusive were
//  written out in words, how many letters would be used?

//  NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) 
//  contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of 
//  "and" when writing out numbers is in compliance with British usage.


#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

void pause()
{
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}

string convertToNumeral(string n)
{
	bool enableHyphens = false;

	string numeral;

	// convert each number to word-format

	////  thousands place
	if (n.length() > 3)
	{
		if (n[n.length()-4] == '1'){numeral += "one";}
		if (n[n.length()-4] == '2'){numeral += "two";} 
		if (n[n.length()-4] == '3'){numeral += "three";}
		if (n[n.length()-4] == '4'){numeral += "four";}
		if (n[n.length()-4] == '5'){numeral += "five";}
		if (n[n.length()-4] == '6'){numeral += "six";}
		if (n[n.length()-4] == '7'){numeral += "seven";}
		if (n[n.length()-4] == '8'){numeral += "eight";}
		if (n[n.length()-4] == '9'){numeral += "nine";}

		if (enableHyphens == true){numeral += "-";}

		numeral += "thousand";
	}	

	//  hundred's place place
	if (n.length() > 2)
	{
		if (n[n.length()-3] == '1'){numeral += "one";  if (enableHyphens == true){numeral += "-";}}
		if (n[n.length()-3] == '2'){numeral += "two";  if (enableHyphens == true){numeral += "-";}} 
		if (n[n.length()-3] == '3'){numeral += "three";if (enableHyphens == true){numeral += "-";}}
		if (n[n.length()-3] == '4'){numeral += "four"; if (enableHyphens == true){numeral += "-";}}
		if (n[n.length()-3] == '5'){numeral += "five"; if (enableHyphens == true){numeral += "-";}}
		if (n[n.length()-3] == '6'){numeral += "six";  if (enableHyphens == true){numeral += "-";}}
		if (n[n.length()-3] == '7'){numeral += "seven";if (enableHyphens == true){numeral += "-";}}
		if (n[n.length()-3] == '8'){numeral += "eight";if (enableHyphens == true){numeral += "-";}}
		if (n[n.length()-3] == '9'){numeral += "nine"; if (enableHyphens == true){numeral += "-";}}

		if (n[n.length()-3] != '0')
		{
		numeral += "hundred";
		}

		if ( (n[n.length()-2] != '0') || n[n.length()-1] != '0')
		{
			if (enableHyphens == true){numeral += "-";}
			numeral += "and";
			if (enableHyphens == true){numeral += "-";}
		}
	}

	//  tens place
	if (n.length() > 1)
	{

		// 10 - 19
		if (n[n.length()-2] == '1')
		{
			if (n[n.length()-1] == '0'){numeral += "ten";}
			if (n[n.length()-1] == '1'){numeral += "eleven";}
			if (n[n.length()-1] == '2'){numeral += "twelve";} 
			if (n[n.length()-1] == '3'){numeral += "thirteen";}
			if (n[n.length()-1] == '4'){numeral += "fourteen";}
			if (n[n.length()-1] == '5'){numeral += "fifteen";}
			if (n[n.length()-1] == '6'){numeral += "sixteen";}
			if (n[n.length()-1] == '7'){numeral += "seventeen";}
			if (n[n.length()-1] == '8'){numeral += "eighteen";}
			if (n[n.length()-1] == '9'){numeral += "nineteen";}
		}

		if (n[n.length()-2] == '2'){numeral += "twenty"; if ((enableHyphens == true) && (n[n.length()-1] != '0')){numeral += "-";}} 
		if (n[n.length()-2] == '3'){numeral += "thirty"; if ((enableHyphens == true) && (n[n.length()-1] != '0')){numeral += "-";}}
		if (n[n.length()-2] == '4'){numeral += "forty";  if ((enableHyphens == true) && (n[n.length()-1] != '0')){numeral += "-";}}
		if (n[n.length()-2] == '5'){numeral += "fifty";  if ((enableHyphens == true) && (n[n.length()-1] != '0')){numeral += "-";}}
		if (n[n.length()-2] == '6'){numeral += "sixty";  if ((enableHyphens == true) && (n[n.length()-1] != '0')){numeral += "-";}}
		if (n[n.length()-2] == '7'){numeral += "seventy";if ((enableHyphens == true) && (n[n.length()-1] != '0')){numeral += "-";}}
		if (n[n.length()-2] == '8'){numeral += "eighty"; if ((enableHyphens == true) && (n[n.length()-1] != '0')){numeral += "-";}}
		if (n[n.length()-2] == '9'){numeral += "ninety"; if ((enableHyphens == true) && (n[n.length()-1] != '0')){numeral += "-";}}
	}

	// ones place
	if (n.length() < 2 || ( (n.length() >= 2) && ( (n[n.length() - 2]) != '1') ) )
	{
		if (n[n.length()-1] == '1'){numeral += "one";}
		if (n[n.length()-1] == '2'){numeral += "two";} 
		if (n[n.length()-1] == '3'){numeral += "three";}
		if (n[n.length()-1] == '4'){numeral += "four";}
		if (n[n.length()-1] == '5'){numeral += "five";}
		if (n[n.length()-1] == '6'){numeral += "six";}
		if (n[n.length()-1] == '7'){numeral += "seven";}
		if (n[n.length()-1] == '8'){numeral += "eight";}
		if (n[n.length()-1] == '9'){numeral += "nine";}
	}

	return numeral;
}


int main()
{
	int totalLetters = 0;

	for (int i = 1; i < 1001; i++)
	{	
		std::string s;
		std::stringstream out;
		out << i;
		s = out.str();
		totalLetters += convertToNumeral(s).length();
		cout << convertToNumeral(s) << endl;
	}
	cout << totalLetters;

	pause();
	return 0;
}

