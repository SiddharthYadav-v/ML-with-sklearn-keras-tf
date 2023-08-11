#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
        char c=strs[0][0];
        string res;
        while(true) {
            for(auto &s:strs) {
                if(i>=s.size() || s[i]!=c) return res;
            }

            res+=c;
            i++;

            if(i<strs[0].size()) c=strs[0][i];
        }

        return res;
    }
};

int main() {
    vector<string> strs;
    for(int i=0; i<3; i++) {
        string tmp;
        cin >> tmp;
        strs.push_back(tmp);
    }

    Solution solve;
    string res=solve.longestCommonPrefix(strs);

    cout << res;

    return 0;
}