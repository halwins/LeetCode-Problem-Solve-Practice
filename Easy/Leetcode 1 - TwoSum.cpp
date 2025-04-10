#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Problem: Two Sum
 *
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 *
 * Assumptions:
 * - Each input would have exactly one solution.
 * - You may not use the same element twice.
 *
 * Return:
 * - The answer in any order.
 */

class Solution
{
public:
    // Solution 1:
    // Traverse the array to find two elements that add up to the target.
    // This approach uses a nested loop to compare each element with every other element.
    // Time complexity: O(n^2) due to the nested loop structure.
    // Space complexity: O(1) as it only uses a constant amount of space.
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>();
    }

    // Solution 2:
    // Using hashmap to store the elements we have seen so far and their indices.
    // This approach uses a single loop to traverse the array and a hashmap to store the elements and their indices.
    // Time complexity: O(n) as it only needs to traverse the array once.
    // Space complexity: O(n) as it needs to store all the elements in the hashmap.
    vector<int> twoSum2(vector<int> &nums, int target)
    {
        unordered_map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (numToIndex.find(complement) != numToIndex.end())
            {
                return vector<int>{numToIndex[complement], i};
            }
            else
            {
                numToIndex[nums[i]] = i;
            }
        }
        return vector<int>();
    }
};