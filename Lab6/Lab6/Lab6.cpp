#include "StringBinaryTree.hpp"
#include <iostream>
#include <limits> // For numeric_limits
using namespace std;

int main() {
    StringBinaryTree tree;
    int choice;
    string value;

    do {

        //giving the user the option to choose which operation they want to do
        cout << "\nBinary Search Tree Operations Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Find\n";
        cout << "3. Remove\n";
        cout << "4. PrintTree\n";
        cout << "5. Size\n";
        cout << "6. EmptyTree\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        switch (choice) {

            //switching between the different choices with the correct functions
        case 1:
            cout << "Enter string to insert: ";
            getline(cin, value);
            tree.Insert(value);
            cout << "'" << value << "' inserted into the tree.\n";
            break;
        case 2:
            cout << "Enter string to find: ";
            getline(cin, value);
            if (tree.Find(value) != "")
                cout << "'" << value << "' found in the tree.\n";
            else
                cout << "'" << value << "' not found in the tree.\n";
            break;
        case 3:
            cout << "Enter string to remove: ";
            getline(cin, value);
            if (tree.Remove(value) != "")
                cout << "'" << value << "' removed from the tree.\n";
            else
                cout << "'" << value << "' not found in the tree.\n";
            break;
        case 4:
            cout << "Tree contents: ";
            tree.PrintTree();
            break;
        case 5:
            cout << "Tree Size: " << tree.Size() << endl;
            break;
        case 6:
            tree.EmptyTree();
            cout << "Tree has been emptied.\n";
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }

    } while (choice != 7); //used for if the user inputs an invalid choice

    return 0;
}