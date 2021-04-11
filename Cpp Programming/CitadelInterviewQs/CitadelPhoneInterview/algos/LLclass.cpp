#include <iostream>


using namespace std;

class List{
private:
    typedef struct node {
        int data;
        node* next;
    }* nodePtr;
    nodePtr head;
    nodePtr curr;
    nodePtr temp;
    // typedef struct node* nodePtr;
public:
    List();
    void AddNode(int addData);
    void DeleteNode(int delData);
    void PrintList();
};
// constructor
List::List() {
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void List::AddNode(int addData) {
    
    nodePtr n = new node;
    n->next = NULL;
    n->data = addData;

    if (head == NULL) {
        head = n;
    } else {
        curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = n;
    }
}

void List::DeleteNode(int delData) {
    nodePtr delPtr = NULL;
    curr = head;
    temp = head;
    while (curr != NULL && curr->data != delData) {
        temp = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << delData << " was not in the list.\n";
    } else {
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        if (head == delPtr) head = curr;
        cout << "The value " << delData << " was deleted.\n";
    }
    delete delPtr;

}

void List::PrintList() {
    curr = head;
    cout << "Linked List:" << endl;
    while (curr != NULL) {
        if (curr->next == NULL) {
            cout << curr->data << endl;
        }else {
            cout << curr->data << " -> ";
        }
        curr = curr->next;
        
    }
}

int main (int argc, char** argv) {
    List linkedlist;
    linkedlist.AddNode(3);
    linkedlist.AddNode(2);
    linkedlist.AddNode(3);
    linkedlist.AddNode(5);
    linkedlist.AddNode(7);
    linkedlist.PrintList();
    linkedlist.DeleteNode(5);
    linkedlist.PrintList();
    linkedlist.DeleteNode(3);
    linkedlist.PrintList();
    linkedlist.DeleteNode(7);
    linkedlist.PrintList();
    
    return 0;
}