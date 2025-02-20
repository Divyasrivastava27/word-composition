#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <chrono>

using namespace std;

// Function to check if a word is a compound word
bool isCompound(string &word, unordered_set<string> &wordSet) {
    int n = word.size();
    if (n == 0) return false;

    vector<bool> dp(n + 1, false);  // DP array to check valid segments
    dp[0] = true; // Base case (empty prefix is valid)

    // Check all possible splits of the word
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            string part = word.substr(j, i - j); // Get substring
            if (dp[j] && wordSet.find(part) != wordSet.end()) { 
                dp[i] = true; // Mark as valid split
                break;
            }
        }
    }
    return dp[n]; // If last position is true, word is compound
}

int main(int argc, char* argv[]) {
    // Check if file name is given
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <input_file.txt>\n";
        return 1;
    }

    ifstream file(argv[1]); // Open input file
    if (!file) {
        cout << "Error opening file: " << argv[1] << "\n";
        return 1;
    }

    vector<string> words; // List of words
    unordered_set<string> wordSet; // Set for quick lookup
    string w;

    // Read words from file and store in vector and set
    while (file >> w) {
        words.push_back(w);
        wordSet.insert(w);
    }
    file.close(); // Close file

    // Sort words by length (longest first)
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.size() > b.size();
    });

    string longest = "", secondLongest = "";

    auto start = chrono::high_resolution_clock::now(); // Start timer

    // Check each word to find longest compound words
    for (const string &w : words) {
        wordSet.erase(w); // Temporarily remove to avoid self-check

        if (isCompound((string &)w, wordSet)) { // Check if compound word
            if (longest.empty())
                longest = w; // Store longest compound word
            else {
                secondLongest = w; // Store second longest
                break; // Stop after finding both
            }
        }
        wordSet.insert(w); // Add back after checking
    }

    auto end = chrono::high_resolution_clock::now(); // Stop timer
    auto timeTaken = chrono::duration_cast<chrono::microseconds>(end - start).count(); // Calculate time

    // Print results
    cout << "Longest Compound Word: " << longest << "\n";
    cout << "Second Longest Compound Word: " << secondLongest << "\n";
    cout << "Time taken: " << timeTaken << " µs\n"; // Print time in microseconds

    return 0;
}
