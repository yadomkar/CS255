//
// Created by Omkar Yadav on 9/4/23.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>

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

    stack<char> topologicalSorted = Question4().dfsTopologicalSort(graph);

    while(!topologicalSorted.empty()) {
        cout << topologicalSorted.top() << " ";
        topologicalSorted.pop();
    }

    return 0;
}

/*

 Output:
 e b g f d c a

 */