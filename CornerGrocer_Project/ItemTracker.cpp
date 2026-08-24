#include "ItemTracker.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor: load the file right away so the object is ready to answer
// questions immediately after it is created.
ItemTracker::ItemTracker(const string& t_inputFileName) {
   loadItems(t_inputFileName);
}

// Read the file one word at a time. Each word is an item; every time an item
// appears, add one to its count. With a map, m_itemFrequencies[item] starts
// at 0 the first time an item is seen, so ++ safely counts it.
void ItemTracker::loadItems(const string& t_inputFileName) {
   ifstream inFile(t_inputFileName);
   if (!inFile) {
      // Throw so main can report the problem instead of running with no data.
      throw runtime_error("Could not open input file: " + t_inputFileName);
   }

   string item;
   while (inFile >> item) {
      m_itemFrequencies[item]++;
   }
   inFile.close();
}

// Look up one item. Using .count() first means a missing item is reported as
// 0 without accidentally inserting it into the map.
int ItemTracker::getFrequency(const string& t_item) const {
   if (m_itemFrequencies.count(t_item) > 0) {
      return m_itemFrequencies.at(t_item);
   }
   return 0;
}

// Print every item and its count, one per line (Menu Option 2).
void ItemTracker::printFrequencies() const {
   for (const auto& entry : m_itemFrequencies) {
      cout << entry.first << " " << entry.second << endl;
   }
}

// Print every item followed by one asterisk per purchase (Menu Option 3).
void ItemTracker::printHistogram() const {
   for (const auto& entry : m_itemFrequencies) {
      cout << entry.first << " ";
      for (int i = 0; i < entry.second; ++i) {
         cout << "*";
      }
      cout << endl;
   }
}

// Save all counts to a backup file so the day's data is not lost.
void ItemTracker::backupToFile(const string& t_outputFileName) const {
   ofstream outFile(t_outputFileName);
   if (!outFile) {
      throw runtime_error("Could not create backup file: " + t_outputFileName);
   }
   for (const auto& entry : m_itemFrequencies) {
      outFile << entry.first << " " << entry.second << endl;
   }
   outFile.close();
}
