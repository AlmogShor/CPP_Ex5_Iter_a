//
// Created by shora on 1/06/2023.
//
// hand in unfinished unfortunately

#include "MagicalContainer.hpp"

using namespace std;


namespace ariel {

    /***********************************************/
    /* MaicalContainer */
    /***********************************************/

    MagicalContainer::MagicalContainer() {
        this->ascendingList = linkedList();
        primePointers = std::vector<int *>();
    }

    MagicalContainer::~MagicalContainer() {
        this->endOfSideCross = nullptr;
        for (auto p = primePointers.begin(); p != primePointers.end(); ++p)
            delete *p;
        primePointers.clear();
    }

    void MagicalContainer::addElement(int elem) {
        this->ascendingList.insert(elem);
        this->endOfSideCross = this->ascendingList.at(this->ascendingList.getSize() / 2);
        if (isPrime(elem)) {
            int *p = new int(elem);
            auto prime_ptr_insertion_point = lower_bound(primePointers.begin(), primePointers.end(), p,
                                                         [](int *a, int *b) { return *a < *b; });
            primePointers.insert(prime_ptr_insertion_point, p);
        }
    }

    void MagicalContainer::removeElement(int elem) {
        this->ascendingList.remove(elem);
        this->endOfSideCross = this->ascendingList.at(this->size() / 2);
        if (isPrime(elem)) {
            int *p = new int(elem);
            auto prime_ptr_insertion_point = lower_bound(primePointers.begin(), primePointers.end(), p,
                                                         [](int *a, int *b) { return *a < *b; });
            primePointers.erase(prime_ptr_insertion_point);
            delete p;
        }
    }

    size_t MagicalContainer::size() {
        return this->ascendingList.getSize();
    }

    /***********************************************/
    /* AscendingIterator */
    /***********************************************/

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container) {
        if (container.size() != 0) {
            this->current = container.ascendingList.getHead();
            this->idx = 0;
        } else {
            this->current = nullptr;
            this->idx = -1;
        }
    }

    MagicalContainer::AscendingIterator::AscendingIterator(ariel::MagicalContainer &container, Node *curr) : container(
            container), current(curr) {
        this->idx = 0;
    }

    // Copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) = default;

    //move constructor
    MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &&other)

    noexcept =
    default;

    //dtor
    MagicalContainer::AscendingIterator::~AscendingIterator() = default;

    //copy assignment
    MagicalContainer::AscendingIterator &
    MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
        if (&this->container != &other.container) {
            throw runtime_error("Cannot assign iterators of different containers");
        }
        if (this != &other) {
            this->container = other.container;
            this->current = other.current;
            this->idx = other.idx;
        }
        return *this;
    }

    //operators

    //comparison
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
        return this->current == other.current && &this->container == &other.container;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
        return this->idx < other.idx && &this->container == &other.container;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const {
        return this->idx > other.idx && &this->container == &other.container;
    }


    int MagicalContainer::AscendingIterator::operator*() const {
        return this->current->getData();
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        if (*this == this->end()) {
            throw runtime_error("Cannot increment end iterator");
        }
        if (this->current->next != nullptr) {
            this->current = this->current->next;
            this->idx++;
        }
        else{
            this->current = nullptr;

        }
        return *this;
    }


}