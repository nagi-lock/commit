class Solution {
    //https://understanding-recursion.readthedocs.io/en/latest/09%20Pascal.html
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        return pascalsHelper(numRows, ans);
    }

private:
    vector<vector<int>> pascalsHelper(int numRows, vector<vector<int>>& ans) {
        if (numRows == 0) {
            return ans;
        }

        // Recursively build up to numRows - 1
        pascalsHelper(numRows - 1, ans);

        // Create the current row
        vector<int> newRow;
        newRow.push_back(1);

        if (!ans.empty()) {
            vector<int>& lastRow = ans.back();
            for (int i = 1; i < lastRow.size(); ++i) {
                newRow.push_back(lastRow[i - 1] + lastRow[i]);
            }
            newRow.push_back(1);
        }

        ans.push_back(newRow);
        return ans;
    }
};
