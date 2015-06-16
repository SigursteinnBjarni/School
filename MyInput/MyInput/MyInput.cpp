// MyInput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Point{
	
	int x;
	int y;
};

struct Point3{
	Point3();
	Point3(float x, float y, float z);

	float m_X, m_Y, m_Z;

};

Point3::Point3(){
	m_X = m_Y = m_Z = 0.0f;
}

Point3::Point3(float x, float y, float z){
	
	m_X = x;
	m_Y = y;
	m_Z = z;
}


int _tmain(int argc, _TCHAR* argv[])
{

	/*
	Point3 cube[8];

	cube[0] = Point3(-1.0f, -1.0f, -1.0f);
	cube[1] = Point3(-1.0f, 1.0f, -1.0f);
	cube[2] = Point3(1.0f, 1.0f, -1.0f);
	cube[3] = Point3(1.0f, -1.0f, -1.0f);
	cube[4] = Point3(-1.0f, -1.0f, 1.0f);
	cube[5] = Point3(-1.0f, 1.0f, 1.0f);
	cube[6] = Point3(1.0f, 1.0f, 1.0f);
	cube[7] = Point3(1.0f, -1.0f, 1.0f);


	ofstream binaryOutFile("pointdata.txt", ios_base::binary);

	if (binaryOutFile){
		binaryOutFile.write((char*)cube, sizeof(Point3) * 8);
		binaryOutFile.close();
	}

	cout << "Before Loading..." << endl;

	for (int i = 0; i < 8; i++)
	{
	cout << "cube[" << i << "] = ";
	cout << "(" << cube[i].m_X << ", " << cube[i].m_Y << ", " << cube[i].m_Z << ")" << endl;
	}

	ifstream binaryInFile("pointdata.txt", ios_base::binary);

	if (binaryInFile){
	binaryInFile.read((char*)cube, sizeof(Point3) * 8);

	binaryInFile.close();
	}

	cout << "AFTER LOADING..." << endl;
	for (int i = 0; i < 8; i++)
	{
	cout << "cube[" << i << "] = ";
	cout << "(" << cube[i].m_X << ", " << cube[i].m_Y << ", " << cube[i].m_Z << ")" << endl;
	}

	*/

	// -------------------------------------------------------------------------------------//

	/* Binary file input / output code
	ofstream binaryOutFile("pointdata.txt", ios_base::binary);
	ifstream binaryInFile("pointdata.txt", ios_base::binary);

	float fArray[4] = { 1, 2, 3, 4 };
	Point p = { 0, 0 };
	int x = 10;

	// write data as binary 
	binaryOutFile.write((char*)fArray, sizeof(float)*4);
	binaryOutFile.write((char*)&p, sizeof(Point));
	binaryOutFile.write((char*)&x, sizeof(int));
	

	float fArray[4];
	Point p;
	int x;
	// read binary data
	binaryInFile.read((char*)fArray, sizeof(float) * 4);	binaryInFile.read((char*)&p, sizeof(Point));	binaryInFile.read((char*)&x, sizeof(int));	/*

	// -------------------------------------------------------------------------------------//

	/* The basic file input/output code
	ofstream outFile("data.txt");
	ifstream inFile("data.txt");
	string line;

	if (outFile){
		outFile << "Test Me" << endl;
		outFile << "Pi = " << "3.14" << endl;
	}


	if (inFile){
		while (getline(inFile, line)){
			cout << line << endl;
		}
	}

	outFile.close();
	inFile.close();
	*/
	cin.get();
	return 0;
}

