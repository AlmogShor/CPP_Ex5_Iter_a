//
// Created by shora on 1/06/2023.
//

#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <math.h>
#include <cmath>


using namespace std;

namespace ariel {
    class MagicalContainer {
        class Iter {
        public:
            // variables
            int *currElem;

            // ctors
            Iter() : currElem(nullptr) {}

            Iter(const Iter &other) = delete; // copy ctor - delete to avoid double free
            Iter(Iter &&other)

            noexcept = delete; // move ctor - delete to avoid double free
            //dtor
            virtual ~Iter() = default;

            //operators
            Iter &operator=(const Iter &other) = delete; // delete to avoid double free
            Iter &operator=(Iter &&other)

            noexcept = delete; // delete to avoid double free
            virtual int &operator*() = 0;

            virtual Iter &operator++() = 0;

            virtual vector<int>::iterator begin() = 0;

            virtual vector<int>::iterator end() = 0;

        };

    public:
        class AscendingIterator : public Iter {
        private:
            MagicalContainer *container;
            vector<int> sortedElements;
            int *currElement;
        public:
            // ctors
            AscendingIterator();

            AscendingIterator(MagicalContainer &container);

            AscendingIterator(const AscendingIterator &other);

            AscendingIterator(AscendingIterator &&other)

            noexcept;

            // dtor
            ~AscendingIterator() override;

            // operators
            AscendingIterator &operator=(const AscendingIterator &other);

            AscendingIterator &operator=(AscendingIterator &&other)

            noexcept;

            int &operator*() override;

            AscendingIterator &operator++() override;

            bool operator==(const AscendingIterator &other) const;

            bool operator==(const vector<int>::iterator &other) const{return true;}

            bool operator!=(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            vector<int>::iterator begin() override;

            vector<int>::iterator end() override;

        };

        class SideCrossIterator : public Iter {
        private:
            MagicalContainer *container;
            vector<int> sortedElements;
            int *currElement;
        public:
            //ctors
            SideCrossIterator();

            SideCrossIterator(MagicalContainer &container);

            SideCrossIterator(const SideCrossIterator &other);

            SideCrossIterator(SideCrossIterator &&other)

            noexcept;

            // dtor
            ~SideCrossIterator() override;

            // operators
            SideCrossIterator &operator=(const SideCrossIterator &other);

            SideCrossIterator &operator=(SideCrossIterator &&other)

            noexcept;

            int &operator*() override;

            SideCrossIterator &operator++() override;

            bool operator==(const SideCrossIterator &other) const;

            bool operator==(const vector<int>::iterator &other) const{return true;}

            bool operator!=(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            vector<int>::iterator begin() override;

            vector<int>::iterator end() override;
        };

        class PrimeIterator : public Iter {
        private:
            MagicalContainer *container;
            vector<int> sortedElements;
            int *currElement;

            static bool isPrime(int num) {
                double sqrtNum = sqrt(num);
                for (int i = 2; i <= sqrtNum; i++) {
                    if (num % i == 0) {
                        return false;
                    }
                }
                return true;
            }

        public:
            //ctors
            PrimeIterator();

            PrimeIterator(MagicalContainer &container);

            PrimeIterator(const PrimeIterator &other);

            PrimeIterator(PrimeIterator &&other)

            noexcept;

            // dtor
            ~PrimeIterator() override;

            // operators
            PrimeIterator &operator=(const PrimeIterator &other);

            PrimeIterator &operator=(PrimeIterator &&other)

            noexcept;

            int &operator*() override;

            PrimeIterator &operator++() override;

            bool operator==(const PrimeIterator &other) const;

            bool operator==(const vector<int>::iterator &other) const{return true;}

            bool operator!=(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            vector<int>::iterator begin() override;

            vector<int>::iterator end() override;
        };
        // variables

        vector<int> elements;
        AscendingIterator ascendingIterator;
        SideCrossIterator sideCrossIterator;
        PrimeIterator primeIterator;

        MagicalContainer();

        ~MagicalContainer();

        void addElement(int element);

        void removeElement(int element);

        std::vector<int> getElements() const;

        int size() const;

        AscendingIterator &getAscendingIterator();

        SideCrossIterator &getSideCrossIterator();

        PrimeIterator &getPrimeIterator();

        MagicalContainer(const MagicalContainer &other) = delete;

        MagicalContainer &operator=(const MagicalContainer &other) = delete;

        MagicalContainer(MagicalContainer &&other)

        noexcept = delete;

        MagicalContainer &operator=(MagicalContainer &&other)

        noexcept = delete;
    };
} // namespace ariel
