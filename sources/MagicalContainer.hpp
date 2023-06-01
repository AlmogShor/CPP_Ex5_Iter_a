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

    private:
        int _size;
        vector<int *> AscendingIteratorElements;
        vector<int *> SideCrossIteratorElements;
        vector<int *> PrimeIteratorElements;
    public:

        MagicalContainer();

//        virtual ~MagicalContainer();

        void addElement(int element);

        void removeElement(int element);

        int size() const{
            return this->_size;
        }

        int contains(int element);

        bool isEmpty() const {
            return this->_size <= 0;
        }


        class Iter {

        public:
            // three ctors
            Iter() : pos(0), container(nullptr) {}

            Iter(MagicalContainer *container) : pos(0), container(container) {}

            Iter(const Iter &other) : pos(other.pos), container(other.container) {}

            // dtor
            virtual ~Iter() {}

            bool operator==(const Iter &other) const;

            bool operator!=(const Iter &other) const;

            bool operator>(const Iter &other) const;

            bool operator<(const Iter &other) const;
            // continue

            // getters
            int getPos();

            int *getLocation();

            MagicalContainer *getContainer() const {
                return this->container;
            }

            //setters
            bool setPos(int new_pos);

            bool setLocation(int *new_location);

            bool setContainer(MagicalContainer *new_container) {
                this->container = new_container;
                return true;
            }

        private:
            int pos;
            MagicalContainer *container;

        };

        class AscendingIterator : public Iter {
        public:
            // three ctors
            AscendingIterator();

            AscendingIterator(MagicalContainer &container);

            AscendingIterator(AscendingIterator &other);

            //dtor
            ~AscendingIterator();

            AscendingIterator &operator=(const AscendingIterator &other);

            AscendingIterator &operator++();

            int operator*();

            //getters
            AscendingIterator begin();

            AscendingIterator end();

        private:

        };

// Define similar classes for SideCrossIterator and PrimeIterator\

        class SideCrossIterator : public Iter {
        public:
            // three ctors
            SideCrossIterator();

            SideCrossIterator(MagicalContainer &container);

            SideCrossIterator(const SideCrossIterator &other);

            //dtor
            ~SideCrossIterator();

            SideCrossIterator &operator=(const SideCrossIterator &other);

            SideCrossIterator &operator++();

            int operator*();

            //getters
            SideCrossIterator begin();

            SideCrossIterator end();


        private:
        };

        class PrimeIterator : public Iter {
        public:
            // three ctors
            PrimeIterator();

            PrimeIterator(MagicalContainer &container);

            PrimeIterator(const PrimeIterator &other);

            //dtor
            ~PrimeIterator();

            PrimeIterator &operator=(const PrimeIterator &other);

            PrimeIterator &operator++();

            int operator*();

            //getters

            PrimeIterator begin();

            PrimeIterator end();

        private:

        };
    };

}