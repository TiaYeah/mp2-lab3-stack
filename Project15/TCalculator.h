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
	string CheckExpression();
	TCalculator(string _expr ="") : expr(_expr) {};
	void SetExpr(string _expr)
	{
		expr = _expr;
	}
	int Priority(const char& op);
	void ToPostfix();
	double Calc();
	double CalcPostfix();
	bool isOperator(char ch);
	bool isFunction(string str);
};

//void TCalculator::ToPostfix()
//{
//	string infix = "(" + expr + ")";
//	st_char.ClearStack();
//	for (int i = 0; i < infix.size(); i++)
//	{
//		if (infix[i] <= '9' && infix[i] >= 1)
//		{
//			//output[i] += infix[i] + ' ';
//		}
//		if (infix[i] == '(')
//			st_char.Push('(');
//		if (infix[i] == ')')
//		{
//			while (st_char.Top() != '(')
//				//output += st_char.Pop() + ' ';
//				st_char.Pop();
//		}
//		if (isOperator(infix[i]))
//		{
//			while (Priority(st_char.Top() <= Priority(infix[i])))
//			{
//				//output += st_char.Pop() + ' ';
//			}
//			st_char.Push(infix[i]);
//		}
//	}
//
//}
//
//bool TCalculator::isOperator(char ch)
//{
//	return true;
//}
//
//double TCalculator::calc()
//{
//	for (int i = 0; i < postfix.size(); i++)
//	{
//		if (postfix[i] <= '9' && postfix[i] >= '1')
//			st_double.Push(stod(&postfix[i]));
//		else
//			if (postfix[i] == '+' || postfix[i] == '-')
//			{
//				double a = st_double.Pop();
//				double b = st_double.Pop();
//				switch (postfix[i])
//				{
//				case '+':
//					st_double.Push(a + b);
//					break;
//				case '-':
//					st_double.Push(b - a);
//					break;
//				default:
//					break;
//				}
//
//			}
//
//	}
//	return(st_double.Top());
//}

