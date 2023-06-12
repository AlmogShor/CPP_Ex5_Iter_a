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
          _size(0) {
    ascendingEnd = new Node<int>();
    descendingEnd = new Node<int>();
    primeEnd = new Node<int>();
    Node<int>::insertAtPosition(ascendingEnd, 0, &ascendingHead);
    Node<int>::insertAtPosition(descendingEnd, 0, &descendingHead);
    Node<int>::insertAtPosition(primeEnd, 0, &primeHead);
}


//copy ctor - in the hpp file

// move ctor - in the hpp file

// The destructor should delete all the nodes to prevent memory leaks
MagicalContainer::~MagicalContainer() {
    Node<int>* current = ascendingHead;
    while (current) {
        Node<int>* next = current->next;
        delete current;
        current = next;
    }
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
        Node<int>* newNode = new Node<int>(num);
        Node<int>::insertAtPosition(newNode, 0, &ascendingHead);
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
    if(this->container != other.container) throw std::runtime_error("can't assign between two different containers");
    this->container = other.container;
    this->currElement = other.currElement;
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept {
this->container = other.container;
this->currElement = other.currElement;
other.container = nullptr;
other.currElement = nullptr;
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
            if(other.currElement == nullptr && this->currElement == nullptr ) return false; //both are at end
            if(other.currElement == nullptr ) return false; // other at end
            if(this->currElement == nullptr) return true; // this at end
            return this->currElement->data > other.currElement->data;

        }

        bool MagicalContainer::AscendingIterator::operator>(const SideCrossIterator &other) const {
            throw std::runtime_error("can't compare 2 iterators with different types"); return false;
        }

        bool MagicalContainer::AscendingIterator::operator>(const PrimeIterator &other) const {
            throw std::runtime_error("can't compare 2 iterators with different types"); return false;
        }

        // smaller than
        bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
            return other > *this;
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


MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container)
: container(&container), currFrontElement(container.ascendingHead), currBackElement(container.descendingEnd), isFront(true) {}


// placements
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
    if(this->container != other.container) throw std::runtime_error("can't assign between two different containers");
    this->container = other.container;
    this->currFrontElement = other.currFrontElement;
    this->currBackElement = other.currBackElement;
    this->isFront = other.isFront;
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept {
this->container = other.container;
this->currFrontElement = other.currFrontElement;
this->currBackElement = other.currBackElement;
this->isFront = other.isFront;
other.container = nullptr;
other.currFrontElement = nullptr;
other.currBackElement = nullptr;
return *this;
}

// dtor
MagicalContainer::SideCrossIterator::~SideCrossIterator() {

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
    if ((other.currBackElement == nullptr || other.currFrontElement == nullptr) &&
        (this->currBackElement == nullptr || this->currFrontElement == nullptr))
        return false; // both this and other at end
    if (other.currBackElement == nullptr || other.currFrontElement == nullptr) return false; // other at end
    if (this->currBackElement == nullptr || this->currFrontElement == nullptr) return true; // this at end
    if (this->isFront && other.isFront) { // both at front
        if (this->currFrontElement->index == 0)
            return other.currFrontElement->index == 0 ? false : true; // special case where this at index 0
        return this->currFrontElement->index > other.currFrontElement->index; // compute by index
    } else if (this->isFront &&
               (!other.isFront)) { // this at front (went through odd num of elments) other at back (went through even num of elments)
        if (this->currFrontElement->index == 0)
            return other.currBackElement->index == 0 ? false : true; // special case where this at index 0
        return ((2 * this->currFrontElement->index) + 1) > (2 * other.currBackElement->index); // compute by index
    } else if ((!this->isFront) &&
               other.isFront) { // this at end (went through even num of elments) other at front (went through odd num of elments)
        if (this->currBackElement->index == 0)
            return other.currFrontElement->index == 0 ? true : false; // special case where this at index 0
        return (2 * this->currBackElement->index) > ((2 * other.currFrontElement->index) + 1); // compute by index
    } else { // both at end
        if (this->currBackElement->index == 0)
            return other.currBackElement->index == 0 ? false : true; // special case where this at index 0
        return this->currBackElement->index > other.currBackElement->index; // compute by index
    }
}

bool MagicalContainer::SideCrossIterator::operator>(const AscendingIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const PrimeIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

// smaller than
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {

    return other > *this;
}

bool MagicalContainer::SideCrossIterator::operator<(const AscendingIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const PrimeIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

// increment
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    if (currBackElement->isValid() == true || currFrontElement->isValid() == true)
        throw std::runtime_error("out of range");

    if (currBackElement->getIndex() + currFrontElement->getIndex() >= container->_size - 1) {
        currBackElement = container->descendingEnd;
        currFrontElement = container->ascendingHead;
        return *this;
    }

    if (isFront) {
        currFrontElement = currFrontElement->getNext();
        isFront = false;
    } else {
        currBackElement = currBackElement->getNext();
        isFront = true;
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
    MagicalContainer::SideCrossIterator iter(*(this->container));
    iter.currFrontElement = this->container->ascendingEnd;
    iter.currBackElement = this->container->descendingEnd;
    return iter;
}

/****************************************************/
/*  PrimeIterator class implementation               */
/****************************************************/

//ctors
//ctors
MagicalContainer::PrimeIterator::PrimeIterator() {

}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container): container(&container), currElement(container.primeHead) {

}



MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) {

}

MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &&other) noexcept {

} // move ctor
// dtor
MagicalContainer::PrimeIterator::~PrimeIterator(){

}

// operators
//placements
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
    if(this->container != other.container) throw std::runtime_error("can't assign between two different containers");
    this->container = other.container;
    this->currElement = other.currElement;
    return *this;
}


MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept {
this->container = other.container;
this->currElement = other.currElement;
other.container = nullptr;
other.currElement = nullptr;
return *this;
} // move assignment

/// equality
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
    return container == other.container && currElement == other.currElement;
}

bool MagicalContainer::PrimeIterator::operator==(const AscendingIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

bool MagicalContainer::PrimeIterator::operator==(const SideCrossIterator &other) const {
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
    if(other.currElement->isValid() == true && this->currElement->isValid() == true ) return false; //this and other are at end
    if(other.currElement->isValid() == true ) return false; //other at end
    if(this->currElement->isValid()) return true; //this at end
    return *(this->currElement->getDataPoint()) > *(other.currElement->getDataPoint());
}

bool MagicalContainer::PrimeIterator::operator>(const AscendingIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

bool MagicalContainer::PrimeIterator::operator>(const SideCrossIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

// smaller than
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
    return other > *this;
}

bool MagicalContainer::PrimeIterator::operator<(const AscendingIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

bool MagicalContainer::PrimeIterator::operator<(const SideCrossIterator &other) const {
    throw std::runtime_error("can't compare 2 iterators with different types"); return false;
}

// increment
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    if (currElement->isValid()) {
        throw std::runtime_error("out of range");
    }
    currElement = currElement->next;
    return *this;
}

// ptr operator
int MagicalContainer::PrimeIterator::operator*() {
    if (currElement->isValid()) {
        throw std::out_of_range("Invalid access. Iterator is at the end");
    }
    return *(currElement->getDataPoint());
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
    return MagicalContainer::PrimeIterator(*(this->container));
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
    MagicalContainer::PrimeIterator iter(*(this->container));
    iter.currElement = this->container->primeEnd;
    return iter;
}