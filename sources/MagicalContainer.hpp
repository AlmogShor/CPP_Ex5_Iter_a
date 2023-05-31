//
// Created by shora on 27/05/2023.
//

// MagicalContainer.hpp
#pragma once

#include <vector>
#include <iterator>
#include <exception>

using namespace std;

class AscendingIterator;

class SideCrossIterator;

class PrimeIterator;
namespace ariel {
    class MagicalContainer {
    public:
        typedef int value_type;
        vector<int*> AscendingIteratorElements;
        vector<int*> SideCrossIteratorElements;
        vector<int*> PrimeIteratorElements;

        MagicalContainer();

        virtual ~MagicalContainer();

        void addElement(int element);

        void removeElement(int element);

        int size() const;

        virtual iterator begin();

        virtual iterator end();

        cross_iterator cross_begin();

        cross_iterator cross_end();

        prime_iterator prime_begin();

        prime_iterator prime_end();

    private:
        std::vector<int> elements;

        void sort();

        bool is_prime(int num);

        friend class AscendingIterator;

        friend class SideCrossIterator;

        friend class PrimeIterator;
    };

    class AscendingIterator : public std::iterator<std::forward_iterator_tag, int> {
    public:
        AscendingIterator();

        AscendingIterator(MagicalContainer &container);

        AscendingIterator(const AscendingIterator &other);

        ~AscendingIterator();

        AscendingIterator &operator=(const AscendingIterator &other);

        bool operator==(const AscendingIterator &other) const;

        bool operator!=(const AscendingIterator &other) const;

        bool operator>(const AscendingIterator &other) const;

        bool operator<(const AscendingIterator &other) const;

        int &operator*();

        AscendingIterator &operator++();

    private:
        std::vector<int>::iterator current;

        friend class MagicalContainer;
    };

// Define similar classes for SideCrossIterator and PrimeIterator\

    class SideCrossIterator : public std::iterator<std::forward_iterator_tag, int> {
    public:
        SideCrossIterator();

        SideCrossIterator(MagicalContainer &container);

        SideCrossIterator(const SideCrossIterator &other);

        ~SideCrossIterator();

        SideCrossIterator &operator=(const SideCrossIterator &other);

        bool operator==(const SideCrossIterator &other) const;

        bool operator!=(const SideCrossIterator &other) const;

        bool operator>(const SideCrossIterator &other) const;

        bool operator<(const SideCrossIterator &other) const;

        int &operator*();

        SideCrossIterator &operator++();

    private:
        std::vector<int>::iterator front;
        std::vector<int>::iterator back;
        bool isFront;

        friend class MagicalContainer;
    };

    class PrimeIterator : public std::iterator<std::forward_iterator_tag, int> {
    public:
        PrimeIterator();

        PrimeIterator(MagicalContainer &container);

        PrimeIterator(const PrimeIterator &other);

        ~PrimeIterator();

        PrimeIterator &operator=(const PrimeIterator &other);

        bool operator==(const PrimeIterator &other) const;

        bool operator!=(const PrimeIterator &other) const;

        bool operator>(const PrimeIterator &other) const;

        bool operator<(const PrimeIterator &other) const;

        int &operator*();

        PrimeIterator &operator++();

    private:
        std::vector<int>::iterator current;

        friend class MagicalContainer;
    };

}