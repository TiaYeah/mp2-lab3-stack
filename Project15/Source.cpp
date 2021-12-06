#include <iostream>
#include <string>
#include "TStack.h"
#include "TCalculator.h"
#include<locale>

using namespace std;





void main()
{
	setlocale(LC_ALL, "Russian");
	
	TCalculator calc;
	string expr;
	cin >> expr; //sin(6)/2+3^2*cos(2)-tg(3)
	calc.SetExpr(expr);
	//cout << calc.GetPostfix() << endl;
	if (calc.CheckExpression())
	{
		try
		{
			cout << "Ответ: " << calc.Calc() << endl;
		}
		catch (...)
		{
			cout << "Неправильное выражение" << endl;
		}
	}
	else
		cout << "Неправильное выражение";
	
}