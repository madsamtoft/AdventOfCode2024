#include <iostream>
#include <fstream>
#include <list>

int main() {
    std::list<int> locationList1;
    std::list<int> locationList2;

    std::ifstream inFile;

    inFile.open("input.txt");

    long long t;

    inFile >> t;

    std::cout << "t: " << t << std::endl;



    return 0;
}