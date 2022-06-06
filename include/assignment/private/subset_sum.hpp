#pragma once

#include <vector>

namespace assignment {

  struct SubsetSumStrategy {

    virtual ~SubsetSumStrategy() = default;

    [[nodiscard]] virtual std::vector<std::vector<int>> search(const std::vector<int> &set, int target_sum) const = 0;
  };

}  // namespace assignment