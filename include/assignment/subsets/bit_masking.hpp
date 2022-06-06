#pragma once

#include "assignment/private/subsets.hpp"

namespace assignment {

  struct SubsetsBitMasking : SubsetsStrategy {

    /**
     * Вычисление всех возможных подмножеств множества методом полного перебора (итеративно).
     *
     * Генерация возможных подмножеств при помощи битовой маски.
     *
     * @param set - множество из уникальных целочисленных элементов
     * @return список из всех возможных подмножеств множества (индексы)
     */
    [[nodiscard]] std::vector<std::vector<int>> generate(const std::vector<int>& set) const override;
  };

}  // namespace assignment