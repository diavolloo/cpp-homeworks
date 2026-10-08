#include <iostream>
#include <vector>
#include <chrono>
#include <random>

#include "../my_sort.hpp"

int main()
{
    auto comp = [](int a, int b)
    {
        return a < b;
    };

    std::vector<int> sizes = {
        1000,
        10000,
        100000,
        1000000
    };

    for (int n : sizes)
    {
        std::vector<int> a(n);

        std::mt19937 gen(42);
        std::uniform_int_distribution<int> dist(0, 1000000);

        for (int i = 0; i < n; i++)
        {
            a[i] = dist(gen);
        }

        auto start = std::chrono::steady_clock::now();

        quicksort(
            a,
            0,
            static_cast<int>(a.size()) - 1,
            comp
        );

        auto finish = std::chrono::steady_clock::now();

        auto time = std::chrono::duration<double, std::milli>(
            finish - start
        );

        std::cout
            << "n = " << n
            << ", time = " << time.count()
            << " ms\n";
    }

    return 0;
}