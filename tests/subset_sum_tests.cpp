#include <catch2/catch.hpp>

#include <algorithm>  // shuffle
#include <random>     // mt19937
#include <numeric>    // iota
#include <vector>
#include <bitset>

#include "assignment/subset_sum/bit_masking.hpp"
#include "assignment/subset_sum/backtracking.hpp"

using assignment::SubsetSumBacktracking;
using assignment::SubsetSumBitMasking;
using assignment::SubsetSumStrategy;

constexpr static int kMaxNumBits = 32;

static int sum_of(const std::vector<int>& set, const std::vector<int>& indices) {
  return std::accumulate(indices.begin(), indices.end(), 0, [&set](int sum, int index) { return sum + set[index]; });
}

static void check_helper(const SubsetSumStrategy& strategy) {

  static auto engine = std::mt19937(std::random_device{}());

  const int size = GENERATE(range(0, 10));

  auto set = std::vector<int>(size);
  std::iota(set.begin(), set.end(), 1);
  std::shuffle(set.begin(), set.end(), engine);

  std::bitset<kMaxNumBits> bit_mask;

  // brute-force each of the combinations of numbers in the set
  for (int curr_mask = 1; curr_mask < (1 << size); curr_mask++) {  // 2^N

    // update the bitset
    bit_mask = curr_mask;

    // compute the indices included in the sum
    std::vector<int> indices;
    indices.reserve(bit_mask.count());

    int expected_sum = 0;

    for (int pos = 0; pos < size; ++pos) {  // N
      if (bit_mask[pos]) {
        expected_sum += set[pos];
        indices.push_back(pos);
      }
    }

    CAPTURE(set, indices, expected_sum);

    const auto found_indices = strategy.search(set, expected_sum);

    REQUIRE_FALSE(found_indices.empty());

    for (const auto& ids : found_indices) {
      CHECK(sum_of(set, ids) == expected_sum);
    }
  }
}

TEST_CASE("SubSetSum::BitMasking") {
  check_helper(SubsetSumBitMasking{});
}

TEST_CASE("SubSetSum::Backtracking") {
  check_helper(SubsetSumBacktracking{});
}
