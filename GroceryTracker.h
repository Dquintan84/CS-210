#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>
using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;

public:
    GroceryTracker();

    void LoadItemsFromFile(const string& fileName);
    int GetItemFrequency(const string& itemName) const;
    void PrintAllFrequencies() const;
    void PrintHistogram() const;
    void WriteFrequencyFile(const string& fileName) const;
};

#endif
