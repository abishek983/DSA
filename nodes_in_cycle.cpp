// https://my.newtonschool.co/playground/code/3fbzogfp46/
/*
Given an undirected graph of N nodes and E edges . Edges are given in the form of x y if there is an edge between x and y . 
Count the number of vertices in the graph which are involved in at least one cycle .
*/

#include <bits/stdc++.h>    
#define MAX 1000001
using namespace std;

vector<int> adj[MAX];
bool visited[MAX];
int n,ans = 0;
stack<int> nodes; // to store the nodes which contribes to the cycle and also will be conted only once

void dfs(int src,int parent){
    visited[src] = true;
    nodes.push(src);
    // cout << src << parent << endl;
    for(int i: adj[src]){
        if(i==parent)
            continue;

        if(!visited[i])
            dfs(i,src);
        
         else {
            //cout << src << " " << i << " " << parent <<endl;
             while(!nodes.empty()){
                 int temp = nodes.top();
                 nodes.pop();
                 ans++;
                 if(temp==i)
                     break;
             }
         }
    }
    if(!nodes.empty())
        nodes.pop();
}


int main(){
    ios::sync_with_stdio(false);
    int k; cin >> n >> k;
    for(int i=0;i<n;i++)
        visited[i] = false;
    for(int i=0;i<k;i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            // cout << i << endl;
            dfs(i,-1);
        }
    }
    
    cout << ans ;
    return 0;
}