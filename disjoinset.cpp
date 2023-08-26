class DS{
    public:
     vector<int>rank;
     vector<int>bysize;
     vector<int>parent;
    DS(int n){
        rank.resize(n+1,0);
        bysize.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            bysize[i] =1;
            parent[i]=i;
        }
    }
    int findparent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }
    void unionbyrank(int v,int u){
        int u_parent = findparent(u);
        int v_parent = findparent(v);
        if(u_parent==v_parent) return;
        if(rank[v_parent]<rank[u_parent]){
            parent[v_parent] = u_parent;
        }
        else if(rank[v_parent]>rank[u_parent]){
            parent[u_parent] = v_parent;
        }
        else{
            parent[u_parent] = v_parent;
            rank[v_parent]++;
        }
    }
    void unionbysize(int v,int u){
        int u_parent = findparent(u);
        int v_parent = findparent(v);
        if(u_parent==v_parent) return;
        if(bysize[u_parent]>bysize[v_parent]){
            parent[v_parent] = u_parent;
            bysize[u_parent] +=bysize[v_parent];
        }
        else{
             parent[u_parent] = v_parent;
            bysize[v_parent] +=bysize[u_parent];
        }
    }
};