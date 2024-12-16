#include<iostream>
#include <queue>
using namespace std;

void DFS(int G[][7],int start,int n){
    static int visited[7] ={0}; //we use static because since we are using recursion, we want visited array to be updated
    if(visited[start]==0){
        cout<<start<<" ";
        visited[start]=1;
        for(int j=1;j<n;j++){
            if(G[start][j]==1 && visited[j]==0)
                DFS(G,j,n);
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

    // Call DFS starting from node 3
    DFS(G, 1, 7);
    
    return 0;
}