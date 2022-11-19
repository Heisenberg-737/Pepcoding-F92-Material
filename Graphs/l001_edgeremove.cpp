#include <iostream>
#include <vector>

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

void AddCheck(int u, int v, int w)
{
    if (u >= graph.size() || u < 0 || v < 0 || v >= graph.size())
        return;

    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

void caseI()
{

    AddCheck(0, 3, 10);
    AddCheck(0, 1, 10);
    AddCheck(1, 2, 10);
    AddCheck(2, 3, 40);
    AddCheck(3, 4, 2);
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

//Remove Edge

void removeEdge(int u, int v)
{
    int i = -1;
    int j = -1;

    for (int k = 0; k < graph[u].size(); k++)
    {
        if (graph[u][k]->v == v)
        {
            i = k;
            break;
        }
    }

    for (int k = 0; k < graph[v].size(); k++)
    {
        if (graph[v][k]->v == u)
        {
            j = k;
            break;
        }
    }

    graph[u].erase(graph[u].begin() + i);
    graph[v].erase(graph[v].begin() + j);
}

void removeVtx(int u)
{
    for (int i = graph[u].size() - 1; i >= 0; i--)
    {
        removeEdge(graph[u][i]->v, u);
    }

    // graph.erase(graph.begin()+u);
}

int main(int args, char **argv)
{
    caseI();
    //Display();
    int edge;

    cout<<"Enter the edge to be removed: ";
    cin>>edge;

    //removeEdge(edge);
    Display();
}