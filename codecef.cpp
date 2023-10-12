#include <bits/stdc++.h>
using namespace std;
#define int long long
#ifdef ONPC
#include "/mydebug.h"
#else
#define debug(...) 1
#endif

int cal(int x) { return x * ( x + 1 ) / 2 ;}

int f(int low, int high, int x){
    if(low > high) return -1;
    int mid = (low + high) / 2;
    if(cal(mid) <= x && cal(mid + 1) > x) return mid;
    if(cal(mid) > x) return f(low, mid - 1, x);
    else return f(mid+1, high, x);
}

void solve(){
    int n;
    cin>>n;
    int x = 2;
    int ans = 0;
    while(n - x >= 0){
        ans += (n - x) / 2;
        x += 2;
    }
    cout<<ans<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) solve();
}

