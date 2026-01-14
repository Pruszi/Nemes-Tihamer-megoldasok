#include <bits/stdc++.h>
using namespace std;

int main() {
   long long int n,k; cin >> n >> k;
   long long int cnt=0;
    for (long long int i=0; i<n; i++) {
        int a; cin >> a;
        cnt+=a;
    }
    cout << (cnt-k+1)*(cnt-k+2)/2;
}
