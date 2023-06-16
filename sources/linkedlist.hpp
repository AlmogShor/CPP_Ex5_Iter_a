//
// Created by shora on 16/06/2023.
//

#pragma once

#include <cmath>
#include <iostream>
#include <iterator>

struct Node {
    int data;
    Node *next;
    Node *back;

    Node(int value) : data(value), next(nullptr), back(nullptr) {}

    bool operator==(const Node &other) const {
        return other.data == data && other.next == next && other.back == back;
    }
};

class linkedList {
private:
    Node *head;
    Node *tail;
    size_t size = 0;

public:
    linkedList();

    ~linkedList();

    // Copy constructor
    linkedList(const linkedList &other) = default;

    // Copy assignment operator
    linkedList &operator=(const linkedList &other) = default;

    // Move constructor
    linkedList(linkedList &&other) = default;

    // Move assignment operator
    linkedList &operator=(linkedList &&other) = default;

    void insert(int value);

    void removeElement(int element);

    size_t getSize() const;

    Node *getLast();

    Node *getHead();

    Node *At(size_t index);

    void display();
}
