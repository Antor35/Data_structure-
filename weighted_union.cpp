#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

void init( ll Arr[ ], ll _size[], ll N)
{
    for(ll i = 0;i<N;i++){
        Arr[ i ] = i ;
        _size[ i ] = 1;
    }
}

ll root(ll x[], ll i){
    // Root hobe jodi nije jiner parent hoy
    while(x[i]!=i){
        i=x[i];
    }
   return i;
}
bool _find(ll x[], ll A,ll B)
{
    if( root(x,A)==root(x,B) )  return true ;     //if A and B have same root,means they are connected.return true;
    else return false;
}
void weighted_union(ll x[ ],ll _size[ ],ll A,ll B)
{
    ll root_A = root(x,A);
    ll root_B = root(x,B);
    if(_size[root_A] < _size[root_B ]){
        x[ root_A ] = x[root_B];
        _size[root_B] += _size[root_A];
    }
    else{
        x[ root_B ] = x[root_A];
        _size[root_A] += _size[root_B];
    }
}

int main(){
    ll n, x[123456],_size[123456],q,a,b;
    cin >> n;
    init(x,_size,n);
    cin >> q;
    // union operation
    while(q--){
        cin >> a >> b;
        weighted_union(x,_size,a,b);
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

++++++++++++++++++++++++++Root_Base_implementation++++++++++++++++++++++++++++++++++++++
    #include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

void init(ll x[], ll n){
    // nije nijer parent
    for(ll i = 0; i<n; i++){
        x[i]=i;
    }
}

ll root(ll x[], ll i){
    // Root hobe jodi nije jiner parent hoy
    while(x[i]!=i){
        i=x[i];
    }
   return i;
}
bool _find(ll x[], ll A,ll B)
{
    if( root(x,A)==root(x,B) )  return true ;     //if A and B have same root,means they are connected.return true;
    else return false;
}
ll _union(ll x[], ll A , ll B){
    ll root_A = root(x,A);
    ll root_B = root(x,B);
    x[root_A]= root_B;// A er parent B
}

int main(){
    ll n, x[123456],q,a,b;
    cin >> n;
    init(x,n);
    cin >> q;
    // union operation
    while(q--){
        cin >> a >> b;
        _union(x,a,b);
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
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
