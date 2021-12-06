#include <iostream>
#include <string>
#include "TCalculator.h"

using namespace std;

bool TCalculator::CheckExpression()
{
	TStack<char> ch(expr.size());
	for (int i = 0; i < expr.size(); i++)
	{
		if (expr[i] == '(')
			ch.Push('(');
		if (expr[i] == ')')
		{
			if (ch.Top() == '(')
				ch.Pop();
			else
				ch.Push(')');
		}
	}
	if (ch.IsEmpty())
		return true;
	else
		return false;
}

int TCalculator::Priority(const char& op)
{
	if (op == '(')
		return 0;
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op ==  '/')
		return 2;
	if (op == '^')
		return 3;
}

bool TCalculator::isOperator(char ch)
{
	char operators[] = { '+', '-', '*', '/', '^' };
	int size = 5;

	for (int i = 0; i < size; i++)
		if (ch == operators[i])
			return true;

	return false;
}

bool TCalculator::isFunction(string str)
{
	string func[] = { "sin", "cos", "tg"};
	int size = 3;

	for (int i = 0; i < size; i++)
		if (str == func[i])
			return true;

	return false;
}

void TCalculator::ToPostfix()
{
	string infix = "(" + expr + ")";
	st_double.ClearStack();
	st_char.ClearStack();
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] <= '9' && infix[i] >= '1')
		{
			size_t ind;
			double num = stod(&infix[i], &ind);
			postfix += to_string(num) + ' ';
			i += ind - 1;
		}
		else
		if (infix[i] == '(')
			st_char.Push('(');
		else
		if (infix[i] == ')')
		{
			while (st_char.Top() != '(')
				postfix += string(1, st_char.Pop()) + ' ';
			st_char.Pop();
		}
		else
		if (isOperator(infix[i]))
		{
			while (Priority(st_char.Top()) >= Priority(infix[i]))
			{
				postfix += string(1, st_char.Pop()) + ' ';
			}
			st_char.Push(infix[i]);
		}
		else
		{
			if (infix[i] == 's' || infix[i] == 'c' || infix[i] == 't')
			{
				string func = "";
				while (infix[i] != '(')
				{
					func += infix[i];
					i++;
				}
				if (isFunction(func))
				{
					if (func == "sin")
						st_char.Push('s');
					else if (func == "cos")
						st_char.Push('c');
					else st_char.Push('t');
				}
			}
			else throw("Неправильное выражение");
		}
		
	}
}

double TCalculator::Calc()
{
	string infix = "(" + expr + ")";
	st_double.ClearStack();
	st_char.ClearStack();
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] >= '0' && infix[i] <= '9')
		{
			size_t ind;
			double num = stod(&infix[i], &ind);
			st_double.Push(num);
			i += ind - 1;
		}
		else
		if (infix[i] == '(')
		{
			st_char.Push('(');
		}
		else
		if (infix[i] == ')')
		{
			while (st_char.Top() != '(')
			{
				i += OperationResult(st_char.Pop());
			}
			st_char.Pop();
		}
		else
		if (isOperator(infix[i]))
		{
			while (Priority(st_char.Top()) >= Priority(infix[i]))
			{
				OperationResult(st_char.Pop());
			}
			st_char.Push(infix[i]);
		}
		else
		{
			if (infix[i] == 's' || infix[i] == 'c' || infix[i] == 't')
			{
				string func = "";
				while (infix[i] != '(')
				{
					func += infix[i];
					i++;
				}
				if (isFunction(func))
				{
					if (func == "sin")
						st_char.Push('s');
					else if (func == "cos")
						st_char.Push('c');
					else st_char.Push('t');
				}
			}
			else throw("Неправильное выражение");
			size_t ind;
			
			st_double.Push(stod(&infix[i + 1], &ind));
			i += ind+1;
			OperationResult(st_char.Pop());
		}
	}
	return(st_double.Top());
}

double TCalculator::CalcPostfix()
{
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] == ' ')
			continue;
		if (postfix[i] <= '9' && postfix[i] >= '1')
		{
			size_t ind;
			double num = stod(&postfix[i], &ind);
			st_double.Push(num);
			i += ind;
		}
		else
			i+=OperationResult(postfix[i]);

	}
	return(st_double.Top());
}

int TCalculator::OperationResult(const char op)
{
	if (isOperator(op))
	{
		double a = st_double.Pop();
		double b = st_double.Pop();
		switch (op)
		{
		case '+':
			st_double.Push(a + b);
			break;
		case '-':
			st_double.Push(b - a);
			break;
		case '*':
			st_double.Push(a * b);
			break;
		case '/':
			st_double.Push(b / a);
			break;
		case '^':
			st_double.Push(pow(b, a));
			break;
		default:
			break;
		}
		return 0;
	}
	else if (op != ' ')
	{
		double a = 0;
		switch (op)
		{
		case 's':
			a = st_double.Pop();
			st_double.Push(sin(a));
			return(3);
			break;
		case 'c':
			a = st_double.Pop();
			st_double.Push(cos(a));
			return(3);
			break;
		case 't':
			a = st_double.Pop();
			st_double.Push(tan(a));
			return(2);
			break;
		default:
			break;
		}
	}
}