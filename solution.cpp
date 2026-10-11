#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int target = n - m;  // Target number of apples left
    
    // DP array: E[k] = expected days to reach target apples left from k apples
    vector<double> dp(n + 1, 0.0);
    
    // Base case: already at target
    dp[target] = 0.0;
    
    // Fill DP from target+1 to n
    for (int k = target + 1; k <= n; k++) {
        double sum = 0.0;
        for (int i = 1; i <= k; i++) {
            int next_apples = max(k - i, target);
            sum += dp[next_apples];
        }
        dp[k] = 1.0 + sum / k;
    }
    
    // Output with 2 decimal places
    cout << fixed << setprecision(2) << dp[n] << endl;
    
    return 0;
}