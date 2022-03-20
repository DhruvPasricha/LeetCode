// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


#define pii pair<int, int>

struct edge
{
    int u;
    int v;
    int wt;

    edge(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }

    void print()
    {
        if (this->u > this->v)
            swap(this->u, this->v);

        cout << this->u << " - " << this->v << " : " << this->wt << endl;
    }
};

bool operator<(edge a, edge b)
{
    return a.wt < b.wt;
}

int prims(vector<pii> Adj[], int n)
{

    vector<bool> visited(n, false);
    vector<pii> parent(n, {-1, INT_MAX});

    visited[0] = true;

    multiset<edge> st;

    for (auto &it : Adj[0])
    {
        edge e(0, it.first, it.second);
        st.insert(e);
    }

    while (not st.empty())
    {

        auto bestEdge = *st.begin();
        int u = bestEdge.u;
        int v = bestEdge.v;
        int wt = bestEdge.wt;
        
        st.erase(st.begin());


        if (visited[u] and visited[v])
            continue;

        if (visited[v])
            swap(u, v);

        // now u is visited and v is unvisited
        parent[v].first = u;
        parent[v].second = wt;
        visited[v] = true;

        for (auto &it : Adj[v])
        {
            edge e(v, it.first, it.second);
            st.insert(e);
        }
    }

    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {

        if (parent[i].first == -1)
            continue;

        ans += parent[i].second;
        // edge e(i, parent[i].first, parent[i].second);
        // e.print();
    }
    
    return  ans;
}


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<pii> A[V];
        
        for(int i = 0; i < V;i++) {
            
            for(auto &a : adj[i]) {
                
                A[i].push_back({a[0], a[1]});
            }
        }
        

        return prims(A, V);
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends