#include<iostream>
#include<queue>
using namespace std;

// BFS function to traverse the graph using a queue
void BFS(int G[][7], int start, int n) {
    int i = start;
    queue<int> q;
    int visited[7] = {0};  // Array to keep track of visited nodes
    
    cout << i << " ";  // Print the starting node
    visited[i] = 1;    // Mark the starting node as visited
    q.push(i);         // Enqueue the starting node
    
    while (!q.empty()) {
        i = q.front();  // Access the front element of the queue
        q.pop();        // Dequeue the front element
        
        for (int j = 1; j < n; j++) {  // Check all adjacent nodes
            if (G[i][j] == 1 && visited[j] == 0) {  // If there is an edge and the node is not visited
                cout << j << " ";   // Print the adjacent node
                visited[j] = 1;     // Mark the node as visited
                q.push(j);          // Enqueue the node
            }
        }
    }
}

int main() {
    // Adjacency matrix representation of the graph
    int G[7][7] = {{0,0,0,0,0,0,0},  /*            1                     */
                   {0,0,1,1,0,0,0},  /*           / \                    */
                   {0,1,0,0,1,0,0},  /*          2   3                   */
                   {0,1,0,0,1,0,0},  /*           \ /                    */
                   {0,0,1,1,0,1,1},  /*            4                     */
                   {0,0,0,0,1,0,0},  /*           / \                    */
                   {0,0,0,0,1,0,0}}; /*          5   6                   */

    // Call BFS starting from node 3
    BFS(G, 6, 7);
    
    return 0;
}
