#include "gtest.h"
#include "../Project15/TCalculator.h"

TEST(TCalculator, can_create_calculator)
{
	ASSERT_NO_THROW(TCalculator m);
}

TEST(TCalculator, can_set_expr)
{
	TCalculator m;
	ASSERT_NO_THROW(m.SetExpr("2+2"));
}

TEST(TCalculator, can_calculate_simple_operators_1_variant)
{
	TCalculator m("(2-(3*4)^2)/2");
	m.ToPostfix();
	double res = (2 - pow(3 * 4, 2)) / 2;
	ASSERT_EQ(m.CalcPostfix(), res);
}


TEST(TCalculator, can_calculate_simple_operators_2_variant)
{
	TCalculator m("(2-(3*4)^2)/2");
	double res = (2 - pow(3 * 4, 2)) / 2;
	ASSERT_EQ(m.Calc(), res);
}

TEST(TCalculator, can_check_correct_brackets)
{
	TCalculator m("(2+2)*2");
	ASSERT_EQ(m.CheckExpression(), true);
}

TEST(TCalculator, can_check_incorrect_brackets)
{
	TCalculator m("(2+2))*2");
	ASSERT_EQ(m.CheckExpression(), false);
}


TEST(TCalculator, can_calculate_trigonometric_functions)
{
	TCalculator m("sin(5)-cos(16)+tg(8)");
	double res = sin(5) - cos(16) + tan(8);
	ASSERT_EQ(m.Calc(), res);
}


TEST(TCalculator, can_calculate_complex_expression)
{
	TCalculator m("sin(6)/2+3^2*cos(2)-tg(3)");
	double res = sin(6) / 2.0 + pow(3, 2) * cos(2) - tan(3);
	ASSERT_EQ(m.Calc(), res);
}
 