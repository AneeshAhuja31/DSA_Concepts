#include<iostream>
#define I INT16_MAX
using namespace std;

int edges[3][9] = {{ 1, 1, 2, 2, 3, 4, 4, 5, 5},
                   { 2, 6, 3, 7, 4, 5, 7, 6, 7},
                   {25, 5,12,10, 8,16,14,20,18}}; // weights of the edges
int set[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int included[9]={0};
int t[2][6];

void Union(int u, int v){
    if(set[u] < set[v]){   // Compare subset parents
        set[u] += set[v];  // Add total elements to parent index of larger subset
        set[v] = u;        // Update parent of smaller subset 
    }
    else{
        set[v] += set[u];
        set[u] = v;
    }
}

int Find(int u){
    int x = u, v = 0;
    while(set[x] > 0){  // Find the root parent
        x = set[x];  
    }
    // Collapsing find
    while(u != x){
        v = set[u];
        set[u] = x; // Connect index u to parent
        u = v;
    }
    return x;
}

int main(){
    int i = 0, j, k, u, v, min = I, n = 7, e = 9;

    while(i < n - 1){
        min = I;
        for(j = 0; j < e; j++){
            if(edges[2][j] < min && included[j] == 0){  // Correct comparison with weight
                min = edges[2][j];  // Use edge weight for comparison
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }
        if(Find(u) != Find(v)){
            t[0][i] = u;
            t[1][i] = v;
            Union(Find(u), Find(v));
            i++;
        } 
        included[k] = 1;
    }

    for(i = 0; i < n - 1; i++)
        cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;

    return 0;
}
