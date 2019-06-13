//
// Created by syue on 19-6-13.
//

template <typename InputIteraor, typename T>
void fill(InputIteraor first, InputIteraor last, T val)
{
    for (; first != last; ++first) {
      *first = val;
    }
}
