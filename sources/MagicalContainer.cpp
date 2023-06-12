//
// Created by shora on 1/06/2023.
//
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

//copy ctor - in the hpp file

// move ctor - in the hpp file

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
        // Node<int>::insertAtPosition(new Node<int>(num), 0, &ascendingHead);
        // TODO: You need to implement the insertAtPosition function in your Node class
        // and then use it here.
        _size++;
    }
}

void MagicalContainer::removeElement(int num) {
    int index = exists(num);
    if (index != -1) {
        // Node<int>::removeAtPosition(index, &ascendingHead);
        // TODO: You need to implement the removeAtPosition function in your Node class
        // and then use it here.
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
            return false;
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
            return false;
        }

        bool MagicalContainer::AscendingIterator::operator<(const SideCrossIterator &other) const {
            throw std::runtime_error("can't compare 2 iterators with different types"); return false;
        }

        bool MagicalContainer::AscendingIterator::operator<(const PrimeIterator &other) const {
            throw std::runtime_error("can't compare 2 iterators with different types"); return false;
        }

        // increment
        MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
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
        : container(nullptr), currFrontElement(nullptr), currBackElement(nullptr), isFront(false) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container) :
: container(&container), currFrontElement(container.ascendingHead), currBackElement(container.descendingEnd), isFront(true) {}


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
    return container == other.container && currFrontElement == other.currFrontElement &&
           currBackElement == other.currBackElement && isFront == other.isFront;
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
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    if (currElement != nullptr) {
        currElement = currElement->next;
    }
    return *this;
}

// ptr operator
int MagicalContainer::SideCrossIterator::operator*() {
    if (this->currFrontElement == nullptr) {
        throw std::out_of_range("Invalid access. Iterator is at the end");
    }
    return this->currFrontElement->data;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
    return MagicalContainer::SideCrossIterator(*(this->container));
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
    return NULL;
}

/****************************************************/
/*  PrimeIterator class implementation               */
/****************************************************/

//ctors
PrimeIterator();

PrimeIterator(const MagicalContainer &container);

PrimeIterator(const PrimeIterator &other);

PrimeIterator(PrimeIterator &&other)

noexcept; // move ctor
// dtor
MagicalContainer::PrimeIterator::~PrimeIterator(){

}

// operators
//placements
PrimeIterator &operator=(const PrimeIterator &other);

PrimeIterator &operator=(PrimeIterator &&other)

noexcept; // move assignment
/// equality
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
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator!=(const AscendingIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const SideCrossIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

// bigger than
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
    // TODO: implement
}

bool MagicalContainer::PrimeIterator::operator>(const AscendingIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

bool MagicalContainer::PrimeIterator::operator>(const SideCrossIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

// smaller than
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
    // TODO: implement
}

bool MagicalContainer::PrimeIterator::operator<(const AscendingIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

bool MagicalContainer::PrimeIterator::operator<(const SideCrossIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

// increment
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++() {
    if (currElement != nullptr) {
        currElement = currElement->next;
    }
    return *this;
}

// ptr operator
int MagicalContainer::PrimeIterator::operator*() {
    if (currElement == nullptr) {
        throw std::out_of_range("Invalid access. Iterator is at the end");
    }
    return currElement->data;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
    return MagicalContainer::PrimeIterator(*(this->container));
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
    return NULL;
}