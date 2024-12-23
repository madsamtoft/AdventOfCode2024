#include <iostream>
#include <fstream>
#include <list>

int main() {
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::list<int> locationList1;
    std::list<int> locationList2;
    int location;

    while(!inFile.eof()) {
        inFile >> location;
        locationList1.push_back(location);
        inFile >> location;
        locationList2.push_back(location);
    }

    inFile.close();

    if(locationList1.size() != locationList2.size()) {
        std::cout << "The two lists are not the same size." << std::endl;
        return 1;
    }

    locationList1.sort();
    locationList2.sort();

    int locationID1 = 0;
    int locationID2 = 0;

    long long sum = 0;


    int size = locationList1.size();

    for(int i = 0; i < size; i++) {
        locationID1 = locationList1.front();
        locationList1.pop_front();

        locationID2 = locationList2.front();
        locationList2.pop_front();

        sum += abs(locationID1 - locationID2);
    }

    std::cout << "The sum of the differences is: " << sum << std::endl;
    
    return 0;
}