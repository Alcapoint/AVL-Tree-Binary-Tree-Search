#include <iostream>
#include <queue>

using namespace std;

class Avl
{
    
    struct Node
    {
        int key;
        Node* left;
        Node* right;
        int height;
    };

    Node* root;

    void delAvl(Node* node) 
    {
        if (node == nullptr)
            return;
        delAvl(node->left);
        delAvl(node->right);
        delete node;
    }

    Node* insert(int x, Node* node)
    {
        if (node == nullptr)
        {
            node = new Node;
            node->key = x;
            node->height = 0;
            node->left = nullptr;
            node->right = nullptr;
        }
        else if (x < node->key)
        {
            node->left = insert(x, node->left);
        }
        else if (x > node->key)
        {
            node->right = insert(x, node->right);
        }

        node->height = max(height(node->left), height(node->right)) + 1;

        return balance(node);
    }
    Node* rightRotate(Node* node)
    {
        Node* u = node->left;
        node->left = u->right;
        u->right = node;
        node->height = max(height(node->left), height(node->right)) + 1;
        u->height = max(height(u->left), node->height) + 1;
        return u;
    }

    Node* leftRotate(Node* node) 
    {
        Node* u = node->right;
        node->right = u->left;
        u->left = node;
        node->height = max(height(node->left), height(node->right)) + 1;
        u->height = max(height(node->right), node->height) + 1;
        return u;
    }

    Node* doubleLeftRotate(Node* node)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    Node* doubleRightRotate(Node* node)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    Node* balance(Node* node)
    {
        int balance = getBalance(node);

        if (balance < -1) 
        {
            if (getBalance(node->left) <= 0)
            {
                return leftRotate(node);
            }
            else
            {
                return doubleLeftRotate(node); 
            }
        }
        else if (balance > 1) 
        {
            if (getBalance(node->right) >= 0)
            {
                return rightRotate(node); 
            }
            else
            {
                return doubleRightRotate(node);
            }
        }
        return node;
    }

    Node* findMin(Node* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        else if (node->left == nullptr)
        {
            return node;
        }
        else
        {
            return findMin(node->left);
        }
    }
    bool isEmpty(Node* node)
    {

        if (node == nullptr) return false;
        else return true;
        
    }

    Node* remove(int x, Node* node) 
    {
        Node* temp;

        if (node == nullptr)
        {
            return nullptr;
        }
        else if (x < node->key)
        {
            node->left = remove(x, node->left);
        }
        else if (x > node->key)
        {
            node->right = remove(x, node->right);
        }

        else if (node->left && node->right) 
        {
            temp = findMin(node->right);
            node->key = temp->key;
            node->right = remove(node->key, node->right);
        }
        else 
        {
            temp = node;
            if (node->left == nullptr)
            {
                node = node->right;
            }
            else if (node->right == nullptr)
            {
                node = node->left;
            }
            delete temp;
        }
        if (node == nullptr)
        {
            return node;
        }

        node->height = max(height(node->left), height(node->right)) + 1;

        return balance(node);
    }

     bool find(Node* node, int x)
    {
         if (node != nullptr) {
             if (node->key == x) return true;
             else if (node->key > x)return find(node->left, x);
             else return find(node->right, x);
         }
         else return false;
    }

    int height(Node* node)
    {
        return (node == nullptr ? -1 : node->height);
    }

    int getBalance(Node* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return height(node->left) - height(node->right);
        }
    }

    void printAvl(Node* p, int level)
    {
        if (p)
        {
            printAvl(p->left, level + 1);
            for (int i = 0; i < level; i++) cout << "   ";
            cout << p->key << endl;
            printAvl(p->right, level + 1);
        }
    }

    void preDepth(Node* root)
    {
        if (root == NULL)  
        {
            return;
        }
        cout << root->key << " ";
        preDepth(root->left);  
        preDepth(root->right); 
    }

    void inDepth(Node* root)
    {
        if (root == NULL)  
        {
            return;
        }
        inDepth(root->left);  
        cout << root->key << " ";
        inDepth(root->right);  
    }

    void postDepth(Node* root)
    {
        if (root == NULL) 
        {
            return;
        }
        postDepth(root->left);  
        postDepth(root->right); 
        cout << root->key << " ";
    }


public:
    Avl()
    {
        root = nullptr;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void search(int x)
    {
        if (find(root, x) == false)
            cout << "Узел с таким ключом отстутствует" << endl;
        else
            cout << "Найден узел с таким ключом " << endl;
    }
   
    void Width(Node *root) {
 	queue<Node *> q;
 	if (root != NULL) {
 		q.push(root);
 	}
 	while(q.empty() == false) {
 		Node *node = q.front();
 		q.pop();
 		cout << node->key << " ";
 		if (node->left != NULL) {
 			q.push(node->left);
 		}
 		if (node->right != NULL) {
 			q.push(node->right);
 		}
 	}
 }
    bool check()
    {
        if (isEmpty(root) == true) return true;
        else return false;
    }

    void print()
    {
        printAvl(root, height(root));
    }

    void PreOrder()
    {
        preDepth(root);
    }

    void InOrder()
    {
        inDepth(root);
    }

    void PostOrder()
    {
        postDepth(root);
    }

    void wide()
    {
        Width(root);
    }
    

};

