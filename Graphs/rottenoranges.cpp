#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Edge
{
public:
    int r = 0;
    int c = 0;
    int time = 0;

    Edge(int r, int c, int t)
    {
        this->r = r;
        this->c = c;
        this->time = t;
    }

    Edge(){};
};

vector<vector<Edge *>> graph(7, vector<Edge *>());

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

int main(int args, char **argv)
{
    caseI();
    Display();
}