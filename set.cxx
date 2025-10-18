/*
 * Itay Volk <ivolk@scu.edu>,
 * David Chousal Cantu <dchousal@scu.edu>,
 * Ding-Shiuan Yang <dyang2@scu.edu>,
 * Rushil Kumar <rkumar3@scu.edu>,
 * Alexander Anokhin <aanokhin@scu.edu>
 * recipe for containers using pointers
 */
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <string.h>
#include "set.h"

namespace csen79 {

    // assignment
    Set &Set::operator=(const Set &rhs) {
        memcpy(data, rhs.data, DATASIZE*sizeof(Data));
        count = rhs.count;
        return *this;
    }

    // Move constructor
    Set::Set(Set &&rhs) : data(rhs.data), count(rhs.count), DATASIZE(rhs.DATASIZE) {
        rhs.data = nullptr;
        rhs.count = 0;
        rhs.DATASIZE = 0;
    }    

    // copy constructor
    Set::Set(const Set &rhs) {
        operator=(rhs);
    }    

    // Move Assignment
    Set &Set::operator=(Set &&rhs) {
        if (this == &rhs) return *this;
        delete[] data;
        data = rhs.data;
        count = rhs.count;
        DATASIZE = rhs.DATASIZE;
        rhs.data = nullptr;
        rhs.count = 0;
        rhs.DATASIZE = 0;
        return *this;
    }

    Set::~Set() {
        delete[] data;
    }

    //Add data to set if not inside
    void Set::insert(const Data &element) {
        //Check if data isn't in set
        for (int i = 0; i < count; i++) {
            if (data[i] == element) {
                return;
            }
        }

        //Increase size if necessary
        if (count == DATASIZE) {
            DATASIZE += 200;
            if (data != nullptr) {
                Data* temp = new Data[DATASIZE];
                memcpy(temp, data, count*sizeof(Data));
                delete[] data;
                data = temp;
            } else {
                data = new Data[DATASIZE];
            }
        }

        data[count++] = element; //Insert data and increment
    };
    //Return the number of elements in the set
    int Set::size() {return 0;};
    //Prints the data to cout
    void Set::print() const {
        for (int i = 0; i < count; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    };
}