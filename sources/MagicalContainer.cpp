//
// Created by shora on 1/06/2023.
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

        // dtor
        MagicalContainer::AscendingIterator::~AscendingIterator() {

        }

        // placements
        MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
            // TODO: implement copying
            return *this;
        }

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept {
            // TODO: implement moving
            return *this;
        }

        // equality
        bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
            return container == other.container && currElement == other.currElement;
        }

        bool MagicalContainer::AscendingIterator::operator==(const SideCrossIterator &other) const {
            throw std::runtime_error("can't compare 2 iterators with different types"); return false;
        }

        bool MagicalContainer::AscendingIterator::operator==(const PrimeIterator &other) const {
            throw std::runtime_error("can't compare 2 iterators with different types"); return false;
        }

        // inequality
        bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
            return !(*this == other);
        }

        bool MagicalContainer::AscendingIterator::operator!=(const SideCrossIterator &other) const {
            throw std::runtime_error("can't compare 2 iterators with different types"); return false;
        }

        bool MagicalContainer::AscendingIterator::operator!=(const PrimeIterator &other) const {
            throw std::runtime_error("can't compare 2 iterators with different types"); return false;
        }

        // bigger than
        bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const {
            // TODO: implement
        }

        bool MagicalContainer::AscendingIterator::operator>(const SideCrossIterator &other) const {
            throw std::runtime_error("can't compare 2 iterators with different types"); return false;
        }

        bool MagicalContainer::AscendingIterator::operator>(const PrimeIterator &other) const {
            throw std::runtime_error("can't compare 2 iterators with different types"); return false;
        }

        // smaller than
        bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
            // TODO: implement
        }

        bool MagicalContainer::AscendingIterator::operator<(const SideCrossIterator &other) const {
            throw std::runtime_error("can't compare 2 iterators with different types"); return false;
        }

        bool MagicalContainer::AscendingIterator::operator<(const PrimeIterator &other) const {
            throw std::runtime_error("can't compare 2 iterators with different types"); return false;
        }

        // increment
        MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++() {
            if (currElement != nullptr) {
                currElement = currElement->next;
            }
            return *this;
        }

        // ptr operator
        int MagicalContainer::AscendingIterator::operator*() {
            if (currElement == nullptr) {
                throw std::out_of_range("Invalid access. Iterator is at the end");
            }
            return currElement->data;
        }
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
    return MagicalContainer::AscendingIterator(*(this->container));
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
// If getAscendingEnd() returns the last valid element,
// we need to return an iterator to one past the last element,
// which is typically represented as an iterator with a null pointer.
MagicalContainer::AscendingIterator iter(*(this->container));
iter.currElement = this->container->ascendingEnd;
return iter;
}



/****************************************************/
/*  SideCrossIterator class implementation           */
/****************************************************/

// SideCrossIterator ctors
MagicalContainer::SideCrossIterator::SideCrossIterator()
        : container(nullptr), currElement(nullptr) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container) :
: container(&container), currElement(container.ascendingHead) {}


// placements
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
    // TODO: implement copying
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept {
// TODO: implement moving
return *this;
}

// equality
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
    return container == other.container && currElement == other.currElement;
}

bool MagicalContainer::SideCrossIterator::operator==(const AscendingIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

bool MagicalContainer::SideCrossIterator::operator==(const PrimeIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

// inequality
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator!=(const AscendingIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

bool MagicalContainer::SideCrossIterator::operator!=(const PrimeIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

// bigger than
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
    // TODO: implement
}

bool MagicalContainer::SideCrossIterator::operator>(const AscendingIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const PrimeIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

// smaller than
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
    // TODO: implement
}

bool MagicalContainer::SideCrossIterator::operator<(const AscendingIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const PrimeIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

// increment
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++() {
    if (currElement != nullptr) {
        currElement = currElement->next;
    }
    return *this;
}

// ptr operator
int MagicalContainer::SideCrossIterator::operator*() {
    if (currElement == nullptr) {
        throw std::out_of_range("Invalid access. Iterator is at the end");
    }
    return currElement->data;
}