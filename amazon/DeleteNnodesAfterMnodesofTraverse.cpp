#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
Node* linkdelete(Node* head, int m, int n) {
    Node* start = head;  // Pointer to traverse the list

    while (start) {
        // Skip `m` nodes
        int m1 = m;  // Copy of m
        while (m1 > 1 && start) {  // Skip only if there are nodes to traverse
            start = start->next;
            m1--;
        }

        // If we've reached the end, break
        if (!start || !start->next) break;

        // Start deleting `n` nodes
        int n1 = n;  // Copy of n
        Node* temp = start->next;
        while (n1 > 0 && temp) {  // Delete only if there are nodes to delete
            Node* nextNode = temp->next;
            delete temp;  // Free memory
            temp = nextNode;
            n1--;
        }

        // Link the remaining list
        start->next = temp;
        start = temp;  // Move the start pointer for the next iteration
    }

    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);

    int m = 2, n = 3;
    Node* result = linkdelete(head, m, n);

    while (result) {
        cout << result->data << " ";
        result = result->next;
    }

    return 0;
}