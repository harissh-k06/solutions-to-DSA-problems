class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0) return; // handle empty
        k = k % size;          // handle k >= size
        if (k == 0) return;    // handle no rotation

        // For a RIGHT rotate, the first part of the new array
        // is the LAST k elements of the old array.
        vector<int> firstPart;
        for (int i = size - k; i < size; i++) { // get last k elements
            firstPart.emplace_back(nums[i]);
        }

        // The second part is the first n-k elements.
        vector<int> secondPart;
        for (int i = 0; i < size - k; i++) { // get first n-k elements
            secondPart.emplace_back(nums[i]);
        }

        // Your merging logic is perfect, so we keep it as is.
        int idx = 0;
        for (const auto& num : firstPart) {
            nums[idx++] = num;
        }
        for (const auto& num : secondPart) {
            nums[idx++] = num;
        }
    }
};