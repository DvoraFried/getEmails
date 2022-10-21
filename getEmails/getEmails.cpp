#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// By Deborah Fried, DFfried.job@gmail.com

int main()
{
	ifstream source("source.txt");
	ofstream csv("emails.csv");
	ofstream txt("emails.txt");
	string text;

	while (!source.eof())
	{
		getline(source, text);
		int start, end;
		string email;

		while (text.find("<") != string::npos && text.find(">") != string::npos) {
			start = text.find("<");
			end = text.find(">");
			email = text.substr(start + 1, end - start - 1);
			txt << email << endl;
			csv << email << endl;
			text[start] = text[end] = 0;
		}
	}
}