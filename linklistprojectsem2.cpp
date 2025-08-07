#include <iostream>
using namespace std;

// Singly Linked List Node
struct SNode {
    int data;
    SNode* next;
    SNode(int val) : data(val), next(nullptr) {}
};

// Singly Linked List class
class SinglyLinkedList {
private:
    SNode* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        SNode* newNode = new SNode(val);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at the beginning.\n";
    }

    void insertAtEnd(int val) {
        SNode* newNode = new SNode(val);
        if (!head) {
            head = newNode;
        } else {
            SNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted " << val << " at the end.\n";
    }

    void insertAtPosition(int val, int pos) {
        if (pos <= 0) {
            cout << "Position should be >= 1.\n";
            return;
        }
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }
        SNode* newNode = new SNode(val);
        SNode* temp = head;
        int count = 1;
        while (temp && count < pos-1) {
            temp = temp->next;
            count++;
        }
        if (!temp) {
            cout << "Position out of range.\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << val << " at position " << pos << ".\n";
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        SNode* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (!head->next) {
            cout << "Deleted " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        SNode* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        cout << "Deleted " << temp->next->data << " from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int pos) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (pos <= 0) {
            cout << "Position should be >= 1.\n";
            return;
        }
        if (pos == 1) {
            deleteAtBeginning();
            return;
        }
        SNode* temp = head;
        int count = 1;
        while (temp->next && count < pos-1) {
            temp = temp->next;
            count++;
        }
        if (!temp->next) {
            cout << "Position out of range.\n";
            return;
        }
        SNode* delNode = temp->next;
        temp->next = delNode->next;
        cout << "Deleted " << delNode->data << " from position " << pos << ".\n";
        delete delNode;
    }

    void traverse() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Singly Linked List: ";
        SNode* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }

    ~SinglyLinkedList() {
        // Clean up nodes
        while (head) {
            SNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Doubly Linked List Node
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << val << " at the beginning.\n";
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
        } else {
            DNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted " << val << " at the end.\n";
    }

    void insertAtPosition(int val, int pos) {
        if (pos <= 0) {
            cout << "Position should be >= 1.\n";
            return;
        }
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }
        DNode* newNode = new DNode(val);
        DNode* temp = head;
        int count = 1;
        while (temp && count < pos-1) {
            temp = temp->next;
            count++;
        }
        if (!temp) {
            cout << "Position out of range.\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Inserted " << val << " at position " << pos << ".\n";
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        DNode* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        cout << "Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (!head->next) {
            cout << "Deleted " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        cout << "Deleted " << temp->data << " from end.\n";
        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteAtPosition(int pos) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (pos <= 0) {
            cout << "Position should be >= 1.\n";
            return;
        }
        if (pos == 1) {
            deleteAtBeginning();
            return;
        }
        DNode* temp = head;
        int count = 1;
        while (temp && count < pos) {
            temp = temp->next;
            count++;
        }
        if (!temp) {
            cout << "Position out of range.\n";
            return;
        }
        cout << "Deleted " << temp->data << " from position " << pos << ".\n";
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

    void traverse() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Doubly Linked List: ";
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }

    ~DoublyLinkedList() {
        while (head) {
            DNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Function to print a decorative star line
void printStarLine(int length) {
    for (int i = 0; i < length; i++)
        cout << "*";
    cout << "\n";
}

// Main menu and interaction
void singlyLinkedListMenu() {
    SinglyLinkedList sList;
    int choice, val, pos;
    do {
        printStarLine(40);
        cout << "*       Singly Linked List Menu       *\n";
        printStarLine(40);
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n";
        cout << "4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n";
        cout << "7. Traverse\n8. Exit\nChoose an option: ";
        cin >> choice;
        cout << "\n";
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                sList.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                sList.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter position: ";
                cin >> pos;
                sList.insertAtPosition(val, pos);
                break;
            case 4:
                sList.deleteAtBeginning();
                break;
            case 5:
                sList.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                sList.deleteAtPosition(pos);
                break;
            case 7:
                sList.traverse();
                break;
            case 8:
                cout << "Exiting Singly Linked List Menu.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);
    cout << "\n";
}

void doublyLinkedListMenu() {
    DoublyLinkedList dList;
    int choice, val, pos;
    do {
        printStarLine(42);
        cout << "*       Doubly Linked List Menu        *\n";
        printStarLine(42);
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n";
        cout << "4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n";
        cout << "7. Traverse\n8. Exit\nChoose an option: ";
        cin >> choice;
        cout << "\n";
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                dList.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                dList.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter position: ";
                cin >> pos;
                dList.insertAtPosition(val, pos);
                break;
            case 4:
                dList.deleteAtBeginning();
                break;
            case 5:
                dList.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                dList.deleteAtPosition(pos);
                break;
            case 7:
                dList.traverse();
                break;
            case 8:
                cout << "Exiting Doubly Linked List Menu.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);
    cout << "\n";
}

int main() {
    int choice;
    do {
        printStarLine(30);
        cout << "*    Linked List Project Menu    *\n";
        printStarLine(30);
        cout << "1. Singly Linked List Operations\n2. Doubly Linked List Operations\n3. Exit\nChoose an option: ";
        cin >> choice;
        cout << "\n";
        switch (choice) {
            case 1:
                singlyLinkedListMenu();
                break;
            case 2:
                doublyLinkedListMenu();
                break;
            case 3:
                cout << "Exiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}

