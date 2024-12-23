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

    while (!inFile.eof()) {
        inFile >> location;
        locationList1.push_back(location);
        inFile >> location;
        locationList2.push_back(location);
    }

    inFile.close();

    if (locationList1.size() != locationList2.size()) {
        std::cout << "The two lists are not the same size." << std::endl;
        return 1;
    }

    int similarityScore, locationID, count;
    int size = locationList1.size();
    std::list<int> dupeList;

    for (int i = 0; i < size; i++) {
        count = 0;

        locationID = locationList1.front();
        locationList1.pop_front();

        dupeList = locationList2;

        for (int j = 0; j < size; j++) {
            if (locationID == dupeList.front()) {
                count++;
                dupeList.pop_front();
            } else {
                dupeList.pop_front();
            }
        }
        similarityScore += (count * locationID);
    }

    std::cout << "The similarity score is: " << similarityScore << std::endl;
    
    return 0;
}

/*  My friend Dejan's "bEtTeR" solution (it is better, but I'm still salty about it)
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
    ifstream infile ("input.txt");
    map<int, int> occ1, occ2;
    int x;

    // Read input file and count how occurences of each number
    // (im assuming the memory at map indexes is preinitialized to 0)
    while(!infile.eof()) {
        infile >> x;
        occ1[x]++;
        
        infile >> x;
        occ2[x]++;
    }

    int simScore = 0;
    int lim = max(occ1.rbegin()->first, occ2.rbegin()->first);
    for(int i = 0; i < lim; i++) {
        int value = occ1[i] * i * occ2[i];
        simScore += value;
    }

    cout << simScore;

    return 0;
}
*/