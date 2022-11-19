import java.util.Scanner;
import java.util.ArrayList;

public class l001_graph {
    public static Scanner scn = new Scanner(System.in);
    public static ArrayList<Edge>[] graph = new ArrayList[7];

    public static void main(String[] args) {
        caseI();
        Display();
    }

    public static class Edge {
        int u = 0;
        int w = 0;

        Edge(int u, int w) {
            this.u = u;
            this.w = w;
        }

        Edge() {
        };
    }

    public static void caseI() {
        for (int i = 0; i < graph.length; i++)
            graph[i] = new ArrayList<Edge>();

        AddCheck(0, 3, 10);
        AddCheck(0, 1, 10);
        AddCheck(1, 2, 10);
        AddCheck(2, 3, 40);
        AddCheck(3, 4, 2);
        AddCheck(4, 5, 2);
        AddCheck(4, 6, 3);
        AddCheck(5, 6, 8);

    }

    public static void Display()
    {
        for(int i=0;i<graph.length;i++)
        {
            System.out.print(i+"=>");
            for(int j=0;j<graph[i].size();j++)
            {
                System.out.print("("+graph[i].get(j).u + "|"+graph[i].get(j).w+") ");
            }

            System.out.println();
        }
    }

    public static void AddCheck(int u, int v, int w) {
        if (u >= graph.length || u < 0 || v < 0 || v >= graph.length)
            return;

        graph[u].add(new Edge(v, w));
        graph[v].add(new Edge(u, w));
    }

}