#include <vector>
#include <map>
#include <unordered_map>
#include <chrono>
#include "gmock/gmock.h"

using namespace std;

#include "twoSum.cpp"


TEST(twoSum, Solution)
{
    vector<int> num{2, 7, 11, 15};
    int target = 9;
    Solution solution;
    auto result = solution.twoSum(num, target);

    ASSERT_EQ(result.size(), 2);
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

    target = 23;
    result = solution.twoSum(num, target);
    ASSERT_EQ(result.size(), 0);
//    ASSERT_EQ(result[0], 1);
//    ASSERT_EQ(result[1], 3);
}

TEST(twoSum, time)
{
    vector<int> num(20000);
    Solution solution;
    auto target = 23;
    auto start = chrono::system_clock::now();
    auto result = solution.twoSum(num, target);
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end-start);
    cout << duration.count() <<std::endl;
    ASSERT_EQ(result.size(), 0);
}