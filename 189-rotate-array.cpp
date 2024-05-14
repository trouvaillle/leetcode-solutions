class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // rotate1(nums, k);
        // rotate2(nums, k);
        // rotate3(nums, k);
        rotate4(nums, k);
    }

    void rotate1(vector<int>& nums, int k) {
        int last = nums.size() - 1;
        int newK = k % nums.size();
        for (int i = 0; i < newK; ++i) {
            nums.insert(nums.begin(), nums[last]);
            nums.erase(nums.begin() + last + 1);
        }
    }

    void rotate2(vector<int>& nums, int k) {
        vector<int> buffer;
        int size = nums.size();
        int newK = k % size;
        for (int i = 0; i < size; ++i) {
            buffer.push_back(nums[(size + i - newK) % size]);
        }
        
        nums.clear();
        for (int i = 0; i < size; ++i) {
            nums.push_back(buffer[i]);
        }
    }

    void rotate3(vector<int>& nums, int k) {
        int size = nums.size();
        int newK = k % size;

        for (int i = 0; i < size; ++i) {
            nums.push_back(nums[(size + i - newK) % size]);
        }
        
        nums.erase(nums.begin(), nums.begin() + size);
    }

    void rotate4(vector<int>& nums, int k) {
        int size = nums.size();
        int buffer[size];
        int newK = k % size;
        for (int i = 0; i < size; ++i) {
            buffer[i] = nums[(size + i - newK) % size];
        }
        
        nums.clear();
        for (int i = 0; i < size; ++i) {
            nums.push_back(buffer[i]);
        }
    }

    // trick!
    void rotate5(vector<int>& nums, int k) {
        int size = nums.size();
        int buffer[size];
        int newK = k % size;
        for (int i = 0; i < size; ++i) {
            buffer[i] = nums[(size + i - newK) % size];
        }
        
        nums.clear();
        for (int i = 0; i < size; ++i) {
            nums.push_back(buffer[i]);
        }
    }
};
