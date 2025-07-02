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
        next = NULL;
    }
};

class DynamicMemoryAllocation {
private:
    Node* head;

public:
    DynamicMemoryAllocation() {
        head = NULL;
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
        while (temp != NULL) {
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
        Node* prev = NULL;

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << key << " not found, nothing to delete." << endl;
            return;
        }

        if (prev == NULL) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Deleted: " << key << endl;
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
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
        while (temp != NULL) {
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
        Case1:
            cout << "Enter value to insert: ";
            cin >> value;
            obj.insert_at_beginning(value);
            break;
        Case2:
            cout << "Enter value to search: ";
            cin >> value;
            obj.Search(value);
            break;
        Case3:
            cout << "Enter value to delete: ";
            cin >> value;
            obj.Delete_node(value);
            break;
        Case4:
            obj.reverse();
            break;
        Case5:
            obj.display();
            break;
        Case0:
            cout << "Exiting..." << endl;
            break;
        Default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
