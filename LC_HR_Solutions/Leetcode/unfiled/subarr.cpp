// Isaac Abella's Solution

#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // tracking values for traversal of subarray 
        int max_prod = 0;
        int min_prod = 0;
        int result = 0;
        // edge case: vector nums is just 1 in size than just return that
        if (nums.size() == 1) {return nums[0];}

        for(int i = 0; i < nums.size(); i++){
            // traverse the array
            int curr = nums[i];
            if (curr < 0){
                std::swap(max_prod, min_prod);
            }

            // update values
            max_prod = std::max(curr, max_prod * curr);
            min_prod = std::min(curr, min_prod * curr);

            // update result
            result = std::max(result, max_prod);
        }
        return result;
    }
};
