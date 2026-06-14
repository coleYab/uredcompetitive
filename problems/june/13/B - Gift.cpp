#include <bits/stdc++.h>

using std::vector, std::cin, std::cout, std::endl;

int main() {
  int n; cin >> n;
  vector<vector<int>> ans(n + 1);
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    for(int j = 0; j < x; j++) {
      int y; cin >> y;
      ans[y].push_back(i + 1);
    }
  }

  for(int i = 0; i < n; i++) {
      auto &it = ans[i + 1];
    sort(it.begin(), it.end());
    cout << it.size();
    for(auto &jt : it) cout << " " << jt;
    cout << endl;
  }
}
