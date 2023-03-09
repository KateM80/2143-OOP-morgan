/*****************************************************************************
 *
 *  Author:           Kate Morgan
 *  Title:            GraphViz
 *  Course:           2143
 *  Semester:         Spring 2023
 *
 *  Description: Utilizes maps to create attributes that are then applied to
 *               Edges and Nodes that are then kept in vectors to allow 
 *               traversal. Then it can be printed to the console or to an
 *               output file.
 *
 *  Usage: The user must create a map<string, string> to hold the desired 
 *         Attributes for either a node or edge. The user then must create
 *         a graph with the GraphViz class to hold the nodes and edges.
 *         The user can then use the AddNode or AddEdge method to create
 *         new nodes or edges. Finally the user can use << or the 
 *         PrintGraph method to print the graph to the console or output file.
 *
 *  Files: main.cpp
 *         test.out
 *****************************************************************************/
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
/**
 * Attribute 
 * 
 * Description: This class contains a map to hold Atrributes and methods
 *              to add Attributes to other classes
 * 
 * 
 * Public Methods:
 *      Attribute() {}
 *      void AddAtt(string key, string add)
 *      void AddAtt(map<string, string> atts)
 */
class Attribute {
protected:
  map<string, string> Att;

public:
  /**
   * @brief -  Default constructor
   * @return None
   */
  Attribute() {}

  /**
   * @brief - Adds an Attribute to the map
   * @param - string key
   * @param - string add
   * @return None
   */
  void AddAtt(string key, string add) {
    Att[key] = add; 
    }

  /**
   * @brief - Adds an Attribute to the map
   * @param - map<string, string>
   * @return None
   */
  void AddAtt(map<string, string> atts) {
    for (auto const &x : atts) {
      Att[x.first] = x.second;
    }
  }
};

/**
 * Node
 * 
 * Description: This class is used for the Nodes in GraphViz
 * 
 * 
 * Public Methods:
 *      Node() {}
 *      Node(map<string, string> atts)
 *      friend ostream &operator<<(ostream &os, Node &n)
 *
 */
class Node : public Attribute {

public:
  /**
   * @brief - Default constructor
   * @return None
   */
  Node() {}

  /**
   * @brief - creates a node with an attribute map
   * @param - map<string, string>
   * @note - uses AddAtt from Attribute class 
   * @return None
   */
  Node(map<string, string> atts) {
    AddAtt(atts); 
    }
  
  /**
   * @brief - Over rides the << operator to allow output
   * @param - ostream &os
   * @param - Node &n
   * @return ostream
   */
  friend ostream &operator<<(ostream &os, Node &n) {
    os << "[";
    int i = 0;
    for (auto const &x : n.Att) {
      os << x.first << "="
         << "\"" << x.second << "\"";

      if (i < n.Att.size() - 1) {
        os << ", ";
      }
      i++;
    }
    os << "]";

    return os;
  }
};

/**
 * Edge 
 * 
 * Description: This class is used for the Edges in GraphViz
 * 
 * Public Methods:
 *          Edge()
 *          Edge(int s, int e, map<string, string> atts)
 *          friend ostream &operator<<(ostream &os, Edge &e)
 */

class Edge : public Attribute {
  int start, end;

public:
  /**
   * @brief -  Default constructor
   * @return None
   */
  Edge() {
    start = 0;
    end = 0;
  }
  /**
   * @brief - creates a Edge with an attribute map
   * @param - map<string, string>
   * @param - int s
   * @param - int e
   * @note - uses AddAtt from Attribute class 
   * @return None
   */
  Edge(int s, int e, map<string, string> atts) {
    start = s;
    end = e;
    AddAtt(atts);
  }

  /**
   * @brief - Over rides the << operator to allow output
   * @param - ostream &os
   * @param - Edge &e
   * @return ostream
   */
  friend ostream &operator<<(ostream &os, Edge &e) {
    os << e.start << "->" << e.end << " ";
    os << "[";
    int i = 0;
    for (auto const &x : e.Att) {
      os << x.first << "="
         << "\"" << x.second << "\"";
      if (i < e.Att.size() - 1) {
        os << ", ";
      }
      i++;
    }
    os << "]";
    return os;
  }
};

