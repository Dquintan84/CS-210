#include <iostream>
#include <string>
#include <cctype>
#include "GroceryTracker.h"
using namespace std;

string NormalizeItemName(string s) {
    if (s.empty()) return s;
    for (size_t i = 0; i < s.size(); ++i) {
        s[i] = static_cast<char>(tolower(static_cast<unsigned char>(s[i])));
    }
    s[0] = static_cast<char>(toupper(static_cast<unsigned char>(s[0])));
    return s;
}

int main() {
    GroceryTracker tracker;
    int choice = 0;
    string itemName;

    tracker.LoadItemsFromFile("CS210_Project_Three_Input_File.txt");
    tracker.WriteFrequencyFile("frequency.dat");

    do {
        cout << "\nMenu\n";
        cout << "1. Look up item frequency\n";
        cout << "2. Print all item frequencies\n";
        cout << "3. Print histogram\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) break;

        if (choice == 1) {
            cout << "Enter item name: ";
            cin.ignore(1000, '\n');
            getline(cin, itemName);

            itemName = NormalizeItemName(itemName);

            int freq = tracker.GetItemFrequency(itemName);

            // Try plural if singular not found
            if (freq == 0 && !itemName.empty() && itemName.back() != 's') {
                int pluralFreq = tracker.GetItemFrequency(itemName + "s");
                if (pluralFreq > 0) {
                    itemName += "s";
                    freq = pluralFreq;
                }
            }

            cout << itemName << " was purchased " << freq << " "
                << (freq == 1 ? "time" : "times") << ".\n";
        }
        else if (choice == 2) {
            tracker.PrintAllFrequencies();
        }
        else if (choice == 3) {
            tracker.PrintHistogram();
        }
        else if (choice == 4) {
            // exit
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}