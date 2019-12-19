#include "curricula.hpp"
#include <string>
#include <utility>
#include <iostream>

#include "avlbst.h"

using namespace std;

#define AVLBST_SETUP \
AVLTree<string, int> mStringIntAVL;\
AVLTree<int, double> mIntDoubleAVL;

typedef AVLTree<string, int>::iterator StringIntIterator;
typedef AVLTree<int, double>::iterator IntDoubleIterator;

HARNESS_BEGIN

TEST(InitiallyEmpty_01)
{
    AVLBST_SETUP;
	EXPECT_EQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_EQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());
    return 0;
}

TEST(SingleInsert_02)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Aaron", 0));
	mIntDoubleAVL.insert(make_pair(1, 100.5));

	EXPECT_UNEQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_UNEQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());

	EXPECT_EQUAL(mStringIntAVL.begin()->first, "Aaron");
	EXPECT_EQUAL(mStringIntAVL.begin()->second, 0);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->first, 1);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->second, 100.5);
	return 0;
}

TEST(DoubleInsertLeft_03)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Aaron", 0));
	mStringIntAVL.insert(make_pair("Aardvark", 2));
	mIntDoubleAVL.insert(make_pair(1, 100.5));
	mIntDoubleAVL.insert(make_pair(0, 0.04));

	EXPECT_UNEQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_UNEQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());

	StringIntIterator siIter = mStringIntAVL.begin();
	IntDoubleIterator idIter = mIntDoubleAVL.begin();

	EXPECT_EQUAL(siIter->first, "Aardvark");
	EXPECT_EQUAL(siIter->second, 2);
	EXPECT_EQUAL(idIter->first, 0);
	EXPECT_EQUAL(idIter->second, 0.04);
	++siIter;
	++idIter;

	EXPECT_UNEQUAL(siIter, mStringIntAVL.end());
	EXPECT_UNEQUAL(idIter, mIntDoubleAVL.end());

	EXPECT_EQUAL(siIter->first, "Aaron");
	EXPECT_EQUAL(siIter->second, 0);
	EXPECT_EQUAL(idIter->first, 1);
	EXPECT_EQUAL(idIter->second, 100.5);
	++siIter;
	++idIter;

	EXPECT_EQUAL(siIter, mStringIntAVL.end());
	EXPECT_EQUAL(idIter, mIntDoubleAVL.end());
    return 0;
}

TEST(DoubleInsertRight_04)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Aaron", 0));
	mStringIntAVL.insert(make_pair("Billy", 2));
	mIntDoubleAVL.insert(make_pair(1, 100.5));
	mIntDoubleAVL.insert(make_pair(2, 0.04));

	EXPECT_UNEQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_UNEQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());

	StringIntIterator siIter = mStringIntAVL.begin();
	IntDoubleIterator idIter = mIntDoubleAVL.begin();

	EXPECT_EQUAL(siIter->first, "Aaron");
	EXPECT_EQUAL(siIter->second, 0);
	EXPECT_EQUAL(idIter->first, 1);
	EXPECT_EQUAL(idIter->second, 100.5);
	++siIter;
	++idIter;

	EXPECT_UNEQUAL(siIter, mStringIntAVL.end());
	EXPECT_UNEQUAL(idIter, mIntDoubleAVL.end());

	EXPECT_EQUAL(siIter->first, "Billy");
	EXPECT_EQUAL(siIter->second, 2);
	EXPECT_EQUAL(idIter->first, 2);
	EXPECT_EQUAL(idIter->second, 0.04);
	++siIter;
	++idIter;

	EXPECT_EQUAL(siIter, mStringIntAVL.end());
	EXPECT_EQUAL(idIter, mIntDoubleAVL.end());
    return 0;
}

