#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <chrono> // For measuring execution time

using namespace std;

// Function to check if a word is a compound word (Brute Force)
bool isCompound(string &w, unordered_set<string> &wordSet) {
    int n = w.size();
    if (n == 0) return false;

    // Try every possible split of the word
    for (int i = 1; i < n; i++) {
        string left = w.substr(0, i); // First part
        string right = w.substr(i); // Second part

        // If both parts exist in the set OR right part is a compound
        if (wordSet.count(left) && (wordSet.count(right) || isCompound(right, wordSet))) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    // Check if file name is provided
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <input_file.txt>\n";
        return 1;
    }

    ifstream file(argv[1]); // Open input file
    if (!file) {
        cout << "Error opening file: " << argv[1] << "\n";
        return 1;
    }

    vector<string> words; // Store words in a list
    unordered_set<string> wordSet; // Store words in a set for quick lookup
    string w;

    // Read words from file and store them
    while (file >> w) {
        words.push_back(w);
        wordSet.insert(w);
    }
    file.close(); // Close file

    string longest = "", secondLongest = "";

    auto start = chrono::high_resolution_clock::now(); // Start time measurement

    // Check each word one by one
    for (const string &w : words) {
        wordSet.erase(w); // Remove the word to avoid using itself

        if (isCompound((string &)w, wordSet)) { // Check if compound
            if (longest.empty())
                longest = w; // Store longest
            else {
                secondLongest = w; // Store second longest
                break; // Stop after finding two compound words
            }
        }
        wordSet.insert(w); // Add back after checking
    }

    auto end = chrono::high_resolution_clock::now(); // End time measurement
    auto timeTaken = chrono::duration_cast<chrono::microseconds>(end - start).count(); // Calculate time

    // Print results
    cout << "Longest Compound Word: " << longest << "\n";
    cout << "Second Longest Compound Word: " << secondLongest << "\n";
    cout << "Time taken: " << timeTaken << " µs\n"; // Print time in microseconds

    return 0;
}
