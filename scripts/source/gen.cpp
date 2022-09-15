#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
  #include "dbg.h" 
#else
  #define dbg(x...)
#endif

using ll = long long;

const int N = 1e9;
random_device dev;
mt19937_64 gen(dev()); 
uniform_int_distribution<int> dist(-N , N);

int get(int mn,int mx) {
  return mn + dist(gen)%(mx - mn);
}

vector<int> getvec(int n,int mn,int mx) {
  vector<int> v;
  for (int i = 0;i < n;i++) {
    v.push_back(get(mn, mx));
  }
  return v;
}

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  return 0;
}
