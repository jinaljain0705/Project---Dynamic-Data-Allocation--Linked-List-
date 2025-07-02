# Dynamic Data Allocation (Linked List)
Program: Dynamic Memory Allocation

Code:
```cpp
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert_at_beginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Value " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Value " << key << " not found in the list." << endl;
    }

    void delete_node(int key) {
        Node* temp = head;
        Node* prev = NULL;

        if (temp != NULL && temp->data == key) {
            head = temp->next;
            delete temp;
            cout << "Node with value " << key << " deleted." << endl;
            return;
        }

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Value " << key << " not found." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Node with value " << key << " deleted." << endl;
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* nextNode = NULL;

        while (current != NULL) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
        cout << "Linked list reversed successfully." << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n------ Linked List Menu ------" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Display" << endl;
        cout << "3. Search" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Reverse" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: " << endl;
                cin >> value;
                list.insert_at_beginning(value);
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Enter value to search: " << endl;
                cin >> value;
                list.search(value);
                break;
            case 4:
                cout << "Enter value to delete: " << endl;
                cin >> value;
                list.delete_node(value);
                break;
            case 5:
                list.reverse();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
```

Output:
![Dynamic Memory Allocation]()
![Dynamic Memory Allocation]()
![Dynamic Memory Allocation]()
![Dynamic Memory Allocation]()
![Dynamic Memory Allocation]()
