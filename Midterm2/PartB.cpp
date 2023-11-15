//
// Created by Omkar Yadav on 11/12/23.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <map>
#include <fstream>
#include <unordered_set>

using namespace std;

class Hercules {
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
    map<int, vector<int>> graph;
    int nodes;
    int edges;

    Erdos(const string& filename) {
        edges = 0;
        graph = makeAdjListFromFile(filename);
        nodes = (int) graph.size();
    }

    map<int, vector<int>> makeAdjListFromFile(const string& filename) {
        map<int, vector<int>> adjList;

        ifstream file(filename);
        if(!file.is_open()) {
            cerr << "Error: " << strerror(errno) << endl;
            return {};
        }

        string header;
        getline(file, header);

        int nodeU, nodeV;
        while(file >> nodeU >> nodeV) {
            edges++;
            adjList[nodeU].push_back(nodeV);
            adjList[nodeV].push_back(nodeU);
        }

        file.close();
        return adjList;
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

            for(auto& collaborator: graph[cur]) {
                if(visited.find(collaborator) == visited.end()) {
                    bfsQueue.push(collaborator);
                    visited.insert(collaborator);
                }
            }
        }

        return collaborators;
    }

    set<int> getMIS() {
        set<int> MIS;
        unordered_set<int> visited;

        for(auto& [vertex, collaborators]: graph) {
            if(visited.find(vertex) == visited.end()) {
                MIS.insert(vertex);
                visited.insert(vertex);
                for(auto& collaborator: collaborators) {
                    visited.insert(collaborator);
                }
            }
        }

        return MIS;
    }

};

int main() {
    cout << "Question 1 (Hercules):" << endl;
    vector<int> arr1 = {20, 1, 15};
    vector<int> arr2 = {2, 1, 7, 4, 2};
    vector<int> arr3 = {4, 10, 6, 7, 3, 1};

    cout << "Test 1, Total Heads 20 = " << Hercules::maxHeads(arr1, 1) << endl;
    cout << "Test 2, Total Heads 35 = " << Hercules::maxHeads(arr1, 2) << endl;
    cout << "Test 3, Total Heads 45 = " << Hercules::maxHeads(arr1, 3) << endl;

    cout << "Test 4, Total Heads 7 = " << Hercules::maxHeads(arr2, 1) << endl;
    cout << "Test 5, Total Heads 11 = " << Hercules::maxHeads(arr2, 2) << endl;
    cout << "Test 6, Total Heads 14 = " << Hercules::maxHeads(arr2, 3) << endl;

    cout << "Test 7, Total Heads 10 = " << Hercules::maxHeads(arr3, 1) << endl;
    cout << "Test 8, Total Heads 17 = " << Hercules::maxHeads(arr3, 2) << endl;
    cout << "Test 9, Total Heads 23 = " << Hercules::maxHeads(arr3, 3) << endl;
    cout << "Test 10, Total Heads 28 = " << Hercules::maxHeads(arr3, 4) << endl;
    cout << "Test 11, Total Heads 32 = " << Hercules::maxHeads(arr3, 5) << endl;
    cout << "Test 12, Total Heads 35 = " << Hercules::maxHeads(arr3, 6) << endl;

    cout << endl << endl << "Question 2 (Erdos):" << endl;

    Erdos erdosGraph("../Midterm2/ErdosCA.txt");

    cout << "Number of Nodes: " << erdosGraph.nodes << endl;
    cout << "Number of Edges: " << erdosGraph.edges << endl << endl;

    unordered_map<int, vector<int>> collaborators = erdosGraph.getCollaboratorsByErdosNumber();

    cout << "Collaborators by Erdos Number:" << endl;
    for(int erdosNumber = 1; erdosNumber <= 3; erdosNumber++) {
        cout << erdosNumber << " (" << collaborators[erdosNumber].size() << "): ";
        for(int collaborator : collaborators[erdosNumber]) {
            cout << collaborator << " ";
        }
        cout << endl;
    }

    cout << endl << "Maximal Independent Set:" << endl;
    set<int> mis = erdosGraph.getMIS();
    cout << "MIS size: " <<  mis.size() << endl;

    for(auto& node: mis) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
