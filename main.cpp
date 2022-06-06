#include <iostream>  // cout
#include <ostream>
#include <vector>

#include "assignment/subsets/bit_masking.hpp"

using namespace assignment;

/**
 * Вывод в поток вывода подмножеств множества.
 *
 * @param subsets - вектор из подмножеств множества
 * @param out - поток вывода
 */
void pretty_print(const std::vector<std::vector<int>>& subsets, std::ostream& out = std::cout) {

  for (const auto& subset : subsets) {

    out << '{';

    for (int index = 0; index < static_cast<int>(subset.size()); index++) {

      out << subset[index];

      if (index != static_cast<int>(subset.size()) - 1) {
        out << ',';
      }
    }

    out << '}' << '\n';
  }
}

int main() {

  SubsetsBitMasking algo;

  const auto subsets = algo.generate({1, 5, 7, 9});

  pretty_print(subsets);

  return 0;
}
