vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> res;
    cout<<res.size()<<endl;
    map<int,bool> marked;
    map<int,vector<int>> adj;
    for (int i =0;i<edges.size();i++){
        vector<int> par = edges[i];
        adj[par[0]].push_back(par[1]);
        adj[par[1]].push_back(par[0]);
    }
    for (auto x: adj){
        marked[x.first] = false;
    }
    map<int,int> res2;
    queue<pair<int,int>> q;
    q.push({s,0});
    marked[s] = true;
    while(!q.empty()){
        pair<int,int> fr = q.front();
        q.pop();
        if (fr.second>0){
            res2[fr.first] = fr.second;
        }
        for (int x : adj[fr.first]){
            if (!marked[x]){
                marked[x] = true;
                q.push({x,fr.second+6});
            }
        }
    }
    for (int i =1;i<=n;i++){
        if (i!=s){
            if (marked[i]) res.push_back(res2[i]);
            else res.push_back(-1);
        }
    }
    return res;
}
