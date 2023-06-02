//
// Created by shora on 1/06/2023.
//

#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace ariel{
    class MagicalContainer {
        class Iter
        {
        public:
            // variables
            int *currElem;
            // ctors
            Iter() : currElem(nullptr) {}
            Iter( const Iter &other) = delete; // copy ctor - delete to avoid double free
            Iter( Iter &&other) noexcept = delete; // move ctor - delete to avoid double free
            //dtor
            virtual ~Iter() = default;

            //operators
            Iter &operator=(const Iter &other) = delete; // delete to avoid double free
            Iter &operator=(Iter &&other) noexcept = delete; // delete to avoid double free
            virtual int &operator*() const = 0;
            virtual Iter &operator++() = 0;
            virtual vector<int>::iterator begin() = 0;
            virtual vector<int>::iterator end() = 0;

        };
    public:
        class AscendingIterator : public Iter
        {
        private:
            MagicalContainer *container;
            vector<int> sortedElements;
            int *currElement;
        public:
            // ctors
            AscensingIterator();
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator(AscendingIterator &&other) noexcept;
            // dtor
            ~AscendingIterator() override;
            // operators
            AscendingIterator &operator=(const AscendingIterator &other);
            AscendingIterator &operator=(AscendingIterator &&other) noexcept;

    };
}
