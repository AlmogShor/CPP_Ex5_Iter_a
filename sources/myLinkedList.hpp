//
// Created by shora on 11/06/2023.
//

#pragma once

#include <iostream>

template<typename T>
class Node {
public:
    Node<T> *next;
    T data;

    Node() : next(nullptr) {}

    Node(T data) : next(nullptr), data(data) {}

    void setNext(Node<T> *nextNode) { next = nextNode; }

    bool operator>(const Node<T> &other) const { return data > other.data; }

    bool operator<(const Node<T> &other) const { return data < other.data; }

    bool operator==(const Node<T> &other) const { return data == other.data; }

    bool operator!=(const Node<T> &other) const { return data != other.data; }

    static void insertAtPosition(Node<T> *toAdd, int position, Node<T> **head) {
        if (position == 0) {
            toAdd->next = *head;
            *head = toAdd;
        } else {
            Node<T> *current = *head;
            for (int i = 0; i < position - 1 && current != nullptr; i++)
                current = current->next;

            if (current != nullptr) {
                toAdd->next = current->next;
                current->next = toAdd;
            }
        }
    }

    static void removeAtPosition(int position, Node<T> **head) {
        if (position == 0 && *head != nullptr) {
            Node<T> *toDelete = *head;
            *head = (*head)->next;
            delete toDelete;
        } else {
            Node<T> *current = *head;
            for (int i = 0; i < position - 1 && current != nullptr; i++)
                current = current->next;

            if (current != nullptr && current->next != nullptr) {
                Node<T> *toDelete = current->next;
                current->next = current->next->next;
                delete toDelete;
            }
        }
    }

    T *getDataPoint() { return &data; }

    Node<T> *getNext() { return next; }
};

template<typename T>
class LinkedList {
public:
    Node<T> *head;

    LinkedList() : head(nullptr) {}

    // More LinkedList functionality goes here
    // Including implementation of various types of iterators
};

