#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <vector>

class Processor {
 public:
  float Utilization();
  void Update(std::vector<std::string> cpu_data);

 private:
  float utilization;
  size_t prev_total;
  size_t prev_idle;
};

#endif