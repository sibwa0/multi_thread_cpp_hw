#include <iostream>

#include "raii_action.hpp"
#include "utils.hpp"


int main()
{
    {
        Resource someResource;

        auto lambda1 = [&someResource](int x) {
            return some_free(someResource, x);
        };

        auto lambda2 = [&someResource](int y) {
            return some_free(someResource, y);
        };

        RAIIAction<std::function<int()>> cleanup_1(std::bind(lambda1, 1));

        // RAIIAction<int> cleanup_2(std::bind(lambda2, 2));

        // operator=() copy
        // cleanup_1 = cleanup_2;

        // std::cout << cleanup_1 << std::endl;

        // std::cout << cleanup_1 << std::endl;
    }

    return 0;
}