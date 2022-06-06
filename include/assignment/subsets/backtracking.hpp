#pragma once

#include "assignment/private/subsets.hpp"

namespace assignment {

  struct SubsetsBacktracking : SubsetsStrategy {

    /**
     * Вычисление всех возможных подмножеств множества методом поиска с возвратом (рекурсивно).
     *
     * Генерация возможных подмножеств при помощи рекурсивного спуска с возвратом (на базе ограничений).
     *
     * @param set - множество из уникальных целочисленных элементов
     * @return список из всех возможные подмножеств множества (индексы)
     */
    [[nodiscard]] std::vector<std::vector<int>> generate(const std::vector<int>& set) const override;

   private:
    /**
     * Вспомогательный метод генерации подмножеств.
     *
     * @param set - множество из уникальных целочисленных элементов
     * @param index - текущий индекс рассматриваемого элемента множества (изначально -1)
     * @param mask - текущая битовая маска входящих в подмножество элементов (изначально 0)
     * @param subsets - все возможные подмножества множества (изначально пустое)
     */
    void generate(const std::vector<int>& set, int index, int mask, std::vector<std::vector<int>>& subsets) const;
  };

}  // namespace assignment
