#include <cstdio>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int target = n - m;
    
    double dp[21];
    for (int i = 0; i <= n; i++) {
        dp[i] = 0.0;
    }
    
    dp[target] = 0.0;
    
    for (int k = target + 1; k <= n; k++) {
        double sum = 0.0;
        for (int i = 1; i <= k; i++) {
            int next_apples = (k - i > target) ? (k - i) : target;
            sum += dp[next_apples];
        }
        dp[k] = 1.0 + sum / k;
    }
    
    printf("%.2f\n", dp[n]);
    
    return 0;
}