// Created by Omkar Yadav on 9/3/23.
//
//

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Question3 {
public:
//  BFS
    static vector<int> breadthFirstSearch(vector<vector<pair<int, int>>>& graph, int start) {
        vector<int> visitedOrder;
        queue<int> q;
        vector<bool> visited(graph.size(), false);

        q.push(start);
        visited[start] = true;
        visitedOrder.push_back(start);

        while(!q.empty()) {
            int cur = q.front(); q.pop();

            for(pair<int, int>& neighbor: graph[cur]) {
                if(!visited[neighbor.first]) {
                    q.push(neighbor.first);
                    visited[neighbor.first] = true;
                    visitedOrder.push_back(neighbor.first);
                }
            }
        }

        return visitedOrder;
    }

//  DFS
    void dfsHelper(int start, vector<vector<pair<int, int>>>& graph, vector<bool>& visited, vector<int>& visitedOrder) {
        visited[start] = true;
        visitedOrder.push_back(start);

        for(pair<int, int>& neighbor: graph[start]) {
            if(!visited[neighbor.first]) {
                dfsHelper(neighbor.first, graph, visited, visitedOrder);
            }
        }
    }

    vector<int> depthFirstSearch(vector<vector<pair<int, int>>>& graph, int start) {
        vector<int> visitedOrder;
        vector<bool> visited(graph.size(), false);
        dfsHelper(start, graph, visited, visitedOrder);
        return visitedOrder;
    }

//  Shortest Path
    static vector<int> dijkstraShortestPath(vector<vector<pair<int, int>>>& graph, int start) {
        vector<int> distance(graph.size(), INT_MAX);
        auto comp = [](pair<int, int>& a, pair<int, int>& b) { return a.second < b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);

        distance[start] = 0;
        minHeap.push({start, 0});

        while(!minHeap.empty()) {
            int cur = minHeap.top().first;
            minHeap.pop();

            for(const auto& neighbor: graph[cur]) {
                if(distance[neighbor.first] > distance[cur] + neighbor.second) {
                    distance[neighbor.first] = distance[cur] + neighbor.second;
                    minHeap.push(neighbor);
                }
            }
        }
        return distance;
    }

//  Using BFS to find Shortest Path
    static vector<int> bfsShortestPath(vector<vector<pair<int, int>>>& graph, int start) {
        queue<int> q;
        vector<int> distance(graph.size(), -1);

        q.push(start);
        distance[start] = 0;

        while(!q.empty()) {
            int cur = q.front(); q.pop();

            for(pair<int, int>& neighbor: graph[cur]) {
                if(distance[neighbor.first] < 0) {
                    q.push(neighbor.first);
                    distance[neighbor.first] = distance[cur] + 1;
                }
            }
        }
        return distance;
    }
};

int main() {
    vector<vector<pair<int, int>>> graph = {
            {{2, 1}, {3, 1}},
            {{2, 1}, {5, 1}, {6, 1}},
            {{0, 1}, {1, 1}, {4, 1}},
            {{0, 1}, {7, 1}},
            {{2, 1}, {6, 1}},
            {{1, 1}, {6, 1}},
            {{1, 1}, {4, 1}, {5, 1}},
            {{3, 1}}
    };

    vector<int> bfsOrderVisited = Question3::breadthFirstSearch(graph, 0);
    vector<int> dfsOrderVisited = Question3().depthFirstSearch(graph, 0);
    vector<int> dijkstraDist = Question3::dijkstraShortestPath(graph, 0);
    vector<int> bfsDist = Question3::bfsShortestPath(graph, 0);

    cout << "BFS: ";
    for(int& node: bfsOrderVisited) {
        cout << node << " ";
    }

    cout << endl << "DFS: ";
    for(int& node: dfsOrderVisited) {
        cout << node << " ";
    }

    cout << endl << "Dijkstra Shortest Path from 0 to 5: " << dijkstraDist[5];
    cout << endl << "BFS Shortest Path from 0 to 5: " << bfsDist[5];

    return 0;
}

/*

Output:
BFS: 0 2 3 1 4 7 5 6
DFS: 0 2 1 5 6 4 3 7
Dijkstra Shortest Path from 0 to 5: 3
BFS Shortest Path from 0 to 5: 3

*/
