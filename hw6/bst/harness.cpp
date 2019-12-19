#include "curricula.hpp"
#include <string>
#include <utility>
#include <iostream>

#include "bst.h"

using namespace std;

#define BST_STRING_INTEGER BinarySearchTree<std::string, int> bst;
#define BST_INTEGER_INTEGER BinarySearchTree<int, int> bst;

HARNESS_BEGIN

TEST(insert_case0)
{
    BST_STRING_INTEGER;
    bst.insert(make_pair("ABC", 1));
    bst.insert(make_pair("BCD", 2));
    return 0;
}

TEST(internal_find)
{
    BST_STRING_INTEGER;
    bst.insert(std::make_pair("ABC", 1));
    EXPECT_UNEQUAL(bst.find("ABC"), bst.end());
    EXPECT_EQUAL(bst.find("ABC")->second, 1);
    bst.insert(std::make_pair("BCD", 2));
    EXPECT_UNEQUAL(bst.find("BCD"), bst.end());
    EXPECT_EQUAL(bst.find("BCD")->second, 2);
    return 0;
}

TEST(internal_find_invalid)
{
    BST_INTEGER_INTEGER;
    for (int i = 0; i < 20; i++)
    {
        EXPECT_EQUAL(bst.find(i), bst.end());
    }
    return 0;
}

TEST(insert_case1)
{
    BST_INTEGER_INTEGER;
    for (int i = 0; i < 20; i++)
    {
        bst.insert(make_pair(i, 2*i));
    }
    for (int i = 0; i < 20; i++)
    {
        EXPECT_UNEQUAL(bst.find(i), bst.end());
        EXPECT_EQUAL(bst.find(i)->second, 2*i);
    }
    return 0;
}

TEST(insert_case2)
{
    BST_STRING_INTEGER;
    for (int i = 0; i < 20; i++)
    {
        bst.insert(make_pair(to_string(i), 2*i));
    }
    for (int i = 0; i < 20; i++)
    {
        EXPECT_UNEQUAL(bst.find(to_string(i)), bst.end());
        EXPECT_EQUAL(bst.find(to_string(i))->second, 2*i);
    }
    return 0;
}

TEST(clear)
{
    BST_INTEGER_INTEGER;
    for (int i = 0; i < 20; i++)
    {
        bst.insert(make_pair(i, 2*i));
    }
    bst.clear();
    for (int i = 0; i < 20; i++)
    {
        EXPECT_EQUAL(bst.find(i), bst.end());
    }
    return 0;
}

TEST(get_smallest)
{
    BST_INTEGER_INTEGER;
    for (int i = 0; i < 20; i++)
    {
        bst.insert(make_pair(i, 2*i));
    }
    EXPECT_EQUAL(bst.begin()->second, 0);
    return 0;
}

TEST(get_smallest_empty)
{
    BST_INTEGER_INTEGER;
    EXPECT_EQUAL(bst.begin(), bst.end());
    return 0;
}

TEST(overwrite)
{
    BST_INTEGER_INTEGER;
    for (int i = 0; i < 20; i++)
    {
        bst.insert(make_pair(i, i));
    }
    bst.insert(make_pair(0, 20));
    EXPECT_UNEQUAL(bst.find(0), bst.end());
    EXPECT_EQUAL(bst.find(0)->second, 20);
    return 0;
}

TEST(iterator)
{
    BST_INTEGER_INTEGER;
    for (int i = 0; i < 20; i++)
    {
        bst.insert(make_pair(i, i));
    }
    int count = 0;
    for (auto it : bst)
    {
        EXPECT_EQUAL(it.second, count++);
    }
    return 0;
}

HARNESS_END
