#include<iostream>
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
        root = new Node;
        root->data = data;
        root->left = root->right = nullptr;
        }
        if (data < root->data) {
            if (root->left != nullptr)
                add ( root->left, data);
            else {
                root->left = new Node;
                root->left->left = nullptr;
                root->left->right = nullptr;
                root->left->data = data;
            }
        }
        if (data > root->data) {
            if (root->right != nullptr)
                add (root->right, data);
            else {
                root->right = new Node;
                root->right->left = nullptr;
                root->right->right = nullptr;
                root->right-> data = data;
            }
        }
    }
    void element(int data) { add(root, data); }
    ~BSTree() {}
};

void menu() {
cout « "Выберете одну из операций:" « endl;
cout « "1. Вывести дерево на экран" « endl;
cout « "2. Вывести список узлов дерева" « endl;
cout « "3. Добавить узел в дерево" « endl;
cout « "4. Удалить узел из дерева" « endl;
cout « "5. Сохранить дерево в файл" « endl;
cout « "6. Загрузить дерево из файла" « endl;
cout « "7. Проверить наличие узла" « endl;
cout « "8. Завершить работу программы" « endl;
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    BSTree *tree = new BSTree;
    for (int i = 1; i < argc; i++) {
        tree -> element(atoi(argv[i]));
    };
    int choise = 0;
    while (true) {
        menu();
        cin » choise;
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
        default: cout << "Неверная команда" << endl;
        }
    }
    delete tree;
}
