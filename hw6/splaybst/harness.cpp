#include "curricula.hpp"
#include <string>
#include <utility>
#include <iostream>

#include "splay.h"

using namespace std;

#define SPLAY_STRING_INTEGER SplayTree<std::string, int> splay;
#define SPLAY_INTEGER_INTEGER SplayTree<int, int> splay;

HARNESS_BEGIN

TEST(insert_case0)
{
    SPLAY_STRING_INTEGER;
    splay.insert(make_pair("ABC", 1));
    splay.insert(make_pair("BCD", 2));
    return 0;
}

TEST(insert_case1)
{
    SPLAY_INTEGER_INTEGER;
    for (int i = 0; i < 20; i++)
    {
        splay.insert(make_pair(i, 2*i));
    }
    for (int i = 0; i < 20; i++)
    {
        EXPECT_UNEQUAL(splay.find(i), splay.end());
        EXPECT_EQUAL(splay.find(i)->second, 2*i);
    }
    return 0;
}

TEST(insert_case2)
{
    SPLAY_STRING_INTEGER;
    for (int i = 0; i < 20; i++)
    {
        splay.insert(make_pair(to_string(i), 2*i));
    }
    for (int i = 0; i < 20; i++)
    {
        EXPECT_UNEQUAL(splay.find(to_string(i)), splay.end());
        EXPECT_EQUAL(splay.find(to_string(i))->second, 2*i);
    }
    return 0;
}

TEST(get_smallest)
{
    SPLAY_INTEGER_INTEGER;
    for (int i = 0; i < 20; i++)
    {
        splay.insert(make_pair(i, 2*i));
    }
    EXPECT_EQUAL(splay.begin()->second, 0);
    return 0;
}

TEST(remove_case0)
{
    SPLAY_STRING_INTEGER;
    splay.insert(make_pair("ABC", 1));
    splay.insert(make_pair("BCD", 2));
    splay.remove("ABC");
    EXPECT_EQUAL(splay.begin()->first, "BCD");
    return 0;
}

TEST(remove_case1)
{
    SPLAY_INTEGER_INTEGER;
    for (int i = 0; i < 20; i++)
    {
        splay.insert(make_pair(i, 2*i));
    }
    for (int i = 0; i < 20; i++)
    {
        splay.remove(i);
    }
    EXPECT_EQUAL(splay.begin(), splay.end());
    return 0;
}

HARNESS_END
