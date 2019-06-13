//
// Created by cuisan on 2019/6/12.
//

/**********************************************************************************
*
* Sort a linked list using insertion sort.
*
**********************************************************************************/

#include <vector>
#include <iostream>
#include <iterator>
#include <gmock/gmock.h>
#include <deque>
#include <list>
#include "boost/range/algorithm.hpp"

using namespace std;
using namespace boost;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *head) {
    // zero or one element in list
    if (head == NULL || head->next ==NULL){
        return head;
    }

    ListNode *pSorted = NULL;
    while ( head != NULL  ){
        /* remember the head */
        ListNode *pHead = head;
        /* trailing pointer for efficient splice */
        ListNode **ppTrail = &pSorted;

        /* pop head off list */
        head = head->next;

        /* splice head into sorted list at proper place */
        while( *ppTrail!=NULL && pHead->val > (*ppTrail)->val )  {
            ppTrail = &(*ppTrail)->next;
        }
        pHead->next = *ppTrail;
        *ppTrail = pHead;
    }

    return pSorted;
}

ListNode* createList(int a[], int n)
{
    ListNode *head=NULL, *p=NULL;
    for(int i=0; i<n; i++){
        if (head == NULL){
            head = p = new ListNode(a[i]);
        }else{
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}
//vector<int> v{1,2,8,4,5,8};
template <typename InputIterator>
void select_sort(InputIterator first, InputIterator last){
    for(;first !=last; ++first)
        swap(*first, *min_element(first, last));
}

template<class RandomAccessRange>
inline RandomAccessRange& select_sort(RandomAccessRange& rng)
{
    select_sort(boost::begin(rng), boost::end(rng));
    return rng;
}
template <typename InputIterator>
void insert_sort(InputIterator first, InputIterator last){
    list<int> l;
    auto tmp = first;
    for(; first != last; ++first)
        l.insert(lower_bound(l,*first),*first);
    copy(l, tmp);
}
template<class RandomAccessRange>
inline RandomAccessRange& insert_sort(RandomAccessRange& rng)
{
//    insert_sort(boost::begin(rng), boost::end(rng));
    list<int> l;
    for_each(rng,[&](auto& first){
        return l.insert(lower_bound(l,*first),*first);
    });
    return rng;
}

TEST(select_sort, test1)
{
    deque<int> v{1,2,1,8,4,10,5,8};
    select_sort(v);
    ASSERT_THAT(v,testing::ContainerEq(deque<int>{1,1,2,4,5,8,8,10}));
}
TEST(insertion, test1)
{
    deque<int> v{1,2,1,8,4,10,5,8};
    insert_sort(v);
    ASSERT_THAT(v,testing::ContainerEq(deque<int>{1,1,2,4,5,8,8,10}));

//    delete[] a;
}