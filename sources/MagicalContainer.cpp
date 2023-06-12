//
// created by Almog Shor
//

#include <stdexcept>
#include <iostream>
#include "MagicalContainer.hpp"
#include "myLinkedList.hpp"

using namespace std;
using namespace ariel;

/****************************************************/
/*  MagicalContainer class implementation           */
/****************************************************/

// MagicalContainers ctors
MagicalContainer::MagicalContainer()
        : ascendingHead(nullptr), ascendingEnd(nullptr),
          descendingHead(nullptr), descendingEnd(nullptr),
          primeHead(nullptr), primeEnd(nullptr),
          _size(0) {}

MagicalContainer::MagicalContainer(const MagicalContainer &other)
        : _size(other._size) {
    // TODO: Copy the linked lists. This will likely involve creating new nodes
    // and setting their next pointers to create a copy of the original list.
}

MagicalContainer::MagicalContainer(MagicalContainer &&other) noexcept
: ascendingHead(other.ascendingHead),
ascendingEnd(other.ascendingEnd),
descendingHead(other.descendingHead),
descendingEnd(other.descendingEnd),
primeHead(other.primeHead),
primeEnd(other.primeEnd),
_size(other._size) {
// Reset other's pointers to ensure it doesn't delete the nodes when it's destructed
other.ascendingHead = other.ascendingEnd = nullptr;
other.descendingHead = other.descendingEnd = nullptr;
other.primeHead = other.primeEnd = nullptr;
other._size = 0;
}

// The destructor should delete all the nodes to prevent memory leaks
MagicalContainer::~MagicalContainer() {
    // TODO: Delete all nodes
}

// MagicalContainer methods
bool MagicalContainer::isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;

    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i = i + 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int MagicalContainer::exists(int num) {
    Node<int> *current = ascendingHead;
    int index = 0;
    while (current) {
        if (current->data == num) return index;
        current = current->next;
        index++;
    }
    return -1;
}

void MagicalContainer::addElement(int num) {
    if (exists(num) == -1) {
        Node<int>::insertAtPosition(new Node<int>(num), 0, &ascendingHead);
        _size++;
    }
}

void MagicalContainer::removeElement(int num) {
    int index = exists(num);
    if (index != -1) {
        Node<int>::removeAtPosition(index, &ascendingHead);
        _size--;
    }
}

int MagicalContainer::size() {
    return _size;
}


/****************************************************/
/*  AscendingIterator class implementation           */
/****************************************************/

// AscendingIterator ctors
MagicalContainer::AscendingIterator::AscendingIterator()
        : container(nullptr), currElement(nullptr) {}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container)
        : container(&container), currElement(container.ascendingHead) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
        : container(other.container), currElement(other.currElement) {}

MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &&other) noexcept
: container(other.container),
currElement(other.currElement) {
other.container = nullptr;
other.currElement = nullptr;
}




/****************************************************/
/*  SideCrossIterator class implementation           */
/****************************************************/

// SideCrossIterator ctors
MagicalContainer::SideCrossIterator::SideCrossIterator()
        : container(nullptr), currElement(nullptr) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container) :
: container(&container), currElement(container.ascendingHead) {}

