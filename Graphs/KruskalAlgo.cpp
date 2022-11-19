#include <iostream>
#include <vector>
#include <List>
#include <queue>

using namespace std;

//Creating_Graph====================================================================================================================
class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int val, int wt)
    {
        this->v = val;
        this->w = wt;
    }

    Edge(){};
};

vector<vector<Edge *>> graph;
vector<vector<Edge *>> kgraph;

void AddCheck(int u, int v, int w)
{
    if (u >= graph.size() || u < 0 || v < 0 || v >= graph.size())
        return;

    graph[u].push_back(new Edge(v, w)); //bidirectional graph
    graph[v].push_back(new Edge(u, w));
}

void AddCheck2(int u, int v, int w)
{
    if (u >= kgraph.size() || u < 0 || v < 0 || v >= kgraph.size())
        return;

    kgraph[u].push_back(new Edge(v, w)); //bidirectional graph
    kgraph[v].push_back(new Edge(u, w));
}

void caseI()
{
    for (int i = 0; i < 9; i++)
    {
        vector<Edge *> arr;
        graph.push_back(arr);

        vector<Edge *> arr1;
        kgraph.push_back(arr1);
    }

    //Graph-1
    // AddCheck(0, 3, 10);
    // AddCheck(0, 1, 10);
    // AddCheck(1, 2, 10);
    // AddCheck(2, 3, 40);
    // AddCheck(3, 4, 2);
    // AddCheck(4, 5, 2);
    // AddCheck(4, 6, 3);
    // AddCheck(5, 6, 8);

    //Graph-2
    // AddCheck(0, 1, 5);
    // AddCheck(0, 2, 2);
    // AddCheck(1, 2, 8);
    // AddCheck(1, 3, 4);
    // AddCheck(2, 4, 7);
    // AddCheck(1, 4, 2);
    // AddCheck(3, 4, 6);
    // AddCheck(3, 5, 3);
    // AddCheck(4, 5, 1);

    //Graph-3
    AddCheck(0, 1, 4);
    AddCheck(0, 7, 8);
    AddCheck(1, 2, 8);
    AddCheck(1, 7, 11);
    AddCheck(7, 6, 1);
    AddCheck(7, 8, 7);
    AddCheck(2, 8, 2);
    AddCheck(2, 3, 7);
    AddCheck(2, 5, 4);
    AddCheck(8, 6, 6);
    AddCheck(6, 5, 2);
    AddCheck(3, 5, 14);
    AddCheck(3, 4, 9);
    AddCheck(5, 4, 10);
}

void Display()
{
    for (int i = 0; i < kgraph.size(); i++)
    {
        cout << i << " => ";
        for (int j = 0; j < kgraph[i].size(); j++)
        {
            cout << "(" << kgraph[i][j]->v << "|" << kgraph[i][j]->w << ") ";
        }

        cout << endl;
    }
}

//Kruskal=================================================================================================

class kpair
{
public:
    int u = 0;
    int v = 0;
    int w = 0;

    kpair(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    bool operator<(const kpair &o) const
    {
        return this->w > o.w; //for sorting
    }

    kpair(){};
};

vector<int> Par(9, 0);
vector<int> Size(9, 1);

int find(int vtx)
{
    if (Par[vtx] != vtx)
        Par[vtx] = find(Par[vtx]);

    return Par[vtx];
}

void Union(int pt1, int pt2)
{
    if (Size[pt1] <= Size[pt2])
    {
        Par[pt1] = pt2;
        Size[pt2] += Size[pt1];
    }
    else
    {
        Par[pt2] = pt1;
        Size[pt1] += Size[pt2];
    }
}

void Kruskal()
{
    priority_queue<kpair> que;

    for (int i = 0; i < graph.size(); i++)
    {
        for (Edge *e : graph[i])
        {
            if (i < e->v)
            {
                kpair npair(i, e->v, e->w);
                que.push(npair);
            }
        }
    }

    while (que.size() != 0)
    {
        kpair rpair = que.top();
        que.pop();

        int pt1 = find(rpair.u);
        int pt2 = find(rpair.v);

        if (pt1 != pt2)
        {
            AddCheck2(rpair.u, rpair.v, rpair.w);
            Union(pt1, pt2);
        }
    }

    Display();
}

int main(int args, char **argv)
{
    caseI();
    for (int i = 0; i < 9; i++)
        Par[i] = i;

    Kruskal();
}