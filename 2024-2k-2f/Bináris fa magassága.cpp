#include <bits/stdc++.h>
using namespace std;

int main() {
   int n,m; cin >> n >> m;
   const int MAXX= 1 << n;

   vector <int> dp(MAXX,0);
   vector <int> elhossz(MAXX,1);
    for (int i=MAXX/2-1; i>0; i--) {
        dp[i]=max(dp[i*2],dp[i*2+1])+1;
    }

   dp[0]=0;
   for (int a,hossz, i=0; i<m; i++) {
        cin >> a >> hossz;
        elhossz[a]=hossz;
        for (int j=a; j>0; j=j/2) {
            int bal=j*2, jobb=j*2+1;
            if (j*2<MAXX) {
                dp[j]=max(dp[bal]+elhossz[bal],
                      dp[jobb]+elhossz[jobb]);
            }
        }
        cout << dp[1] << "\n";
   }
}
