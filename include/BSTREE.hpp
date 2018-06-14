#include<iostream>
#include<fstream>
namespace BSTREE{
struct Node{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};

class BSTree{
    private:
    Node *root;
    auto insert(Node*& root,Node*& parent,Node*& value)-> Node*;
    void delete_tree(Node *&data);
    void show(Node*node, int stage);
    void direct_bypass(Node* root);
    void cross_bypass(Node* root);
    void reverse_bypass(Node* root);
    void direct_bypass(Node* root, std::ofstream &fout);
    auto delete_node(Node *&root, int value) ->bool;
    auto insert(Node*& root, Node*& parent, int value) -> Node*;


    public:
    BSTree();
    void insert(int value);
    void show();
    void select_bypass( char choice_bypass );
    bool upload_to_file(std::string& road);
    bool unload_from_file(std::string& road);
    bool exists(int value) const;
    auto delete_node(int value) ->void;
    ~BSTree();
    };
}
