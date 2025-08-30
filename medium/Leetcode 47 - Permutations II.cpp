#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void backtrack(vector<vector<int>>& result, vector<int>& current, const vector<int>& nums, vector<bool>& used) {
        if (current.size() == nums.size()) {
            result.push_back(current); // Thêm trực tiếp current vào result
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Bỏ qua nếu phần tử đã được dùng hoặc là phần tử trùng lặp ở cùng mức đệ quy
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) continue;

            used[i] = true;
            current.push_back(nums[i]);
            backtrack(result, current, nums, used);
            current.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false); // Mảng theo dõi phần tử đã dùng
        sort(nums.begin(), nums.end()); // Sắp xếp để xử lý trùng lặp
        backtrack(result, current, nums, used);
        return result;
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    Solution s;
    vector<vector<int>> result = s.permuteUnique(nums);
    
    // In kết quả
    for (const auto& perm : result) {
        for (int num : perm) cout << num << " ";
        cout << endl;
    }
    return 0;
}