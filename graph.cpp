#include <vector>
using namespace std;
// #define graph;

template <typename T>
class Node{
public:
   int color;
   T data;
   bool checked;
   Node(const T data)
   {
      color = 0;
      this->data = data;
      this.id=id;
   }
   void check(){checked = true;}
   void uncheck(){checked = false;}

};

template <typename T, typename W>
class Edge{
public:
   Edge(const Node<T> &src, const Node<T> &dest, const W &weight)
   {
      this->src = src;
      this->dest = dest;
      this->weight = weight;
      this->color = 0;
   }

   Node<T> getSource() const{return src;}

   Node<T> getDestination() const{return dest;}

   W getWeight() const{return weight;}
private:
   Node<T> src, dest;
   W weight;
   int color;
};

template <typename T, typename W>
class Graph
{
public:
   Graph(bool directed) {}
   vector<Node> node_map = new vector<Node>();
   vector<vector<Edge>> adjacency_matrix = new vector<vector<Node>>();

   Node<T> addNode(const T &data)
   {
      Node<T> newnode = Node<T>(data);
      // insert in node_map the pointer to newnode
      node_map.push_back(newnode);
      // insert a NULL* in each vector
      vector<Edge> temp = new vector<Edge>();
      for (vector<Node> vec : adjacency_matrix) {
      vec.push_back(nullptr);
      temp.push_back(nullptr);
      }
      temp.push_back(nullptr);
      // insert a vector of NULL in adjacency matrix of length len(vector)
      adjacency_matrix.push_back(temp);

      delete temp;
      return newnode;
   }

   void addEdge_bynodeid(const int src, const int dest, const W &weight = W())
   {  
      Edge<T, W> newEdge = Edge<T, W>(node_map[src], node_map[dest], weight);
      adjacency_matrix[src][dest] = newEdge;
   }
   void addEdge_bynodepointer(const Node<T> &src, const Node<T> &dest, const W &weight = W())
   {  
      Edge<T, W> newEdge = Edge<T, W>(src, dest, weight);
      int source, destination, count = 0;
      for (auto& node : node_map) {
      if(node == src){source = count}
      else if(node == dest){destination = count}
      count = count + 1;
      }
      adjacency_matrix[source][destination] = newEdge;
   }

   bool hasCycle() const {
      int row = 0;
      for (auto& vec : adjacency_matrix) {
         int column = 0;
         for (auto& edge : vec){
            edge.dest.check();
         }
         row=row+1;
      }
   }

   // Algorithm implementations
//    vector<int> nodeColoring() const {}
//    vector<int> edgeColoring() const {}
//    void completeEdges() {}
//    vector<vector<T>> connectedComponents() const {}
//    vector<double> katzCentrality(double alpha, double beta) const {}
//    vector<Edge<T, W>> primMST() const {}
//    vector<Edge<T, W>> kruskalMST() const {}
//    vector<T> iterativeDFS(const T &start) const {}
//    vector<T> uniformCostSearch(const T &start, const T &goal) const {}
//    vector<T> aStarSearch(const T &start, const T &goal, function<double(T, T)> heuristic) const {}
};

// #define later;
#ifdef later;
// Pybind11 integration (inside a separate . file)
PYBIND11_MODULE(graphlib, m)
{
   py::class_<Graph>(m, "Graph")
       // Constructors, member functions, etc.
       ;
}
#endif