#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "../my_sort.hpp"
#include "../point.hpp"


int main()
{
    auto compInt = [](int a, int b)
    {
        return a < b;
    };

    auto compPoint = [](Point a, Point b)
    {
        return a.x * a.x + a.y * a.y
             < b.x * b.x + b.y * b.y;
    };


    std::vector<int> sizes = {
        1000,
        10000,
        100000,
        1000000
    };

    std::mt19937 gen(42);
    std::uniform_int_distribution<int> distInt(-1000000, 1000000);
    std::uniform_int_distribution<int> distPoint(-1000, 1000);


    std::cout << "INT BENCHMARK\n";

    for (int n : sizes)
    {
        std::vector<int> original(n);

        for (int i = 0; i < n; i++)
        {
            original[i] = distInt(gen);
        }

        std::vector<int> myData = original;
        std::vector<int> stdData = original;


        auto startMy = std::chrono::steady_clock::now();

        mySort(
            myData,
            0,
            static_cast<int>(myData.size()) - 1,
            compInt
        );

        auto finishMy = std::chrono::steady_clock::now();


        auto startStd = std::chrono::steady_clock::now();

        std::sort(
            stdData.begin(),
            stdData.end(),
            compInt
        );

        auto finishStd = std::chrono::steady_clock::now();


        double myTime =
            std::chrono::duration<double, std::milli>(
                finishMy - startMy
            ).count();

        double stdTime =
            std::chrono::duration<double, std::milli>(
                finishStd - startStd
            ).count();


        std::cout
            << "n = " << n
            << " | quicksort = " << myTime << " ms"
            << " | std::sort = " << stdTime << " ms"
            << " | ratio = " << myTime / stdTime
            << '\n';
    }


    std::cout << "\nPOINT BENCHMARK\n";

    for (int n : sizes)
    {
        std::vector<Point> original(n);

        for (int i = 0; i < n; i++)
        {
            original[i].x = distPoint(gen);
            original[i].y = distPoint(gen);
        }

        std::vector<Point> myData = original;
        std::vector<Point> stdData = original;


        auto startMy = std::chrono::steady_clock::now();

        mySort(
            myData,
            0,
            static_cast<int>(myData.size()) - 1,
            compPoint
        );

        auto finishMy = std::chrono::steady_clock::now();


        auto startStd = std::chrono::steady_clock::now();

        std::sort(
            stdData.begin(),
            stdData.end(),
            compPoint
        );

        auto finishStd = std::chrono::steady_clock::now();


        double myTime =
            std::chrono::duration<double, std::milli>(
                finishMy - startMy
            ).count();

        double stdTime =
            std::chrono::duration<double, std::milli>(
                finishStd - startStd
            ).count();


        std::cout
            << "n = " << n
            << " | quicksort = " << myTime << " ms"
            << " | std::sort = " << stdTime << " ms"
            << " | ratio = " << myTime / stdTime
            << '\n';
    }


    std::cout << "\nSORTED INT BENCHMARK\n";

    {
        int n = 100000;

        std::vector<int> sortedData(n);

        for (int i = 0; i < n; i++)
        {
            sortedData[i] = i;
        }

        auto start = std::chrono::steady_clock::now();

        mySort(
            sortedData,
            0,
            static_cast<int>(sortedData.size()) - 1,
            compInt
        );

        auto finish = std::chrono::steady_clock::now();

        double time =
            std::chrono::duration<double, std::milli>(
                finish - start
            ).count();

        std::cout
            << "n = " << n
            << " | sorted quicksort = "
            << time << " ms\n";
    }


    return 0;
}