// C++ program to find the longest
// path in the DAG

//source : Geeks for geeks
/* link source  : https://www.geeksforgeeks.org/longest-path-in-a-directed-acyclic-graph-dynamic-programming/ */

#include <bits/stdc++.h>
using namespace std;

// Function to traverse the DAG
// and apply Dynamic Programming
// to find the longest path

void dfs(int node, vector<int> adj[], int dp[], bool vis[])
{
//dp = dynamic programming. menyimpan semacam nilai kedalaman 
    
    // Mark as visited

    vis[node] = true;

    // Traverse for all its children
    for (int i = 0; i < adj[node].size(); i++) {

        // If not visited
        if (!vis[adj[node][i]])
            dfs(adj[node][i], adj, dp, vis);

        // Store the max of the paths
        dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
    }
}

// Function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

// Function that returns the longest path
int findLongestPath(vector<int> adj[], int n)
{
    // Dp array
    int dp[n + 1];
    memset(dp, 0, sizeof dp);

    // Visited array to know if the node
    // has been visited previously or not

    bool vis[n + 1];

    memset(vis, false, sizeof vis);

    // Call DFS for every unvisited vertex
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i, adj, dp, vis);
    }

    int ans = 0;
    // Traverse and find the maximum of all dp[i]
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }

    return ans;

}

  

// Driver Code

int main()
{
    int n;
    
    cin >> n;
    
    vector<int> adj[n + 1];
    int a, b;
    
    for(int i=0; i<n; i++){
        cin >> a >> b;
        
        addEdge(adj, a, b);
        
    }

    cout << findLongestPath(adj, n);
    return 0;
}
