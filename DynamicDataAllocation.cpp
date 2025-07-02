/*
    Project Definition: Dynamic Memory Allocation

    Develop a simple CRUD Operation in a linked list with the help of C++ that will help you to
    Understand the system and memory to provide dynamic support.

    Project Criteria:
    Requirements:
        - Class & Object
        - Constructors
        - Methods

    Class Structure:
    1. Base Class: Dynamic Memory Allocation
        Attributes:
            - New node
            - Next node
            - Head
        Methods:
            - insert_at_beginning(data)
            - Search(key)
            - Delete_node(key)
            - reverse()
    
    Requirements:
    1. Basic Linked List Implementation.
    2. Insert at Beginning & Search Operation.
    3. Deletion of a Node.
    4. Reversing the Linked List.
*/

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class DynamicMemoryAllocation {
private:
    Node* head;

public:
    DynamicMemoryAllocation() {
        head = nullptr;
    }

    void insert_at_beginning(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        cout << "Inserted: " << data << endl;
    }

    void Search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Found " << key << " at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << key << " not found in the list." << endl;
    }

    void Delete_node(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << key << " not found, nothing to delete." << endl;
            return;
        }

        if (prev == nullptr) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Deleted: " << key << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        cout << "List reversed." << endl;
    }

    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DynamicMemoryAllocation obj;
    int choice, value;

    do {
        cout << "------ DYNAMIC CRUD MENU ------" << endl; 
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Reverse" << endl;
        cout << "5. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: " << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            obj.insert_at_beginning(value);
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            obj.Search(value);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            obj.Delete_node(value);
            break;
        case 4:
            obj.reverse();
            break;
        case 5:
            obj.display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
