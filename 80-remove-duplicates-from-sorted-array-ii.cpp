class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int prev = nums[0];
        int cnt = 1;
        int offset = 1;
        int index = 1;

        for (offset = 1; offset < size; ++offset) {
            if (prev == nums[offset]) {
                nums[index] = prev;
                ++cnt;
                if (cnt <= 2) {
                    ++index;
                }
            } else if (prev != nums[offset]){
                iter_swap(nums.begin() + index, nums.begin() + offset);
                prev = nums[index];
                cnt = 1;
                ++index;
            }
        }

        return index;
    }
};
