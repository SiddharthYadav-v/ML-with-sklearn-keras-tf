#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> grid[i][j];

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    int maxSum=0;

    function<void(int, int, int)> util=[&](int i, int j, int curSum)->void {
        if(i==n-1 && j==n-1) {
            maxSum=max(maxSum, curSum+grid[i][j]);
            return;
        }

        if(vis[i][j]) return;

        vis[i][j]=true;
        util((i+1)%n, j, curSum+grid[i][j]);
        util(i, (j+1)%n, curSum+grid[i][j]);
        vis[i][j]=false;
    };

    util(0, 0, 0);

    cout << maxSum << "\n";

    // return 1;
}