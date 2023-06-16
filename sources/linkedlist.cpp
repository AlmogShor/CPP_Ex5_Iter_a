//
// Created by shora on 16/06/2023.
//

#include "linkedlist.hpp"

linkedList::linkedList() : head(nullptr), tail(nullptr) {}


linkedList::~linkedList(){
    Node *curr = head;
    while (curr != nullptr) {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }
}
void linkedList::insert(int value){
    Node *newNode = new Node(value);
    if (head == nullptr) { // empty list
        head = newNode;
        tail = newNode;
    }
    else if (value < head->data) { // insert at head
        newNode->next = head;
        head->back = newNode;
        head = newNode;
    }
    else if (value > tail->data) { // insert at tail
        newNode->back = tail;
        tail->next = newNode;
        tail = newNode;
    }
    else { // middle
        Node *current = head;
        while (value >= current->next->data) { // find location
            current = current->next;
        }

        newNode->next = current->next;
        current->next->back = newNode;
        current->next = newNode;
        newNode->back = current;
    }
    this->size++;
}

void linkedList::remove(int elem){
    if (head == nullptr) {
        return;
    }

    if (head->data == elem) {

        Node *temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        size--;
        return;
    }

    Node *curr = head;
    while (curr->next != nullptr) {
        if (curr->next->data == elem) {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            if (curr->next == nullptr) {
                tail = curr;
            }
            else {
                curr->next->back = curr;
            }
            delete temp;
            size--;
            return;
        }
        curr = curr->next;
    }
}

size_t linkedList::getSize(){
    return this->size;
}

Node *linkedList::getLast(){
    return this->tail;
}

Node *linkedList::getHead(){
    return this->head;
}

Node *linkedList::at(size_t index){
    if (index >= size) {
        return nullptr;
    }
    Node *curr = head;
    for (size_t i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr;
}

void linkedList::display(){
    Node *curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}
