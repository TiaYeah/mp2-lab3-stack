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
	cin >> expr;
	calc.SetExpr(expr);
	cout << calc.CheckExpression() << endl;
	//calc.ToPostfix();
	cout << calc.Calc();
	//cout << calc.CalcPostfix();
	//TStack<int> st(2), st2;
	//st.Push(5);
	//st.Push(2);
	//st2.Push(5);
	//cout << (st != st2) << endl;
	//cout << (st == st2) << endl;
	//for (int i = 0; i <= st.GetNumLast(); i++)
	//{
	//	st.Pop();
	//}
	//cout << (st == st2)<<endl;
	//// 2)
	//	SetExpression
//	GetExpression
//	CheckExpression
}