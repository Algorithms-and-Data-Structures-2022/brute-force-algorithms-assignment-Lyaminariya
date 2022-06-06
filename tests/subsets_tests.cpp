#include <catch2/catch.hpp>

#include <numeric>  // iota
#include <vector>
#include <array>

#include "assignment/subsets/bit_masking.hpp"
#include "assignment/subsets/backtracking.hpp"

using Catch::UnorderedEquals;

using assignment::SubsetsBacktracking;
using assignment::SubsetsBitMasking;
using assignment::SubsetsStrategy;

using Set = std::vector<int>;
using SubSets = std::vector<Set>;

// clang-format off

static std::array<SubSets, 5> SUBSETS = {
    SubSets{{}},
    SubSets{{}, {0}},
    SubSets{{}, {0}, {1}, {0, 1}},
    SubSets{{}, {0}, {1}, {0, 1}, {2}, {0, 2}, {1, 2}, {0, 1, 2}},
    SubSets{{}, {0}, {1}, {0, 1}, {2}, {0, 2}, {1, 2}, {0, 1, 2}, {3}, {0, 3}, {1, 3}, {0, 1, 3},
                        {2, 3}, {0, 2, 3}, {1, 2, 3}, {0, 1, 2, 3}}
};

// clang-format on

void check_helper(const SubsetsStrategy& strategy) {

  const int size = GENERATE_REF(range(0, static_cast<int>(SUBSETS.size())));
  const int num_subsets = 1 << size;

  auto set = Set(size);
  std::iota(set.begin(), set.end(), -5);

  const auto subsets = strategy.generate(set);

  REQUIRE(num_subsets == subsets.size());
  CHECK_THAT(subsets, UnorderedEquals(SUBSETS[size]));
}

TEST_CASE("Subsets::BitMasking") {
  check_helper(SubsetsBitMasking{});
}

TEST_CASE("Subsets::Backtracking") {
  check_helper(SubsetsBacktracking{});
}
