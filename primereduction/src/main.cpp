#include <bitset>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pair<int, int> primereduce(int);
vi eratosthenes();

auto MEMO = unordered_map<int, pair<int, int>>();

const int LIM = 1e5;
bitset<LIM> is_prime;
vi pr;

int main() {
  iostream::sync_with_stdio(false);
  cin.tie(NULL);

  pr = eratosthenes();

  vi nums = vi();

  int tc;
  cin >> tc;
  while (tc != 4) {
    nums.push_back(tc);
    cin >> tc;
  }

  auto out = vector<pair<int, int>>();
  for (auto n : nums) {
    out.push_back(primereduce(n));
  }

  for (auto r : out) {
    cout << r.first << " " << r.second << "\n";
  }
}

pair<int, int> primereduce(int num) {
  auto cached = MEMO.find(num);
  if (cached != MEMO.end()) {
    return {cached->second.first, cached->second.second};
  }

  int val = num;
  int factor_sum = 0;
  if (val < 1e5 && is_prime[val]) {
    MEMO.insert({num, {val, 1}});
    return {val, 1};
  } else {
    factor_sum = 0;
    for (auto p : pr) {
      while (val % p == 0) {
        factor_sum += p;
        val /= p;
      }

      if (val < 1e5 && is_prime[val]) {
        factor_sum += val;
        break;
      } else if (val == 1) {
        break;
      }
    }

    auto next = primereduce(factor_sum);
    next.second += 1;

    MEMO.insert({num, next});
    return next;
  }
}

vi eratosthenes() {
  const int S = (int)round(sqrt(LIM)), R = LIM / 2;
  vi pr = {2}, sieve(S + 1);
  pr.reserve(int(LIM / log(LIM) * 1.1));
  vector<pii> cp;
  for (int i = 3; i <= S; i += 2)
    if (!sieve[i]) {
      cp.push_back({i, i * i / 2});
      for (int j = i * i; j <= S; j += 2 * i)
        sieve[j] = 1;
    }
  for (int L = 1; L <= R; L += S) {
    vector<bool> block = vector<bool>(S);
    for (auto &[p, idx] : cp)
      for (int i = idx; i < S + L; idx = (i += p))
        block[i - L] = 1;
    rep(i, 0, min(S, R - L)) if (!block[i]) pr.push_back((L + i) * 2 + 1);
  }
  for (int i : pr)
    is_prime[i] = 1;
  return pr;
}