TEST(InsertZigZigLeft_05)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Cathy", 0));
	mStringIntAVL.insert(make_pair("Billy", 1));
	mStringIntAVL.insert(make_pair("Aaron", 2));
	mIntDoubleAVL.insert(make_pair(2, 3.5));
	mIntDoubleAVL.insert(make_pair(1, 100.5));
	mIntDoubleAVL.insert(make_pair(0, 0.04));

	EXPECT_UNEQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_UNEQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());

	StringIntIterator siIter = mStringIntAVL.begin();
	IntDoubleIterator idIter = mIntDoubleAVL.begin();

	EXPECT_EQUAL(siIter->first, "Aaron");
	EXPECT_EQUAL(siIter->second, 2);
	EXPECT_EQUAL(idIter->first, 0);
	EXPECT_EQUAL(idIter->second, 0.04);
	++siIter;
	++idIter;

	EXPECT_UNEQUAL(siIter, mStringIntAVL.end());
	EXPECT_UNEQUAL(idIter, mIntDoubleAVL.end());

	EXPECT_EQUAL(siIter->first, "Billy");
	EXPECT_EQUAL(siIter->second, 1);
	EXPECT_EQUAL(idIter->first, 1);
	EXPECT_EQUAL(idIter->second, 100.5);
	++siIter;
	++idIter;

	EXPECT_EQUAL(siIter->first, "Cathy");
	EXPECT_EQUAL(siIter->second, 0);
	EXPECT_EQUAL(idIter->first, 2);
	EXPECT_EQUAL(idIter->second, 3.5);
	++siIter;
	++idIter;

	EXPECT_EQUAL(siIter, mStringIntAVL.end());
	EXPECT_EQUAL(idIter, mIntDoubleAVL.end());
	return 0;
}

TEST(InsertZigZigRight_06)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Aaron", 2));
	mStringIntAVL.insert(make_pair("Billy", 1));
	mStringIntAVL.insert(make_pair("Cathy", 0));
	mIntDoubleAVL.insert(make_pair(0, 0.04));
	mIntDoubleAVL.insert(make_pair(1, 100.5));
	mIntDoubleAVL.insert(make_pair(2, 3.5));

	EXPECT_UNEQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_UNEQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());

	StringIntIterator siIter = mStringIntAVL.begin();
	IntDoubleIterator idIter = mIntDoubleAVL.begin();

	EXPECT_EQUAL(siIter->first, "Aaron");
	EXPECT_EQUAL(siIter->second, 2);
	EXPECT_EQUAL(idIter->first, 0);
	EXPECT_EQUAL(idIter->second, 0.04);
	++siIter;
	++idIter;

	EXPECT_UNEQUAL(siIter, mStringIntAVL.end());
	EXPECT_UNEQUAL(idIter, mIntDoubleAVL.end());

	EXPECT_EQUAL(siIter->first, "Billy");
	EXPECT_EQUAL(siIter->second, 1);
	EXPECT_EQUAL(idIter->first, 1);
	EXPECT_EQUAL(idIter->second, 100.5);
	++siIter;
	++idIter;

	EXPECT_EQUAL(siIter->first, "Cathy");
	EXPECT_EQUAL(siIter->second, 0);
	EXPECT_EQUAL(idIter->first, 2);
	EXPECT_EQUAL(idIter->second, 3.5);
	++siIter;
	++idIter;

	EXPECT_EQUAL(siIter, mStringIntAVL.end());
	EXPECT_EQUAL(idIter, mIntDoubleAVL.end());
	return 0;
}

TEST(InsertZigZagLeft_07)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Cathy", 0));
	mStringIntAVL.insert(make_pair("Aaron", 2));
	mStringIntAVL.insert(make_pair("Billy", 1));
	mIntDoubleAVL.insert(make_pair(2, 3.5));
	mIntDoubleAVL.insert(make_pair(0, 0.04));
	mIntDoubleAVL.insert(make_pair(1, 100.5));

	EXPECT_UNEQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_UNEQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());

	StringIntIterator siIter = mStringIntAVL.begin();
	IntDoubleIterator idIter = mIntDoubleAVL.begin();

	EXPECT_EQUAL(siIter->first, "Aaron");
	EXPECT_EQUAL(siIter->second, 2);
	EXPECT_EQUAL(idIter->first, 0);
	EXPECT_EQUAL(idIter->second, 0.04);
	++siIter;
	++idIter;

	EXPECT_UNEQUAL(siIter, mStringIntAVL.end());
	EXPECT_UNEQUAL(idIter, mIntDoubleAVL.end());

	EXPECT_EQUAL(siIter->first, "Billy");
	EXPECT_EQUAL(siIter->second, 1);
	EXPECT_EQUAL(idIter->first, 1);
	EXPECT_EQUAL(idIter->second, 100.5);
	++siIter;
	++idIter;

	EXPECT_EQUAL(siIter->first, "Cathy");
	EXPECT_EQUAL(siIter->second, 0);
	EXPECT_EQUAL(idIter->first, 2);
	EXPECT_EQUAL(idIter->second, 3.5);
	++siIter;
	++idIter;

	EXPECT_EQUAL(siIter, mStringIntAVL.end());
	EXPECT_EQUAL(idIter, mIntDoubleAVL.end());
	return 0;
}

