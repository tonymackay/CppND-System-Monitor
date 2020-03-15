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

int Process::Pid() const { return this->pid; }

float Process::CpuUtilization() const { return this->cpu_utilization; }

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

bool Process::operator<(Process const& a) const { 
    return this->pid < a.Pid();
}

bool Process::operator>(Process const& a) const { 
    return this->pid > a.Pid();
}