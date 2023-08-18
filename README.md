## Introduction
The provided C++ code aims to establish a robust graph-based system for managing interconnected nodes within galaxies. This comprehensive report offers an in-depth analysis and thorough documentation of the code, focusing on the classes, methods, and their underlying functionalities.

## Code Overview
The code is structured into three primary classes: Node, Galaxy, and World. Collectively, these classes facilitate the creation of a hierarchical representation of galaxies and their associated nodes. Additionally, the code offers methods for managing connections, finding paths, and extracting relevant information.

### 1. Node Class
- Represents an individual node within a galaxy.
- Attributes:
  - galaxyName: The name of the galaxy containing the node.
  - nodeName: The name of the node.
  - id: A unique identifier for the node.
- Constructor: Initializes the attributes.

### 2. Galaxy Class
- Represents a galaxy containing a collection of nodes.
- Attributes:
  - name: The name of the galaxy.
  - nodes: A vector of Node instances within the galaxy.
- Methods:
  - addNode: Adds a new node to the galaxy.

### 3. World Class
- Manages a world of galaxies and their connections.
- Attributes:
  - galaxies: A vector of Galaxy instances.
  - connections: A map of node connections, where each node ID is associated with a vector of connected nodes and their weights.
- Methods:
  - addGalaxy: Adds a new galaxy to the world.
  - connectNodes: Connects two nodes with a weighted edge.
  - shortestPath: Finds the shortest path between two nodes using Dijkstra's algorithm.
  - show_id: Finds the ID of a node given galaxy and node names.
  - letter_find: Extracts node ID from a text containing galaxy and node names.
  - show_3_number: Extracts a vector of three numbers from a text.
  - displayGalaxiesAndNodes: Displays information about galaxies and their nodes.

### Regular Expressions and Main Function
- The code employs regular expressions to extract relevant information from input strings.
- The main function showcases the functionality of the classes and methods. It creates galaxies, nodes, connections, and finds the shortest path between nodes.

## Function Documentation
### Node Class
cpp
class Node
{
public:
    /**
     * Constructor to create a node within a galaxy.
     * @param _galaxyName The name of the containing galaxy.
     * @param _nodeName The name of the node.
     * @param _id A unique identifier for the node.
     */
    Node(char _galaxyName, char _nodeName, int _id);
};

### Galaxy Class
cpp
class Galaxy
{
public:
    /**
     * Constructor to create a galaxy.
     * @param _name The name of the galaxy.
     */
    Galaxy(char _name);

    /**
     * Add a new node to the galaxy.
     * @param nodeName The name of the new node.
     * @param nodeId The unique identifier for the new node.
     */
    void addNode(char nodeName, int nodeId);
};

### World Class
```cpp
class World
{
public:
    // ...

    /**
     * Add a new galaxy to the world.
     * @param galaxyName The name of the new galaxy.
     */
    void addGalaxy(char galaxyName);

    /**
     * Connect two nodes with a weighted edge.
     * @param node1Id The ID of the first node.
     * @param node2Id The ID of the second node.
     * @param weight The weight of the edge.
     */
    void connectNodes(int node1Id, int node2Id, double weight);

    /**
     * Find the shortest path between two nodes using Dijkstra's algorithm.
     * @param startNodeId The ID of the starting node.
     * @param endNodeId The ID of the ending node.
     * @return A pair containing the shortest weight and the path's node IDs.
     */
    std::pair<double, std::vector<int>> shortestPath(int startNodeId, int endNodeId);

    /**
     * Find the ID of a node given its galaxy and node names.
     * @param galaxyName The name of the galaxy.
     * @param node_name The name of the node.
     * @return The ID of the node or -1 if not found.
     */
    int show_id(char galaxy_name, char node_name);
// ...
};

```

```

## Conclusion
The provided C++ code showcases an efficient and versatile graph-based system for managing interconnected nodes within galaxies. By employing classes, methods, and regular expressions, the code achieves flexibility and functionality. Although the code is well-structured, there's potential for further optimization through improved error handling and modularization. The documented classes and methods offer a solid foundation for expanding and utilizing the system effectively.
