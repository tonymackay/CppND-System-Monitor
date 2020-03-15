#ifndef PROCESS_H
#define PROCESS_H

#include <string>

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
  bool operator<(Process const& a) const;
  bool operator>(Process const& a) const;

 private:
  int pid{0};
  std::string user{};
  std::string command{};
  float cpu_utilization{0};
  int ram{0};
  long int up_time{0};
};

#endif