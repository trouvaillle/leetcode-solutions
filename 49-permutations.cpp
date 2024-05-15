class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int maxLength = 6;
        vector<int> factorials = getFactorials(maxLength);
        int length = nums.size();
        vector<vector<int>> result;

        for (int i = 0; i < factorials[length]; ++i) {
            result.push_back(getSequence(nums, factorials, i));
        }
        return result;
    }   

    vector<int> getFactorials(int maxLength) {
        vector<int> factorials(maxLength + 1);
        factorials[0] = 1;
        for (int i = 1; i < maxLength + 1; ++i) {
            factorials[i] = factorials[i - 1] * i;
        }
        return factorials;
    }

    vector<int> getSequence(vector<int>& nums, vector<int> factorials, int index) {
        vector<int> candidates(nums);
        vector<int> result;
        int length = nums.size();
        int remaining = index;
        int offset = 0;

        for (int i = 0; i < length; ++i) {
            offset = remaining / factorials[length - 1 - i];
            remaining = remaining % factorials[length - 1 - i];

            result.push_back(candidates[offset]);
            candidates.erase(candidates.begin() + offset);
        }

        return result;
    }
};
