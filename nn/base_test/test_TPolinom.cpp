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

/*TEST(TPolinom, add_polinom)
{
	TPolinom mypl2("x2+y2+z"), mypl1("3x2+y2+z"), mypl3("4x2+2y2+2z");
	mypl1.ToMonom();
	mypl2.ToMonom();
	mypl3.ToMonom();
	EXPECT_TRUE(mypl1 + mypl2 == mypl3);
}


TEST(TPolinom, sub_polinom)
{
	TPolinom mypl2("x2+y2+z"), mypl1("3x2+2y2+4z"), mypl3("2x2+y2+3z"), sum;
	mypl1.ToMonom();
	mypl2.ToMonom();
	mypl3.ToMonom();
	sum = mypl1 - mypl2;
	
	EXPECT_EQ(sum, mypl3);
}*/

TEST(TPolinom, cat_calculate_polinom)
{
	TPolinom mypl2("x2+y3+z");
	mypl2.ToMonom();
	int x = 1, y = 2, z = 0;
	int e = mypl2.Calculate(x, y, z);
	EXPECT_EQ(e, 9);
}
