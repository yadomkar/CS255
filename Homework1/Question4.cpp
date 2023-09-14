//
// Created by Omkar Yadav on 9/4/23.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Question4 {
private:
    void dfs(char vertex, unordered_map<char, vector<char>>& graph, unordered_set<char>& visited, stack<char>& topo) {
        visited.insert(vertex);

        for(char& neighbor: graph[vertex]) {
            if(visited.find(neighbor) == visited.end()) {
                dfs(neighbor, graph, visited, topo);
            }
        }
        topo.push(vertex);
    }

public:
    stack<char> dfsTopologicalSort(unordered_map<char, vector<char>>& graph) {
        stack<char> topo;
        unordered_set<char> visited;
        for(auto& [key, value]: graph){
            if(visited.find(key) == visited.end()) {
                dfs(key, graph, visited, topo);
            }
        }
        return topo;
    }

    static vector<char> kahnsTopologicalSort(unordered_map<char, vector<char>>& graph) {
        vector<char> topo;
        unordered_map<char, int> indegree;

        for(auto& [key, value]: graph) {
            for(auto& node: value) indegree[node]++;
        }

        queue<char> q;
        for(auto& [key, value]: graph) {
            if(indegree[key] == 0) q.push(key);
        }

        while(!q.empty()) {
            char cur = q.front();
            q.pop();
            topo.push_back(cur);
            for(auto& neighbor: graph[cur]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        return topo;
    }
};

int main() {
    unordered_map<char, vector<char>> graph = {
            {'a', {}},
            {'b', {'a', 'd'}},
            {'c', {'a'}},
            {'d', {'a', 'c'}},
            {'e', {'b', 'd', 'g'}},
            {'f', {'c', 'd'}},
            {'g', {'d', 'f'}}
    };

    stack<char> dfsTopologicalSorted = Question4().dfsTopologicalSort(graph);
    vector<char> kahnsTopologicalSorted = Question4::kahnsTopologicalSort(graph);

    cout << "DFS Topological Sort" << endl;
    while(!dfsTopologicalSorted.empty()) {
        cout << dfsTopologicalSorted.top() << " ";
        dfsTopologicalSorted.pop();
    }

    cout << endl << "Kahn's Topological Sort" << endl;
    for(auto& node: kahnsTopologicalSorted) cout << node << " ";

    return 0;
}

/*

Output:

DFS Topological Sort
e b g f d c a
Kahn's Topological Sort
e b g f d c a

 */