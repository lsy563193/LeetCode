// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Hao Chen
// Date   : 2014-06-17

/*********************************************************************************
* 
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=0, index2=1
* 
*               
**********************************************************************************/

/*
 *   The easy solution is O(n^2) run-time complexity.
 *   ```
 *       foreach(item1 in array) {
 *           foreach(item2 in array){
 *               if (item1 + item2 == target) {
 *                   return result
 *               }
 *           }
 *   ```
 *
 *   We can see the nested loop just for searching,
 *   So, we can use a hashmap to reduce the searching time complexity from O(n) to O(1)
 *   (the map's `key` is the number, the `value` is the position)
 *
 *   But be careful, if there are duplication numbers in array,
 *   how the map store the positions for all of same numbers?
 *
 */


//
// The implementation as below is bit tricky. but not difficult to understand
//
//  1) Traverse the array one by one
//  2) just put the `target - num[i]`(not `num[i]`) into the map
//     so, when we checking the next num[i], if we found it is exisited in the map.
//     which means we found the second one.
//
//  l,r = v[l] + v[r] =  target;
//easy solution
/*
template <typename InputIterator, typename T>
std::pair<InputIterator, InputIterator>
twoSum(InputIterator first, InputIterator last, T target) {
    for (; first != last; ++first) {
        for (auto r = next(first); r != last; ++r) {
            if (*first + *r == target)
                return {first, r};
        }
    }
    return {last, last};
}*/
//better
//template <typename InputIterator, typename T>
//std::pair<InputIterator, InputIterator>
//twoSum(InputIterator first, InputIterator last, T target) {
//    unordered_map<InputIterator, T> m;
//    for (; first != last; ++first) {
//        if(auto it = m.find(target - *first) != m.end())
//            return {first, first};
//        else{
//            m[*first] = target - *first;
//        }
//    }
//    return {last, last};
//}

template<typename InputIterator, typename T>
std::pair<InputIterator, InputIterator>
twoSum(InputIterator first, InputIterator last, T target) {
    unordered_map<T, InputIterator> m;
    for (;first != last; ++first) {
        if (m.find(target - *first) == m.end())
            m[*first] = first;
        else
            return {m[target-*first], first};
    }
    return {last, last};
}
