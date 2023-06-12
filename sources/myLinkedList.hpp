//
// Created by shora on 11/06/2023.
//
#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class Node {
public:
    Node<T> *next;
    T data;
    int index = -1; // added index
    bool valid = false; // for the iterator end() method to know if it's the end of the list

    Node() : next(nullptr) {}

    Node(T data) : next(nullptr), data(data) {}

    Node(T data, int idx) : next(nullptr), data(data), index(idx) {}

    void setNext(Node<T> *nextNode) { next = nextNode; }

    void setFinal(bool isFinal) { valid = isFinal; }

    void setIndex(int idx) { index = idx; } // added setIndex method

    bool operator>(const Node<T> &other) const { return index > other.index; }

    bool operator<(const Node<T> &other) const { return index < other.index; }

    bool operator==(const Node<T> &other) const { return index == other.index; }

    bool operator!=(const Node<T> &other) const { return index != other.index; }

    T *getDataPoint() { return &data; }

    Node<T> *getNext() { return next; }
    bool isValid() { return valid; }
    int getIndex() { return index; } // added getIndex method

    //methods insert and remove
    static void insertAtPosition(Node<T>* toAdd, int position, Node<T>** head);
    static int findPosition(Node<T>* head, T newdata);
    static void incrementFromPos(Node<T>* head, int position);
    static void decreaseFromPos(Node<T>* head, int position);
    static void removeAtPosition(int position, Node<T>** head);
};

template <typename T>
void Node<T>::insertAtPosition(Node<T>* toAdd, int position, Node<T>** head) {
    if (position < 0) {
        // Invalid position
        throw std::invalid_argument("Position out of range");
    }

    if (*head == nullptr || position == 0) {
        // Empty list or insert at the beginning
        toAdd->next = *head;
        *head = toAdd;
        toAdd->index = 0;
        Node<T>::incrementFromPos(*head, 1);
        return;
    }

    Node<T>* currentNode = *head;
    int currentIndex = 0;

    while (currentNode->next && currentIndex < position - 1) {
        currentNode = currentNode->next;
        currentIndex++;
    }

    toAdd->next = currentNode->next;
    currentNode->next = toAdd;
    toAdd->index = currentIndex + 1;
    Node<T>::incrementFromPos(toAdd->next, toAdd->index + 1);
}

template <typename T>
int Node<T>::findPosition(Node<T>* head, T newdata){
    if (head == nullptr) {
        return 0;
    }

    Node<T>* currentNode = head;
    int position = 0;

    while (currentNode && currentNode->data < newdata) {
        currentNode = currentNode->next;
        position++;
    }

    return position;
}

template <typename T>
void Node<T>::incrementFromPos(Node<T>* head, int position) {
    Node<T>* currentNode = head;
    int idx = 0;
    while (currentNode) {
        if (idx >= position) {
            currentNode->index++;
        }
        currentNode = currentNode->next;
        idx++;
    }
}

template <typename T>
void Node<T>::decreaseFromPos(Node<T>* head, int position) {
    Node<T>* currentNode = head;
    int idx = 0;
    while (currentNode) {
        if (idx >= position) {
            currentNode->index--;
        }
        currentNode = currentNode->next;
        idx++;
    }
}

template <typename T>
void Node<T>::removeAtPosition(int position, Node<T>** head) {
    if (position < 0) {
        // Invalid position
        throw std::invalid_argument("Position out of range");
    }

    if (*head == nullptr) {
        // Empty list
        throw std::invalid_argument("List is empty");
    }

    Node<T>* temp = *head;

    if (position == 0) {
        // Remove the head node
        *head = temp->next;
        delete temp;
        Node<T>::decreaseFromPos(*head, 0);
        return;
    }

    for (int i = 0; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        throw std::invalid_argument("Position out of range");
    }

    Node<T>* next = temp->next->next;

    delete temp->next;

    temp->next = next;
    Node<T>::decreaseFromPos(temp->next, position);
}


// Implementetion of  the methods here



template<typename T>
class LinkedList {
public:
    Node<T> *head;

    LinkedList() : head(nullptr) {}

    //methods

    void insertAtPosition(T data, int position) {
        Node<T>* toAdd = new Node<T>(data, position);

        if (position == 0) {
            toAdd->next = head;
            head = toAdd;
            return;
        }

        Node<T>* prev = head;
        for (int i = 0; prev != nullptr && i < position - 1; i++) {
            prev = prev->next;
        }

        if (prev == nullptr) {
            throw std::invalid_argument("Position out of range");
        }

        toAdd->next = prev->next;
        prev->next = toAdd;
    }

    void removeAtPosition(int position) {
        Node<T>* temp = head;

        if (position == 0) {
            head = temp->next;
            delete temp;
            return;
        }

        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            throw std::invalid_argument("Position out of range");
        }

        Node<T>* next = temp->next->next;

        delete temp->next;

        temp->next = next;
    }
};
