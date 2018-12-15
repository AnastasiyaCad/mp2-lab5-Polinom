#include "TPolinom.h"
#include "TPolinom.cpp"
#include <gtest.h>

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom p);
}

TEST(TPostfix, can_create_polinom1)
{
	string tmp = "3x2+5";
	ASSERT_NO_THROW(TPolinom p(tmp));
}

TEST(TPostfix, can_not_create_polinom)
{
	string tmp = "3f+p";
	TPolinom p(tmp);
	ASSERT_ANY_THROW(p.Proverka(tmp));
}