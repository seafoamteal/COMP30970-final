#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

pair<int, int> primereduce(int, int);

auto MEMO = unordered_map<int, pair<int, int>>();
const auto LIM = 1e5;
vector<bool> is_prime(LIM + 1, true);

int main() {
  iostream::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 1e5;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }

  auto out = vector<pair<int, int>>();

  int tc;
  cin >> tc;
  while (tc != 4) {
    out.push_back(primereduce(tc, 0));
    cin >> tc;
  }

  for (auto c : out) {
    cout << c.first << " " << c.second << "\n";
  }
}

pair<int, int> primereduce(int num, int count) {
  auto cached = MEMO.find(num);
  if (cached != MEMO.end()) {
    return {cached->second.first, cached->second.second + count};
  }

  int val = num;
  int factor_sum = 0;
  if (val <= 1e5 && is_prime[val]) {
    MEMO.insert({val, {val, 1}});

    return {val, count + 1};
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

  auto next = primereduce(factor_sum, count + 1);
  MEMO.insert({num, {next.first, next.second - count}});

  return next;
}
