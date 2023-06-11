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

    //methods
    template <typename T>
    void Node<T>::insertAtPosition(Node<T>* toAdd, int position, Node<T>** head) {
        // Special case for the head end
        if (position == 0) {
            toAdd->next = *head;
            *head = toAdd;
            return;
        }

        // Locate the node before the point of insertion
        Node<T>* prev = *head;
        for (int i = 0; prev != nullptr && i < position - 1; i++) {
            prev = prev->next;
        }

        // Check if the given position is greater than the number of nodes
        if (prev == nullptr || prev->next == nullptr) {
            throw std::invalid_argument("Position out of range");
        }

        // Insert node after the previous node
        toAdd->next = prev->next;
        prev->next = toAdd;
    }

    template <typename T>
    void Node<T>::removeAtPosition(int position, Node<T>** head) {
        Node<T>* temp = *head;

        // If head node itself is to be deleted
        if (position == 0) {
            *head = temp->next;
            delete temp;
            return;
        }

        // Find previous node of the node to be deleted
        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

        // If position is more than number of nodes
        if (temp == nullptr || temp->next == nullptr) {
            throw std::invalid_argument("Position out of range");
        }

        // Node temp->next is the node to be deleted, store pointer to the next of node to be deleted
        Node<T>* next = temp->next->next;

        // Delete node at position (skip from list)
        delete temp->next;

        // Unlink the deleted node from list
        temp->next = next;
    }


};

