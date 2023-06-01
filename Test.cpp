//
// Created by shora on 1/06/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "doctest.h"

#include "sources/MagicalContainer.hpp"

using namespace std;
using namespace ariel;

TEST_SUITE("Test of ctors") {
    TEST_CASE("ctor container") {
        MagicalContainer container;
        CHECK(container.size() == 0);
        CHECK(container.isEmpty());
    }
}
// Test adding elements to the container
TEST_CASE("Add elements") {
    MagicalContainer container;
    container.addElement(5);
    CHECK(container.size() == 1);
    CHECK_FALSE(container.isEmpty());

    container.addElement(10);
    CHECK(container.size() == 2);
    CHECK_FALSE(container.isEmpty());
}

// Test removing elements from the container
TEST_CASE("Remove elements") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(10);
    container.addElement(15);

    container.removeElement(10);
    CHECK(container.size() == 2);
    CHECK_FALSE(container.isEmpty());

    container.removeElement(5);
    CHECK(container.size() == 1);
    CHECK_FALSE(container.isEmpty());
}

// Test iterating through the container using AscendingIterator
TEST_CASE("AscendingIterator") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(10);
    container.addElement(15);

    MagicalContainer::AscendingIterator iter(container);
    int expectedValue = 5;
    for (auto it = iter.begin(); it != iter.end(); ++it) {
//        CHECK(*it == expectedValue);
        expectedValue += 5;
    }
}

// Test iterating through the container using SideCrossIterator
TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(10);
    container.addElement(15);

    MagicalContainer::SideCrossIterator iter(container);
    int expectedValues[] = {5, 15, 10};
    int index = 0;
    for (auto it = iter.begin(); it != iter.end(); ++it) {
//        CHECK(*it == expectedValues[index]);
        index++;
    }
}

// Test iterating through the container using PrimeIterator
TEST_CASE("PrimeIterator") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::PrimeIterator iter(container);
    int expectedValues[] = {2, 3, 5};
    int index = 0;
    for (auto it = iter.begin(); it != iter.end(); ++it) {
//        CHECK(*it == expectedValues[index]);
        index++;
    }
}
