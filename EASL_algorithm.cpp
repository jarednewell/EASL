#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <iterator> 
#include <string>
#include <chrono>

using namespace std::chrono;

std::tuple<std::vector<Node*>,std::vector<int>> EASL_append(int new_version, Node* last_node){
    /*
    Used to append items to the deterministic append only skip-list.
    Supports the tracking of 2,147,483,647 versions.
    Due to the nature of blockchain with immutability appending is the only valid method type.
    The base variable b is able to be set to meet the requirements of the index at initialisation.
    */

    int b = 2; // base used to defined the interval size at each level
    int level = 1; // DASL level starts at 0 - level 0 is always occupied (save on a single loop)
    int interval = 0;
    int pre_level = 0;
    bool finish = false; // main loop control
    Node* current = last_node; // DASL Node (a version of a tracked indentifier)
    std::vector<Node*> pre_nodes; // return list (vector) - every item at 0 level
    std::vector<int> node_levels; // return list (vector) - the position has a relationship with pre_nodes

    while (!finish){
                    
            while(true){

                if (current -> pre_nodes.empty()){
                    // if the node has no pointers then it is the first node
                    finish = true;
                }
                else{
                    // attempt to bring up to height with the previous
                    pre_level = current -> node_level.back();
                    interval = pow(b, pre_level);

                    // only sets the height if the interval is not already occupied
                    if (int (current -> Version / interval) < int (new_version / interval)){
                        level = pre_level;
                        // start from pre_level height
                    }
                    else{
                        finish = true;
                    }
                    // otherwise start from level 1                                        
                }

                interval = pow(b, level);
                        
                if (int (current -> Version / interval) == int (new_version / interval) || pre_level == level){
                    // the maximum height is one level back
                    if (!(pre_level == level) || int (current -> Version / interval) == int (new_version / interval)){
                        level = level - 1;
                    }
                    // add the previous node pointer
                    pre_nodes.push_back(current);
                    // add the heighest level that the pointer applies to
                    node_levels.push_back(level);
                    break;
                }
                level++;
            }

            if (!finish){
                // goes back one node
                while(true){

                    if (current -> pre_nodes.back()->Version == 1){
                        // this version is the highest due to its pointer to the first version 
                        // therefore finish checking pre version version and finish with the 
                        // first version
                        current = current->pre_nodes.back();
                    } else {
                        // at level 0 all nodes point to the pre-version node
                        current = current -> pre_nodes.front();
                    }
                    
                    if (current -> pre_nodes.empty()){
                        // first node doesn't contain any reference to previous nodes
                        break;
                    } 
                    else if (current -> node_level.back() >= node_levels.back()){
                        // selects the previous node if its level is equal or higher
                        break;
                    }
                }
                level = level + 1;
            }
        }
        return std::make_tuple(pre_nodes, node_levels);
}