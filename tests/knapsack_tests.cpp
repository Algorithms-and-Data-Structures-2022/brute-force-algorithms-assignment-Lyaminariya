#include <catch2/catch.hpp>

#include <utility>  // pair
#include <vector>

#include "assignment/knapsack/bit_masking.hpp"
#include "assignment/knapsack/backtracking.hpp"

using assignment::KnapsackBacktracking;
using assignment::KnapsackBitMasking;
using assignment::KnapsackStrategy;

using Catch::Equals;

using Profits = std::vector<int>;
using Weights = std::vector<int>;
using Knapsack = std::pair<Profits, Weights>;

static const Knapsack KNAPSACK = std::make_pair(Profits{2, 3, 1, 4}, Weights{3, 4, 6, 5});

static void check_helper(const KnapsackStrategy& knapsack) {
  // 1
  auto indices = knapsack.solve(KNAPSACK.first, KNAPSACK.second, 8);

  CHECK_THAT(indices, Equals(std::vector<int>{0, 3}));

  // 2
  indices = knapsack.solve(KNAPSACK.first, KNAPSACK.second, 7);

  CHECK_THAT(indices, Equals(std::vector<int>{0, 1}));

  // 3
  indices = knapsack.solve(KNAPSACK.first, KNAPSACK.second, 6);

  CHECK_THAT(indices, Equals(std::vector<int>{3}));

  // 4
  indices = knapsack.solve(KNAPSACK.first, KNAPSACK.second, 5);

  CHECK_THAT(indices, Equals(std::vector<int>{3}));

  // 5
  indices = knapsack.solve(KNAPSACK.first, KNAPSACK.second, 4);

  CHECK_THAT(indices, Equals(std::vector<int>{1}));

  // 6
  indices = knapsack.solve(KNAPSACK.first, KNAPSACK.second, 3);

  CHECK_THAT(indices, Equals(std::vector<int>{0}));

  // 7
  indices = knapsack.solve(KNAPSACK.first, KNAPSACK.second, 2);

  CHECK(indices.empty());

  // 8
  indices = knapsack.solve(KNAPSACK.first, KNAPSACK.second, 1);

  CHECK(indices.empty());

  // 9
  indices = knapsack.solve(KNAPSACK.first, KNAPSACK.second, 9);

  CHECK_THAT(indices, Equals(std::vector<int>{1, 3}));

  // 10
  indices = knapsack.solve(KNAPSACK.first, KNAPSACK.second, 12);

  CHECK_THAT(indices, Equals(std::vector<int>{0, 1, 3}));

  // 11
  indices = knapsack.solve(KNAPSACK.first, KNAPSACK.second, 18);

  CHECK_THAT(indices, Equals(std::vector<int>{0, 1, 2, 3}));

  // 12
  indices = knapsack.solve(KNAPSACK.first, KNAPSACK.second, 20);

  CHECK_THAT(indices, Equals(std::vector<int>{0, 1, 2, 3}));
}

TEST_CASE("Knapsack::BitMasking") {
  check_helper(KnapsackBitMasking{});
}

TEST_CASE("Knapsack::Backtracking") {
  check_helper(KnapsackBacktracking{});
}