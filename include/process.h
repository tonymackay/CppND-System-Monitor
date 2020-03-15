#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
 public:
  Process(int pid, std::string user, std::string command);
  int Pid();
  std::string User();
  std::string Command();
  int Ram();
  void Ram(std::string ram);
  long int UpTime();  
  void UpTime(long int up_time);
  float CpuUtilization();
  bool operator<(Process const& a) const;

 private:
  int pid{0};
  std::string user{};
  std::string command{};
  float cpu_utilization{0};
  int ram{0};
  long int up_time{0};
};

#endif