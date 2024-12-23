#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

bool isSafeReport(std::vector<int> report) {
    bool increasing = true;
    bool decreasing = true;

    int length = report.size();
    for (int i = 0; i < length - 1; i++) {
        int diff = report[i + 1] - report[i];
        if (abs(diff) < 1 || abs(diff) > 3) {
            return false; // Difference out of range
        }
        increasing = diff > 0 ? false : increasing; // Not increasing
        decreasing = diff < 0 ? false : decreasing; // Not decreasing
    }
    return increasing || decreasing; // Must be either all increasing or all decreasing
}

bool tolerateBadLevel(std::vector<int> report) {
    int length = report.size();
    for (int i = 0; i < length; i++) {
        std::vector<int> reportCopy = report;
        reportCopy.erase(reportCopy.begin() + i);
        if (isSafeReport(reportCopy)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ifstream inFile("input.txt");
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    int safeCount = 0;

    while (getline(inFile, line)) {
        std::istringstream iss(line);
        std::vector<int> report;
        int number;

        // Parse the line into a vector of integers
        while (iss >> number) {
            report.push_back(number);
        }

        // Check if the report is safe
        if (isSafeReport(report)) {
            ++safeCount;
        } else if (tolerateBadLevel(report)) {
            ++safeCount;
        }
    }

    std::cout << "The safe count is: " << safeCount << std::endl;
    return 0;
}
