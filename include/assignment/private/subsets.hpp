#pragma once

#include <vector>

namespace assignment {

  struct SubsetsStrategy {

    virtual ~SubsetsStrategy() = default;

    [[nodiscard]] virtual std::vector<std::vector<int>> generate(const std::vector<int>& set) const = 0;
  };

}  // namespace assignment