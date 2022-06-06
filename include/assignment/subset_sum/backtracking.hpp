#pragma once

#include "assignment/private/subset_sum.hpp"

namespace assignment {

  struct SubsetSumBacktracking : SubsetSumStrategy {

    /**
     * Поиск всех возможных подмножеств множества, сумма элементов которых равна целевой (рекурсивно).
     *
     * Используется метод поиска с возвратом с ограничением по сумме элементов.
     *
     * @param set - множество из положительных целочисленных элементов
     * @param target_sum - значение целевой суммы (положительное)
     * @return все возможные подмножества множества с суммой элементов = target_sum
     */
    [[nodiscard]] std::vector<std::vector<int>> search(const std::vector<int> &set, int target_sum) const override;

   private:
    /**
     * Вспомогательный метод поиска подмножеств.
     *
     * Ведется рекурсивный поиск решений с ограничениями:
     * 1. Сумма рассматриваемых элементов должна быть не больше целевой.
     * 2. Остатка суммы от нерассмотренных элементов должно быть достаточно, чтобы получить целевую сумму.
     *
     * @param set - множество из положительных целочисленных элементов
     * @param index - индекс рассматриваемого элемента множества (изначально -1)
     * @param mask - характеристическая маска элементов рассматриваемого подмножества
     * @param sum - сумма рассматриваемого подмножества
     * @param residual - разница между максимально возможной и текущей суммами (остаток суммы)
     * @param target_sum - значение целевой суммы (положительное)
     * @param indices - все подмножества с суммой = target_sum (результат)
     */
    void search(const std::vector<int> &set, int index, int mask, int sum, int residual, int target_sum,
                std::vector<std::vector<int>> &indices) const;
  };

}  // namespace assignment