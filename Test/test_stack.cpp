#include "gtest.h"
#include "../Project15/TStack.h"

TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> m(5));
}
TEST(TStack, cant_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStack<int> m(-5));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> m(5);
	ASSERT_NO_THROW(TStack<int> m2(m));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> m1(5);
	TStack<int> m2(m1);
	ASSERT_EQ(m1==m2,true);
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> m1(5);
	TStack<int> m2(m1);
	ASSERT_NE(&m1, &m2);
}

TEST(TStack, stack_after_creating_is_empty)
{
	TStack<int> m(5);
	ASSERT_EQ(m.IsEmpty(), true);
}

TEST(TStack, can_push_element_to_stack)
{
	TStack<int> m(5);
	ASSERT_NO_THROW(m.Push(1));
}

TEST(TStack, cant_push_element_to_full_stack)
{
	TStack<int> m(1);
	m.Push(1);
	ASSERT_ANY_THROW(m.Push(1));
}

TEST(TStack, cant_pop_element_from_empty_stack)
{
	TStack<int> m(5);
	ASSERT_ANY_THROW(m.Pop());
}


TEST(TStack, equal_stacks_are_equal)
{
	TStack<int> m1(5);
	TStack<int> m2(5);
	m1.Push(5);
	m2.Push(5);
	ASSERT_EQ(m1 == m2, true);
}

TEST(TStack, unequal_stacks_arent_equal)
{
	TStack<int> m1(5);
	TStack<int> m2(5);
	m1.Push(5);
	m2.Push(6);
	ASSERT_EQ(m1 != m2, true);
}