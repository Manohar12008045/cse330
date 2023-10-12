#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N = 5e6+5;
bool prime[N];
ll pre[N];

void sieve(){
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=N; p++){
        if (prime[p] == true){
            for (int i=p*p; i<=N; i += p)
                prime[i] = false;
        }
    }
}

void solve(){
    sieve();
    pre[0]=pre[1]=0;
    for(ll i=2;i<N;i++){
        if(prime[i]){
            pre[i]=(pre[i-1]+((i-1)/2))%mod;
        }
        else{
            pre[i]=pre[i-1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<pre[n]<<endl;
    }
    return 0;
}

