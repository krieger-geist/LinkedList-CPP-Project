#include <iostream>
#include <limits>
using namespace std;

// Utility for printing a star line
void printStarLine(int length) {
    cout << string(length, '*') << '\n';
}

// Utility for clearing input buffer after bad input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Safe integer input with prompt
int inputInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cout << "Invalid input. Please enter an integer.\n";
            clearInput();
        } else {
            clearInput();
            return value;
        }
    }
}

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
        while (temp && count < pos - 1) {
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
        while (temp->next && temp->next->next) temp = temp->next;
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
        while (temp->next && count < pos - 1) {
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
        while (temp && count < pos - 1) {
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

// Menu for singly linked list
void singlyLinkedListMenu() {
    SinglyLinkedList sList;
    int choice;
    do {
        printStarLine(40);
        cout << "*       Singly Linked List Menu       *\n";
        printStarLine(40);
        cout
            << "1. Insert at Beginning\n"
            << "2. Insert at End\n"
            << "3. Insert at Position\n"
            << "4. Delete at Beginning\n"
            << "5. Delete at End\n"
            << "6. Delete at Position\n"
            << "7. Traverse\n"
            << "8. Exit\n"
            << "Choose an option: ";
        cin >> choice; clearInput();
        cout << "\n";
        int val, pos;
        switch (choice) {
            case 1:
                val = inputInt("Enter value to insert: ");
                sList.insertAtBeginning(val);
                break;
            case 2:
                val = inputInt("Enter value to insert: ");
                sList.insertAtEnd(val);
                break;
            case 3:
                val = inputInt("Enter value to insert: ");
                pos = inputInt("Enter position: ");
                sList.insertAtPosition(val, pos);
                break;
            case 4:
                sList.deleteAtBeginning();
                break;
            case 5:
                sList.deleteAtEnd();
                break;
            case 6:
                pos = inputInt("Enter position to delete: ");
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

// Menu for doubly linked list
void doublyLinkedListMenu() {
    DoublyLinkedList dList;
    int choice;
    do {
        printStarLine(42);
        cout << "*       Doubly Linked List Menu        *\n";
        printStarLine(42);
        cout
            << "1. Insert at Beginning\n"
            << "2. Insert at End\n"
            << "3. Insert at Position\n"
            << "4. Delete at Beginning\n"
            << "5. Delete at End\n"
            << "6. Delete at Position\n"
            << "7. Traverse\n"
            << "8. Exit\n"
            << "Choose an option: ";
        cin >> choice; clearInput();
        cout << "\n";
        int val, pos;
        switch (choice) {
            case 1:
                val = inputInt("Enter value to insert: ");
                dList.insertAtBeginning(val);
                break;
            case 2:
                val = inputInt("Enter value to insert: ");
                dList.insertAtEnd(val);
                break;
            case 3:
                val = inputInt("Enter value to insert: ");
                pos = inputInt("Enter position: ");
                dList.insertAtPosition(val, pos);
                break;
            case 4:
                dList.deleteAtBeginning();
                break;
            case 5:
                dList.deleteAtEnd();
                break;
            case 6:
                pos = inputInt("Enter position to delete: ");
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

// Main menu
int main() {
    int choice;
    do {
        printStarLine(35);
        cout << "*    Linked List Project Menu    *\n";
        printStarLine(35);
        cout
            << "1. Singly Linked List Operations\n"
            << "2. Doubly Linked List Operations\n"
            << "3. Exit\n"
            << "Choose an option: ";
        cin >> choice; clearInput();
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
