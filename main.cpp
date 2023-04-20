#include <vector>
using namespace std;

template<typename T>
class Node{
    Node(const T data,){
        color = 0;
        data = data;
    }
    private:
    void check(){
        checked = true;
    }
    void uncheck(){
        checked = false;
    }
    public:
        int color;
        T data;
        vector<Edge> from_edges;
        bool checked;
}; 

// template<typename T>
// class edge{
//     Edge(const Node& src, const Node& dest, const W& weight = W()){
//         from = src;
//         to = dest;
//         w = weight;
//         checked = false;
//         string = "white";
//     }
//     public:
//     Node<T> from;
//     Node<T> to;
//     int w;
//     string color;
//     bool checked;
// };
template <typename T, typename W>
class Edge {
private:
 Node<T> src,dest;
 W weight;
 int color;
public:
 Edge(const Node<T>& src, const Node<T>& dest, const W& weight){
    this->src = src;
    this->dest = dest;
    this->weight = weight;
    this->color = 0;
 };
 T getSource(){
    return src;
 } const;
 T getDestination(){
    return dest;
 } const;
 W getWeight() const;
};

template<typename T, typename W>
class Graph {

public:
 Graph(bool directed);
 Node addNode(const T& data){
    Node newnode = Node<T>(data);
 };
 void addEdge(const Node<T>& src, const Node<T>& dest, const W& weight = W()){
    Edge newEdge = Edge(Node& src, Node& dest, const W& weight = W())
    src.from_edges.push_back(newEdge);
 };
 bool hasCycle(){

 } const;
 // Algorithm implementations
 vector<int> nodeColoring() const;
 vector<int> edgeColoring() const;
 void completeEdges();
 vector<vector<T>> connectedComponents() const;
 vector<double> katzCentrality(double alpha, double beta) const;
 vector<Edge> primMST() const;
 vector<Edge> kruskalMST() const;
 vector<T> iterativeDFS(const T& start) const;
 vector<T> uniformCostSearch(const T& start, const T& goal) const;
 vector<T> aStarSearch(const T& start, const T& goal, function<double(T, T)> heuristic) 
const;
};


// #define later;
#ifdef later;
// Pybind11 integration (inside a separate . file)
PYBIND11_MODULE(graphlib, m) {
 py::class_<Graph>(m, "Graph")
 // Constructors, member functions, etc.
 ;
}
#endif