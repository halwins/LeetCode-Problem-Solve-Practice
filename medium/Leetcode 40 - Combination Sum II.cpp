#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void backtrack(const vector<int>& candidates, vector<vector<int>>& result, vector<int>& current, int index, int target) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (index >= candidates.size() || target < 0) return;

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            
            if (candidates[i] > target) break;
            
            current.push_back(candidates[i]);
            backtrack(candidates, result, current, i + 1, target - candidates[i]);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, result, current, 0, target);
        return result;
    }
};

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution s;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    
    // In kết quả
    for (const auto& comb : result) {
        for (int num : comb) cout << num << " ";
        cout << endl;
    }
    return 0;
}