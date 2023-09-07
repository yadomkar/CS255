//
// Created by Omkar Yadav on 9/6/23.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Question7 {
public:
    static vector<int> bfsLombardi(vector<vector<int>>& graph, int start) {
        queue<int> q;
        vector<int> distance(graph.size(), INT_MAX);
        vector<int> count(graph.size());

        q.push(start);
        distance[start] = 0;
        count[start] = 1;

        while(!q.empty()) {
            int cur = q.front(); q.pop();

            for(auto& neighbor: graph[cur]) {
                if(distance[neighbor] == INT_MAX) {
                    q.push(neighbor);
                    distance[neighbor] = distance[cur] + 1;
                }
                if(distance[neighbor] == distance[cur] + 1) {
                    count[neighbor] += count[cur];
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2, 4},
        {0, 1, 3, 5},
        {0, 2, 4, 5},
        {1, 3, 6},
        {2, 3, 6, 7},
        {4, 5, 7, 8},
        {5, 6, 8},
        {6, 7}
    };

    int start = 0;
    vector<int> lombardi = Question7::bfsLombardi(graph, start);

    for(int end = 0; end < graph.size(); end++) {
        cout << "Paths from " << start << " to " << end << ": " << lombardi[end] << endl;
    }

    return 0;
}

/*

 Output:
Paths from 0 to 0: 1
Paths from 0 to 1: 1
Paths from 0 to 2: 1
Paths from 0 to 3: 1
Paths from 0 to 4: 2
Paths from 0 to 5: 2
Paths from 0 to 6: 4
Paths from 0 to 7: 2
Paths from 0 to 8: 6

 */