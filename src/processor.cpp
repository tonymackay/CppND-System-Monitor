#include <string>
#include <vector>

#include "processor.h"

float Processor::Utilization() { return this->utilization; }

void Processor::Update(std::vector<std::string> cpu_data) {
  size_t idle = std::stoul(cpu_data[3]);
  size_t total;
  for (std::string value : cpu_data) {
    total += std::stoul(value);
  }

  const float idle_time_delta = idle - this->prev_idle;
  const float total_time_delta = total - this->prev_total;

  this->utilization = (1.0 - idle_time_delta / total_time_delta);
  this->prev_total = total;
  this->prev_idle = idle;
}