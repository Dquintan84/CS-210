#include "GroceryTracker.h"
#include <iostream>
#include <fstream>

GroceryTracker::GroceryTracker() {
    // constructor
}

void GroceryTracker::LoadItemsFromFile(const string& fileName) {
    ifstream inFS(fileName);

    if (!inFS.is_open()) {
        cout << "Error: could not open input file: " << fileName << endl;
        return;
    }

    string item;
    while (inFS >> item) {
        itemFrequency[item]++;
    }

    inFS.close();
}

int GroceryTracker::GetItemFrequency(const string& itemName) const {
    auto it = itemFrequency.find(itemName);

    if (it != itemFrequency.end()) {
        return it->second;
    }

    return 0;
}

void GroceryTracker::PrintAllFrequencies() const {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void GroceryTracker::PrintHistogram() const {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

void GroceryTracker::WriteFrequencyFile(const string& fileName) const {
    ofstream outFS(fileName);

    if (!outFS.is_open()) {
        cout << "Error: could not write to file: " << fileName << endl;
        return;
    }

    for (const auto& pair : itemFrequency) {
        outFS << pair.first << " " << pair.second << endl;
    }

    outFS.close();
}