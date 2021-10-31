/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    void connect(Node* node, Node* next_node ){
        
        Node* cur_node = node;
        Node* pre_node = node;
        
        while(node != NULL){
            
            pre_node = node;
            
            if(node->child!=NULL){
                connect(node->child,node->next);
                node->next = node->child;
                node->child->prev = node;
                
                node->child = NULL;
            }
            node = node->next;
            
        }
        
        if(next_node != NULL){
            
            pre_node->next = next_node;
            next_node->prev = pre_node;
            
        }
        
        
        
        
    }
    
    Node* flatten(Node* head) {
        
        if(head == NULL)
            return head;
        else
            connect(head,NULL); //開始執行 dfs
        
        return head;
    }
};
