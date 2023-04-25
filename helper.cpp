#include <vector>
using namespace std;

// ... (Node and Edge classes) ...

template <typename T, typename W>
class Graph {
public:
    // ... (Constructor, addNode, addEdge_bynodeid, addEdge_bynodepointer) ...

    bool hasCycle() const {
        for (const Node<T>& node : node_map) {
            if (!node.checked) {
                if (dfs(node, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    vector<Node<T>> node_map;
    vector<vector<Edge<T, W>>> adjacency_matrix;
    bool directed;

    bool dfs(const Node<T>& node, int parent) const {
        node_map[node.id].checked = true;
        for (const Edge<T, W>& edge : adjacency_matrix[node.id]) {
            if (edge) {
                int neighbor = edge.getDestination().id;
                if (!node_map[neighbor].checked) {
                    if (dfs(node_map[neighbor], node.id)) {
                        return true;
                    }
                } else if (neighbor != parent || directed) {
                    return true;
                }
            }
        }
        return false;
    }
};
