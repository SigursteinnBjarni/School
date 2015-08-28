#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class LineCounter
{
public:
	LineCounter(string path, ifstream infile);
	void readFromfile();
	~LineCounter();
private:
	string m_path;
	int m_noLines;
	ifstream m_inFile;

};

