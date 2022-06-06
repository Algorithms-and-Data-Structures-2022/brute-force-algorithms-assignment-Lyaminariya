#pragma once

#include <vector>

namespace assignment {

  struct KnapsackStrategy {

    // type aliases
    using Profits = std::vector<int>;
    using Weights = std::vector<int>;

    virtual ~KnapsackStrategy() = default;

    [[nodiscard]] virtual std::vector<int> solve(const Profits& profits, const Weights& weights,
                                                 int capacity) const = 0;
  };

}  // namespace assignment