#include <iostream>
#include <vector>
#include <List>

using namespace std;

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

vector<vector<Edge *>> graph(7, vector<Edge *>());

class partite_pair
{

public:
    int vtx = 0;
    int color = 0;

    partite_pair(int v, int color)
    {
        this->vtx = v;
        this->color = color;
    }

    partite_pair(){};
};

bool Bipartite(int src, vector<int> &visited)
{
    list<partite_pair> que;
    bool res = true;

    partite_pair root(src, 0);
    que.push_back(root);

    while (que.size() != 0)
    {
        partite_pair rpair = que.front();
        que.pop_front();

        if (visited[rpair.vtx] != -1)
        {
            if (visited[rpair.vtx] != rpair.color)
            {
                cout << rpair.vtx << " ->  Not Bipartite " << endl;
                res = false;
            }
            else
                cout << rpair.vtx << " -> Bipartite " << endl;
            continue;
        }

        visited[rpair.vtx] = rpair.color;

        for (Edge *e : graph[rpair.vtx])
        {
            if (visited[e->v] == -1)
            {
                partite_pair npair(e->v, (rpair.color + 1) % 2);
                que.push_back(npair);
            }
        }
    }

    return res;
}

//Creating_Graph====================================================================================================================

void AddCheck(int u, int v, int w)
{
    if (u >= graph.size() || u < 0 || v < 0 || v >= graph.size())
        return;

    graph[u].push_back(new Edge(v, w)); //bidirectional graph
    graph[v].push_back(new Edge(u, w));
}

void caseI()
{

    AddCheck(0, 3, 10);
    AddCheck(0, 1, 10);
    AddCheck(1, 2, 10);
    AddCheck(2, 3, 40);
    //AddCheck(3, 4, 2);
    AddCheck(4, 5, 2);
    AddCheck(4, 6, 3);
    AddCheck(5, 6, 8);
}

void Display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " => ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "(" << graph[i][j]->v << "|" << graph[i][j]->w << ") ";
        }

        cout << endl;
    }
}

int main(int args, char **argv)
{
    caseI();
    // Display();

    vector<int> visitedcolor(graph.size(), -1);
    for (int i = 0; i < graph.size(); i++)
    {
        cout << (boolalpha) << Bipartite(i, visitedcolor) << endl;
    }

    return 0;
}