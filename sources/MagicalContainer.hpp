//
// created by shora 1/06/2023.
//

#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "linkedList.hpp"

namespace ariel
{

    class MagicalContainer
    {
    private:
        linkedList ascendingVector;
        std::vector<int> primePointers;

    public:
        MagicalContainer();
        MagicalContainer(const MagicalContainer &other)= default;
        MagicalContainer(MagicalContainer &&other) noexcept= default;
        MagicalContainer &operator=(const MagicalContainer &other)= default;
        ~MagicalContainer();
        void addElement(int element);
        void removeElement(int element);
        size_t size() const;

        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            Node *current;
            int index;

        public:
            AscendingIterator(MagicalContainer &cont);
            AscendingIterator(MagicalContainer &cont, Node *cur);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();

            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;

            int operator*() const;

            AscendingIterator &operator++();
            AscendingIterator begin() const;
            AscendingIterator end() const;

            // Move constructor
            AscendingIterator(AscendingIterator&& other)noexcept;

            // Move assignment operator
            AscendingIterator& operator=(AscendingIterator&& other) noexcept;
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &container;
            Node *tail;
            Node *head;
            bool odd;

        public:
            SideCrossIterator(MagicalContainer &cont);
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator();

            SideCrossIterator &operator=(const SideCrossIterator &other);

            bool operator==(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;

            int operator*() const;

            SideCrossIterator &operator++();
            SideCrossIterator begin() const;
            SideCrossIterator end() const;

            // Move constructor
            SideCrossIterator(SideCrossIterator&& other) noexcept;

            // Move assignment operator
            SideCrossIterator& operator=(SideCrossIterator&& other) noexcept;
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t currentIndex;

        public:
            PrimeIterator(MagicalContainer &cont, size_t index = 0);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();

            PrimeIterator &operator=(const PrimeIterator &other);

            bool operator==(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;

            int operator*() const;

            PrimeIterator &operator++();
            PrimeIterator begin() const;
            PrimeIterator end() const;

            // Move constructor
            PrimeIterator(PrimeIterator&& other) noexcept;

            // Move assignment operator
            PrimeIterator& operator=(PrimeIterator&& other) noexcept;
        };