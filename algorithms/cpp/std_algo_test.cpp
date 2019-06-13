#include <random>

//
// Created by syue on 19-6-13.
//

#include "gmock/gmock.h"
#include "glog/logging.h"
#include <algorithm>
#include <boost/range.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/fusion/algorithm/transformation/push_back.hpp>
#include <boost/fusion/include/push_back.hpp>

using namespace std;
using namespace boost;
TEST(fill, test)
{
    vector<int> v;
    auto i = boost::irange(1,10);
//    copy(v.begin(), v.end(),i.begin());
//    random_shuffle(i.begin(),i.end(), std::mt19937(std::random_device()()));
//    cout << i;

}
