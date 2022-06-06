#pragma once

// 1. Brute-force
// 2. Backtracking

#include <vector>
#include <ostream>

namespace assignment {

  /**
   * Проверка бита на указанной позиции маски.
   *
   * Например:                     3 2 1 0  <- разряды (pos)
   * 9 (10ая СС) = 1001 (2ая СС) = 1 0 0 1  <- mask
   * бит установлен на позициях pos = 3 и pos = 0
   *
   * проверка бита на позиции 3: 1 0 0 1
   *                           & 1 0 0 0  <- проверочная маска
   *                           ---------
   *                             1 0 0 0 = 8 (10ая СС)
   *
   * проверка бита на позиции 2: 1 0 0 1
   *                           & 0 1 0 0  <- проверочная маска
   *                           ---------
   *                             0 0 0 0 = 0 (10ая СС)
   *
   * @param mask - неотрицательная целочисленная маска
   * @param pos - разряд/позиция проверки бита в маске
   * @return true - бит установлен, false - бит не установлен
   */
  bool is_bit_set(int mask, int pos);

  /**
   * Вычисление всех возможных подмножеств множества полным перебором.
   *
   * Итеративная реализация на базе bit-masking подхода.
   *
   * Например:
   * [1, 2, 3] => {}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}
   *
   * @param set - множество из уникальных целочисленных элементов
   * @return все возможные подмножества множества
   */
  std::vector<std::vector<int>> brute_force_bit_masking_subsets(const std::vector<int>& set);

  /**
   * Вычисление всех возможных подмножеств множества полным перебором.
   *
   * Рекурсивная реализация на базе backtracking подхода.
   *
   * @param set - множество из уникальных целочисленных элементов
   * @param index - текущий индекс рассматриваемого элемента множества (изначально -1)
   * @param mask - текущая битовая маска входящих в подмножество элементов (изначально 0)
   * @param subsets - все возможные подмножества множества (изначально пустое)
   */
  void brute_force_backtracking_subsets(const std::vector<int>& set, int index, int mask,
                                        std::vector<std::vector<int>>& subsets);

  /**
   * Вывод в поток вывода подмножеств множества.
   *
   * @tparam T - целочисленный параметр типа элементов множества
   * @param subsets - вектор из подмножеств множества
   * @param out - поток вывода
   */
  template<typename T>
  inline void pretty_print(const std::vector<std::vector<T>>& subsets, std::ostream& out) {
    static_assert(std::is_integral_v<T>, "template parameter must be an integral type: char, short, int, long, etc.");

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

}  // namespace assignment