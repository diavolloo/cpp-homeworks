#include <iostream>
#include <vector>
#include "my_sort.hpp"
#include "point.hpp"

int main()
{
    std::vector<int> a = {7, 2, 9, 1, 5};

    auto compInt = [](int x, int y)
    {
        return x < y;
    };

    mySort(a, 0, a.size() - 1, compInt);

    for (int x : a)
        std::cout << x << " ";
    std::cout <<"\n";
    
    std::vector<Point> points = {
        {0, 5},
        {3, 5},
        {1, 2}
    };
    auto compPoint = [](Point a, Point b)
    {
        return a.x * a.x + a.y * a.y 
        < b.x * b.x + b.y * b.y;
    
    };
    
    mySort(points, 0, points.size() - 1, compPoint);
    
    for (Point p : points)
    {
        std::cout << p.x << " " << p.y << ", ";
    };
    
    return 0;


}