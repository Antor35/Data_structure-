#include<bits/stdc++.h>
using namespace std;
#define N 200200


vector<int>g[N];
int chainId[N],chainpos[N],chainHead[N],chainLength[N],Base[N],Baspos[N];
int chain_no=0,pos=0;
int sz[N],par[N];

void dfs(int nd, int pr){
    sz[nd]=1;
    for(int i=0; i<g[nd].size(); i++){
        int v = g[nd][i];
        if(v!=pr){
            par[v]=nd;
            dfs(v,nd);
            sz[nd]+=sz[v];
        }
    }
}
void HLD(int cur){
    if(chainHead[chain_no]==-1)
        chainHead[chain_no]=cur;

    chainId[cur]=chain_no;
    chainpos[cur]=chainLength[chain_no];
    chainLength[chain_no]++;

    Base[pos]=cur;
    Baspos[cur]=pos;
    pos++;


    int sc = -1 ;
    int index=-1;
    int mx=-1;
    for(int i=0; i<g[cur].size(); i++){
        int v =g[cur][i];
        if(par[cur]!= v){
            if(sz[v] > mx){
                mx = sz[v];
                index = i ;
            }
        }
    }


    if(index != -1){
        sc  = g[cur][index] ;
        HLD(g[cur][index]) ;

    }

    for(int i=0; i<g[cur].size();i++){
        int v = g[cur][i];
        if(par[cur]!= v && v != sc ){
            chain_no++;
            HLD(g[cur][i]);
        }
    }

}


int main(){

    int nd,v,u;
    cin >> nd ;
    for(int i=1; i<nd; i++){
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(1,-1);
    memset(chainHead,-1,sizeof(chainHead));
    memset(chainLength,0,sizeof(chainLength));

    chain_no=0,pos=0;
    HLD(1) ;

    for(int i=0; i<=chain_no ; i++){
        cout << chainHead[i]<< " ";
    }
    cout << endl;
return 0;
}
