#include "assignment/knapsack/bit_masking.hpp"

#include <cassert>  // assert
#include <numeric>  // accumulate

#include "assignment/bits.hpp"  // mask2elems, mask2indices

namespace assignment {

  // вспомогательная функция подсчета суммы элементов массива
  static int sum_helper(const std::vector<int>& arr) {
    return std::accumulate(arr.begin(), arr.end(), 0);
  }

  std::vector<int> KnapsackBitMasking::solve(const Profits& profits, const Weights& weights, int capacity) const {
    assert(profits.size() == weights.size() && capacity > 0);

    const auto num_elems = static_cast<int>(profits.size());  // N
    const int num_subsets = 1 << num_elems;                   // 2^N

    // результат: лучшая найденная "польза" (+ маска для получения элементов)
    int best_profit = 0;
    int best_profit_mask = 0;

    // Tip: What if the weight is equal to the max weight? Can we stop the process?

    // 0..00, 0..01, 0..10, 0..11, ..., 1..11
    for (int mask = 0; mask < num_subsets; mask++) {  // 2^N

      // массив из весов рассматриваемых элементов
      const auto masked_weights = mask2elems(weights, mask);

      // вычисление общего веса рассматриваемых элементов
      const int curr_weight = sum_helper(masked_weights);

      // ... обработка случая превышения емкости рюкзака

      // массив из "пользы" рассматриваемых элементов
      const auto masked_profits = mask2elems(profits, mask);

      // вычисление общей "пользы" рассматриваемых элементов
      const int curr_profit = sum_helper(masked_profits);

      // ... обработка случая нахождения большего значения "пользы"
    }

    // ... возвращение итогового результата: используйте mask2indices;

    return {};
  }

}  // namespace assignment