#include <iostream>
#include "MagicalContainer.hpp"
#include "doctest.h"

using namespace ariel;

TEST_SUITE("MagicalContainer Tests") {

    TEST_CASE("Adding and Removing Elements") {
        MagicalContainer container;
        CHECK(container.size() == 0);

        container.addElement(10);
        container.addElement(20);
        container.addElement(30);
        CHECK(container.size() == 3);

        container.removeElement(20);
        CHECK(container.size() == 2);

        container.removeElement(40);
        CHECK(container.size() == 2);
    }

    TEST_CASE("AscendingIterator Test") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(3);
        container.addElement(7);
        container.addElement(2);

        MagicalContainer::AscendingIterator it(container);
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 7);
        ++it;

    }

    TEST_CASE("SideCrossIterator Test") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(4);
        container.addElement(3);
        container.addElement(2);
        container.addElement(1);

        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it == 4);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 3);
        ++it;

    }

    TEST_CASE("PrimeIterator Test") {
        MagicalContainer container;
        container.addElement(7);
        container.addElement(8);
        container.addElement(11);
        container.addElement(15);
        container.addElement(17);

        MagicalContainer::PrimeIterator it(container);
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 11);
        ++it;
        CHECK(*it == 17);
        ++it;

    }

    // Add more test cases here...

}

TEST_SUITE("Additional Test Suite") {
    TEST_CASE("Size Test") {
        MagicalContainer container;
        CHECK(container.size() == 0);

        container.addElement(10);
        container.addElement(20);
        container.addElement(30);
        CHECK(container.size() == 3);

        container.removeElement(10);
        CHECK(container.size() == 2);

        container.removeElement(40);
        CHECK(container.size() == 2);
    }

    TEST_CASE("Empty Container Test") {
        MagicalContainer container;
        CHECK(container.size() == 0);

    }

    TEST_CASE("Iterator Comparison Test") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(15);

        MagicalContainer::AscendingIterator ascIter(container);
        MagicalContainer::SideCrossIterator crossIter(container);

        CHECK(ascIter == ascIter);

        CHECK(crossIter == crossIter);

    }

    TEST_CASE("Iterator Range-based For Loop Test") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(3);
        container.addElement(7);

        std::vector<int> expected{3, 5, 7};
        std::vector<int> actual;



// Add more test cases here...


    }
}

//int main(int argc, char* argv[]) {
//    doctest::Context context;
//    context.applyCommandLine(argc, argv);
//    int res = context.run();
//    return res;
//}
