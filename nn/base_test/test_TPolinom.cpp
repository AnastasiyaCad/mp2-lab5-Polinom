#include "TPolinom.h"
#include "TPolinom.cpp"
#include <gtest.h>

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom p);
}

TEST(TPolinom, can_create_polinom1)
{
	string tmp = "3x2+5";
	ASSERT_NO_THROW(TPolinom p(tmp));
}

TEST(TPolinom, can_not_create_polinom)
{
	string tmp = "3f+p";
	TPolinom p(tmp);
	ASSERT_ANY_THROW(p.Proverka(tmp));
}

TEST(TPolinom, kkkkk)
{
	TPolinom mypl2("x2+y3+z"), mypl1("3x2+y2+z"), mypl3("4x2+2y2+2z"), sum;
	sum = mypl1 + mypl2;
	EXPECT_EQ(sum, mypl3);
}