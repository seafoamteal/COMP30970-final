#include <iostream>
using namespace std;

int main() {
  iostream::sync_with_stdio(false);
  cin.tie(nullptr);

  string before, after;
  cin >> before;
  cin >> after;

  size_t i = 0;
  while (i < before.size() && i < after.size() && before[i] == after[i]) {
    i++;
  }

  // case nothing was added
  if (i == after.size()) {
    cout << 0 << endl;
    return 0;
  }

  size_t j = 0;
  while (j < before.size() - i &&
         after[after.size() - 1 - j] == before[before.size() - 1 - j]) {
    j++;
  }

  cout << after.size() - j - i << endl;
}
