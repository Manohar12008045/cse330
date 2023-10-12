#include <bits/stdc++.h>
using namespace std;

#define MAX INT_MAX
#define MIN INT_MIN
#define ll long long int
#define nline "\n"
#define BIG 998244353
#define MOD 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<ll,ll>
#define vi vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vvi vector<vi>
#define vpii vector<pii>
#define ff first
#define ss second
#define mkp make_pair
#define pb emplace_back

ll rec(vpii &arr, ll k, ll i, ll ans){
    if(k<0 || i<0) return ans;
    ll a=0;
    if(k>=arr[i].ff)
        a=rec(arr,k-arr[i].ff, i-1,ans+arr[i].ss);
    ll b=rec(arr,k,i-1,ans);
    return max(a,b);
}
void solve(){
    ll n,k;
    cin>>n>>k;
    vpii arr;
    for(int i=0; i<n; i++){
        ll x,y;
        cin>>x>>y;
        arr.pb(mkp(x,y));
    }
    ll ans=rec(arr,k,n-1,0);
    cout<<ans<<nline;
}
int main()
{
    fast_io;
    
    int t=1;
    cin>>t;
    while(t--) 
        solve();
}