/**
 * GraphViz
 * 
 * Description: This Class contains a vector of nodes and a vector
 *              of edges as well as a name for a graph to allow the
 *              user to create their own graph. It includes methods
 *              to create Nodes and Edges with attributes
 * 
 * 
 * Public Methods:
 *           GraphViz()
 *           GraphViz(string name)
 *           int AddNode(map<string, string> atts)
 *           int AddEdge(int s, int e, map<string, string> atts)
 *           void PrintGraph()
 *           friend ostream &operator<<(ostream &os, GraphViz &g)
 * 
 * Usage: 
 *      GraphViz G1("LinkedList")
 *      nodeid = G1.AddNode(folder);
 *      
 */

class GraphViz {
  int nodeid;
  int edgeid;
  vector<Edge> Edges;
  vector<Node> Nodes;
  string GraphName;
  string GraphType;

public:
  /**
   * @brief -  Default constructor
   * @return None
   */
  GraphViz() {
    nodeid = 0;
    edgeid = 0;
    GraphName = "Default";
  }

  /**
   * @brief - Over rides the default constructor to input graph name
   * @param - string name
   * @return none
   */
  GraphViz(string name) {
    nodeid = 0;
    edgeid = 0;
    GraphName = name;
  }

  /**
   * @brief - Adds a node to the Graph
   * @param - map<string, string>
   * @note - returns an int to keep track of id, need an int in main 
   * @return int
   */
  int AddNode(map<string, string> atts) {
    Nodes.push_back(Node(atts));
    return Nodes.size() - 1;
  }

  /**
   * @brief - Adds a Edge to the Graph
   * @param - map<string, string>
   * @note - returns an int to keep track of id, need an int in main 
   * @return int
   */
  int AddEdge(int s, int e, map<string, string> atts) {
    Edges.push_back(Edge(s, e, atts));
    return Edges.size() - 1;
  }
  /**
   * @brief - prints the graph to console
   * @note - formated to print out the graph in dot symtex
   * @return none 
   */
  void PrintGraph() {
    cout << "digraph " << GraphName << "{\n";
    cout << "rankdir = LR\n";
    for (int i = 0; i < Nodes.size(); i++) {
      cout << i << " " << Nodes[i] << endl;
    }
    for (int i = 0; i < Edges.size(); i++) {
      cout << Edges[i] << endl;
    }
    cout << "}\n";
  }
  /**
   * @brief - Over rides the << operator to allow output
   * @param - ostream &os
   * @param - GraphViz &g
   * @note - Formated to output the graph in dot symtex
   * @return ostream
   */
  friend ostream &operator<<(ostream &os, GraphViz &g) {
    os << "digraph " << g.GraphName << "{\n";
    os << "rankdir = LR\n";
    for (int i = 0; i < g.Nodes.size(); i++) {
      os << i << " " << g.Nodes[i] << endl;
    }
    for (int i = 0; i < g.Edges.size(); i++) {
      os << g.Edges[i] << endl;
    }
    os << "}\n";
    return os;
  }
};

