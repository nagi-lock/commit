class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& path, vector<string>& result) {
        if (path.size() == 4) {
            if (start == s.length()) {
                result.push_back(join(path));
            }
            return;
        }

        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.length()) break;

            string segment = s.substr(start, len);

            if (isValid(segment)) {
                path.push_back(segment);
                backtrack(s, start + len, path, result);
                path.pop_back();
            }
        }
    }

    bool isValid(const string& segment) {
        if (segment.length() > 1 && segment[0] == '0') return false; // leading zero
        int val = stoi(segment);
        return val >= 0 && val <= 255;
    }

    string join(const vector<string>& path) {
        return path[0] + "." + path[1] + "." + path[2] + "." + path[3];
    }
};