#include <bits/stdc++.h>

using namespace std;

#ifdef PRADEEP
  #include "dbg.h" 
#else
  #define dbg(x...)
#endif

using ll = long long;

ostream& operator<<(ostream& os,const vector<int>& x) {
  for (const int& i : x) { os << i << ' '; }
  return os;
}

ostream& operator<<(ostream& os,const vector<double>& x) {
  for (const double& i : x) { os << setprecision(17) << i << ' '; }
  return os;
}

template <typename T>
void print(int t,const T& x) {
  cout << "Case #" << t << ": " << fixed << setprecision(10) << x << '\n';
}

// constants ..
const int N = 1e6+5;

int main() 
{
  ios_base::sync_with_stdio(false); 
  cin.tie(nullptr);
  
  int T;
  cin >> T;
  for (int test_case = 1;test_case <= T;test_case++) {
    int m, n, p;
    cin >> m >> n >> p;
    --p;
    vector<int> a(n , 0);
    vector<int> b(n , 0);
    for (int i = 0;i < m;i++) {
      for (int j = 0;j < n;j++) {
        int x; cin >> x;
        if (i == p) {
          b[j] = x;
        } else {
          a[j] = max(a[j] , x);
        }
      }
    }
    int ans = 0;
    for (int i = 0;i < n;i++) {
      if (b[i] < a[i]) {
        ans += a[i] - b[i];
      }
    }
    print(test_case, ans);
  }
  
  return 0;
}
