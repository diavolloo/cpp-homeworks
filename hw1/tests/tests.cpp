#include <cassert>
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "../my_sort.hpp"
#include "../point.hpp"

bool samePoints(std::vector<Point> a, std::vector<Point> b)
{
    if (a.size() != b.size())
        return false;

    auto compXY = [](Point p1, Point p2)
    {
        if (p1.x != p2.x)
            return p1.x < p2.x;

        return p1.y < p2.y;
    };

    std::sort(a.begin(), a.end(), compXY);
    std::sort(b.begin(), b.end(), compXY);

    for (int i = 0; i < static_cast<int>(a.size()); i++)
    {
        if (a[i].x != b[i].x || a[i].y != b[i].y)
            return false;
    }

    return true;
}

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


    // Пустой vector<int>
    {
        std::vector<int> a = {};

        mySort(
            a,
            0,
            static_cast<int>(a.size()) - 1,
            compInt
        );

        assert(a.empty());
    }


    // Один элемент int
    {
        std::vector<int> a = {5};
        std::vector<int> expected = a;

        std::sort(expected.begin(), expected.end(), compInt);

        mySort(
            a,
            0,
            static_cast<int>(a.size()) - 1,
            compInt
        );

        assert(std::is_sorted(a.begin(), a.end(), compInt));
        assert(a == expected);
    }


    // Уже отсортированный int
    {
        std::vector<int> a = {1, 2, 3, 4, 5};
        std::vector<int> expected = a;

        std::sort(expected.begin(), expected.end(), compInt);

        mySort(
            a,
            0,
            static_cast<int>(a.size()) - 1,
            compInt
        );

        assert(std::is_sorted(a.begin(), a.end(), compInt));
        assert(a == expected);
    }


    // int в обратном порядке
    {
        std::vector<int> a = {5, 4, 3, 2, 1};
        std::vector<int> expected = a;

        std::sort(expected.begin(), expected.end(), compInt);

        mySort(
            a,
            0,
            static_cast<int>(a.size()) - 1,
            compInt
        );

        assert(std::is_sorted(a.begin(), a.end(), compInt));
        assert(a == expected);
    }


    // Все int равны
    {
        std::vector<int> a = {7, 7, 7, 7, 7};
        std::vector<int> expected = a;

        std::sort(expected.begin(), expected.end(), compInt);

        mySort(
            a,
            0,
            static_cast<int>(a.size()) - 1,
            compInt
        );

        assert(std::is_sorted(a.begin(), a.end(), compInt));
        assert(a == expected);
    }


    // int с отрицательными числами
    {
        std::vector<int> a = {-5, 3, -10, 0, 8, -2};
        std::vector<int> expected = a;

        std::sort(expected.begin(), expected.end(), compInt);

        mySort(
            a,
            0,
            static_cast<int>(a.size()) - 1,
            compInt
        );

        assert(std::is_sorted(a.begin(), a.end(), compInt));
        assert(a == expected);
    }


    // int с повторяющимися значениями
    {
        std::vector<int> a = {5, 2, 5, 1, 2, 5, 1, 3};
        std::vector<int> expected = a;

        std::sort(expected.begin(), expected.end(), compInt);

        mySort(
            a,
            0,
            static_cast<int>(a.size()) - 1,
            compInt
        );

        assert(std::is_sorted(a.begin(), a.end(), compInt));
        assert(a == expected);
    }


    // Случайные int размеров 10, 1000, 100000
    {
        std::vector<int> sizes = {10, 1000, 100000};

        std::mt19937 gen(42);
        std::uniform_int_distribution<int> dist(-100000, 100000);

        for (int n : sizes)
        {
            std::vector<int> a(n);

            for (int i = 0; i < n; i++)
                a[i] = dist(gen);

            std::vector<int> expected = a;

            std::sort(expected.begin(), expected.end(), compInt);

            mySort(
                a,
                0,
                static_cast<int>(a.size()) - 1,
                compInt
            );

            assert(std::is_sorted(a.begin(), a.end(), compInt));
            assert(a == expected);
        }
    }


    // Пустой vector<Point>
    {
        std::vector<Point> points = {};

        mySort(
            points,
            0,
            static_cast<int>(points.size()) - 1,
            compPoint
        );

        assert(points.empty());
    }


    // Один Point
    {
        std::vector<Point> points = {
            {3, 4}
        };

        std::vector<Point> expected = points;

        std::sort(expected.begin(), expected.end(), compPoint);

        mySort(
            points,
            0,
            static_cast<int>(points.size()) - 1,
            compPoint
        );

        assert(std::is_sorted(
            points.begin(),
            points.end(),
            compPoint
        ));

        assert(points[0].x == expected[0].x);
        assert(points[0].y == expected[0].y);
    }


    // Уже отсортированные Point
    {
        std::vector<Point> points = {
            {1, 0},
            {1, 1},
            {0, 2},
            {3, 4}
        };

        std::vector<Point> expected = points;

        std::sort(expected.begin(), expected.end(), compPoint);

        mySort(
            points,
            0,
            static_cast<int>(points.size()) - 1,
            compPoint
        );

        assert(std::is_sorted(
            points.begin(),
            points.end(),
            compPoint
        ));

        for (int i = 0; i < static_cast<int>(points.size()); i++)
        {
            assert(points[i].x == expected[i].x);
            assert(points[i].y == expected[i].y);
        }
    }


    // Point в обратном порядке
    {
        std::vector<Point> points = {
            {3, 4},
            {0, 2},
            {1, 1},
            {1, 0}
        };

        std::vector<Point> expected = points;

        std::sort(expected.begin(), expected.end(), compPoint);

        mySort(
            points,
            0,
            static_cast<int>(points.size()) - 1,
            compPoint
        );

        assert(std::is_sorted(
            points.begin(),
            points.end(),
            compPoint
        ));

        for (int i = 0; i < static_cast<int>(points.size()); i++)
        {
            assert(points[i].x == expected[i].x);
            assert(points[i].y == expected[i].y);
        }
    }


    // Все Point одинаковые
    {
        std::vector<Point> points = {
            {3, 4},
            {3, 4},
            {3, 4},
            {3, 4}
        };

        std::vector<Point> expected = points;

        std::sort(expected.begin(), expected.end(), compPoint);

        mySort(
            points,
            0,
            static_cast<int>(points.size()) - 1,
            compPoint
        );

        assert(std::is_sorted(
            points.begin(),
            points.end(),
            compPoint
        ));

        for (int i = 0; i < static_cast<int>(points.size()); i++)
        {
            assert(points[i].x == expected[i].x);
            assert(points[i].y == expected[i].y);
        }
    }


    // Point с отрицательными координатами
    {
        std::vector<Point> points = {
            {-3, -4},
            {-1, 0},
            {0, -2},
            {-2, -2}
        };

        std::vector<Point> expected = points;

        std::sort(expected.begin(), expected.end(), compPoint);

        mySort(
            points,
            0,
            static_cast<int>(points.size()) - 1,
            compPoint
        );

        assert(std::is_sorted(
            points.begin(),
            points.end(),
            compPoint
        ));

        for (int i = 0; i < static_cast<int>(points.size()); i++)
        {
            assert(points[i].x == expected[i].x);
            assert(points[i].y == expected[i].y);
        }
    }


    // Point с повторяющимися значениями
    {
        std::vector<Point> points = {
            {3, 4},
            {1, 0},
            {3, 4},
            {0, 2},
            {1, 0},
            {2, 2}
        };

        std::vector<Point> expected = points;

        std::sort(expected.begin(), expected.end(), compPoint);

        mySort(
            points,
            0,
            static_cast<int>(points.size()) - 1,
            compPoint
        );

        assert(std::is_sorted(
            points.begin(),
            points.end(),
            compPoint
        ));

        for (int i = 0; i < static_cast<int>(points.size()); i++)
        {
            assert(points[i].x == expected[i].x);
            assert(points[i].y == expected[i].y);
        }
    }
    // Случайные Point размеров 10, 1000, 100000
    {
        std::vector<int> sizes = {10, 1000, 100000};

        std::mt19937 gen(42);
        std::uniform_int_distribution<int> dist(-1000, 1000);

        for (int n : sizes)
        {
            std::vector<Point> points(n);

            for (int i = 0; i < n; i++)
            {
                points[i].x = dist(gen);
                points[i].y = dist(gen);
            }

            std::vector<Point> original = points;

            mySort(
                points,
                0,
                static_cast<int>(points.size()) - 1,
                compPoint
            );

            assert(std::is_sorted(
                points.begin(),
                points.end(),
                compPoint
            ));

            assert(samePoints(points, original));
        }
    }
    std::cout << "Good!\n";

    return 0;
}