//
// Created by shora on 1/06/2023.
//


#pragma once

#include "myLinkedList.hpp"
#include <stdexcept>
#include <vector>

namespace ariel {
    class MagicalContainer {
    private:
        Node<int> *ascendingHead;
        Node<int> *ascendingEnd;
        Node<int> *descendingHead;
        Node<int> *descendingEnd;
        Node<int> *primeHead;
        Node<int> *primeEnd;
        int _size;

        // private methods
        bool isPrime(int num);

        int exists(int num); // returns the index of the element if it exists, -1 otherwise

    public:
        // ctors
        MagicalContainer();

        MagicalContainer(const MagicalContainer &other) = default;

        MagicalContainer(MagicalContainer&& other) noexcept = default; // move ctor
        // dtor
        ~MagicalContainer();



        // methods
        void addElement(int num);

        void removeElement(int num);

        int size();

        class AscendingIterator;

        class SideCrossIterator;

        class PrimeIterator;

        class AscendingIterator {
        private:
            const MagicalContainer *container;
            Node<int> *currElement;
        public:
            // ctors
            AscendingIterator();

            AscendingIterator(const MagicalContainer &container);

            AscendingIterator(const AscendingIterator &other);

            AscendingIterator(AscendingIterator &&other)

            noexcept; // move ctor
            // dtor
            ~AscendingIterator();

            // operators
            //placements
            AscendingIterator &operator=(const AscendingIterator &other);

            AscendingIterator &operator=(AscendingIterator &&other)

            noexcept; // move assignment
            // equality
            bool operator==(const AscendingIterator &other) const;

            bool operator==(const SideCrossIterator &other) const;

            bool operator==(const PrimeIterator &other) const;

            // inequality
            bool operator!=(const AscendingIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            //bigger than
            bool operator>(const AscendingIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            //smaller than
            bool operator<(const AscendingIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            //increment
            AscendingIterator &operator++();

            //ptr oerator
            int operator*();

            // methods
            AscendingIterator begin();

            AscendingIterator end();
        };

        class SideCrossIterator {
        private:
            const MagicalContainer *container;
            Node<int> *currFrontElement;
            Node<int> *currBackElement;
            bool isFront;
        public:
            // ctors
            SideCrossIterator();

            SideCrossIterator(const MagicalContainer &container);

            SideCrossIterator(const SideCrossIterator &other);

            SideCrossIterator(SideCrossIterator &&other)

            noexcept; // move ctor
            // dtor
            ~SideCrossIterator();

            // operators
            //placements
            SideCrossIterator &operator=(const SideCrossIterator &other);

            SideCrossIterator &operator=(SideCrossIterator &&other)

            noexcept; // move assignment
            // equality
            bool operator==(const AscendingIterator &other) const;

            bool operator==(const SideCrossIterator &other) const;

            bool operator==(const PrimeIterator &other) const;

            // inequality
            bool operator!=(const AscendingIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            //bigger than
            bool operator>(const AscendingIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            //smaller than
            bool operator<(const AscendingIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            //increment
            SideCrossIterator &operator++();

            //ptr oerator
            int operator*();

            // methods
            SideCrossIterator begin();

            SideCrossIterator end();

        };

        class PrimeIterator {
        private:
            const MagicalContainer *container;
            Node<int> *currElement;
        public:
            // ctors
            PrimeIterator();

            PrimeIterator(const MagicalContainer &container);

            PrimeIterator(const PrimeIterator &other);

            PrimeIterator(PrimeIterator &&other)

            noexcept; // move ctor
            // dtor
            ~PrimeIterator();

            // operators
            //placements
            PrimeIterator &operator=(const PrimeIterator &other);

            PrimeIterator &operator=(PrimeIterator &&other)

            noexcept; // move assignment
            // equality
            bool operator==(const AscendingIterator &other) const;

            bool operator==(const SideCrossIterator &other) const;

            bool operator==(const PrimeIterator &other) const;

            // inequality
            bool operator!=(const AscendingIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            //bigger than
            bool operator>(const AscendingIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            //smaller than
            bool operator<(const AscendingIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            //increment
            PrimeIterator &operator++();

            //ptr oerator
            int operator*();

            // methods
            PrimeIterator begin();

            PrimeIterator end();
        };
    };
}
