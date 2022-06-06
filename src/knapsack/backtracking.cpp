#include "assignment/knapsack/backtracking.hpp"

#include <cassert>  // assert

#include "assignment/bits.hpp"

namespace assignment {

  std::vector<int> KnapsackBacktracking::solve(const Profits& profits, const Weights& weights, int capacity) const {
    assert(profits.size() == weights.size() && capacity > 0);

    // результат: наибольшая "польза"
    int best_profit = 0;
    int best_profit_mask = 0;

    // вызов вспомогательного метода: обратите внимание на входные аргументы
    // и на то, как они передаются (по значению или ссылке, почему так?)
    solve(profits, weights, capacity, -1, 0, 0, 0, best_profit, best_profit_mask);

    return mask2indices(profits, best_profit_mask);
  }

  void KnapsackBacktracking::solve(const Profits& profits, const Weights& weights, int capacity, int index, int mask,
                                   int weight, int profit, int& best_profit, int& best_profit_mask) const {

    // Ограничение 0: выход за пределы
    if (index == static_cast<int>(profits.size())) {
      return;
    }

    // Ограничение 1: превышение лимита емкости рюкзака
    if (weight > capacity) {
      return;
    }

    // ... если текущая "польза" максимальна, обновляем наилучшую "пользу"
    if (profit > best_profit) {
      // ...
    }

    // рассматриваем следующий элемент
    index += 1;

    // ... рекурсивные вызовы со включением/исключением следующего элемента
  }

}  // namespace assignment
