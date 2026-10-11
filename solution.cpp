#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int target = n - m;
    
    double dp[21];
    int i;
    for (i = 0; i <= n; i++) {
        dp[i] = 0.0;
    }
    
    dp[target] = 0.0;
    
    int k;
    for (k = target + 1; k <= n; k++) {
        double sum = 0.0;
        int j;
        for (j = 1; j <= k; j++) {
            int next_apples = (k - j > target) ? (k - j) : target;
            sum += dp[next_apples];
        }
        dp[k] = 1.0 + sum / k;
    }
    
    printf("%.2f\n", dp[n]);
    
    return 0;
}