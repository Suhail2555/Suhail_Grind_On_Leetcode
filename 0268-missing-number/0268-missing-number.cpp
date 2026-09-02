class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        // Sum of numbers from 0 to n
        int expectedSum = n * (n + 1) / 2;

        // Sum of numbers actually present
        int actualSum = 0;

        for (int num : nums) {
            actualSum += num;
        }

        // Difference is the missing number
        return expectedSum - actualSum;
    }
};