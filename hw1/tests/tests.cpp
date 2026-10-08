#include <cassert>
#include <vector>

#include "../my_sort.hpp"
#include "../point.hpp"

int main()
{
    // ТЕСТЫ ДЛЯ INT
    auto comp = [](int a, int b)
    {
        return a < b;
    };

    // 1. Обычный массив
    {
        std::vector<int> a = {7, 2, 9, 1, 5};

        quicksort(a, 0, a.size() - 1, comp);

        assert(a[0] == 1);
        assert(a[1] == 2);
        assert(a[2] == 5);
        assert(a[3] == 7);
        assert(a[4] == 9);
    }

    // 2. Один элемент
    {
        std::vector<int> a = {5};

        quicksort(a, 0, a.size() - 1, comp);

        assert(a[0] == 5);
    }

    // 3. Уже отсортированный
    {
        std::vector<int> a = {1, 2, 3, 4, 5};

        quicksort(a, 0, a.size() - 1, comp);

        assert(a[0] == 1);
        assert(a[1] == 2);
        assert(a[2] == 3);
        assert(a[3] == 4);
        assert(a[4] == 5);
    }

    // 4. Обратный порядок
    {
        std::vector<int> a = {5, 4, 3, 2, 1};

        quicksort(a, 0, a.size() - 1, comp);

        assert(a[0] == 1);
        assert(a[1] == 2);
        assert(a[2] == 3);
        assert(a[3] == 4);
        assert(a[4] == 5);
    }
    
    // 5. Пустой массив
    {
        std::vector<int> a = {};
        quicksort(a, 0 , a.size() - 1, comp);
        assert(a.empty());

    }

    // ТЕСТЫ ДЛЯ POINT
    auto compPoint = [](Point a, Point b)
    {
        return a.x * a.x + a.y * a.y
            < b.x * b.x + b.y * b.y;
    };
    
    // Пустой вектор
    {
        std::vector<Point> points = {};

        quicksort(
            points,
            0,
            static_cast<int>(points.size()) - 1,
            compPoint
        );

        assert(points.empty());
    }

    // Один элемент
    {
        std::vector<Point> points = {
            {3, 4}
        };

        quicksort(
            points,
            0,
            static_cast<int>(points.size()) - 1,
            compPoint
        );

        assert(points[0].x == 3);
        assert(points[0].y == 4);
    }

    // Уже отсортированный вектор
    {
        std::vector<Point> points = {
            {1, 0},
            {1, 1},
            {0, 2},
            {3, 4}
        };

        quicksort(
            points,
            0,
            static_cast<int>(points.size()) - 1,
            compPoint
        );

        assert(points[0].x == 1 && points[0].y == 0);
        assert(points[1].x == 1 && points[1].y == 1);
        assert(points[2].x == 0 && points[2].y == 2);
        assert(points[3].x == 3 && points[3].y == 4);
    }

    // Обратный порядок
    {
        std::vector<Point> points = {
            {3, 4},
            {0, 2},
            {1, 1},
            {1, 0}
        };

        quicksort(
            points,
            0,
            static_cast<int>(points.size()) - 1,
            compPoint
        );

        assert(points[0].x == 1 && points[0].y == 0);
        assert(points[1].x == 1 && points[1].y == 1);
        assert(points[2].x == 0 && points[2].y == 2);
        assert(points[3].x == 3 && points[3].y == 4);
    }

    return 0;
    
    
}