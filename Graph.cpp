#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    std::vector<std::vector<int>> adjacencyList;

public:
    Graph(int numVertices) : adjacencyList(numVertices) {}

    void addEdge(int source, int destination) {
        if (source >= 0 && source < adjacencyList.size() && destination >= 0 && destination < adjacencyList.size()) {
            adjacencyList[source].push_back(destination);
        } else {
            std::cerr << "Invalid vertex indices." << std::endl;
        }
    }

    void displayGraph() {
        for (int i = 0; i < adjacencyList.size(); ++i) {
            std::cout << "Vertex " << i << ": ";
            for (const int& neighbor : adjacencyList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    void dfsRecursive(int startVertex, std::vector<bool>& visited) {
        visited[startVertex] = true;
        std::cout << startVertex << " ";

        for (const int& neighbor : adjacencyList[startVertex]) {
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);
            }
        }
    }

    void dfs(int startVertex) {
        std::vector<bool> visited(adjacencyList.size(), false);
        std::cout << "DFS (Recursive): ";
        dfsRecursive(startVertex, visited);
        std::cout << std::endl;
    }

    void bfs(int startVertex) {
        std::vector<bool> visited(adjacencyList.size(), false);
        std::queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        std::cout << "BFS (While Loop): ";
        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            std::cout << currentVertex << " ";

            for (const int& neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        std::cout << std::endl;
    }
};

int main() {
    Graph myGraph(5);

    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 3);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(2, 4);
    myGraph.addEdge(3, 4);

    std::cout << "Graph Representation:" << std::endl;
    myGraph.displayGraph();

    myGraph.dfs(0);
    myGraph.bfs(0);

    return 0;
}
