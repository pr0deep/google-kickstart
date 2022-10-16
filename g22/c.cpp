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

// source : kactl (https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/SegmentTree.h)
// query => [b ,e)
struct Tree {
  typedef int T;
  static constexpr T unit = 1e9;
  T f(T a, T b) { return min(a, b); }
  vector<T> s; int n;
  Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
  void update(int pos, T val) {
    for (s[pos += n] = val; pos /= 2;)
      s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  T query(int b, int e) { 
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
  }
    return f(ra, rb);
  }
};

int main() 
{
  ios_base::sync_with_stdio(false); 
  cin.tie(nullptr);
  
  int T;
  cin >> T;
  for (int test_case = 1;test_case <= T;test_case++) {
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a)
      cin >> i;
    vector<int> pre(n + 1,0);
    Tree t(n + 5);
    for (int i = 1;i <= n;i++) {
      pre[i] = pre[i - 1] + a[i - 1];
      t.update(i - 1 , pre[i]);
    }

    vector<ll> pp(n + 1,0);
    for (int i = 1;i <= n;i++) {
      pp[i] = pp[i - 1] + pre[i];
    }

    ll ans = 0;
    for (int i = 0;i < n;i++) {
      int l = i,r = n - 1;
      while (l <= r) {
        int m = (l + r)/2;
        int mn = t.query(i , m + 1);
        dbg(i ,m, mn , pre[i]);
        if (mn - pre[i] >= 0) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      dbg(i , l);
      ll x = l - 1;
      ll s = (pp[x + 1] - pp[i]) - (x - i + 1)*pre[i];
      dbg(x + 1,i , x - i + 1,i, s);
      ans += s;
    }
    print(test_case , ans);
    
  }
  
  return 0;
}
