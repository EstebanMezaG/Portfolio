#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <map>
#include <string>

// ItemTracker reads a list of purchased items from a text file and keeps a
// running count of how many times each item appears. Once built, it can look
// up a single item, print the full list, print a histogram, and write a
// backup file of all the counts. Keeping the data and this behavior together
// in one class (with a private map and a public interface) satisfies the
// "at least one class with public and private sections" requirement.
class ItemTracker {
public:
   // Build a tracker from the given input file. The file is read here so the
   // counts are ready to use as soon as the object is created.
   ItemTracker(const std::string& t_inputFileName);

   // Return how many times a single item was purchased (0 if never seen).
   int getFrequency(const std::string& t_item) const;

   // Print every item next to its purchase count (Menu Option 2).
   void printFrequencies() const;

   // Print every item followed by one asterisk per purchase (Menu Option 3).
   void printHistogram() const;

   // Write every item and its count to a backup file such as frequency.dat.
   void backupToFile(const std::string& t_outputFileName) const;

private:
   // Maps an item name to the number of times it was purchased. A std::map
   // keeps the items sorted alphabetically, which makes the output tidy.
   std::map<std::string, int> m_itemFrequencies;

   // Read the input file and fill m_itemFrequencies. Called by the constructor.
   void loadItems(const std::string& t_inputFileName);
};

#endif  // ITEM_TRACKER_H
