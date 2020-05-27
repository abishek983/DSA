// considering the gprah is connected

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,int> PII;
const int MAX = 1e4+5;
vector<PII> adj[MAX]; // this will store the graph 
bool visited[MAX]; // assign it to false in the main function

int prims(int x){
    priority_queue<PII,vector<PII>,greater<PII>> pq;
    pq.push({0,x});
    
    int cost = 0;
    while(!pq.empty()){
        //selecting the edge with minimum weight
        PII temp = pq.top();
        pq.pop();
        int local_cost = temp.first;
        int v = temp.second;
        if(visited[v])
            continue;
        cost += local_cost;
        for(int i=0;i<adj[v].size();i++){
            // if a vertex is already visited we are not pushing it to the stack
            if(!visited[adj[v][i].second]){
                pq.push(adj[v][i]);
            }
        }
        visited[v] = true;
    }
    return cost;
}

int main(){
    int vertices,edges; cin >> vertices >> edges;
    int x,y; long long cost;
    for(int i=0;i<edges;i++){
        cin >> x >> y >> cost;
        adj[x].push_back({cost,y});
        adj[y].push_back({cost,x});
    }

    int min_cost = prims(1);
    cout << min_cost << endl;

    return 0;
}
