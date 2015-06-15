#include "FractionCalc.h"
#include <iostream>
using namespace std;
FractionCalc::FractionCalc()
{
	m_Numerator = 0.0;
	m_Demominator = 1.0;
}

FractionCalc::FractionCalc(float numerator, float demoninator)
{
	m_Numerator = numerator;
	m_Demominator = demoninator;
}

FractionCalc FractionCalc::operator*(const FractionCalc &rhs){
	
	FractionCalc frac;

	frac.m_Demominator = m_Demominator * rhs.m_Demominator;
	frac.m_Numerator = m_Numerator * rhs.m_Numerator;
	return frac;

}

FractionCalc FractionCalc::operator+(const FractionCalc &rhs){
	FractionCalc frac;

	frac.m_Numerator = (m_Numerator * rhs.m_Demominator) + (rhs.m_Numerator * m_Demominator);
	frac.m_Demominator = (m_Demominator * rhs.m_Demominator);

	return frac;
}

FractionCalc FractionCalc::operator-(const FractionCalc &rhs){
	FractionCalc frac;

	frac.m_Numerator = (m_Numerator * rhs.m_Demominator) - (rhs.m_Numerator * m_Demominator);
	frac.m_Demominator = (m_Demominator * rhs.m_Demominator);

	return frac;


}

FractionCalc FractionCalc::operator/(const FractionCalc &rhs){
	FractionCalc frac;

	frac.m_Numerator = m_Numerator * rhs.m_Demominator;
	frac.m_Demominator = m_Demominator * rhs.m_Numerator;

	return frac;
}

ostream& operator<<(ostream& out, const FractionCalc &frac){
	cout << frac.m_Numerator << "/" << frac.m_Demominator << endl;
	return out;
}

istream& operator>>(istream& ins, FractionCalc &frac){
	
	cout << "Numerator: ";
	cin >> frac.m_Numerator;
	cout << "Denominator: ";
	cin >> frac.m_Demominator;

	return ins;
}
float FractionCalc::convertToDecimal(){

	return m_Numerator / m_Demominator;
}

FractionCalc::~FractionCalc()
{
}
