#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

Processor& System::Cpu() {
  vector<string> cpu_data = LinuxParser::CpuUtilization();
  cpu_.Update(cpu_data);
  return cpu_;
}

// TODO: Return a container composed of the system's processes
// 1. Add CPU Util
// 2. Sort by Memory/CPU

vector<Process>& System::Processes() { 
    vector<int> pids = LinuxParser::Pids();
    for(int pid : pids) {
        auto itr = std::find_if(processes_.begin(), processes_.end(), [&pid](const Process & p) { return p.Pid() == pid; });
        if (itr != processes_.cend()) {
            itr->Ram(LinuxParser::Ram(pid));
            itr->UpTime(LinuxParser::UpTime(pid));
        }
        else {
            Process process{pid, LinuxParser::User(pid), LinuxParser::Command(pid)};
            process.Ram(LinuxParser::Ram(pid));
            process.UpTime(LinuxParser::UpTime(pid));
            processes_.push_back(process);
        }
    }

    std::sort(processes_.begin(), processes_.end(), [](const Process & pa, const Process & pb) {
        // by default sort by highest to lowest PID
        return pa > pb;
    });

    return processes_; 
}

std::string System::Kernel() { return LinuxParser::Kernel(); }

float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

long System::UpTime() { return LinuxParser::UpTime(); }