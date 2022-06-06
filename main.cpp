#include <iostream>  // cout
#include <numeric>   // iota

#include "assignment/subsets.hpp"

using assignment::brute_force_backtracking_subsets;
using assignment::brute_force_bit_masking_subsets;
using assignment::pretty_print;

int main() {

  // мощность множество
  const int power = 3;

  // [0, 0, ...] - num_elems нулей раз
  auto set = std::vector<int>(power);

  // заполнение элементов вектора [0,1,2,...]
  iota(set.begin(), set.end(), 0);

  std::vector<std::vector<int>> subsets;  // 2^N
  brute_force_backtracking_subsets(set, -1, 0, subsets);

  pretty_print(subsets, std::cout);

  return 0;
}
