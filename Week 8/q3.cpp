#include<bits/stdc++.h>
using namespace std; 

struct edge
{
    int u,v,w; 
};

struct UnionFind
{
    vector<int> parent; 
    vector<int> set_size; 
    void init(int sz)
    {
        parent.assign(sz+1,0); 
        set_size.assign(sz+1,1); 
        iota(parent.begin(),parent.end(),0); 
    }
    int find(int s)
    {
        if (s == parent[s])
            return s;
        return parent[s] = find(parent[s]);
    }
    void merge(int u, int v)
    {
        u = find(u); 
        v = find(v); 
        if(set_size[u] > set_size[v])
            swap(u,v); 
        parent[u] = v; 
        set_size[v] += set_size[u]; 
    }
};

int main()
{
    freopen("input3.txt","r",stdin); 
    freopen("output.txt","w",stdout); 

    int n,e; cin>>n>>e; 
    vector<edge> edges(e); 
    vector<int> mst_edges;
    for(int i = 0; i < e; i++)
    {
        cin>>edges[i].u>>edges[i].v>>edges[i].w; 
    }
    sort(edges.begin(),edges.end(),[](auto a, auto b)
    {
        return a.w < b.w; 
    }); 
    UnionFind UF; 
    UF.init(n); 
    for(int i = 0; i < e && mst_edges.size() < n; i++)
    {
        if(UF.find(edges[i].u) != UF.find(edges[i].v)) 
        {
            UF.merge(edges[i].u,edges[i].v); 
            mst_edges.push_back(i); 
        }
    }
    long long wt = LONG_LONG_MAX;  
    vector<int> second_mst_edges; 
    for(auto excluded_edge : mst_edges)
    {
        UnionFind UF; 
        UF.init(n); 
        vector<int> temp_edges; 
        long long temp_wt = 0; 
        for(int i = 0; i < e && temp_edges.size() < n; i++)
        {   
            if(i == excluded_edge) continue; 
            if(UF.find(edges[i].u) != UF.find(edges[i].v)) 
            {
                UF.merge(edges[i].u,edges[i].v); 
                temp_edges.push_back(i);
                temp_wt += edges[i].w;  
            }
        }
        if(temp_wt < wt)
        {
            wt = temp_wt; 
            second_mst_edges = temp_edges;  
        }
    }
    cout<<"Weight: "<<wt<<"\n"; 
    cout<<"Edges are: \n";
    for(auto idx : second_mst_edges)
    {
        cout<<edges[idx].u<<" "<<edges[idx].v<<" "<<edges[idx].w<<"\n"; 
    } 
}