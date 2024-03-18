#include <algorithm>
#include <vector>
#include <cassert>
#include <iostream>

void printPoints(std::vector<std::vector<int>>& points) 
{
    for (auto entry: points) {
        std::cout << "[" << entry[0] << ", " << entry[1] << "]" << '\n';
    }
}

int findMinArrowShots(std::vector<std::vector<int>>& points) 
{
    std::sort(points.begin(), points.end(), 
              [](auto& lhs, auto& rhs) { return lhs[1] < rhs[1];});
    
    int hit = points[0][1];
    int counter = 1;
    for (int i = 1; i < points.size(); ++i) {
        if (hit < points[i][0]) {
            ++counter;
            hit = points[i][1];
        }
    }

    return counter;
}

int main()
{
    // 452. Minimum Number of Arrows to Burst Balloons

    {
        std::vector<std::vector<int>> points = {
            {10,16}, {2,8}, {1,6}, {7,12}
        };
        assert(findMinArrowShots(points) == 2);
    }

    {
        std::vector<std::vector<int>> points = {
            {1,2},{3,4},{5,6},{7,8}
        };
        assert(findMinArrowShots(points) == 4);
    }

    {
        std::vector<std::vector<int>> points = {
            {1,2},{2,3},{3,4},{4,5},{6,10}, {7,9}
        };
        assert(findMinArrowShots(points) == 3);
    }

    return 0;
}