//  =====================================
//    Starting by the Name of Allah
//  =====================================
//    S. M. Shaheen Sha (shan)
//    shaheen.cse20@gmail.com
//  =====================================
// clang-format off
#include <bits/stdc++.h>
#define  FAST    ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
//              0123456789
#define     MX  100007
// clang-format on

int dp[MX];

int solve(int n) {
  if (n == 1) return 1;

  if (n < MX && dp[n] != -1) return dp[n];

  int ret;

  if (n & 1)
    ret = solve((3 * n + 1) / 2) + 2;
  else
    ret = solve(n / 2) + 1;

  if (n < MX) dp[n] = ret;

  return ret;
}

void TestCase() {
  memset(dp, -1, sizeof dp);

  int a, b;

  while (cin >> a >> b) {
    int result = 0;

    int x = min(a, b);
    int y = max(a, b);

    for (int i = x; i <= y; i++) {
      int steps = solve(i);
      result = max(result, steps);
    }
    cout << a << " " << b << " " << result << endl;
  }
}

int main() {
  FAST;

  TestCase();

  return 0;
}
