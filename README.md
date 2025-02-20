**COMPOUND WORD FINDER**

This is a C++ program that finds the longest and second-longest compound words from a given list of words. A compound word is a word that can be formed by combining two or more other words from the same list.

**BRUTE FORCE APPROACH**
**HOW IT WORKS**

1.Reads words from an input file and stores them in an unordered_set.

2.Tries every possible way to split a word into two or more smaller words.

3.Uses recursion to check if both parts exist in the list.

4.Finds the longest and second-longest compound words.

5.Measures execution time.

**KEY FEATURES**

1.Simple Implementation – Uses recursion to check word formation.

2. Basic Set Operations – Uses unordered_set for quick word lookups.
  
3. No Sorting Required – Directly checks each word without pre-processing.
  
4. Performance Tracking – Measures processing time in microseconds (µs).

**TIME & SPACE COMPLEXITY**

1.Time Complexity: O(N * 2^L) 

2.Space Complexity: O(N) 

**OPTIMIZED APPROACH**
**HOW IT WORKS**

1.Reads words from an input file and stores them in an unordered_set for quick lookups.

2.Sorts the words by length (longest first) so the longest compound word is found first.

3.Uses Dynamic Programming (DP) to check if a word can be formed by joining smaller words from the list.

4.Finds and prints the longest and second-longest compound words, along with the time taken to process them.

**KEY FEATURES**

1.Fast Execution – Uses an unordered_set for quick word lookups.

2.Efficient Sorting – Checks longest words first to find results faster.

3.Dynamic Programming (DP) – Optimized approach to check if words can be formed from others.

4.Performance Tracking – Measures processing time in microseconds (µs).

**TIME & SPACE COMPLEXITY**

1.TIME Complexity → O(N log N + N * L²)

2.SPACE Complexity → O(N * L)


**COMPARISON OF BOTH APPROACHES**

1.Feature              	                    Brute Force (Slow)	                               Optimized (Fast)

2.Method	                                  Tries every split recursively	                     Uses Sorting + DP

3.Time Complexity      	                    O(N * 2^L) (Exponential)	                         O(N log N + N * L²) (Efficient)

4.Sorting             	                    ❌ No Sorting                                    	✅ Sorts words by length

5.Lookup Method	                            ❌ Checks full list (O(N))	                      ✅ unordered_set (O(1))

6.Recursive Stack Issues	                  🚨 Stack overflow for large inputs              	✅ No recursion, uses DP

7.Performance on Large Inputs	              ❌ Very slow	                                    ✅ Fast and scalable

**CONCLUSION**

1.If the dataset is small, brute force can work.

2. If the dataset is large, the optimized approach is much better.
3. 
4. For real-world applications, always use the optimized approach. 
