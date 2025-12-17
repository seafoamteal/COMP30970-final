#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  iostream::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 1e5;
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }

  auto out = vector<pair<int, int>>();

  int val, factor_sum, count;
  cin >> val;
  while (val != 4) {
    count = 0;

    while (true) {
      count++;
      if (val <= 1e5 && is_prime[val]) {
        factor_sum = val;
      } else {
        factor_sum = 0;
        for (int i = 0; i <= 1e5 && val != 1; i++) {
          if (is_prime[i]) {
            while (val % i == 0) {
              factor_sum += i;
              val /= i;
            }
          }
        }
      }

      if (factor_sum == val) {
        break;
      } else {
        val = factor_sum;
      }
    }

    out.push_back({val, count});
    cin >> val;
  }

  for (auto c : out) {
    cout << c.first << " " << c.second << "\n";
  }
}
