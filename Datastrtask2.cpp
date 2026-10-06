#include <iostream>
using namespace std;

struct Node {
    string coach;
    Node* next;
};

void addBeginning(Node*& head, string coach) {
    Node* newNode = new Node{coach, head};
    head = newNode;
}

void addEnd(Node*& head, string coach) {
    Node* newNode = new Node{coach, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void removeCoach(Node*& head, string coach) {
    if (head == NULL)
        return;

    if (head->coach == coach) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->coach != coach)
        temp = temp->next;

    if (temp->next != NULL) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->coach << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    addEnd(head, "Coach 1");
    addEnd(head, "Coach 2");
    addEnd(head, "Coach 3");
    addEnd(head, "Coach 4");

    cout << "Original train: ";
    display(head);

    addBeginning(head, "Coach 0");
    cout << "After adding at beginning: ";
    display(head);

    addEnd(head, "Coach 5");
    cout << "After adding at end: ";
    display(head);

    removeCoach(head, "Coach 3");
    cout << "After removing Coach 3: ";
    display(head);

    return 0;
}
