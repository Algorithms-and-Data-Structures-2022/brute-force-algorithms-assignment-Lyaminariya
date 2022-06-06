#include "assignment/subsets.hpp"

#include <cassert>  // assert

namespace assignment {

  bool is_bit_set(int mask, int pos) {
    assert(pos < 30);  // pos < макс. кол-ва бит в маске (31 бит)

    const int pos_check_mask = 1 << pos;
    return (mask & pos_check_mask) != 0;
  }

  std::vector<std::vector<int>> brute_force_bit_masking_subsets(const std::vector<int>& set) {
    assert(set.size() <= 16);  // избегаем проблем с выделением памяти и переполнением типов

    const auto num_elems = static_cast<int>(set.size());  // N
    const int num_subsets = 1 << num_elems;               // 2^N

    // выделяем память
    auto subsets = std::vector<std::vector<int>>(num_subsets);

    // 0..00, 0..01, 0..10, 0..11, ... 1..11
    for (int mask = 0; mask < num_subsets; mask++) {  // 2^N

      // проверка позиций в маске - элемент входит или не входит
      for (int index = 0; index < num_elems; index++) {  // N

        if (is_bit_set(mask, index)) {
          subsets[mask].push_back(set[index]);
        }
      }
    }

    return subsets;
  }

  void brute_force_backtracking_subsets(const std::vector<int>& set, int index, int mask,
                                        std::vector<std::vector<int>>& subsets) {

    // В данном случае backtracking практически не выражен.
    // Нас удовлетворяют все возможные подмножества и мы останавливаемся
    // лишь в случае достижения последнего элемента множества.

    if (index != -1 && is_bit_set(mask, index) && set[index] == 2) {
      return;  // backtracking - поднимаемся обратно по дереву рекурсии в случае нарушения условия задачи (отрубаем ветку)
      // данный случай, когда нарушено условие не учитывается при дальнейшем решении
    }

    index += 1;  // рассматриваем следующий элемент

    if (index > static_cast<int>(set.size()) - 1) {  // обошли все элементы множества

      std::vector<int> curr_subset;  // пустое подмножество

      // генерация подмножества на базе битовой маски
      for (int pos = 0; pos < set.size(); pos++) {
        if (is_bit_set(mask, pos)) {
          curr_subset.push_back(set[pos]);
        }
      }

      // сохранение полученного подмножества
      subsets.emplace_back(std::move(curr_subset));

      return;  // возвращаемся по дереву рекурсии
    }

    // включаем или не включаем элемент с текущим индексом в подмножество (используя битовую маску)
    brute_force_backtracking_subsets(set, index, mask, subsets);                 // не включаем
    brute_force_backtracking_subsets(set, index, mask | (1 << index), subsets);  // включаем
  }

}  // namespace assignment
