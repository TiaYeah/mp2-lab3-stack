#include "gtest.h"
#include "../Project15/TCalculator.h"

TEST(TCalculator, can_create_calculator)
{
    ASSERT_NO_THROW(TCalculator m);
}

TEST(TCalculator, can_calculate)
{
	TCalculator m("2+2*2");
	m.ToPostfix();
	ASSERT_EQ(m.CalcPostfix(),6);
}
TEST(TCalculator, can_calculate2)
{
	TCalculator m("2+2*2");
	ASSERT_EQ(m.Calc(), 6);
}

TEST(TCalculator, can_check_correct_brackets)
{
	TCalculator m("(2+2)*2");
	ASSERT_EQ(m.CheckExpression(), "Верно");
}

TEST(TCalculator, can_check_incorrect_brackets)
{
	TCalculator m("(2+2))*2");
	ASSERT_EQ(m.CheckExpression(), "Неверно");
}
