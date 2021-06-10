#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
    int src;
    int dest;
    int value;
};

bool compare(edge a,edge b){
    return a.value < b.value;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int V,E;
    vector<edge> Tree;
    
    Tree.reserve(E);
    cin>>V>>E;
    int parent[E];
    
    for(int i=0;i<E;i++)
        parent[i] = i;
    
    for(int i=0;i<E;i++){
        edge t;
        int src,dest,val;
        cin>>src;
        cin>>dest;
        cin>>val;
        t.src = src-1,t.dest = dest-1,t.value = val;
        Tree.push_back(t);  
    }
    
    sort(Tree.begin(),Tree.end(),compare);
    
    int count = 0;
    
    for(int i=0;i<E;i++){
      
            int u = Tree[i].src;
            int v = Tree[i].dest;    
            while(parent[u]!=u)
                u = parent[u];
            while(parent[v]!=v)
                v = parent[v];
       
        if(u!=v){
            u > v ? parent[u] = v : parent[v] = u;
            count+=Tree[i].value;
        }
    }
    
    cout<<count;
    return 0;
}
