#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,k,l,f;
    cin >> n >> k >> l >> f;
    bool riado=0;
    long long ans=0;
    long long cnt_meleg=0, cnt_hideg=0;
    for (long long a, i=0; i<n; i++) {
        cin >> a;
        if (a>f) {
            cnt_meleg++;
            cnt_hideg=0;
        }
        else if (a<f) {
            cnt_hideg++;
            cnt_meleg=0;
        }
        else {
            cnt_meleg=0;
            cnt_hideg=0;
        }
        if (!riado && cnt_meleg==k) {
            riado=1;
            ans++;
            cnt_meleg=0;
        }
        else if (riado && cnt_hideg==l) {
            riado=0;
            cnt_hideg=0;
        }
    }
    cout << ans;
}
