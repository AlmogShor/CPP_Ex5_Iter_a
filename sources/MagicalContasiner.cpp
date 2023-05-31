// MagicalContainer.cpp
#include "MagicalContainer.hpp"
#include <algorithm>

namespace ariel {

    // Helper function to check if a number is prime
    bool isPrime(int number) {
        if (number < 2) return false;
        for (int i = 2; i*i <= number; i++) {
            if (number % i == 0) return false;
        }
        return true;
    }

    // MagicalContainer methods
    // ------------------------

    MagicalContainer::MagicalContainer() {
        // Initialize MagicalContainer
        this->AscendingIteratorElements = vector<int *>();
        this->SideCrossIteratorElements = vector<int *>();
        this->PrimeIteratorElements = vector<int *>();
        this->size = 0;
    }

    int MagicalContainer::size() const {
        // Provide the current size of the container
        return this->size();
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
        this->++size;
    }

    // Similarly, removeElement() method can be implemented
    // Remember to remove from all three containers

    // Implement Iter, AscendingIterator, SideCrossIterator, PrimeIterator classes here.

    // Here's an example of what AscendingIterator class might look like
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
            : Iter(&container), index(0) {
        // Initialize AscendingIterator
    }

    MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &other)
            : Iter(other), index(other.index) {
        // Initialize AscendingIterator from another AscendingIterator
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        // Increment operator for AscendingIterator
        if (index < container->AscendingIteratorElements.size()) {
            index++;
        }
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
        // Assignment operator for AscendingIterator
        this->index = other.index;
        this->container = other.container;
        return *this;
    }


    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++(int) {
        // Increment operator for AscendingIterator
        AscendingIterator temp = *this;
        ++*this;
        return temp;
    }

    // Similarly, you can implement SideCrossIterator and PrimeIterator

    // End of namespace ariel
}
