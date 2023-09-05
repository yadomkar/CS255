//
// Created by Omkar Yadav on 9/4/23.
//

// #include<unordered_map>
#include<iostream>
// #include<vector>

using namespace std;

class Question4 {

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
    return 0;
}