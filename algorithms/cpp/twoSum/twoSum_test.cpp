#include <vector>
#include <map>
#include <unordered_map>
#include "gmock/gmock.h"

using namespace std;

#include "twoSum.cpp"


TEST(twoSum, Solution)
{
    vector<int> num{2, 7, 11, 15};
    int target = 9;
    Solution solution;
    auto result = solution.twoSum(num, target);

    ASSERT_EQ(result[0], 0);
    ASSERT_EQ(result[1], 1);

    target = 18;
    result = solution.twoSum(num, target);

    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 2);

    target = 22;
    result = solution.twoSum(num, target);

    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 3);
}