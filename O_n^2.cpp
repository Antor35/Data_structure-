#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void init(ll x[], ll n){
    for(ll i = 0; i<n; i++){
        x[i]=i;
    }
}

bool _find(ll x[], ll a, ll b){
    if(x[a]==x[b])return true;
    else return false;
}
void _union(ll x[], ll a, ll b, ll n){
    ll tmp=x[a];
    for(ll i =0; i<n; i++){
        if(x[i]==tmp){
            x[i]=x[b];
        }
    }
}
int main(){
    ll n, x[123456],q,a,b;
    cin >> n;
    init(x,n);
    cin >> q;
    // union operation
    while(q--){
        cin >> a >> b;
        _union(x,a,b,n);
    }
    ll t;
    // find operation
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(_find(x,a,b))cout << "Connected" << endl;
        else cout << "Disconnected" << endl;
    }

return 0;
}
