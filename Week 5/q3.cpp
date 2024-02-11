#include<bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<bool>> &adj, vector<int> &color, bool &is_bipartite)
{
    for(int i = 0; i < adj.size(); i++)
    {
        if(adj[v][i])
        {
            if(color[i] == 0)
            {
                color[i] = -color[v]; 
                dfs(i, adj, color, is_bipartite); 
            }
            else if(color[i] == color[v])
            {
                is_bipartite = false; 
                return; 
            }
        }
    }
}

int main()
{
    // file IO
    freopen("input3.txt", "r", stdin); 
    // please comment the above line and uncomment the one below to see different outputs
    // freopen("input3_1.txt", "r", stdin);

    // here we are using adjacency matrix for representing the edges of the graph 
    int number_of_nodes; 
    cin>>number_of_nodes; 
    vector<vector<bool>> adj(number_of_nodes, vector<bool>(number_of_nodes)); 
    for(int i = 0; i < number_of_nodes; ++i)
    {
        for(int j = 0; j < number_of_nodes; ++j)
        {
            char ch; cin>>ch; 
            if (i != j)
                adj[i][j] = (ch == '0'); 
        }
    }

    bool is_bipartite = true; 
    vector<int> color(number_of_nodes,0);
    for(int i = 0; i < number_of_nodes; ++i)
    {
        if(color[i] == 0)
        {
            color[i] = 1; 
            dfs(i, adj, color, is_bipartite); 
        }
    }  

    if(is_bipartite) 
    {
        cout<<"It can be divided into two cliques\n"; 
    }
    else
    {
        cout<<"It cannot be divided into two cliques\n"; 
    }

    return 0;
}