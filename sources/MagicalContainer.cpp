//
// Created by shora on 1/06/2023.
//

#include "MagicalContainer.hpp"


namespace ariel {

    // AscendingIterator implementation

    MagicalContainer::AscendingIterator::AscendingIterator() : container(nullptr), currElement(nullptr) {}

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
            : container(&container), currElement(nullptr) {
        sortedElements = container.elements;
        std::sort(sortedElements.begin(), sortedElements.end());
        currElement = sortedElements.data();
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
            : container(other.container), sortedElements(other.sortedElements), currElement(other.currElement) {}

    MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &&other)

    noexcept
    :
    container(other
    .container),
    sortedElements(std::move(other.sortedElements)
    ),
    currElement(other
    .currElement) {
}

MagicalContainer::AscendingIterator::~AscendingIterator() = default;

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
    if (this != &other) {
        container = other.container;
        sortedElements = other.sortedElements;
        currElement = other.currElement;
    }
    return *this;
}

MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other)

noexcept {
if (this != &other) {
container = other.container;
sortedElements = std::move(other.sortedElements);
currElement = other.currElement;
}
return *this;
}

int &MagicalContainer::AscendingIterator::operator*() {
    return *currElement;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    ++currElement;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
    return currElement == other.currElement;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
    return currElement != other.currElement;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
    return currElement < other.currElement;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const {
    return currElement > other.currElement;
}

std::vector<int>::iterator MagicalContainer::AscendingIterator::begin() {
    return sortedElements.begin();
}

std::vector<int>::iterator MagicalContainer::AscendingIterator::end() {
    return sortedElements.end();
}

// SideCrossIterator implementation

MagicalContainer::SideCrossIterator::SideCrossIterator() : container(nullptr), currElement(nullptr) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
        : container(&container), currElement(nullptr) {
    sortedElements = container.elements;
    std::sort(sortedElements.begin(), sortedElements.end(), [](int a, int b) {
        if (a % 2 == 0 && b % 2 == 1) {
            return true;
        } else if (a % 2 == 1 && b % 2 == 0) {
            return false;
        } else {
            return a < b;
        }
    });
    currElement = sortedElements.data();
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
        : container(other.container), sortedElements(other.sortedElements), currElement(other.currElement) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &&other)

noexcept
:
container(other
.container),
sortedElements(std::move(other.sortedElements)
),
currElement(other
.currElement) {
}

MagicalContainer::SideCrossIterator::~SideCrossIterator() = default;

MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
    if (this != &other) {
        container = other.container;
        sortedElements = other.sortedElements;
        currElement = other.currElement;
    }
    return *this;
}

MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other)

noexcept {
if (this != &other) {
container = other.container;
sortedElements = std::move(other.sortedElements);
currElement = other.currElement;
}
return *this;
}

int &MagicalContainer::SideCrossIterator::operator*() {
    return *currElement;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    ++currElement;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
    return currElement == other.currElement;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
    return currElement != other.currElement;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
    return currElement < other.currElement;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
    return currElement > other.currElement;
}

std::vector<int>::iterator MagicalContainer::SideCrossIterator::begin() {
    return sortedElements.begin();
}

std::vector<int>::iterator MagicalContainer::SideCrossIterator::end() {
    return sortedElements.end();
}

// PrimeIterator implementation

MagicalContainer::PrimeIterator::PrimeIterator() : container(nullptr), currElement(nullptr) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
        : container(&container), currElement(nullptr) {
    sortedElements = container.elements;
    sortedElements.erase(std::remove_if(sortedElements.begin(), sortedElements.end(),
                                        [](int num) { return !isPrime(num); }), sortedElements.end());
    currElement = sortedElements.data();
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
        : container(other.container), sortedElements(other.sortedElements), currElement(other.currElement) {}

MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &&other)

noexcept
:
container(other
.container),
sortedElements(std::move(other.sortedElements)
),
currElement(other
.currElement) {
}

MagicalContainer::PrimeIterator::~PrimeIterator() = default;

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
    if (this != &other) {
        container = other.container;
        sortedElements = other.sortedElements;
        currElement = other.currElement;
    }
    return *this;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other)

noexcept {
if (this != &other) {
container = other.container;
sortedElements = std::move(other.sortedElements);
currElement = other.currElement;
}
return *this;
}

int &MagicalContainer::PrimeIterator::operator*() {
    return *currElement;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    ++currElement;
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
    return currElement == other.currElement;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
    return currElement != other.currElement;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
    return currElement < other.currElement;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
    return currElement > other.currElement;
}

std::vector<int>::iterator MagicalContainer::PrimeIterator::begin() {
    return sortedElements.begin();
}

std::vector<int>::iterator MagicalContainer::PrimeIterator::end() {
    return sortedElements.end();
}

// MagicalContainer implementation
// Constructors
MagicalContainer::MagicalContainer() = default;

//dtor
MagicalContainer::~MagicalContainer() = default;

void MagicalContainer::addElement(int element) {
    elements.push_back(element);
}

void MagicalContainer::removeElement(int element) {
    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
}

int MagicalContainer::size() const {
    return elements.size();
}

}  // namespace ariel

