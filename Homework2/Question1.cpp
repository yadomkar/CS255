//
// Created by Omkar Yadav on 10/28/23.
//

#include <iostream>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

class Homework2Question1 {
public:
    static double findLongestPath(int vertex, int target, vector<vector<pair<int, double>>>& adj) {
        // Base Case: Longest Path from Target to Target is 0
        if(vertex == target) return 0;

        double longestPath = numeric_limits<double>::lowest();

        // Explore all paths from the current vertex to the target, and update the longest path length.
        for(auto& [neighbor, weight]: adj[vertex]) {
            double pathLength = weight + findLongestPath(neighbor, target, adj);
            longestPath = max(longestPath, pathLength);
        }
        return longestPath;
    }

    static double memoizedFindLongestPath(int vertex, int target, vector<vector<pair<int, double>>>& adj, vector<double>& memo) {
        // Base Case: Longest Path from Target to Target is 0
        if(vertex == target) return 0;

        // Check if longest path already computed. If it is return the path.
        if(memo[vertex] != numeric_limits<double>::lowest()) return memo[vertex];

        double longestPath = numeric_limits<double>::lowest();
        for(auto& [neighbor, weight]: adj[vertex]) {
            double pathLength = weight + memoizedFindLongestPath(neighbor, target, adj, memo);
            longestPath = max(longestPath, pathLength);
        }

        // Memoize the computed path.
        return memo[vertex] = longestPath;
    }
};


int main() {
    // Number of vertices
    int V = 5;

    // Adjacency list representation
    // The pair stores (neighbor, edge_weight)
    vector<vector<pair<int, double>>> adj(V);

    // Adding some edges to form a DAG
    // (u, v, w) represents an edge from u to v with weight w
    adj[0].push_back({1, 0.5});
    adj[0].push_back({2, 2.0});
    adj[1].push_back({3, 1.2});
    adj[1].push_back({4, 1.5});
    adj[2].push_back({3, 1.3});
    adj[3].push_back({4, 0.8});

    // Print the adjacency list to verify the graph
    for (int u = 0; u < V; ++u) {
        cout << "Vertex " << u << " has edges to: ";
        for (const auto& [v, w] : adj[u]) {
            cout << "(" << v << ", " << w << ") ";
        }
        cout << endl;
    }

    vector<double> memo(V, numeric_limits<double>::lowest());

    cout << Homework2Question1::findLongestPath(0, 4, adj) << endl;
    cout << Homework2Question1::memoizedFindLongestPath(0, 4, adj, memo) << endl;

    for(auto& ans: memo) {
        cout << ans << " ";
    }

    return 0;
}
