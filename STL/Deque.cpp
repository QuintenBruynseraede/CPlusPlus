#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;


class Graph {
private:
    vector<int> nodes;
    vector<int> edges;
public:
    Graph() {}
    void addNode(int node) {
        nodes.push_back(node);
    }
    void addEdge(int edge) {
        edges.push_back(edge);
    }
    void print() {
        cout << "Graph with " << nodes.size() << " nodes, " << edges.size() << " edges " << endl;
        cout << "nodes = [" << flush;
        sort(nodes.begin(),nodes.end());
        for (vector<int>::iterator it = nodes.begin();it != nodes.end();it++) {
            if (it != nodes.end()-1) {
                cout << *it << ", " << flush;
            }
            else {
                cout << *it << "]" << endl;
            }
        }
        cout << "edges = [" << flush;
        for (vector<int>::iterator it = edges.begin();it != edges.end();it++) {
            if (it != edges.end()-1) {
                cout << *it << ", " << flush;
            }
            else {
                cout << *it << "]" << endl;
            }
        }
    }
    friend bool compGraphs(const Graph& g1,const Graph& g2);
};

bool compGraphs(const Graph &g1,const Graph &g2) {
    return g1.edges.size() < g2.edges.size();
}



int main() {
    Graph g1;
    g1.addEdge(4);
    g1.addEdge(2);
    g1.addEdge(3);
    
    g1.addNode(7);
    g1.addNode(5);
    g1.addNode(6);

    //g1.print();

    Graph g2;
    g2.addEdge(11);
    g2.addEdge(12);
    g2.addEdge(13);
    g2.addEdge(10);
    g2.addNode(14);
    g2.addNode(15);
    g2.addNode(16);
    g2.addNode(17);


   // g2.print();

    deque<Graph> graphs;
    graphs.push_back(g1);
    graphs.push_back(g2);
    graphs.push_front(g2);

    sort(graphs.begin(),graphs.end(),compGraphs);

    for (deque<Graph>::iterator it=graphs.begin();it!=graphs.end();it++) {
        it->print();
    }

    return 0;
}