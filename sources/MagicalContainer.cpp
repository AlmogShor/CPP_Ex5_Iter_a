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
        for (auto it = primePointers.begin(); it != primePointers.end(); ++it)
        {
            if (**it == elem)
            {
                delete *it;
                primePointers.erase(it);
                break;
            }
        }
        this->endOfSideCross = this->ascendingList.at(this->size() / 2);
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
        } else {
            this->current = nullptr;

        }
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        MagicalContainer::AscendingIterator it = MagicalContainer::AscendingIterator(*this);
        return it;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        MagicalContainer::AscendingIterator it = MagicalContainer::AscendingIterator(this->container, nullptr);

        it.idx = -1;
        return it;
    }

    /***********************************************/
    /* SideCrossIterator */
    /***********************************************/

    MagicalContainer::SideCrossIterator::SideCrossIterator(ariel::MagicalContainer &cont) : container(cont),
                                                                                            head(cont.ascendingList.getHead()),
                                                                                            tail(cont.ascendingList.getLast()),
                                                                                            idx(0) {

    }

    // Copy constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) = default;

    //move constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &&other)

    noexcept:
    container(other
    .container),
    head(other
    .head),
    tail(other
    .tail),
    odd(other
    .odd),
    idx(other
    .idx) {

}

//dtor
MagicalContainer::SideCrossIterator::~SideCrossIterator() = default;

//copy assignment
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
    if (&this->container != &other.container) {
        throw runtime_error("Cannot assign iterators of different containers");
    }
    if (this != &other) {
        this->container = other.container;
        this->head = other.head;
        this->tail = other.tail;
        this->idx = other.idx;
    }
    return *this;
}

// Move assignment

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other)

noexcept  {
this->
container = other.container;
this->
head = other.head;
this->
tail = other.tail;
this->
idx = other.idx;
other.
idx = -1;
return *this;
}

//operators

//comparison
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
    return this->head == other.head && this->tail == other.tail && &this->container == &other.container;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
    return this->idx < other.idx && &this->container == &other.container;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
    return this->idx > other.idx && &this->container == &other.container;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    if (this->tail != nullptr && this->odd)
        return this->tail->getData();
    if (this->head != nullptr) {
        return this->head->getData();
    }

    throw runtime_error("Cannot dereference end iterator");
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    if (*this == this->end()) {
        throw runtime_error("Cannot increment end iterator");
    }
    if (this->head == this->tail) {
        this->head = nullptr;
        this->tail = nullptr;
        return *this;
    }
    if (this->odd) {
        this->tail = this->tail->prev;
        this->odd = false;
    } else {
        this->head = this->head->next;
        this->odd = true;
        ++this->idx;
    }
    if (this->tail->next != nullptr && this->tail->next == this->head) {
        this->head = nullptr;
        this->tail = nullptr;
    }
    return *this;
}

//begin
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    MagicalContainer::SideCrossIterator iter = MagicalContainer::SideCrossIterator(this->container);
    return iter;
}

//end
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    MagicalContainer::SideCrossIterator iter = MagicalContainer::SideCrossIterator(this->container);
    iter.head = nullptr;
    iter.tail = nullptr;
    if (this->container.size() % 2 != 0)
        iter.odd = true;
    return iter;
}

/***********************************************/
/* PrimeIterator */
/***********************************************/

//dtor is in the header file

//ctors

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container, size_t idx) : container(container),
                                                                                          currentIdx(idx) {}

// Copy constructor
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) = default;

//move constructor

MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &&other)

noexcept:
container(other
.container),
currentIdx(other
.currentIdx) {
other.
currentIdx = size_t(-1);
}

//copy assignment
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
    if (&this->container != &other.container) {
        throw runtime_error("Cannot assign iterators of different containers");
    }
    if (this != &other) {
        this->container = other.container;
        this->currentIdx = other.currentIdx;
    }
    return *this;
}

// Move assignment
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other)

noexcept {
if (this != &other) {
this->
container = other.container;
this->
currentIdx = other.currentIdx;

}
return *this;
}

bool
MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
    return &this->container == &other.container && this->currentIdx == other.currentIdx;
}

bool
MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
    return !(*this == other);
}

bool
MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
    return this->currentIdx > other.currentIdx && &this->container == &other.container;
}

bool
MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
    return this->currentIdx < other.currentIdx && &this->container == &other.container;
}


int
MagicalContainer::PrimeIterator::operator*() const{
    if (this->currentIdx >= this->container.primePointers.size()) {
        throw runtime_error("Cannot dereference end iterator");
    }
    return *(this->container.primePointers[this->currentIdx]);
}

MagicalContainer::PrimeIterator &
MagicalContainer::PrimeIterator::operator++(){
    if (*this == this->end()) {
        throw runtime_error("Cannot increment end iterator");
    }
    ++this->currentIdx;
    return *this;
}

MagicalContainer::PrimeIterator
MagicalContainer::PrimeIterator::begin(){
    MagicalContainer::PrimeIterator iter = MagicalContainer::PrimeIterator(this->container, 0);
    return iter;
}


MagicalContainer::PrimeIterator
MagicalContainer::PrimeIterator::end(){
    MagicalContainer::PrimeIterator iter = MagicalContainer::PrimeIterator(this->container, this->container.primePointers.size());
    return iter;
}


} // namespace ariel