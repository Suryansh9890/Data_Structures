#include <iostream>
#include<queue>
using namespace std;

template<typename T>
 class AVL{
    public:
        
        struct Node{
                T data;
                int height;
                Node* left;
                Node* right;
                Node(T val){
                    data = val;
                    height = 1;
                    left=nullptr;
                    right=nullptr; 
            }
        };
        Node* root;
        void getRoot(){
            cout<<root->data<<"\n";
        }
        AVL(){
            root = nullptr;
        }
        void insert(T key){
            root = insertUtil(root,key);
        }
        int getHeight(){
            int ht = height(root);
            return ht;
        }
        void displayInorder(){
            inorderUtil(root);
            cout<<"\n";
        }
        void displayLevelOrder(){
            levelOrderUtil(root);
            cout<<"\n";
        }
        void deleteItem(T val){
            deleteUtil(root,val);
        }
    private:
        int height(Node* node){
            int hl{},hr{};
            if(node==nullptr)
                return 0;
            hl = (node->left != nullptr) ? node->left->height : 0;
            hr = (node->right != nullptr) ? node->right->height : 0;
            return (hl > hr) ? hl+1 : hr+1;
        }
        int balancefactor(Node* node){
            int hl{},hr{};
            if(node == nullptr)
                return 0;
            hl = (node->left != nullptr) ? node->left->height : 0;
            hr = (node->right != nullptr) ? node->right->height : 0;
            return hl-hr;
        }
        Node* LLrotation(Node* node){
            Node* temp = node->left;
            node->left = node->left->right;
            temp->right = node;
            
            node->height = height(node);
            temp->height = height(temp);
            if(root == temp){
                root = temp;
            }
            return temp;
        }
        Node* LRrotation(Node* node){
            Node* temp = node->left->right;
            node->left->right = temp->left;
            temp->left = node->left;
            node->left = temp->right;
            temp->right = node;
            node->height = height(node);
            temp->left->height = height(temp->left);
            temp->height = height(temp);
            if(root == temp){
                root = temp;
            }
            return temp;
        }
        Node* RRrotation(Node* node){
            Node* temp = node->right;
            node->right = temp->left;
            temp->left = node;
            node->height = height(node);
            temp->height = height(temp);
            if(root == temp){
                root = temp;
            }
            return temp;
        }
        Node* RLrotation(Node* node){
            Node* temp = node->right->left;
            node->right->left = temp->right;
            temp->right = node->right;
            node->right = temp->left;
            temp->left = node;

            node->height = height(node);
            temp->height = height(temp->right);
            temp->height = height(temp);
            if(root == temp){
                root = temp;
            }
            return temp;
        }
        Node* insertUtil(Node* node , T key){
            if(node==nullptr){
                Node* new_node = new Node(key);
                return new_node;
            }
            if(key < node->data)
            {
                node->left = insertUtil(node->left , key);            
            }
            else
            {
                node->right = insertUtil(node->right , key);
            }
            node->height = height(node);
            if(balancefactor(node)==2 && balancefactor(node->left) == 1){
                return LLrotation(node);
            }
            else if(balancefactor(node)==2 && balancefactor(node->left) == -1){
                return LRrotation(node);
            }
            else if(balancefactor(node)==-2 && balancefactor(node->right) == -1){
                return RRrotation(node);
            }
            else if(balancefactor(node)== -2 && balancefactor(node->right) == 1){
                return RLrotation(node);
            }
           return node;
        }
        void inorderUtil(Node* node){
            if(node==nullptr){
                return;
            }
            inorderUtil(node->left);
            cout<<node->data<<" ";
            inorderUtil(node->right);
        }
        void levelOrderUtil(Node* node){
            if(node==nullptr)
                return;
            queue<Node*> level;
            level.push(node);
            while (!level.empty())
            {
                Node* curr = level.front();
                level.pop();
                cout<<curr->data<<" ";
                if(curr->left != nullptr)
                    level.push(curr->left);
                if(curr->right != nullptr)
                    level.push(curr->right);
            }
            
        }
        Node* find_min(Node* node){
            if(node==nullptr)
                return nullptr;
            while(node->left != nullptr){
                node = node->left; 
            }
            return node;
        }
        Node* deleteUtil(Node* node , T key){
            if(node==nullptr)
                return nullptr;
            else if(key < node->data)
                node->left = deleteUtil(node->left , key);
            else if(key>node->data){
                node->right = deleteUtil(node->right , key);
            }
            else{
                if(node->left == nullptr && node->right == nullptr){
                    free(node);
                    return nullptr;
                }
                else if(node->left==nullptr){
                    Node* temp = node->right;
                    *node = *temp;
                    free(temp);
                }
                else if(node->right==nullptr){
                    Node* temp = node->left;
                    *node = *temp;
                    free(temp);
                }
                else{
                    Node* temp = find_min(node->right);
                    node->data = temp->data;
                    node->right = deleteUtil(node->right , key);
                }

            }
            node->height = height(node);
            if(balancefactor(node)==2 && balancefactor(node->left) == 1){
                return LLrotation(node);
            }
            else if(balancefactor(node)==2 && balancefactor(node->left) == -1){
                return LRrotation(node);
            }
            else if(balancefactor(node)==-2 && balancefactor(node->right) == -1){
                return RRrotation(node);
            }
            else if(balancefactor(node)== -2 && balancefactor(node->right) == 1){
                return RLrotation(node);
            }
           return node;
        }

 };
int main()
{
	AVL<int> avl;
    
    avl.insert(11); 
    avl.insert(5);
    avl.insert(55);
    avl.insert(31);
    avl.insert(1);
    avl.insert(19);
    avl.insert(45);
    avl.insert(67);
    avl.insert(0);
    avl.insert(13);
    avl.insert(98);
    avl.displayInorder();
    avl.getRoot();
    avl.displayLevelOrder();
    avl.deleteItem(0);
    avl.displayInorder();
    avl.displayLevelOrder();
    return 0;
}