TEST(InsertZigZagRight_08)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Aaron", 2));
	mStringIntAVL.insert(make_pair("Cathy", 0));
	mStringIntAVL.insert(make_pair("Billy", 1));
	mIntDoubleAVL.insert(make_pair(0, 0.04));
	mIntDoubleAVL.insert(make_pair(2, 3.5));
	mIntDoubleAVL.insert(make_pair(1, 100.5));

	EXPECT_UNEQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_UNEQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());

	StringIntIterator siIter = mStringIntAVL.begin();
	IntDoubleIterator idIter = mIntDoubleAVL.begin();

	EXPECT_EQUAL(siIter->first, "Aaron");
	EXPECT_EQUAL(siIter->second, 2);
	EXPECT_EQUAL(idIter->first, 0);
	EXPECT_EQUAL(idIter->second, 0.04);
	++siIter;
	++idIter;

	EXPECT_UNEQUAL(siIter, mStringIntAVL.end());
	EXPECT_UNEQUAL(idIter, mIntDoubleAVL.end());

	EXPECT_EQUAL(siIter->first, "Billy");
	EXPECT_EQUAL(siIter->second, 1);
	EXPECT_EQUAL(idIter->first, 1);
	EXPECT_EQUAL(idIter->second, 100.5);
	++siIter;
	++idIter;

	EXPECT_UNEQUAL(siIter, mStringIntAVL.end());
	EXPECT_UNEQUAL(idIter, mIntDoubleAVL.end());

	EXPECT_EQUAL(siIter->first, "Cathy");
	EXPECT_EQUAL(siIter->second, 0);
	EXPECT_EQUAL(idIter->first, 2);
	EXPECT_EQUAL(idIter->second, 3.5);
	++siIter;
	++idIter;

	EXPECT_EQUAL(siIter, mStringIntAVL.end());
	EXPECT_EQUAL(idIter, mIntDoubleAVL.end());
	return 0;
}

TEST(SingleInsertRemove_09)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Aaron", 0));
	mIntDoubleAVL.insert(make_pair(0, 0.4));

	mStringIntAVL.remove("Aaron");
	mIntDoubleAVL.remove(0);

	EXPECT_EQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_EQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());
	return 0;
}

TEST(DoubleInsertLeftRemoveRoot_10)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Betty", 0));
	mStringIntAVL.insert(make_pair("Aaron", 1));
	mIntDoubleAVL.insert(make_pair(1, 0.4));
	mIntDoubleAVL.insert(make_pair(-1, 0.3));

	mStringIntAVL.remove("Betty");
	mIntDoubleAVL.remove(1);

	EXPECT_UNEQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_UNEQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());
	EXPECT_EQUAL(mStringIntAVL.begin()->first, "Aaron");
	EXPECT_EQUAL(mStringIntAVL.begin()->second, 1);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->first, -1);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->second, 0.3);
	return 0;
}

TEST(DoubleInsertRightRemoveRoot_11)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Aaron", 0));
	mStringIntAVL.insert(make_pair("Betty", 1));
	mIntDoubleAVL.insert(make_pair(-1, 0.4));
	mIntDoubleAVL.insert(make_pair(1, 0.3));

	mStringIntAVL.remove("Aaron");
	mIntDoubleAVL.remove(-1);

	EXPECT_UNEQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_UNEQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());
	EXPECT_EQUAL(mStringIntAVL.begin()->first, "Betty");
	EXPECT_EQUAL(mStringIntAVL.begin()->second, 1);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->first, 1);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->second, 0.3);
	return 0;
}

