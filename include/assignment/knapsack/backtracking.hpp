#include "assignment/private/knapsack.hpp"

namespace assignment {

  struct KnapsackBacktracking : KnapsackStrategy {

    /**
     * Решение задачи о рюкзаке методом полного перебора (рекурсивно).
     *
     * Рассматриваются решения с весом не превышающим установленный лимит.
     * Среди возможных решений ищется решение с максимальной пользой (profit).
     *
     * @param profits - "польза" элементов
     * @param weights - "веса" элементов
     * @param capacity - максимальная вместимость рюкзака (по весу)
     * @return список индексов элементов
     */
    [[nodiscard]] std::vector<int> solve(const std::vector<int>& profits, const std::vector<int>& weights,
                                         int capacity) const override;

   private:
    /**
     * Вспомогательный метод для реализации рекурсии.
     *
     * @param profits - "польза" элементов
     * @param weights - "веса" элементов
     * @param capacity - максимальная вместимость рюкзака (по весу)
     * @param index - индекс рассматриваемого элемента
     * @param mask - битовая маска рассматриваемого элемента
     * @param weight - текущий вес элементов в рюкзаке
     * @param profit - текущая "польза" элементов в рюкзаке
     * @param best_profit - максимальная найденная "польза"
     * @param best_profit_mask - битовая маска для элементов с максимально найденной "пользой"
     */
    void solve(const Profits& profits, const Weights& weights, int capacity, int index, int mask, int weight,
               int profit, int& best_profit, int& best_profit_mask) const;
  };

}  // namespace assignment