/*

Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.
Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

Since the answer may be very large, return it modulo 109 + 7.

***


To solve this problem, we need to understand that the structure of a BST is determined by the order in which values are inserted. For two sequences to produce the same BST, they must ensure that at every step, the same decisions are made regarding whether to go left or right in the tree. This implies that the relative order of insertion for the left and right subtrees must be maintained.

A key insight is that the first element in the sequence determines the root of the BST. The elements to the left of the root in the permutation form the left subtree, and those to the right form the right subtree. Any reordering must keep all elements in the left subtree before any elements in the right subtree to maintain the BST structure.

This problem can be reduced to counting the number of valid combinations of left and right subtree permutations. This is a combinatorial problem that can be solved using dynamic programming and divide-and-conquer. The solution involves calculating the number of distinct BSTs that can be formed from the left and right subtrees, and then using the formula for combinations to calculate the total.

The number of ways to interleave two sequences of lengths left and right while maintaining their internal order is given by the binomial coefficient C(left + right, left) (or C(left + right, right)), which represents the number of ways to choose left (or right) positions out of left + right total positions.

*/


#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate the factorial modulo MOD
long long factorialMod(int n, long long* fact, long long* invFact) {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
        // Modular inverse using Fermat's little theorem, since MOD is prime
        invFact[i] = (invFact[i - 1] * powMod(i, MOD - 2)) % MOD;
    }
}

// Modular exponentiation
long long powMod(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

// Function to calculate binomial coefficient modulo MOD
long long binomialMod(int n, int k, long long* fact, long long* invFact) {
    return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD;
}

// Recursive function to count the number of ways
int countWays(int* nums, int start, int end, long long* fact, long long* invFact) {
    if (start >= end) return 1;
    int root = nums[start];
    int left = start + 1;
    int right = start + 1;
    
    // Split elements into those that go to the left and right of the root
    while (right <= end && nums[right] < root) ++right;
    
    // Count the number of ways to reorder the left and right subtrees
    long long leftWays = countWays(nums, left, right - 1, fact, invFact);
    long long rightWays = countWays(nums, right, end, fact, invFact);

    // Calculate the number of ways to interleave the left and right subtrees
    long long totalWays = (leftWays * rightWays) % MOD;
    totalWays = (totalWays * binomialMod(right - left + end - right, right - left, fact, invFact)) % MOD;
    
    return (int)totalWays;
}

// Main function to return the number of ways to reorder nums
int numOfWays(int* nums, int numsSize) {
    long long fact[numsSize + 1], invFact[numsSize + 1];
    factorialMod(numsSize, fact, invFact);
    return countWays(nums, 0, numsSize - 1, fact, invFact) - 1; // Subtract 1 to exclude the original order
}

int main() {
    int nums[] = {2, 1, 3}; // Example input
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = numOfWays(nums, numsSize);
    printf("Number of ways to reorder: %d\n", result);
    return 0;
}

