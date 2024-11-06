#include <vector>

struct Node {
    /* data container */
    int Version; // version of identifier
    int Value; // the state value for version of identifier
    std::vector<Node*> pre_nodes; // list of pointers to earlier nodes, which contain pre_version
    std::vector<int> node_level; // the level the associated pre_node (associated by index position)  
};

