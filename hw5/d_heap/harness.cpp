#include "heap.h"
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <iostream>

using namespace std;

// Return 1 if incorrect, 0 if correct
int contents_ordered(int size, MinHeap<int>& heap)
{
    for (int i = 0; i < size; ++i)
    {
        if (heap.isEmpty())
        {
            return 1;
        }
        if (heap.peek() != i)
        {
            return 1;
        }
        heap.remove();
    }
    if (!heap.isEmpty())
    {
        return 1;
    }
    return 0;
}

#define EXPECT_TRUE(condition) if (!condition) { return 1; }
#define EXPECT_FALSE(condition) if (condition) { return 1; }
#define EXPECT_THROW(statement) try { statement; } catch (...) { return 0; } return 1;
#define EXPECT_EQUAL(left, right) if (left != right)  { return 1; }

// Magic to index functions
typedef int (*Case)();

int case0()
{
    MinHeap<int> heap(2);
    return 0;
}

int case1()
{
    MinHeap<int> heap(2);
    EXPECT_TRUE(heap.isEmpty());
	return 0;
}

int case2()
{
    MinHeap<int> heap(2);
    EXPECT_THROW(heap.peek());
}

int case3()
{
    MinHeap<int> heap(2);
    try
    {
        heap.remove();
    }
    catch(...)
    {
    }
    return 0;
}

int case4()
{
	MinHeap<int> heap(2);
	heap.add(2, 1);
	EXPECT_FALSE(heap.isEmpty());
	return 0;
}

int case5()
{
    MinHeap<int> heap(2);
	heap.add(10, 1);
	EXPECT_EQUAL(10, heap.peek());
	return 0;
}

int case6()
{
    MinHeap<int> heap(2);
	heap.add(10, 1);
	heap.remove();
	EXPECT_TRUE(heap.isEmpty());
	return 0;
}

int case7()
{
    MinHeap<int> heap(2);
	heap.add(10, 3);
	heap.add(20, 10);
	EXPECT_EQUAL(10, heap.peek());
	heap.remove();
	EXPECT_EQUAL(20, heap.peek());
	return 0;
}

int case8()
{
    MinHeap<int> heap(2);
	heap.add(10, 50);
	heap.add(20, 49);
	EXPECT_EQUAL(20, heap.peek());
	heap.remove();
	EXPECT_EQUAL(10, heap.peek());
	return 0;
}

int case9()
{
    MinHeap<int> heap(2);
	heap.add(20, 9);
	heap.add(10, 9);
	EXPECT_TRUE((heap.peek() == 10) || (heap.peek() == 20));
	return 0;
}

int case10()
{
    MinHeap<int> heap(2);
	heap.add(10, 0);
	heap.add(20, 5);
	heap.add(30, 10);
	EXPECT_EQUAL(10, heap.peek());
	heap.remove();
	EXPECT_EQUAL(20, heap.peek());
	heap.remove();
	EXPECT_EQUAL(30, heap.peek());
	return 0;
}

int case11()
{
    MinHeap<int> heap(2);
	heap.add(10, 0);
	heap.add(30, 10);
	heap.add(20, 5);
	EXPECT_EQUAL(10, heap.peek());
	heap.remove();
	EXPECT_EQUAL(20, heap.peek());
	heap.remove();
	EXPECT_EQUAL(30, heap.peek());
	return 0;
}

int case12()
{
    MinHeap<int> heap(2);
	heap.add(20, 5);
	heap.add(10, 0);
	heap.add(30, 10);
	EXPECT_EQUAL(10, heap.peek());
	heap.remove();
	EXPECT_EQUAL(20, heap.peek());
	heap.remove();
	EXPECT_EQUAL(30, heap.peek());
	return 0;
}

int case13()
{
    MinHeap<int> heap(2);
	heap.add(20, 5);
	heap.add(30, 10);
	heap.add(10, 0);
	EXPECT_EQUAL(10, heap.peek());
	heap.remove();
	EXPECT_EQUAL(20, heap.peek());
	heap.remove();
	EXPECT_EQUAL(30, heap.peek());
	return 0;
}

int case14()
{
    MinHeap<int> heap(2);
	heap.add(30, 10);
	heap.add(10, 0);
	heap.add(20, 5);
	EXPECT_EQUAL(10, heap.peek());
	heap.remove();
	EXPECT_EQUAL(20, heap.peek());
	heap.remove();
	EXPECT_EQUAL(30, heap.peek());
	return 0;
}