TEST(DoubleInsertLeftRemoveLeft_12)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Betty", 0));
	mStringIntAVL.insert(make_pair("Aaron", 1));
	mIntDoubleAVL.insert(make_pair(1, 0.4));
	mIntDoubleAVL.insert(make_pair(-1, 0.3));
	mStringIntAVL.remove("Aaron");
	mIntDoubleAVL.remove(-1);

	EXPECT_UNEQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_UNEQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());
	EXPECT_EQUAL(mStringIntAVL.begin()->first, "Betty");
	EXPECT_EQUAL(mStringIntAVL.begin()->second, 0);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->first, 1);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->second, 0.4);
	return 0;
}

TEST(DoubleInsertRightRemoveRight_13)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Aaron", 0));
	mStringIntAVL.insert(make_pair("Betty", 1));
	mIntDoubleAVL.insert(make_pair(-1, 0.4));
	mIntDoubleAVL.insert(make_pair(1, 0.3));
	mStringIntAVL.remove("Betty");
	mIntDoubleAVL.remove(1);

	EXPECT_UNEQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_UNEQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());
	EXPECT_EQUAL(mStringIntAVL.begin()->first, "Aaron");
	EXPECT_EQUAL(mStringIntAVL.begin()->second, 0);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->first, -1);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->second, 0.4);
	return 0;
}

TEST(TripleInsertRemoveRoot_14)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Betty", 0));
	mStringIntAVL.insert(make_pair("Aaron", 1));
	mStringIntAVL.insert(make_pair("Carla", 2));
	mIntDoubleAVL.insert(make_pair(0, 0.4));
	mIntDoubleAVL.insert(make_pair(-1, 0.3));
	mIntDoubleAVL.insert(make_pair(1, 11.12));
	mStringIntAVL.remove("Betty");
	mIntDoubleAVL.remove(0);

	StringIntIterator siIter = mStringIntAVL.begin();
	IntDoubleIterator idIter = mIntDoubleAVL.begin();

	EXPECT_EQUAL(siIter->first, "Aaron");
	EXPECT_EQUAL(siIter->second, 1);
	EXPECT_EQUAL(idIter->first, -1);
	EXPECT_EQUAL(idIter->second, 0.3);
	++siIter;
	++idIter;

	EXPECT_UNEQUAL(siIter, mStringIntAVL.end());
	EXPECT_UNEQUAL(idIter, mIntDoubleAVL.end());

	EXPECT_EQUAL(siIter->first, "Carla");
	EXPECT_EQUAL(siIter->second, 2);
	EXPECT_EQUAL(idIter->first, 1);
	EXPECT_EQUAL(idIter->second, 11.12);
	++siIter;
	++idIter;

	EXPECT_EQUAL(siIter, mStringIntAVL.end());
	EXPECT_EQUAL(idIter, mIntDoubleAVL.end());
	return 0;
}

TEST(SingleInsertInvalidRemove_15)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Aaron", 0));
	mStringIntAVL.remove("Betty");

	mIntDoubleAVL.insert(make_pair(1, 100.5));
	mIntDoubleAVL.remove(20);

	EXPECT_UNEQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_UNEQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());

	EXPECT_EQUAL(mStringIntAVL.begin()->first, "Aaron");
	EXPECT_EQUAL(mStringIntAVL.begin()->second, 0);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->first, 1);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->second, 100.5);
	return 0;
}

TEST(SingleInsertDuplicateInsert_16)
{
    AVLBST_SETUP;

	mStringIntAVL.insert(make_pair("Aaron", 0));
	mStringIntAVL.insert(make_pair("Aaron", 10));

	mIntDoubleAVL.insert(make_pair(1, 100.5));
	mIntDoubleAVL.insert(make_pair(1, 200.5));

	EXPECT_UNEQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_UNEQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());

	EXPECT_EQUAL(mStringIntAVL.begin()->first, "Aaron");
	EXPECT_EQUAL(mStringIntAVL.begin()->second, 10);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->first, 1);
	EXPECT_EQUAL(mIntDoubleAVL.begin()->second, 200.5);

	mStringIntAVL.remove("Aaron");
	mIntDoubleAVL.remove(1);

	EXPECT_EQUAL(mStringIntAVL.begin(), mStringIntAVL.end());
	EXPECT_EQUAL(mIntDoubleAVL.begin(), mIntDoubleAVL.end());
	return 0;
}

HARNESS_END
