#pragma once

#include <utility>
#include <vector>

#include "core/task/include/task.hpp"

namespace sozonov_i_image_filtering_block_partitioning_omp {

std::vector<double> ZeroEdges(std::vector<double> img, int wdth, int hght);

class TestTaskOpenMP : public ppc::core::Task {
 public:
  explicit TestTaskOpenMP(ppc::core::TaskDataPtr task_data) : Task(std::move(task_data)) {}
  bool PreProcessingImpl() override;
  bool ValidationImpl() override;
  bool RunImpl() override;
  bool PostProcessingImpl() override;

 private:
  std::vector<double> image_, filtered_image_;
  int width_{}, height_{};
};

}  // namespace sozonov_i_image_filtering_block_partitioning_omp