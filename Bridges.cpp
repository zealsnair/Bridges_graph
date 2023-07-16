#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define lp(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
#define map map<int,vector<int>>
const int N=1e5+2;
vector<int> adj[N];

void dfs(int node,int parent, vi &vis,vi &tin,vi &low,int &timer,vi adj[]){
    vis[node]=1;
    tin[node]=low[node]=timer++;
    for(auto it:adj[node]){
        if(it==parent)continue;
        if(!vis[it]){
            dfs(it,node,vis,tin,low,timer,adj);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node]){
                cout<<node<<"to"<<it<<endl;
            }
        }
        else 
        low[node]=min(low[node],tin[it]);
        
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    lp(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi tin(n,-1);
    vi low(n,-1);
    vi vis(n,0);
    int timer=0;
    lp(i,0,n){
        if(!vis[i]){
            dfs(1,-1,vis,tin,low,timer,adj);
        }
    }

    return 0;
}
