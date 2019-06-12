#include <vector>
#include <map>
#include <unordered_map>
#include <chrono>
#include "gmock/gmock.h"

using namespace std;

#include "twoSum.hpp"
#include <memory>

class Num{
public:
    int num{};
};

//TEST(twoSumtmp, test)
//{
//    vector<int> v;
//
//    unordered_map<(int, int> m;
//    Num n1 = Num();
//    Num n2 = Num();
//    m[n1] = 11;
//    m[n2] = 22;
////    if(auto it = m.find(n1) != m.end())
////    {
//////        std::cout << it.num;
////        std::cout << " find" <<endl;
////    }else
////        std::cout << "not find" <<endl;
//}

TEST(twoSumtmp, Solution)
{
    vector<int> num{2, 7, 11, 15};
    int target = 9;
    auto result = twoSum(num.begin(), num.end(), target);

    ASSERT_EQ(result.first, num.begin());
    ASSERT_EQ(result.second, num.begin()+1);

    target = 18;
    result = twoSum(num.begin(), num.end(), target);
    ASSERT_EQ(result.first, num.begin()+1);
    ASSERT_EQ(result.first, num.begin()+1);

    target = 22;
    result = twoSum(num.begin(), num.end(), target);
    ASSERT_EQ(result.first, num.begin() + 1);
    ASSERT_EQ(result.second, num.begin() + 3);

    target = 23;
    result = twoSum(num.begin(), num.end(), target);
    ASSERT_EQ(result.first, num.end());
    ASSERT_EQ(result.second, num.end());
}

TEST(twoSumtmp, time)
{
    vector<int> num(100);
    auto target = 23;
    auto start = chrono::system_clock::now();
    auto result = twoSum(num.begin(), num.end(), target);
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end-start);
    cout << duration.count() <<std::endl;
    ASSERT_EQ(result.first, num.end());
    ASSERT_EQ(result.second, num.end());
}