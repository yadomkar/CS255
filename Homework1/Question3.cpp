// Created by Omkar Yadav on 9/3/23.
//
//

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>

using namespace std;

class Question3 {
public:
    static vector<int> breadthFirstSearch(unordered_map<int, vector<pair<int, int>>>& graph, int start) {
        vector<int> visitedOrder;
        queue<int> q;
        unordered_set<int> visited;

        q.push(start);
        visited.insert(start);
        visitedOrder.push_back(start);

        while(!q.empty()) {
            int cur = q.front(); q.pop();

            for(pair<int, int>& neighbor: graph[cur]) {
                if(visited.find(neighbor.first) == visited.end()) {
                    q.push(neighbor.first);
                    visited.insert(neighbor.first);
                    visitedOrder.push_back(neighbor.first);
                }
            }
        }

        return visitedOrder;
    }

    void dfsHelper(int start, unordered_map<int, vector<pair<int, int>>>& graph, unordered_set<int>& visited, vector<int>& visitedOrder) {
        visited.insert(start);
        visitedOrder.push_back(start);

        for(pair<int, int>& neighbor: graph[start]) {
            if(visited.find(neighbor.first) == visited.end()) {
                dfsHelper(neighbor.first, graph, visited, visitedOrder);
            }
        }
    }

    vector<int> depthFirstSearch(unordered_map<int, vector<pair<int, int>>>& graph, int start) {
        vector<int> visitedOrder;
        unordered_set<int> visited;
        dfsHelper(start, graph, visited, visitedOrder);
        return visitedOrder;
    }
};

int main() {
    unordered_map<int, vector<pair<int, int>>> graph = {
            {0, {{2, 1}, {3, 1}}},
            {1, {{2, 1}, {5, 1}, {6, 1}}},
            {2, {{0, 1}, {1, 1}, {4, 1}}},
            {3, {{0, 1}, {7, 1}}},
            {4, {{2, 1}, {6, 1}}},
            {5, {{1, 1}, {6, 1}}},
            {6, {{1, 1}, {4, 1}, {5, 1}}},
            {7, {{3, 1}}}
    };

    vector<int> bfsOrderVisited = Question3::breadthFirstSearch(graph, 0);
    vector<int> dfsOrderVisited = Question3().depthFirstSearch(graph, 0);

    cout << "BFS: ";
    for(int& node: bfsOrderVisited) {
        cout << node << " ";
    }

    cout << endl << "DFS: ";
    for(int& node: dfsOrderVisited) {
        cout << node << " ";
    }
}