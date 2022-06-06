#pragma once

#include "assignment/private/subset_sum.hpp"

namespace assignment {

  struct SubsetSumBitMasking : SubsetSumStrategy {

    /**
     * Поиск всех возможных подмножеств множества, сумма элементов которых равна целевой (итеративно).
     *
     * Используются битовые маски для перебора всех потенциальных решений.
     *
     * @param set - множество из положительных целочисленных элементов
     * @param target_sum - значение целевой суммы (положительное)
     * @return все возможные подмножества множества с суммой элементов = target_sum
     */
    [[nodiscard]] std::vector<std::vector<int>> search(const std::vector<int>& set, int target_sum) const override;
  };

}  // namespace assignment