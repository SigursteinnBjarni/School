#include<iostream>
#include "FractionCalc.h"
using namespace std;

int main(){
	char choise = ' ';
	while (choise != 'q'){
		FractionCalc firstFrac;
		FractionCalc secondFrac;
		FractionCalc result;
		cin >> firstFrac;
		cout << "+ - * /" << endl;
		cin >> choise;
		cin >> secondFrac;

		switch (choise)
		{
		case '+':
			result = firstFrac + secondFrac;
			break;
		case '-':
			result = firstFrac - secondFrac;
			break;
		case '*':
			result = firstFrac * secondFrac;
			break;
		case '/':
			result = firstFrac / secondFrac;
		default:
			break;
		}
		cout << result << endl;
		cout << "Convert to decimal? (Y/N) ";
		char ans = ' ';
		cin >> ans;
		if (ans == 'Y' || ans == 'y'){
			cout << "Decimal = " << result.convertToDecimal() << endl;
		}
	}

	cin.get();
	return 0;
}