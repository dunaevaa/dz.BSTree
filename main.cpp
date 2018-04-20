#include<iostream>
#include<locale>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class BSTree {
    private:
        Node *root;
    public:
        BSTree() { root = nullptr; }
        void add(Node *&root, int data) {
            if (root == nullptr) {
                root = new Node { data, nullptr, nullptr };
            }
            if (data < root->data) {
                if (root->left = nullptr) {
                        root->left = new Node { data, nullptr, nullptr };
                }
                else add(root->left, data);
            }
            if (data > root->data) {
                if (root->right = nullptr) {
                        root->right = new Node { data, nullptr, nullptr };
                }   
                else add(root->right, data);
            }
        }
        void insert(int data) { add (root, data); }
        void delete_tree(Node *&data) {
            if (data != nullptr) {
                delete_tree(data->left);
                delete_tree(data->right);
                delete data;
                data = nullptr;
            }
        }
        ~BSTree() {
            delete_tree(root);
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
        tree.element(atoi(argv[i]));
    };
    int choice = 0;
    while (true) {
        menu();
        cin >> choice;
        switch (choice) {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:
            return 0;
            default: cout << " Неверная команда " << endl;
        }
    }
}