int case15()
{
	MinHeap<int> heap(2);
	heap.add(30, 10);
	heap.add(20, 5);
	heap.add(10, 0);
	EXPECT_EQUAL(10, heap.peek());
	heap.remove();
	EXPECT_EQUAL(20, heap.peek());
	heap.remove();
	EXPECT_EQUAL(30, heap.peek());
	return 0;
}

int case16()
{
    MinHeap<string> stringHeap(2);
	stringHeap.add("blah", 25);
	stringHeap.add("bluh", 30);
	stringHeap.add("bloh", 35);
	EXPECT_EQUAL("blah", stringHeap.peek());
	stringHeap.remove();
	EXPECT_EQUAL("bluh", stringHeap.peek());
	stringHeap.remove();
	EXPECT_EQUAL("bloh", stringHeap.peek());
	return 0;
}

int case17()
{
    MinHeap<int> heap(3);
	heap.add(10, 0);
	heap.add(20, 5);
	heap.add(30, 10);
	EXPECT_EQUAL(10, heap.peek());
	heap.remove();
	EXPECT_EQUAL(20, heap.peek());
	heap.remove();
	EXPECT_EQUAL(30, heap.peek());
	return 0;
}

int case18()
{
    MinHeap<int> heap(4);
	heap.add(10, 0);
	heap.add(20, 5);
	heap.add(30, 10);
	EXPECT_EQUAL(10, heap.peek());
	heap.remove();
	EXPECT_EQUAL(20, heap.peek());
	heap.remove();
	EXPECT_EQUAL(30, heap.peek());
	return 0;
}

int stress(int size, MinHeap<int>& heap)
{
    vector<int> benchmark(size);

    int i;
    vector<int>::iterator it;
    for (it = benchmark.begin(), i = 0; it != benchmark.end(); ++it, ++i)
    {
        *it = i;
    }

    unsigned int seed = 69420;
    shuffle(benchmark.begin(), benchmark.end(), default_random_engine(seed));

    for (auto it = benchmark.begin(); it != benchmark.end(); ++it)
    {
        heap.add(*it, *it);
    }

    return contents_ordered(size, heap);
}

int case19()
{
    MinHeap<int> heap(2);
    return stress(5000, heap);
}

int case20()
{
    MinHeap<int> heap(4);
    return stress(5000, heap);
}

int case21()
{
    MinHeap<int> heap(12);
    return stress(5000, heap);
}

int case22()
{
    MinHeap<int> heap(2);
    return stress(10000, heap);
}

int case23()
{
    MinHeap<int> heap(2);
	heap.add(10, 10);
	heap.add(20, 20);
	heap.add(30, 30);
	heap.update(2, 0);
	EXPECT_EQUAL(30, heap.peek());
	heap.remove();
	EXPECT_EQUAL(10, heap.peek());
	heap.remove();
	EXPECT_EQUAL(20, heap.peek());
	return 0;
}

int case24()
{
    MinHeap<int> heap(2);
	heap.add(10, 10);
	heap.add(20, 20);
	heap.add(30, 30);
	heap.update(1, 0);
	EXPECT_EQUAL(20, heap.peek());
	heap.remove();
	EXPECT_EQUAL(10, heap.peek());
	heap.remove();
	EXPECT_EQUAL(30, heap.peek());
	return 0;
}

int case25()
{
    MinHeap<int> heap(2);
	heap.add(10, 10);
	heap.add(20, 20);
	heap.add(30, 30);
	heap.update(0, 0);
	EXPECT_EQUAL(10, heap.peek());
	heap.remove();
	EXPECT_EQUAL(20, heap.peek());
	heap.remove();
	EXPECT_EQUAL(30, heap.peek());
	return 0;
}

int main(int argc, char** argv)
{
    Case cases[] = {
        case0, case1, case2, case3, case4, case5, case6, case7, case8, case9, case10, case11, case12, case13, case14,
        case15, case16, case17, case18, case19, case20, case21, case22, case23, case24, case25
    };
    if (argc > 0)
    {
        return cases[stoi(argv[1])]();
    }
    else
    {
        return -1;
    }
}
