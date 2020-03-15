#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid, std::string user, std::string command)
{
    this->pid = pid;
    this->user = user;
    this->command = command;
}

int Process::Pid() { return this->pid; }

float Process::CpuUtilization() { return this->cpu_utilization; }

string Process::Command() { return this->command; }

int Process::Ram() { return this->ram; }

void Process::Ram(std::string ram) {
    int kb = std::stoi(ram);
    int mb = kb / 1000;
    this->ram = mb; 
}

string Process::User() { return this->user; }

long int Process::UpTime() { return this->up_time; }

void Process::UpTime(long int up_time) { this->up_time = up_time; }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a[[maybe_unused]]) const { return true; }