int main() {
  //Opens the output file
  ofstream outfile;
  outfile.open("test.out");

  //Creation of an Attribute called Null
  map<string, string> Null;
  Null["shape"] = "cirlce";
  Null["label"] = "Null";
  Null["color"] = "white";

  //Creation of an Attribute called record
  map<string, string> record;
  record["shape"] = "record";
  record["style"] = "filled";
  record["fillcolor"] = "blue:orange";
  record["label"] = "{<data> num | <next>}";

  //Creation of an Attribute called record2
  map<string, string> record2;
  record2["shape"] = "record";
  record2["style"] = "filled";
  record2["fillcolor"] = "blue:purple";
  record2["label"] = "{<data> num | <next>}";

  //Creation of an Attribute called folder
  map<string, string> folder;
  folder["shape"] = "folder";
  folder["style"] = "filled";
  folder["label"] = "Data";
  folder["fillcolor"] = "antiquewhite";

  //Creation of an Attribute called egg
  map<string, string> egg;
  egg["shape"] = "egg";
  egg["fillcolor"] = "white:yellow";
  egg["style"] = "filled";

  //Creation of an Attribute called Arrow1
  map<string, string> Arrow1;
  Arrow1["arrowhead"] = "vee";
  Arrow1["color"] = "red";

  //Creation of an Attribute called Arrow2
  map<string, string> Arrow2;
  Arrow2["arrowhead"] = "crow";
  Arrow2["color"] = "green";

  //Creation of an Attribute called Arrow3
  map<string, string> Arrow3;
  Arrow3["arrowhead"] = "box";
  Arrow3["color"] = "coral";

  //Creation of an Attribute called Arrow4
  map<string, string> Arrow4;
  Arrow4["arrowhead"] = "curve";
  Arrow4["color"] = "blue";

  //out puts a header for the console and output file
  cout << "Kate Morgan\n3/8/2023\nSpring 2023\n\n";
  outfile << "Kate Morgan\n3/8/2023\nSpring 2023\n\n";

  //Creation of a graph called G1 LinkedList
  GraphViz G1("LinkedList");
  //int to keep track of node ids
  int nodeid;
  //Adding nodes to G1
  nodeid = G1.AddNode(folder);
  nodeid = G1.AddNode(record);
  nodeid = G1.AddNode(record);
  nodeid = G1.AddNode(record);
  nodeid = G1.AddNode(Null);

  //int to keep track of edge ids
  int edgeid;
  //adding edges to G1
  edgeid = G1.AddEdge(0, 1, Arrow1);
  edgeid = G1.AddEdge(1, 2, Arrow1);
  edgeid = G1.AddEdge(2, 3, Arrow1);
  edgeid = G1.AddEdge(3, 4, Arrow1);

  //Printing G1 to console and output file
  G1.PrintGraph();
  outfile << G1 << endl;
  cout << endl;

  //Creation of a graph called G2 DoubleLinkedList
  GraphViz G2("DoubleLinkList");
  //Adding nodes to G2
  nodeid = G2.AddNode(Null);
  nodeid = G2.AddNode(record2);
  nodeid = G2.AddNode(record2);
  nodeid = G2.AddNode(record2);
  nodeid = G2.AddNode(record2);
  nodeid = G2.AddNode(record2);
  nodeid = G2.AddNode(Null);

  //adding edges to G2
  edgeid = G2.AddEdge(0, 1, Arrow2);
  edgeid = G2.AddEdge(1, 2, Arrow2);
  edgeid = G2.AddEdge(2, 1, Arrow3);
  edgeid = G2.AddEdge(2, 3, Arrow2);
  edgeid = G2.AddEdge(3, 2, Arrow3);
  edgeid = G2.AddEdge(3, 4, Arrow2);
  edgeid = G2.AddEdge(4, 3, Arrow3);
  edgeid = G2.AddEdge(4, 5, Arrow2);
  edgeid = G2.AddEdge(5, 4, Arrow3);
  edgeid = G2.AddEdge(5, 6, Arrow2);

  //Printing G2 to console and output file
  G2.PrintGraph();
  outfile << G2 << endl;
  cout << endl;

  //Creation of a graph called G3 Binary Search
  GraphViz G3("BinarySearch");
  //Adding nodes to G3
  nodeid = G3.AddNode(egg);
  nodeid = G3.AddNode(egg);
  nodeid = G3.AddNode(egg);
  nodeid = G3.AddNode(egg);
  nodeid = G3.AddNode(egg);
  nodeid = G3.AddNode(egg);
  nodeid = G3.AddNode(egg);

  //adding edges to G3
  edgeid = G3.AddEdge(0, 1, Arrow4);
  edgeid = G3.AddEdge(0, 2, Arrow4);
  edgeid = G3.AddEdge(1, 3, Arrow4);
  edgeid = G3.AddEdge(1, 4, Arrow4);
  edgeid = G3.AddEdge(2, 5, Arrow4);
  edgeid = G3.AddEdge(2, 6, Arrow4);

  //Printing G3 to console and output file
  G3.PrintGraph();
  outfile << G3 << endl;
}