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
const ll pinf = 1e17;
const ll ninf = -1e17;

int main() 
{
  ios_base::sync_with_stdio(false); 
  cin.tie(nullptr);
  
  int T;
  cin >> T;
  for (int test_case = 1;test_case <= T;test_case++) {
    ll n, e;
    cin >> n >> e;

    map<ll,vector<array<ll,2>>> m;
    map<ll,array<vector<ll>,2>> dp;

    for (int i = 0;i < n;i++) {
      ll x, y, c;
      cin >> x >> y >> c;
      m[y].push_back({x , c});
    }
    
    m[pinf].push_back({0 , 0}); 

    auto i = m.rbegin(); ++i;
    ll ans = 0,yp = pinf;
    
    for (;i != m.rend();i++) {
      auto y = i->first; auto& v = i->second;
      sort(v.begin(),v.end());

      auto& pv = m[yp];
      auto& L = dp[y][1];
      auto& R = dp[y][0];
      auto& PL = dp[yp][1];
      auto& PR = dp[yp][0];

      ll layer_sum = accumulate(v.begin(),v.end(),0LL),
         prmax = *max_element(R.begin(),R.end()), 
         plmax = *max_element(L.begin(),L.end());

      // R
      ll crmax = max(prmax - 2*e + layer_sum,plmax - 3*e + layer_sum);
      R.assign(v.size() , crmax);

      for (ll j = 0,prf = 0,ptr = 0,mx1 = ninf,mx2 = ninf;j < v.size();j++) {
        prf += v[j][1];
        if (mx2 != ninf)
          mx2 += v[j][1];
        for (;ptr < m[yp].size() and pv[ptr][1] <= v[j][0];ptr++) {
          mx1 = max(mx1 , PL[ptr]);
          mx2 = max(mx2 , PR[ptr] + v[j][1]);
        }
        if (mx1 != ninf)
          R[j] = max(R[j], mx1 - e + prf);
        R[j] = max(R[j], mx2);
      }

      for (ll j = v.size() - 1,ptr = pv.size() - 1,mx = ninf;j >= 0;j--) {
        if (mx != ninf)
          mx += v[j][1];
        for (;ptr >= 0 and pv[ptr][0] >= v[j][0];ptr--) {
          mx = max(mx , PL[ptr] + v[j][1]);
        }
        R[j] = max(R[j] , mx - e);
      }

      // L
      //

      ll clmax = max(prmax - 3*e + layer_sum,plmax - 2*e + layer_sum);
      dp[y][1].assign(v.size() , clmax);

      for (ll j = v.size() - 1,ptr = m[yp].size() - 1,m1 = ninf,m2 = ninf,sfx = 0;j >= 0;j--) {
        sfx += v[j].second;
        if (m2 != ninf)
          m2 += v[j].second;
        for (;ptr >= 0 and m[yp][ptr].first >= v[j].first;ptr--) {
          m1 = max(m1 , dp[yp][0][ptr]);
          m2 = max(m2 , v[j].second + dp[yp][1][ptr]);
        }
        if (m1 != ninf)
          dp[y][1][j] = max(dp[y][1][j] , m1 - e + sfx);
        dp[y][1][j] = max(dp[y][1][j] , m2);
      }
      
      for (ll j = 0;j < v.size();j++) {

      }

      for (auto j : dp[y])
        for (auto k : j)
          ans = max(ans , k);
      yp = y;
    }
    print(test_case, ans);
  }
  
  return 0;
}
