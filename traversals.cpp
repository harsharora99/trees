#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;

//Preorder
vector<int> pre;

//Postorder
vector<int> post;

void dfs(int v, int p = -1){
    pre.push_back(v);
    for(auto nbr : adj[v]){
      if(nbr != p) {
        dfs(nbr, v);
      }
    }
    post.push_back(v);
}
int main(){
  adj = vector<vector<int>> (n);
  pre = vector<int> ();
  post = vector<int> ();
  dfs(0);
  return 0;
}
