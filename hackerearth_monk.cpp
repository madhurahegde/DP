// Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
// Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. 
// Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

#include<iostream>
#include<list>
#include<queue>
#define MAX 10001
using namespace std;

class Graph {
    int V,E;
    list<int> grp[MAX];

    public:
    Graph(int ver, int edg) {
        V = ver;
        E =edg;
    }
    void addEdge(int u,int v);
    void printGraph();
    int findBridge();
};

void Graph::printGraph() {
    for(int i=0;i<=V;i++) {
        for(auto j=grp[i].begin();j!=grp[i].end();++j) {
            cout<<i << "=>" << *j << endl;
        }
    }
    
}

void Graph::addEdge(int u,int v) {
    grp[u].push_back(v);
    grp[v].push_back(u);
}

int Graph::findBridge() {
    bool visited[V+1];
    int bridgeCount[V+1];
    queue<int> BFS;
    
    for(int j=0;j<=V;j++) {
        visited[j] = 0;
        bridgeCount[j] = 0;
    }

    visited[1] = true;
    bridgeCount[1] = 0;
    BFS.push(1);

    while(!BFS.empty()) {
        int cur = BFS.front();
        BFS.pop();

        if(cur != V) {
            for(auto i=grp[cur].begin();i!=grp[cur].end();++i) {
                if(!visited[*i]){
                    visited[*i] = true;
                    bridgeCount[*i] = bridgeCount[cur] +1;
                    BFS.push(*i);
                }
            }
        } else {
            break;
        } 
    }
    return bridgeCount[V];

}

int main() {
    int testcase,v,e,x,y;

    cin>>testcase;

    for(int i=0;i<testcase;i++) {
       cin>>v>>e;
       Graph g(v,e);

        for(int j=0;j<e;j++ ){
            cin>>x>>y;
            g.addEdge(x,y);
        }
        cout<<g.findBridge()<<endl;
    }
    return 0;
}