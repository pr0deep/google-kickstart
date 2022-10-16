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
    ll r1, r2, n;
    cin >> r1 >> r2 >> n;
    using T = array<ll,2>;
    vector<T> v1(n);
    for (int i = 0;i < n;i++) {
      cin >> v1[i][0] >> v1[i][1];
    }
    int m;
    cin >> m;
    vector<T> v2(m);
    for (int i = 0;i < m;i++) {
      cin >> v2[i][0] >> v2[i][1];
    }
    
    vector<T> a, b;
    ll D = (r1 + r2)*(r1 + r2);
    for (int i = 0;i < n;i++) {
      ll d = (v1[i][0] * v1[i][0]) + (v1[i][1] * v1[i][1]);
      if (d > D) {
        continue ;
      }
      a.push_back(v1[i]);
    }
    for (int i = 0;i < m;i++) {
      ll d = (v2[i][0] * v2[i][0]) + (v2[i][1] * v2[i][1]);
      if (d > D) {
        continue ;
      }
      b.push_back(v2[i]);
    }

    ll d1 = 1e18, d2 = 1e18;
    for (auto i : a) {
      d1 = min(d1 , i[0]*i[0] + i[1]*i[1]);
    }
    for (auto i : b) {
      d2 = min(d2 , i[0]*i[0] + i[1]*i[1]);
    }
    auto cnt = [](vector<T> r,ll cut) {
      int ret = 0;
      for (auto i : r) {
        if (i[0]*i[0] + i[1]*i[1] <= cut) 
          ret++;
      }
      return ret;
    };
    dbg(a , b , d1 , d2);
    vector<int> ans(2 , 0);
    if (a.empty() and b.empty()) {
    } else if (d1 == d2) {
      ans[0] = cnt(a , d1);
      ans[1] = cnt(b , d1);
    } else if (d1 < d2) {
      ans[0] = cnt(a , d2);
    } else {
      ans[1] = cnt(b , d1);
    }
    print(test_case , ans);
  }
  
  return 0;
}
