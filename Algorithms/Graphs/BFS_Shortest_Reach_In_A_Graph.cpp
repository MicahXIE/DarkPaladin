/*
BFS: Shortest Reach in a Graph

problem:
https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem

Sample Input

2
4 2
1 2
1 3
1
3 1
2 3
2
Sample Output

6 6 -1
-1 6
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class Graph {
    public:
        Graph(int n) {
            this->nodeNum = n;
            this->nodeAdj = new vector<int>[n];
            
        }
    
        void add_edge(int u, int v) {
            nodeAdj[u].push_back(v);
            nodeAdj[v].push_back(u);
        }
        
        //BFS method to find the shortest distance for the adjacent nodes
        vector<int> shortest_reach(int start) {
            //initialize the distance
            vector<int> distance(nodeNum, -1);
            //store the adjacent node in sequence
            queue<int> nodeQueue;
            //store the node seen during the searching process
            unordered_set<int> nodeSeen;
            
            nodeQueue.push(start);
            nodeSeen.insert(start);
            distance[start] = 0;
            
            while(!nodeQueue.empty()){
                
                int cur = nodeQueue.front();
                nodeQueue.pop();
                for(int node : nodeAdj[cur]){
                    if(nodeSeen.find(node) == nodeSeen.end()){
                        nodeQueue.push(node);
                        nodeSeen.insert(node);
                        distance[node] = distance[cur] + 6;
                    }
                }            
                
            }
            
            return distance;
            
        }
    
    private:
        int nodeNum;
        vector<int> *nodeAdj;
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}