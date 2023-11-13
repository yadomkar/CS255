//
// Created by Omkar Yadav on 11/12/23.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <unordered_set>

using namespace std;

class PartBQuestion1 {
public:
    static int maxHeads(vector<int>& birds, int m) {
        priority_queue<int> maxHeap(birds.begin(), birds.end());

        int headCount = 0;
        while(!maxHeap.empty() and m--) {
            int heads = maxHeap.top();
            headCount += heads;
            maxHeap.pop();
            maxHeap.push(heads / 2);
        }

        return headCount;
    }
};

class Erdos {
public:
    unordered_map<int, vector<int>> adjList;
    int nodes;
    int edges;

    Erdos(const string& filename) {
        makeAdjListFromFile(filename);
    }

    void makeAdjListFromFile(const string& filename) {
        ifstream file(filename);
        if(!file.is_open()) {
            cerr << "Error: " << strerror(errno) << endl;
            return;
        }

        string header;
        getline(file, header);

        int edgeCount = 0;
        int nodeU, nodeV;

        while(file >> nodeU >> nodeV) {
            edgeCount++;
            adjList[nodeU].push_back(nodeV);
            adjList[nodeV].push_back(nodeU);
        }

        nodes = (int) adjList.size();
        edges = edgeCount;

        file.close();
    }


    unordered_map<int, vector<int>> getCollaboratorsByErdosNumber() {
        unordered_map<int, vector<int>> collaborators;

        queue<int> bfsQueue;
        unordered_set<int> visited;
        bfsQueue.push(1);
        visited.insert(1);

        int dummy = -1;
        bfsQueue.push(dummy);
        int erdosNumber = 0;

        while(!bfsQueue.empty()) {
            int cur = bfsQueue.front();
            bfsQueue.pop();

            if(cur == dummy) {
                if(bfsQueue.empty()) break;
                sort(collaborators[erdosNumber].begin(), collaborators[erdosNumber].end());
                erdosNumber++;
                bfsQueue.push(dummy);
                continue;
            }

            collaborators[erdosNumber].push_back(cur);

            for(auto& collaborator: adjList[cur]) {
                if(visited.find(collaborator) == visited.end()) {
                    bfsQueue.push(collaborator);
                    visited.insert(collaborator);
                }
            }


        }

        return collaborators;
    }

};

int main() {
    vector<int> arr1 = {20, 1, 15};
    vector<int> arr2 = {2, 1, 7, 4, 2};
    vector<int> arr3 = {4, 10, 6, 7, 3, 1};

    Erdos erdosGraph("../Midterm2/ErdosCA.txt");

    cout << "Nodes: " << erdosGraph.nodes << endl;
    cout << "Edges: " << erdosGraph.edges << endl;

    unordered_map<int, vector<int>> collaboratorsByErdosNumber = erdosGraph.getCollaboratorsByErdosNumber();

    for(int i = 0; i < 11; i++) {
        cout << i << ": ";
        for(int j : collaboratorsByErdosNumber[i]) {
            cout << j << " ";
        }
        cout << endl;
    }


    cout << "Test 1, Total Heads 20 = " << PartBQuestion1::maxHeads(arr1, 1) << endl;
    cout << "Test 2, Total Heads 35 = " << PartBQuestion1::maxHeads(arr1, 2) << endl;
    cout << "Test 3, Total Heads 45 = " << PartBQuestion1::maxHeads(arr1, 3) << endl;

    cout << "Test 4, Total Heads 7 = " << PartBQuestion1::maxHeads(arr2, 1) << endl;
    cout << "Test 5, Total Heads 11 = " << PartBQuestion1::maxHeads(arr2, 2) << endl;
    cout << "Test 6, Total Heads 14 = " << PartBQuestion1::maxHeads(arr2, 3) << endl;

    cout << "Test 7, Total Heads 10 = " << PartBQuestion1::maxHeads(arr3, 1) << endl;
    cout << "Test 8, Total Heads 17 = " << PartBQuestion1::maxHeads(arr3, 2) << endl;
    cout << "Test 9, Total Heads 23 = " << PartBQuestion1::maxHeads(arr3, 3) << endl;
    cout << "Test 10, Total Heads 28 = " << PartBQuestion1::maxHeads(arr3, 4) << endl;
    cout << "Test 11, Total Heads 32 = " << PartBQuestion1::maxHeads(arr3, 5) << endl;
    cout << "Test 12, Total Heads 35 = " << PartBQuestion1::maxHeads(arr3, 6) << endl;

    return 0;
}
