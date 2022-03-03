#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

 pair<int,int> findFirstGateWay(list<int> *adj,vector<int> &gateways,int S,int nodesNbr,list<int>queue){
     bool *visited=new bool[nodesNbr];
     //list<int> queue;
     for(int i=0;i<nodesNbr;i++){
         visited[i]=false;
     }
     visited[S]=true;
     queue.push_back(S);
     list<int>::iterator it;
     while(!queue.empty()){
         S=queue.front();
         queue.pop_front();
         for (it = adj[S].begin(); it != adj[S].end(); ++it){
             if(!visited[*it]){
                 visited[*it] = true; 
                queue.push_back(*it); 
                if(find(gateways.begin(),gateways.end(),*it)!=gateways.end()){
                    return make_pair(S,*it);
                }
             }
         } 
     }
 }
int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    list<int> *adj=new list<int>[N];
    vector<int> sorties;
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        adj[N1].push_back(N2);
        adj[N2].push_back(N1);
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        sorties.push_back(EI);
    }
    std::pair<int,int> link;
    list<int> queue;
    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        link=findFirstGateWay(adj,sorties,SI,N,queue);

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        cout << link.first<<" "<<link.second << endl;
        adj[link.first].remove(link.second);
    }
}