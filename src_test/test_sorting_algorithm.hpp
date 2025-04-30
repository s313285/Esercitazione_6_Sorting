#pragma once

#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include "SortingAlgorithm.hpp"

namespace SortLibrary {

TEST(TestSorting, TestBubbleSort)
{
    std::vector<double> v = {9.2, 13.3, 5.1, 10.2, 1.0, 7.3, 9.6, 4.0, 6.13, 11.7};
    BubbleSort<double>(v);
    std::vector<double> sortedV = {1.0, 4.0, 5.1, 6.13, 7.3, 9.2, 9.6, 10.2, 11.7 ,13.3};
    ASSERT_EQ(v, sortedV);
}

TEST(TestSorting, TestHeapSort)
{
    std::vector<int> v = {9, 13, 5, 10, 1, 7, 9, 4, 6, 12};
    HeapSort<int>(v);
    std::vector<int> sortedV = {1, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    ASSERT_EQ(v, sortedV);
}

}
