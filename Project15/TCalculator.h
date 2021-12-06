#pragma once

#include <iostream>
#include <string>
#include "TStack.h"
using namespace std;


class TCalculator
{
	string expr;
	string postfix; // 1 2 5 + 4 3 - * /
	TStack<char> st_char;
	TStack<double> st_double;
public:
	bool CheckExpression();
	TCalculator(string _expr ="") : expr(_expr) {};
	void SetExpr(string _expr)
	{
		expr = _expr;
	}
	string GetPostfix()
	{
		return postfix;
	}
	int Priority(const char& op);
	void ToPostfix();
	double Calc();
	double CalcPostfix();
	int OperationResult(const char op);
	bool isOperator(char ch);
	bool isFunction(string str);
};
