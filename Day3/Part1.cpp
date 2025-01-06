#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    std::ifstream inFile("input.txt");
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    std::string input;
    while (std::getline(inFile, line)) {
        input += line; // Combine all lines into a single string
    }

    // Define the regex to match valid mul(X,Y) instructions
    std::regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    std::smatch match;

    int totalSum = 0;

    // Search for all matches in the input string
    auto it = std::sregex_iterator(input.begin(), input.end(), pattern);
    auto end = std::sregex_iterator();
    for (; it != end; ++it) {
        match = *it;
        int x = std::stoi(match[1].str());
        int y = std::stoi(match[2].str());
        totalSum += x * y; // Multiply and add to the total sum
    }

    std::cout << "The total sum of valid multiplications is: " << totalSum << std::endl;
    return 0;
}
