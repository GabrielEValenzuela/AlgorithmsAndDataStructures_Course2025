#include "wrapperVector.hpp"
#include <gtest/gtest.h>

TEST(WrapperVectorTest, PushBackAndAccess)
{
    wrapperVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);

    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);
}

TEST(WrapperVectorTest, ResizeCorrectly)
{
    wrapperVector<int> vec;
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 0);
    for (int i = 0; i < 200; ++i) vec.push_back(i);

    EXPECT_EQ(vec.capacity(), 200);
    EXPECT_EQ(vec.size(), 200);
    EXPECT_EQ(vec[199], 199);
}

TEST(WrapperVectorTest, SwapWorks)
{
    wrapperVector<std::string> a;
    wrapperVector<std::string> b;

    a.push_back("foo");
    b.push_back("bar");

    a.swap(b);

    EXPECT_EQ(a[0], "bar");
    EXPECT_EQ(b[0], "foo");
}

TEST(WrapperVectorTest, ConstAccessAt)
{
    wrapperVector<int> vec;
    vec.push_back(42);
    const auto& ref = vec;
    EXPECT_EQ(ref.at(0), 42);
}
