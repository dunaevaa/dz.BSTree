#include<iostream>
#include<locale>
#include<string>
#include<fstream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node *parent;
};

class BSTree {
    private:
        Node *root;
    public:
        BSTree() { root = nullptr; }
    
        auto insert(Node*& root, Node*& parent, Node*& value) -> Node* {
            if (root == nullptr) {
		        root = value;
		        if(root != this->root)
                    root->parent = parent;
	        } else {
		        if (root->data < value->data) {
			        root->left = insert(root->left, root, value);
		        } else if (root->data > value->data) {
                    root->right = insert(root->right, root, value);
                }
            }
            return root;
        }
        void insert(int value) { insert(root, value); }
        void delete_tree(Node *&data) {
            if (data != nullptr) {
                delete_tree(data->left);
                delete_tree(data->right);
                delete data;
                data = nullptr;
            }
        }
        ~BSTree() {
            cout << "Был вызван деструктор" << endl;
            delete_tree(root);
        }
        void show(Node*node, int stage) {
            if (node->left != nullptr)
                show(node->left, stage+1);
            if (node != root) { 
                cout.width(stage*4);
                cout << "--";
            }
            cout << "(" << node->data << ")" << endl;
            if (node->right != nullptr)
                show(node->right, stage+1);
        }
        void show() {
            if (root != nullptr) 
                show (root, 1);
            else cout << "Дерево пустое" << endl;
        }
        void direct_bypass(Node* root) {
            if (root != nullptr) {
                cout << root->data << " ";
                direct_bypass(root->right);
                direct_bypass(root->left);
            }
        }
        void cross_bypass(Node* root) {
            if (root != nullptr) {
                cross_bypass(root->right);
                cout << root->data << " ";
                cross_bypass(root->left);
            }
            return;
        }
        void reverse_bypass(Node* root) {
            if (root != nullptr) {
                reverse_bypass(root->left);
                reverse_bypass(root->right);
                cout << root->data << " ";
            }
        }
        void select_bypass(char choice_bypass) {
            if (choice_bypass == 'a') 
                direct_bypass(root);
            if (choice_bypass == 'b') 
                cross_bypass(root);
            if (choice_bypass == 'c') 
                reverse_bypass(root);
        }
        
        bool upload_to_file(string& road)  {
            ofstream fout(road.c_str());
            if(!fout.is_open() || root == nullptr) {
                cout << "Файл не открыт или дерево пустое" << endl;
                return false;
            }
            direct_bypass(root, fout);
            return true;
        }
        void direct_bypass(Node* root, ofstream &fout) {
            if (root != nullptr) {
                fout << root->data << " ";
                direct_bypass(root->right, fout);
                direct_bypass(root->left, fout);
            }
        }

        bool unload_from_file(string& road) {
            ifstream fin(road.c_str());
            if (!fin.is_open()) {
                cout << "файл не открыт";
                return false;
            }
            if (root) 
                delete_tree(root);
            int value;
            while(fin >> value) 
                insert(value);
            return true;
        }

        bool exists(int value) const {
            if(!root) {
                cout << "дерево пустое" << endl;
                return false;
            } else if (root) {
                Node *current = root;
                while(current != nullptr) {
                    if(value < current->data) 
                        current = current->right;
                    else if(value > current->data) 
                        current = current->left;
                    else if(current->data == value) 
                    break;
                }
                if(current == nullptr) {
                    cout << "узел не найден" << endl;
                    return false;
                } else {
                    cout << "узел найден" << endl;
                    return true;
                }
            }
        }
    
