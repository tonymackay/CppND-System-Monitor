#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid, std::string user, std::string command) {
  this->pid = pid;
  this->user = user;
  this->command = command;
  this->hertz = sysconf(_SC_CLK_TCK);
}

int Process::Pid() const { return this->pid; }

float Process::CpuUtilization() const { return this->cpu_utilization; }

void Process::CpuUtilization(std::vector<std::string> proc_stat_data) {
  if (proc_stat_data.size() > 22) {
    size_t utime = std::stoul(proc_stat_data[13]);
    size_t stime = std::stoul(proc_stat_data[14]);
    size_t cutime = std::stoul(proc_stat_data[15]);
    size_t cstime = std::stoul(proc_stat_data[16]);
    size_t start_time = std::stoul(proc_stat_data[21]);

    size_t total_time = utime + stime + cutime + cstime;
    size_t seconds = this->up_time - (start_time / this->hertz);

    this->cpu_utilization = ((static_cast<float>(total_time) / this->hertz) / seconds);
  }
}

string Process::Command() const { return this->command; }

int Process::Ram() const { return this->ram; }

void Process::Ram(std::string ram) {
  int kb = std::stoi(ram);
  int mb = kb / 1000;
  this->ram = mb;
}

string Process::User() const { return this->user; }

long int Process::UpTime() const { return this->up_time; }

void Process::UpTime(long int up_time) { this->up_time = up_time; }

bool Process::operator<(Process const& a) const { return this->pid < a.Pid(); }

bool Process::operator>(Process const& a) const { return this->pid > a.Pid(); }
