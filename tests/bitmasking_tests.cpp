#include <catch2/catch.hpp>

#include <bitset>
#include <vector>
#include <unordered_set>

#include "assignment/bits.hpp"

using Catch::Contains;

using assignment::is_bit_set;
using assignment::mask2elems;
using assignment::mask2indices;
using assignment::set_bit;

constexpr static int kMaxNumBits = 29;

TEST_CASE("Bits::IsBitSet") {

  const int mask = GENERATE_REF(range(0, kMaxNumBits), 1 << kMaxNumBits);
  std::bitset<kMaxNumBits + 1> bitset(mask);

  for (int pos = 0; pos <= kMaxNumBits; pos++) {
    if (bitset[pos]) {
      REQUIRE(is_bit_set(mask, pos));
    }
  }
}

TEST_CASE("Bits::SetBit") {

  int mask = GENERATE_REF(range(0, kMaxNumBits), 1 << kMaxNumBits);
  auto bitset = std::bitset<kMaxNumBits + 1>(mask);

  for (int pos = 0; pos <= kMaxNumBits; pos++) {
    bitset.set(pos);
    mask = set_bit(mask, pos);

    REQUIRE(std::bitset<kMaxNumBits + 1>(mask) == bitset);
  }
}

TEST_CASE("Bits::Mask2Indices") {

  const auto items = std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int mask = GENERATE_REF(range(0, 1 << items.size()));
  auto bitset = std::bitset<kMaxNumBits + 1>(mask);

  const auto masked_items = mask2indices(items, mask);
  const auto masked_items_set = std::unordered_set<int>(masked_items.begin(), masked_items.end());

  REQUIRE(masked_items.size() == bitset.count());

  for (int pos = 0; pos < static_cast<int>(items.size()); pos++) {

    if (mask == 0) {
      REQUIRE(masked_items.empty());
    }

    if (bitset[pos]) {
      REQUIRE(masked_items_set.count(items[pos]) == 1);
    }
  }
}

TEST_CASE("Bits::Mask2Elems") {

  const auto items = std::vector<int>{0, 1, 2, 3, 4, 5, 5, 6, 7, 8, 9};

  int mask = GENERATE_REF(range(0, 1 << items.size()));
  auto bitset = std::bitset<kMaxNumBits + 1>(mask);

  const auto masked_items = mask2elems(items, mask);
  const auto masked_items_set = std::unordered_set<int>(masked_items.begin(), masked_items.end());

  REQUIRE(masked_items.size() == bitset.count());

  for (int pos = 0; pos < static_cast<int>(items.size()); pos++) {

    if (mask == 0) {
      REQUIRE(masked_items.empty());
    }

    if (bitset[pos]) {
      REQUIRE(masked_items_set.count(items[pos]) == 1);
    }
  }
}