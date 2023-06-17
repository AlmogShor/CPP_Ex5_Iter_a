//
// created by shora 1/06/2023.
//

#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "linkedList.hpp"

inline bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i = i + 2)
        if (n % i == 0)
            return false;

    return true;
}

namespace ariel {

    class MagicalContainer {
    private:
        linkedList ascendingList;
        std::vector<int *> primePointers;
        Node *endOfSideCross = nullptr;

    public:
        MagicalContainer();

        MagicalContainer(const MagicalContainer &other) = default;

        MagicalContainer(MagicalContainer &&other)

        noexcept =
        default;

        MagicalContainer &operator=(const MagicalContainer &other) = default;

        ~MagicalContainer();

        void addElement(int element);

        void removeElement(int element);

        size_t size();

        class AscendingIterator {
        private:
            MagicalContainer &container;
            Node *current;
            int idx;

        public:
            AscendingIterator(MagicalContainer &container);

            AscendingIterator(MagicalContainer &container, Node *curr);

            AscendingIterator(const AscendingIterator &other);

            // Move constructor
            AscendingIterator(AscendingIterator &&other)

            noexcept;

            // Move assignment operator
            AscendingIterator &operator=(AscendingIterator &&other)

            noexcept;

            ~AscendingIterator();

            AscendingIterator &operator=(const AscendingIterator &other);

            bool operator==(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            int operator*() const;

            AscendingIterator &operator++();

            AscendingIterator begin();

            AscendingIterator end();
        };

        class SideCrossIterator {
        private:
            MagicalContainer &container;
            Node *tail;
            Node *head;
            bool odd;
            int idx = 0;

        public:
            SideCrossIterator(MagicalContainer &cont);

            SideCrossIterator(const SideCrossIterator &other);

            // Move constructor
            SideCrossIterator(SideCrossIterator &&other)

            noexcept;

            // Move assignment operator
            SideCrossIterator &operator=(SideCrossIterator &&other)

            noexcept;

            ~SideCrossIterator();

            SideCrossIterator &operator=(const SideCrossIterator &other);

            bool operator==(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            int operator*() const;

            SideCrossIterator &operator++();

            SideCrossIterator begin();

            SideCrossIterator end();


        };

        class PrimeIterator {
        private:
            MagicalContainer &container;
            size_t currentIdx;

        public:
            PrimeIterator(MagicalContainer &cont, size_t index = 0);

            PrimeIterator(const PrimeIterator &other);

            // Move constructor
            PrimeIterator(PrimeIterator &&other)

            noexcept;

            // Move assignment operator
            PrimeIterator &operator=(PrimeIterator &&other)

            noexcept;

            //dtor
            ~PrimeIterator(){}

            //copy assignment
            PrimeIterator &operator=(const PrimeIterator &other);

            bool operator==(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            int operator*() const;

            PrimeIterator &operator++();

            PrimeIterator begin();

            PrimeIterator end();


        };
    };
}