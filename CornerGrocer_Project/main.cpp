#include "ItemTracker.h"

#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Print the four-option menu the grocer uses to interact with the program.
void displayMenu() {
   cout << "\n===== Corner Grocer Item Tracker =====\n";
   cout << "1. Look up the frequency of a single item\n";
   cout << "2. Print all item frequencies\n";
   cout << "3. Print a histogram of item frequencies\n";
   cout << "4. Exit\n";
   cout << "Enter your choice (1-4): ";
}

// Read the user's menu choice. Returns 0 when the input is not a number so
// the main loop can show an error and prompt again (basic input validation).
int readMenuChoice() {
   int choice;
   if (!(cin >> choice)) {
      cin.clear();  // reset the stream's error flag
      cin.ignore(numeric_limits<streamsize>::max(), '\n');  // drop the bad text
      return 0;     // 0 is not a valid menu option, so it signals "invalid"
   }
   cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear the leftover newline
   return choice;
}

int main() {
   // File names kept as named constants so they are easy to find and change.
   const string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
   const string BACKUP_FILE = "frequency.dat";

   try {
      // Build the tracker, which reads and counts the items from the file.
      ItemTracker tracker(INPUT_FILE);

      // Requirement: create the backup file automatically at start-up,
      // before the user does anything.
      tracker.backupToFile(BACKUP_FILE);

      int choice = 0;
      do {
         displayMenu();
         choice = readMenuChoice();

         if (choice == 1) {
            // Menu Option 1: frequency of a single item.
            cout << "Enter the item to look up: ";
            string item;
            getline(cin, item);
            cout << item << " was purchased " << tracker.getFrequency(item)
                 << " time(s).\n";
         }
         else if (choice == 2) {
            // Menu Option 2: full frequency list.
            cout << "\nItem Frequencies:\n";
            tracker.printFrequencies();
         }
         else if (choice == 3) {
            // Menu Option 3: histogram.
            cout << "\nItem Histogram:\n";
            tracker.printHistogram();
         }
         else if (choice == 4) {
            // Menu Option 4: exit.
            cout << "Goodbye!\n";
         }
         else {
            // Anything else is invalid input.
            cout << "Invalid choice. Please enter a number from 1 to 4.\n";
         }
      } while (choice != 4);
   }
   catch (const exception& error) {
      // If the input file is missing or the backup cannot be written, report
      // it clearly and exit with a non-zero code instead of crashing.
      cout << "Error: " << error.what() << endl;
      return 1;
   }

   return 0;
}
