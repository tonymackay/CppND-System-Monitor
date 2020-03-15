#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <vector>

class Process {
 public:
  Process(int pid, std::string user, std::string command);
  int Pid() const;
  std::string User() const;
  std::string Command() const;
  int Ram() const;
  void Ram(std::string ram);
  long UpTime() const;
  void UpTime(long up_time);
  float CpuUtilization() const;
  void CpuUtilization(std::vector<std::string> proc_stat_data);
  bool operator<(Process const& a) const;
  bool operator>(Process const& a) const;

 private:
  int pid{0};
  std::string user{};
  std::string command{};
  float cpu_utilization{0};
  int ram{0};
  long int up_time{0};
  long hertz{0};
};

#endif