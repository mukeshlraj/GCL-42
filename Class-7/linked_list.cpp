#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// insert at beginning
// TC - O(1)
Node *insert_at_beginning(Node *head, int new_data) {
    Node *new_node = new Node(new_data);
    new_node->next = head;
    head = new_node;

    return head;
}

// TC - O(n)
Node *insert_at_end(Node *head, int new_data) {

    if (head == NULL) {
        return insert_at_beginning(head, new_data);
    }

    Node *new_node = new Node(new_data);
    Node *temp = head;

    while (temp->next !=  NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    return head;
}

// TC : O(min(n, pos))
Node *insert_at_position(Node *head, int new_data, int pos) {

    // if pos >= (len+1) - insert at the end

    if (pos < 1) {
        return head;
    }

    if (pos == 1 or head == NULL) {
        return insert_at_beginning(head, new_data);
    }

    Node *new_node = new Node(new_data);
    Node *temp = head;

    pos = pos-2;
    while(pos > 0 and temp->next != NULL) {
        temp = temp->next;
        pos--;
    }

    new_node->next = temp->next;
    temp->next = new_node;

    return head;
}

// TC - O(1)
Node *delete_from_beginning(Node *head) {

    if (head == NULL) {
        return head;
    }

    Node *temp = head;
    head = head->next;
    delete(temp);

    return head;
}

// TC - O(n)
Node *delete_from_end(Node *head) {

    if (head==NULL or head->next == NULL) {
        return delete_from_beginning(head);
    }

    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    Node *temp2 = temp->next;
    temp->next = NULL;
    delete(temp2);

    return head;
}

// TC - O(min(n, pos))
Node *delete_from_pos(Node *head, int pos) {

    if (pos < 1 or head == NULL) {
        return head;
    }

    if (head->next == NULL) {
        if (pos == 1) {
            delete(head);
            return NULL;
        } else {
            return head;
        }
    }

    Node *temp = head;
    pos = pos-2;
    while(pos > 0 and temp->next != NULL) {
        temp = temp->next;
        pos--;
    }

    if (temp->next == NULL) {
        return head;
    }

    Node *temp2 = temp->next;
    temp->next = temp2->next;
    delete(temp2);

    return head;
}