#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int find_shortest_path(const vector <vector <int>>& graph, const vector <int>& unvisited_nodes, int cur_node, int cur_len)
{
    if (unvisited_nodes.size() == 1)
    {
        return cur_len + graph[cur_node][unvisited_nodes[0]] + graph[unvisited_nodes[0]][0];
    }
    else
    {
        int min_path = -1;
        int new_path;
        for (int i = 0; i < unvisited_nodes.size(); i++)
        {
            vector <int> new_nodes = unvisited_nodes;
            new_nodes.erase(new_nodes.begin() + i);
            new_path = find_shortest_path(graph, new_nodes, unvisited_nodes[i], cur_len + graph[cur_node][unvisited_nodes[i]]);
            if (min_path == -1)
            {
                min_path = new_path;
            }
            else
            {
                if (new_path < min_path)
                    min_path = new_path;
            }
        }
        return min_path;
    }
}


int find_shortest_path(const vector <vector <int>>& graph)
{
    vector <int> unvisited_nodes;
    for (int i = 1; i < graph.size(); i++)
    {
        unvisited_nodes.push_back(i);
    }
    return find_shortest_path(graph, unvisited_nodes, 0, 0);
}


int main()
{
    vector <vector <int>> graph1 = {{0, 10, 8, 6},
                                    {10, 0, 3, 7},
                                    {8, 3, 0, 1},
                                    {6, 7, 1, 0}};
    cout << find_shortest_path(graph1) << endl;
}
