#include <catch2/catch.hpp>

#include <numeric>  // iota
#include <vector>
#include <bitset>
#include <unordered_map>

#include "assignment/subsets.hpp"  // is_bit_set, brute_force_bit_masking_subsets, brute_force_backtracking_subsets

using Catch::UnorderedEquals;

using assignment::brute_force_backtracking_subsets;
using assignment::brute_force_bit_masking_subsets;
using assignment::is_bit_set;

using Set = std::vector<int>;
using SubSets = std::vector<Set>;

// clang-format off

static std::unordered_map<int, SubSets> kSubSetsDict = {
    {0, SubSets{{}}},
    {1, SubSets{{}, {0}}},
    {2, SubSets{{}, {0}, {1}, {0, 1}}},
    {3, SubSets{{}, {0}, {1}, {0, 1}, {2}, {0, 2}, {1, 2}, {0, 1, 2}}},
    {4, SubSets{{}, {0}, {1}, {0, 1}, {2}, {0, 2}, {1, 2}, {0, 1, 2}, {3}, {0, 3}, {1, 3}, {0, 1, 3},
                        {2, 3}, {0, 2, 3}, {1, 2, 3}, {0, 1, 2, 3}}}};

// clang-format on

TEST_CASE("Subsets::IsBitSet") {

  constexpr int kMaxNumBits = 30;

  const int mask = GENERATE_REF(range(0, 16), 1 << kMaxNumBits);
  std::bitset<kMaxNumBits> bitset(mask);

  for (int pos = 0; pos < kMaxNumBits; pos++) {
    REQUIRE(bitset[pos] == is_bit_set(mask, pos));
  }
}

TEST_CASE("Subsets::BruteForceBitMasking") {

  const int size = GENERATE_REF(range(0, static_cast<int>(kSubSetsDict.size())));
  const int num_subsets = 1 << size;

  auto set = Set(size);
  std::iota(set.begin(), set.end(), 0);

  const auto subsets = brute_force_bit_masking_subsets(set);

  REQUIRE(num_subsets == subsets.size());
  CHECK_THAT(subsets, UnorderedEquals(kSubSetsDict[size]));
}

TEST_CASE("Subsets::BruteForceBacktracking") {

  const int size = GENERATE_REF(range(0, static_cast<int>(kSubSetsDict.size())));
  const int num_subsets = 1 << size;

  auto set = Set(size);
  std::iota(set.begin(), set.end(), 0);

  SubSets subsets;  // result
  brute_force_backtracking_subsets(set, -1, 0, subsets);

  REQUIRE(num_subsets == subsets.size());
  CHECK_THAT(subsets, UnorderedEquals(kSubSetsDict[size]));
}
