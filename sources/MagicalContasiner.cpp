//
// Created by shora on 27/05/2023.
//

#include "MagicalContainer.h"
// MagicalContainer.cpp
//#include "MagicalContainer.hpp"
#include <algorithm>

MagicalContainer::MagicalContainer() {}

MagicalContainer::~MagicalContainer() {}

void MagicalContainer::addElement(int element) {
    elements.push_back(element);
    sort();
}

void MagicalContainer::removeElement(int element) {
    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    sort();
}

int MagicalContainer::size() const {
    return elements.size();
}

MagicalContainer::iterator MagicalContainer::begin() {
    return iterator(elements.begin());
}

MagicalContainer::iterator MagicalContainer::end() {
    return iterator(elements.end());
}

// Similar methods for cross_begin/cross_end and prime_begin/prime_end

void MagicalContainer::sort() {
    std::sort(elements.begin(), elements.end());
}

bool MagicalContainer::is_prime(int num) {
    // implement a method to check if a number is prime
}

//ctors
AscendingIterator::AscendingIterator(std::vector<int>::iterator iter) : current(iter) {}

AscendingIterator::AscendingIterator(MagicalContainer &container) : current(container.elements.begin()) {}

AscendingIterator::AscendingIterator(const AscendingIterator &other) : current(other.current) {}

AscendingIterator::~AscendingIterator() {}

AscendingIterator &AscendingIterator::operator=(const AscendingIterator &other) {
    current = other.current;
    return *this;
}

bool AscendingIterator::operator==(const AscendingIterator &other) const {
    return current == other.current;
}

bool AscendingIterator::operator!=(const AscendingIterator &other) const {
    return !(*this == other);
}

bool AscendingIterator::operator>(const AscendingIterator &other) const {
    // implement this
}

bool AscendingIterator::operator<(const AscendingIterator &other) const {
    // implement this
}

int &AscendingIterator::operator*() {
    return *current;
}

AscendingIterator &AscendingIterator::operator++() {
    ++current;
    return *this;
}

// Similar implementation for SideCrossIterator and PrimeIterator


