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

    Node(T data, int idx) : next(nullptr), data(data), index(idx) {}

    void setNext(Node<T> *nextNode) { next = nextNode; }

    void setValid(bool isValid) { valid = isValid; }

    void setIndex(int idx) { index = idx; } // added setIndex method

    bool operator>(const Node<T> &other) const { return index > other.index; }

    bool operator<(const Node<T> &other) const { return index < other.index; }

    bool operator==(const Node<T> &other) const { return index == other.index; }

    bool operator!=(const Node<T> &other) const { return index != other.index; }

    T *getDataPoint() { return &data; }

    Node<T> *getNext() { return next; }
    bool isValid() { return valid; }
    int getIndex() { return index; } // added getIndex method
};

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
