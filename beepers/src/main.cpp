#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  iostream::sync_with_stdio(false);
  cin.tie(nullptr);

  int S;
  cin >> S;
  while (S) {
    int X, Y, Kx, Ky, Cx, Cy, N, bx, by, path, dist, min_dist, min_idx;
    cin >> X >> Y;
    cin >> Kx >> Ky;
    cin >> N;

    auto bs = vector<pair<int, int>>(N);

    for (int i = 0; i < N; i++) {
      cin >> bx >> by;
      bs[i] = {bx, by};
    }

    path = 0;
    Cx = Kx;
    Cy = Ky;
    for (int i = 0; i < N; i++) {
      min_dist = INT32_MAX;
      min_idx = -1;

      for (int j = 0; j < N; j++) {
        dist = abs(Cx - bs[j].first) + abs(Cy - bs[j].second);
        if (dist < min_dist) {
          min_dist = dist;
          min_idx = j;
        }
      }

      path += min_dist;
      Cx = bs[min_idx].first;
      Cy = bs[min_idx].second;

      bs[min_idx] = {INT16_MAX, INT16_MAX};
    }

    path += abs(Cx - Kx) + abs(Cy - Ky);
    cout << path << "\n";

    S--;
  }
}
