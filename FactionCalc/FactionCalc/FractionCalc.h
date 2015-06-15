#pragma once
#include <iostream>
using namespace std;
class FractionCalc
{
public:
	FractionCalc();
	FractionCalc(float numerator, float demoninator);
	FractionCalc operator+(const FractionCalc &rhs);
	FractionCalc operator-(const FractionCalc &rhs);
	FractionCalc operator*(const FractionCalc &rhs);
	FractionCalc operator/(const FractionCalc &rhs);
	float convertToDecimal();
	friend ostream& operator<<(ostream& out, const FractionCalc &frac);
	friend istream& operator>>(istream& ins, FractionCalc &frac);
	~FractionCalc();

private:
	float m_Numerator, m_Demominator = 0.0f;


};

