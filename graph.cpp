#include <vector>
using namespace std;
// #define graph;
template <typename T, typename W>
class Edge;

template <typename T>
class Node{
public:
   int id;
   int color;
   T data;
   bool checked;
   Node(const T data)
   {
      color = 0;
      this->data = data;
   }
   void check(){checked = true;}
   void uncheck(){checked = false;}

};

template <typename T, typename W>
class Edge
{
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
   int number_of_nodes=0;
   Graph(bool directed) {}
   vector<vector<Edge>> adjacency_matrix = new vector<vector<Node>>();
   Node<T> addNode(const T &data)
   {
      // incrementing the number of nodes for the next node id
      number_of_nodes=number_of_nodes+1;
      Node<T> newnode = Node<T>(data);
      newnode.id = number_of_nodes;
      // insert a NULL* in each vector
      vector<Edge> temp = new vector<Edge>();
      for (auto& vec : adjacency_matrix) {
      vec.push_back(nullptr);
      temp.push_back(nullptr);
      }
      temp.push_back(nullptr);
      // insert a vector of NULL in adjacency matrix of length len(vector)
      adjacency_matrix.push_back(temp);
      delete temp;

      return newnode;
   }

   void addEdge(const Node<T> &src, const Node<T> &dest, const W &weight = W())
   {
      Edge<T, W> newEdge = Edge<T, W>(src, dest, weight);

   }

//    bool hasCycle() const {}

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