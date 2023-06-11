//
// created by Almog Shor
//

#include <stdexcept>
#include <iostream>
#include "MagicalContainer.hpp"
#include "myLinkedList.hpp"

using namespace std;
using namespace ariel;

/****************************************************/
/*  MagicalContainer class implementation           */
/****************************************************/

// ctors
MagicalContainer::MagicalContainer() : ascendingHead(nullptr), ascendingEnd(nullptr), descendingHead(nullptr),
                                       descendingEnd(nullptr), primeHead(nullptr), primeEnd(nullptr), _size(0) {
    this->ascendingEnd = new Node<int>();
    this->descendingEnd = new Node<int>();
    this->primeEnd = new Node<int>();

}


//private methods
bool MagicalContainer::isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int MagicalContainer::exists(int num) {
    Node<int> *curr = this->ascendingHead;
    int index = 0;
    while (curr != nullptr) {
        if (curr->data == num) {
            return index;
        }
        curr = curr->next;
        index++;
    }
    return -1;
}




