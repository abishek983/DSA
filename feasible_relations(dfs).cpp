// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/
/*
1
12 80
1 = 2
1 = 3
1 = 4
5 = 1
1 = 6
2 = 3
2 = 4
5 = 2
2 = 6
3 = 4
5 = 3
6 = 3
5 = 4
6 = 4
5 = 6
7 = 8
7 = 9
7 = 10
7 = 11
7 = 12
9 = 8
10 = 8
11 = 8
12 = 8
10 = 9
9 = 11
9 = 12
10 = 11
12 = 10
12 = 11
7 != 6
9 != 3
12 != 4
11 != 3
12 != 1
11 != 2
2 != 9
11 != 2
4 != 12
9 != 5
1 != 10
8 != 5
10 != 5
3 != 8
9 != 1
3 != 8
10 != 5
12 != 1
3 != 11
10 != 1
8 != 2
3 != 9
7 != 4
5 != 12
3 != 11
11 != 1
1 != 12
3 != 10
4 != 12
11 != 4
11 != 3
4 != 10
9 != 6
2 != 7
9 != 5
4 != 11
5 != 12
11 != 3
9 != 2
10 != 5
12 != 6
3 != 11
9 != 2
3 != 8
9 != 1
11 != 2
7 != 1
7 != 2
10 != 1
7 != 3
*/


#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

vector<int> adj[MAX];
bool visited[MAX];
int component[MAX];
int val = 0;
void dfs(int src){
    // cout << src << endl;
    visited[src] = true;
    component[src] = val;

    for(auto& i: adj[src]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin); 
    int t,a,b; cin >> t;
    int x,y; string op;
    while(t--){
        cin >> a >> b ;
        val = 0;
        vector<pair<int,int>> notEquals;
        
        for(int i=0;i<a;i++)
            visited[i] = false , component[i] = -1;
        
        for(int i=0;i<b;i++){
            cin >> x >> op >> y;
            // cout << op << endl;
            if(op== "="){
                adj[--x].push_back(--y);
                adj[y].push_back(x);
            }
            else 
                notEquals.emplace_back(--x,--y);
        }
    //    cout << notEquals.size() ; 
        for(int i=0;i<a;i++){
            if(!visited[i]){
                // cout << i << endl;
                dfs(i);
                val++;
            }
        }
        int flag = 0;
        // cout << component[0] << " " << component[1] << endl;
        for(auto i:notEquals){
            // cout <<component[i.first] << " " << component[i.second] ;
            if((component[i.first] == component[i.second]) && component[i.first]!= -1){
                flag = 1 ; break;
            }
        }
        /* for(int i=0;i<a;i++){
            cout << i << " " << component[i] << endl;
        } */


        if(flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

        for(auto& v:adj)
            v.clear();
    }
    return 0;
}