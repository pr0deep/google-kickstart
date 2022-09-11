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
  cout << "Case #" << t << ": " << x << '\n';
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
      
  }
  
  return 0;
}
