#include <gtest/gtest.h>
#include "raii_action.hpp"
#include "utils.hpp"
#include <sstream>
#include <type_traits>


TEST(TestRAIIAction, DefaultConstructor)
{
    Resource someResource;
    auto lambda1 = [&someResource](int x) {
        return some_free(someResource, x);
    };

    RAIIAction<std::function<int()>> sample(
        std::bind(lambda1, 1)
    );

    std::ostringstream oss;
    oss << sample;
    EXPECT_EQ(oss.str(), "1");
}

TEST(TestRAIIAction, CopyConstructor)
{
    Resource someResource;

    auto lambda1 = [&someResource](int x) {
        return some_free(someResource, x);
    };

    RAIIAction<std::function<int()>> sample1(
        std::bind(lambda1, 1)
    );

 	EXPECT_FALSE(std::is_copy_constructible<RAIIAction<std::function<int()>>>::value);
}

TEST(TestRAIIAction, EffectOfWrappedFunction) {
    bool isCalled = false;

    auto func = [&isCalled]() {
        isCalled = true;
    };

    {
        auto sample = RAIIAction<std::function<void()>>(std::bind(func));
    }

    EXPECT_TRUE(isCalled);
}

TEST(TestRAIIAction, CopyOperator)
{
    auto lambda1 = []() {;};
    
    auto sample1 = RAIIAction<std::function<void()>>(std::bind(lambda1));

	EXPECT_FALSE(std::is_copy_assignable<RAIIAction<std::function<int()>>>::value);
}

TEST(TestRAIIAction, MoveConstructor)
{
    auto lambda1 = []() {;};
    
    auto sample1 = RAIIAction<std::function<void()>>(std::bind(lambda1));

	EXPECT_FALSE(std::is_move_constructible<RAIIAction<std::function<int()>>>::value);
}

TEST(TestRAIIAction, MoveOperator)
{
    auto lambda1 = []() {;};
    
    auto sample1 = RAIIAction<std::function<void()>>(std::bind(lambda1));

	EXPECT_FALSE(std::is_move_assignable<RAIIAction<std::function<int()>>>::value);
}

