//Prim + promqna na operatora < -tyrsene na max tovar

#include <iostream>
#include<vector>
#include<algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int n,m;
vector<pair <int,int> > allEdges[50001];
bool marked[50001];
int d[50001];
int pi[50001];

struct edge{
    int key;
    int parent;
    int current;

    bool operator < (edge other) const {
        return key<other.key;
    }
};


void Prim(int nachalo){
//    for(int i=0;i<m;i++){
//        marked[i] = false;
//    }

    edge node;
    node.key = 0;
    node.parent = -1;
    node.current = nachalo;
    priority_queue<edge> PQ;
    PQ.push(node);
    while(!PQ.empty()){
        edge currentNode = PQ.top();
        PQ.pop();
        int cur = currentNode.current;
        if(marked[cur] == false){
            marked[cur] = true;
            d[cur] = currentNode.key;
            pi[cur] = currentNode.parent;
            for(int i=0;i<allEdges[cur].size();i++){
                edge neigh;
                neigh.key = allEdges[cur][i].second;
                neigh.parent = cur;
                neigh.current = allEdges[cur][i].first;
                PQ.push(neigh);
            }
        }
    }
}



int main()
{
    scanf("%d %d", &n, &m);
    int currSt, currF,currDist;


    for(int i=0; i<m;i++){
        scanf("%d %d %d", &currSt, &currF, &currDist);
        allEdges[currSt].push_back(make_pair(currF,currDist));
        allEdges[currF].push_back(make_pair(currSt,currDist));
    }

    Prim(1);

    int minn = 1000;
    for(int i=1;i<=m;i++){
        if(minn >d[i] && d[i]!=0){
            minn = d[i];
        }
    }
    printf("%d\n", minn);

    return 0;
}
