//
// Created by shora on 27/05/2023.
//

// MagicalContainer.hpp
#pragma once
#include <vector>
#include <iterator>
#include <exception>

class AscendingIterator;
class SideCrossIterator;
class PrimeIterator;

class MagicalContainer {
public:
    typedef int value_type;
    typedef AscendingIterator iterator;
    typedef SideCrossIterator cross_iterator;
    typedef PrimeIterator prime_iterator;

    MagicalContainer();
    ~MagicalContainer();

    void add(int element);
    void remove(int element);
    int size() const;

    iterator begin();
    iterator end();

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
    AscendingIterator(const AscendingIterator& other);
    ~AscendingIterator();

    AscendingIterator& operator=(const AscendingIterator& other);

    bool operator==(const AscendingIterator& other) const;
    bool operator!=(const AscendingIterator& other) const;
    bool operator>(const AscendingIterator& other) const;
    bool operator<(const AscendingIterator& other) const;

    int& operator*();
    AscendingIterator& operator++();

private:
    std::vector<int>::iterator current;

    friend class MagicalContainer;
};

// Define similar classes for SideCrossIterator and PrimeIterator
