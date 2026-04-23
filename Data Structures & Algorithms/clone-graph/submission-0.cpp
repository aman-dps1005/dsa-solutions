/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node * dfsClone(Node * node,unordered_map<Node *,Node *> & cloneMap){

        
        if (cloneMap.find(node) != cloneMap.end()) {
            return cloneMap[node];
        }

        Node* newNode = new Node(node->val);
        cloneMap[node] = newNode;

        for (Node* it : node->neighbors) {
            newNode->neighbors.push_back(dfsClone(it, cloneMap));
        }

        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        unordered_map<Node*, Node*> cloneMap;
        return dfsClone(node, cloneMap);
    }
};
