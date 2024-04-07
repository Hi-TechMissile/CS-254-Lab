#include <bits/stdc++.h>
using namespace std;

int minCost(int n, int m, int mask, int prev, int color,vector<vector<pair<int,int>>> &graph,vector<vector<pair<int,int>>> &dp)
{
    if (mask == ((1 << n) - 1))
        return 0; 
    if(color == 0) 
        return dp[mask][prev].first; 
    else 
        return dp[mask][prev].second; 
    int ans = INT_MAX;   
    for (int i = 0; i < n; i++)
    {
        if(color == 1 && graph[prev][i].first && !(mask & (1<<i)))
            ans = min(ans, graph[prev][i].first + minCost(n,m,mask|(1<<i),i,0,graph,dp)); 
        if(color == 0 && graph[prev][i].second && !(mask & (1<<i)))
            ans = min(ans, graph[prev][i].second + minCost(n,m,mask|(1<<i),i,1,graph,dp)); 
    }
    if(color == 0)
        return dp[mask][prev].first;
    else 
        return dp[mask][prev].second;
}

int main()
{
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int n,m; cin>>n>>m; 
    vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>(n)); 
    vector<vector<pair<int,int>>> dp(1<<n,vector<pair<int,int>>(n)); 
    for(int i = 0; i < m; i++)
    {
        int u,v,color,w; 
        cin>>u>>v>>color>>w; 
        if(color == 0)
            graph[u][v].first = graph[v][u].first = w; 
        else
            graph[u][v].second = graph[v][u].second = w; 
    }
    for(int i = 0; i < m; i++)
    {
        int u,v,color; cin>>u>>v>>color; 
        if(color == 0) 
            graph[u][v].first = 1; 
        else 
            graph[u][v].second = 1; 
    }    
    int ans = INT_MAX; 
    for(int i = 0; i < n; i++)
    {
        ans = min(ans, minCost(n,m,1<<i,i,2,graph,dp)); 
    }
    cout<<ans<<"\n"; 
}
