// MagicalContainer.cpp
#include "MagicalContainer.hpp"
#include <algorithm>

namespace ariel {

    // Helper function to check if a number is prime
    bool isPrime(int number) {
        if (number < 2) return false;
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) return false;
        }
        return true;
    }

    // MagicalContainer methods
    // ------------------------

    MagicalContainer::MagicalContainer() {
        // Initialize MagicalContainer
        this->AscendingIteratorElements = vector<int>();
        this->SideCrossIteratorElements = vector<int>();
        this->PrimeIteratorElements = vector<int>();
        this->_size = 0;
    }


    void MagicalContainer::addElement(int element) {
        AscendingIteratorElements.push_back(element);
        std::sort(AscendingIteratorElements.begin(), AscendingIteratorElements.end());

        // For SideCrossIterator, push to the back
        SideCrossIteratorElements.push_back(element);

        // For PrimeIterator, push to the back if it's prime
        if (isPrime(element)) {
            PrimeIteratorElements.push_back(element);
        }
        this->_size++;
    }

    // Similarly, removeElement() method can be implemented
    // Remember to remove from all three containers

    // Implement Iter, AscendingIterator, SideCrossIterator, PrimeIterator classes here.

    // Here's an example of what AscendingIterator class might look like
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
            : Iter(&container) {
        // Initialize AscendingIterator
    }

    MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &other)
            : Iter(other) {
        // Initialize AscendingIterator from another AscendingIterator
    }

    MagicalContainer::AscendingIterator &
    MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
        // Assignment operator for AscendingIterator
        this->setPos(other.getPos());
        this->setContainer(other.getContainer());
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        // Increment operator for AscendingIterator
        if (this->getPos() < getContainer()->AscendingIteratorElements.size()) {
            this->setPos(this->getPos() + 1);
        }
        return *this;
    }


    int* &MagicalContainer::AscendingIterator::operator*() {
        // Check if index is valid
        int index = this->getPos();
        if (index >= 0 && index < getContainer()->AscendingIteratorElements.size()) {
            return container->AscendingIteratorElements[index];
        }
        throw std::out_of_range("Iterator out of range");
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        // Return an iterator pointing to the first element
        return AscendingIterator(*this);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        // Return an iterator pointing to the past-the-end element
        return AscendingIterator(*this);
    }



    // Similarly, you can implement SideCrossIterator and PrimeIterator

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
            : Iter(&container) {
        // Initialize SideCrossIterator

    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &other)
            : Iter(other) {
        // Initialize SideCrossIterator from another SideCrossIterator
    }

    MagicalContainer::SideCrossIterator &
    MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
        // Assignment operator for SideCrossIterator
        this->setPos(other.getPos());
        this->setContainer(other.getContainer());
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        // Increment operator for SideCrossIterator
        int index = this->getPos();
        if (index < getContainer()->SideCrossIteratorElements.size()) {

            index++;
        }
        return *this;
    }

    int* &MagicalContainer::SideCrossIterator::operator*() {
        // Check if index is valid
        int index = this->getPos();
        if (index >= 0 && index < getContainer()->SideCrossIteratorElements.size()) {
            return getContainer()->SideCrossIteratorElements[index];
        }
        throw std::out_of_range("Iterator out of range");
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        // Return an iterator pointing to the first element
        return SideCrossIterator(*this);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        // Return an iterator pointing to the past-the-end element
        return SideCrossIterator(*this);
    }

    // End of namespace ariel
}
