#include <gtest/gtest.h>
#include "raii_action.hpp"
#include "utils.hpp"
#include <sstream>


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
    auto lambda2 = [&someResource](int x) {
        return some_free(someResource, x);
    };

    RAIIAction<std::function<int()>> sample1(
        std::bind(lambda1, 1)
    );
    RAIIAction<std::function<int()>> sample2(
        std::bind(lambda2, 2)
    );

    sample1 = sample2;

    std::ostringstream oss;
    oss << sample1 << sample2;
    EXPECT_EQ(oss.str(), "22");
}
