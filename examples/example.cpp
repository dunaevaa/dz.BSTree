#include "bstree.cpp"
#include<iostream>
#include<locale>
#include<string>
#include<fstream>
using namespace std;

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
            default: cout << "Неверная команда " << endl;
        }
    }
}