        auto delete_node(Node *&root, int value) -> bool {
            if(!root) {
		        cout << "дерево пустое" << endl;
		        return false;
	        } else if(root) {
		        Node *current = root;
		        while (current != nullptr) {
			        if (value < current->data) 
				        current = current->right;
			        else if (value > current->data) 
				        current = current->left;
			        else if (current->data == value)
				        break;
                }
                if (current == nullptr) {
                    cout << "узел не найден" << endl;
                    return false;
                }
                Node* left = nullptr;
                Node* right = nullptr;
		        if (current == root) {
		            if (current->right!=nullptr && current->left!=nullptr) {
		                root=current->right;
		                insert(root,root,current->left);
		            } else if (current->right!=nullptr && current->left==nullptr) 
			            root = current->right;
		              else if (current->left!=nullptr && current->right==nullptr) 
		                root = current->left;
                      else if (current->left==nullptr && current->right==nullptr)
		                root=nullptr;
			        delete current;
			        cout << "успешно удалено" << endl;
			        return true;
		        } else {
                    if (current->right != nullptr && current->left == nullptr) {
				        if (current == current->parent->left)
					        current->parent->left = nullptr;
				        else
					        current->parent->right = nullptr;
				        right = current->right;
				        insert(root, root, right);
			        } else if (current->left != nullptr && current->right == nullptr) {
				        if (current == current->parent->left)
					        current->parent->left = nullptr;
				        else
					        current->parent->right = nullptr;
				        left = current->left;
				        insert(root, root, left);
			        } else if (current->right != nullptr && current->left != nullptr) {
				        left = current->left;
				        right = current->right;
				        if (current == current->parent->left)
					        current->parent->left = nullptr;
				        else
					        current->parent->right = nullptr;
				        insert(root, root, left);
				        insert(root, root, right);
			        } else {
				        if (current == current->parent->left)
					        current->parent->left = nullptr;
				        if (current == current->parent->right)
					        current->parent->right = nullptr;
			        }
			        delete current;
			        cout << "Удалено успешно" << endl;
			        return true;
		        }
	        }
        }
        auto insert(Node*& root, Node*& parent, int value) -> Node* {
	        if (root == nullptr) {
		        root = new Node {value, nullptr, nullptr, nullptr};
		        if (root != this->root)
			        root->parent = parent;
	        } else {
		        if (root->data < value) 
			        root->left = insert(root->left, root, value);
		        else if (root->data > value) 
			        root->right = insert(root->right, root, value);
		        else if (root -> data == value) {
			        cout << "Дерево имеет этот узел" << endl;
			        return root;
		        }
	        }
	        return root;
        }
        auto delete_node(int value) -> void {
            delete_node(root,value);
        }
};

void menu(){
    cout << "Выберете одну из операций:" << endl;
    cout << "1. Вывести дерево на экран" << endl;
    cout << "2. Вывести список узлов дерева" << endl;
    cout << "3. Добавить узел в дерево" << endl;
    cout << "4. Удалить узел из дерева" << endl;
    cout << "5. Сохранить дерево в файл" << endl;
    cout << "6. Загрузить дерево из файла" << endl;
    cout << "7. Проверить наличие узла" << endl;
    cout << "8. Завершить работу программы" << endl;
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    BSTree tree;
    for (int i=1; i<argc; i++) { 
        tree.insert(atoi(argv[i]));
    };
    string choice_exit;
    char choice_bypass;
    int choice = 0;
    while (true) {
        string road;
        int value = 0;
        menu();
        cin >> choice;
        switch (choice) {
            case 1: tree.show ();
            break;
            case 2: cout << "Выберите способ обхода" << endl;
                    cin >> choice_bypass;
                    tree.select_bypass(choice_bypass);
                    cout << endl;
            break;
            case 3: cin >> value;
                    tree.insert(value);
            break;
            case 4: cin >> value;
                    tree.delete_node(value);
            break;
            case 5: cin >> road;
                    tree.upload_to_file(road);
            break;
            case 6: cin >> road;
                    tree.unload_from_file(road);
            break;
            case 7: cin >> value;
                    tree.exists(value);
            break;
            case 8: cout << "Вы уверены, что хотите выйти из программы?";
                    cin >> choice_exit;
                    if (choice_exit == "Да")
                        return 0;
                    else if (choice_exit == "да") 
                        return 0;
            default: cout << " Неверная команда " << endl;
        }
    }
}
