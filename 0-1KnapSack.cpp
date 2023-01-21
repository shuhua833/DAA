#include<iostream>
using namespace std;

int knapsack(int  weights[], int  profits[], int n, int maxWeight) {

  int dp[20][20];
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < maxWeight + 1; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      }
      else if (weights[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + profits[i - 1]);
      }
    }
  }
  return dp[n][maxWeight];
}

int main() {
  int n=7;
  int weights[]={ 3,5,7,4,3,9,2 };
  int profits[]={ 2,3,3,4,4,5,7};
  int maxWeight=9;
  
  cout << knapsack(weights, profits, n, maxWeight);
}
