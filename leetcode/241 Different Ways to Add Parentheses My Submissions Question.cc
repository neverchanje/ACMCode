class Solution {
public:

    vector<int> nums;
    typedef binary_function<int, int, int> Op;
    vector<char> ops;

    int readNum(const string &s, int *pi) {
        int ret = 0;
        int i = (*pi);
        for(; i < s.length() && s[i] <= '9' && s[i] >= '0'; i++) {
            ret *= 10;
            ret += s[i]-'0';
        }
        (*pi) = i;
        return ret;
    }
    
    char readOp(const string &s, int *pi) {
          int i = (*pi);
          (*pi)++;
          return s[i];
    }
    
    vector<int> dfs(int l, int r) {
        vector<int> ret;
        if(l == r) {
            ret.push_back(nums[l]);
            return ret;
        }
        
        for(int m = l; m < r; m++) {
            for(int u : dfs(l, m)) {
                for(int v : dfs(m+1, r)) {
                    if(ops[m] == '*') {
                        ret.push_back(u * v);
                    } else if(ops[m] == '+') {
                        ret.push_back(u + v);
                    } else {
                        ret.push_back(u - v);
                    }
                }
            }
        }
        return ret;
    }

    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        if(input.length() == 0) 
            return ans;
            
        int si = 0;
        nums.push_back(readNum(input, &si));

        while(si < input.length()) {
            ops.push_back(readOp(input, &si));
            nums.push_back(readNum(input, &si));
        }
        
        ans = dfs(0, nums.size() - 1);
        sort(ans.begin(), ans.end());
        return ans;
    }
};