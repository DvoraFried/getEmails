#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// By Deborah Fried, DFfried.job@gmail.com

int main()
{
	//open source file
	ifstream source("source.txt");
	//open 2 output files
	ofstream csv("emails.csv");
	ofstream txt("emails.txt");

	string text;

	while (!source.eof())
	{
		//reading line after line
		getline(source, text);
		
		int start, end;
		string email;

		//Finds these characters - '<', '>' - means there is an email address between them, extracts itand outputs it to the output files
		while (text.find("<") != string::npos && text.find(">") != string::npos) {
			start = text.find("<");
			end = text.find(">");
			//copy the email
			email = text.substr(start + 1, end - start - 1);
			txt << email << endl;
			csv << email << endl;
			text[start] = text[end] = 0;
		}
	}
}