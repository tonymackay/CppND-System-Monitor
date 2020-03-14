#include <string>
#include <sstream>
#include <iomanip>

#include "format.h"

std::string Format::ElapsedTime(long seconds) {
    int days = seconds / (24 * 3600); 
    seconds = seconds % (24 * 3600);
    int hours = seconds / 3600;
    seconds %= 3600;
    int minutes = seconds / 60;
    seconds %= 60;
    std::stringstream stringstream;
    if (days == 1) {
        stringstream << days << " day, ";
    } else if (days > 1) {
        stringstream << days << " days, ";
    }

    stringstream << std::setfill('0') << std::setw(2) << hours << ":";
    stringstream << std::setfill('0') << std::setw(2) << minutes << ":";
    stringstream << std::setfill('0') << std::setw(2) << seconds;
    return stringstream.str(); 
}