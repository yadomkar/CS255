//
// Created by Omkar Yadav on 9/6/23.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Question6 {
public:
    static vector<vector<int>> multiToSimple(const vector<vector<int>>& multiGraph) {
        vector<vector<int>> simpleGraph;
        for(int vertex = 0; vertex < multiGraph.size(); vertex++) {
            set<int> uniqueEdges;
            for(auto& neighbor: multiGraph[vertex]) {
                if(vertex != neighbor) uniqueEdges.insert(neighbor);
            }
            simpleGraph.push_back(vector<int>(uniqueEdges.begin(), uniqueEdges.end()));
        }
        return simpleGraph;
    }
};

int main() {
    vector<vector<int>> multiGraph = {
        {1, 1, 2, 3, 4},
        {0, 0, 2, 3, 4, 4},
        {0, 1, 3, 4, 4, 5},
        {0, 1, 2, 4, 5},
        {0, 1, 1, 2, 2, 3, 5, 5},
        {2, 3, 4, 4}
    };

    vector<vector<int>> simpleGraph = Question6::multiToSimple(multiGraph);

    for(int vertex = 0; vertex < simpleGraph.size(); vertex++) {
        cout << endl << vertex << " -> ";
        for(auto& neighbor: simpleGraph[vertex]) {
            cout << neighbor << " ";
        }
    }
    return 0;
}

/*

Output:
0 -> 1 2 3 4
1 -> 0 2 3 4
2 -> 0 1 3 4 5
3 -> 0 1 2 4 5
4 -> 0 1 2 3 5
5 -> 2 3 4

 */