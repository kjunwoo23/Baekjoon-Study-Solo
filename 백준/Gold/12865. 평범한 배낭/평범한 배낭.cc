#include <iostream>
 
using namespace std;
 
int N, K;
int dp[100001];
int weight[101], value[101];
 
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    cin >> N >> K;
    
    for (int i = 1; i <= N; ++i) cin >> weight[i] >> value[i];
    
    for (int i = 1; i <= N; ++i) 
        for (int j = K; j >= 1; --j) 
            if (j - weight[i] >= 0)
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    
    cout << dp[K];
    
    return 0;
}