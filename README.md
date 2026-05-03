# ADA_lab
Searching Algorithms
Linear Search
Checks each element one by one.
Works on unsorted data.
Time Complexity: O(n)
Use when data is small or unsorted.

👉 Idea:
Compare target with every element until found.

Binary Search
Works only on sorted arrays.
Divides search space in half each step.
Time Complexity: O(log n)

👉 Idea:

Check middle element
If target < mid → search left
Else → search right
🔄 Sorting Algorithms
Selection Sort
Repeatedly selects the minimum element and places it at correct position.
Time: O(n²)

👉 Simple but inefficient for large data.

Insertion Sort
Builds sorted array one element at a time.
Efficient for small or nearly sorted arrays.
Time: O(n²) worst, O(n) best

👉 Like sorting cards in your hand.

Merge Sort
Uses Divide and Conquer.
Splits array → sorts → merges.
Time: O(n log n)

👉 Very efficient and stable.

🔁 Recursion & Basic Problems
Tower of Hanoi
Move disks from source → destination using auxiliary rod.
Rule: Larger disk cannot be on smaller one.
Time: O(2ⁿ)

👉 Classic recursion problem.

Power Calculation
Computes a
n
Optimized using:
Exponentiation by squaring
Time: O(log n)
Sum of Numbers
Recursive or iterative sum of elements.
Permutation Finder
Generates all possible arrangements of elements.
Time: O(n!)
First Duplicate Element
Finds first repeating value.
Can be optimized using hashing.
Missing Number
Finds missing number in sequence.
Uses:
Sum formula OR
XOR trick
🧮 Mathematical Algorithms
Horner’s Rule
Efficient polynomial evaluation.

Instead of:

ax
3
+bx
2
+cx+d

Use:

((ax+b)x+c)x+d

👉 Reduces multiplications.

Truth Table Generator
Generates all combinations of boolean variables.
Used in logic design & digital circuits.
🎒 Greedy & Divide and Conquer
Knapsack Problem (0/1)
Maximize value within weight limit.
Two types:
Greedy (fractional)
DP (0/1)

👉 Your version likely uses 0/1 knapsack (DP)

Matrix Multiplication (Divide & Conquer)
Splits matrices into submatrices.
Improves efficiency for large inputs.
📊 Graph Algorithms
Dijkstra’s Algorithm
Finds shortest path from source to all nodes.
Works for non-negative weights.
Time: O(V²) or O(E log V) (heap)
Cycle Detection
Detects loops in a graph.
Methods:
DFS
Union-Find
Multi-stage Graph
Graph divided into stages.
Solve using Dynamic Programming.
Used in shortest path problems.
🧠 Dynamic Programming
Matrix Chain Multiplication
Finds optimal way to multiply matrices.
Minimizes number of multiplications.
Multi-stage Decision Problem
Solve step-by-step optimization problems.
Each stage depends on previous.
Longest Common Subsequence (LCS)
Finds longest common sequence between two strings.
Time: O(n × m)

👉 Example:
"ABCBDAB" & "BDCAB" → "BCAB"

♟️ Backtracking Algorithms
N-Queens Problem
Place N queens so none attack each other.
Uses recursion + safety checks.
Graph Coloring
Assign colors to vertices such that:
No adjacent vertices share same color.
Hamiltonian Cycle
Visit every vertex exactly once and return to start.
Sum of Subsets
Find subsets whose sum = target.
Uses pruning to reduce search.
