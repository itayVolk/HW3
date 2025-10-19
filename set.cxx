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
#include <utility>
#include "set.h"

namespace csen79 {

    // assignment
    Set &Set::operator=(const Set &rhs) {
        if (this == &rhs) return *this;  // Self-assignment check

        if (data != nullptr)
            delete[] data;  // Delete old memory

        DATASIZE = rhs.DATASIZE;
        count = rhs.count;
        fail = rhs.fail;

        if (rhs.data != nullptr) {
            data = new Data[DATASIZE];  // Allocate new memory
            memcpy(data, rhs.data, count*sizeof(Data));
        } else {
            data = nullptr;
        }

        return *this;
    }

    // Move constructor
    Set::Set(Set &&rhs) {
        operator=(std::move(rhs));
    }    

    // copy constructor
    Set::Set(const Set &rhs) {
        operator=(rhs);
    }    

    // Move operator
    Set &Set::operator=(Set &&rhs) {
        if (this == &rhs) return *this;
        delete[] data;
        data = rhs.data;
        count = rhs.count;
        DATASIZE = rhs.DATASIZE;
        fail = rhs.fail;
        rhs.data = nullptr;
        rhs.count = 0;
        rhs.DATASIZE = 0;
        rhs.fail = fail;
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
            if (data != nullptr) {
                if (fail)
                    throw std::bad_alloc();
                Data* temp = new Data[DATASIZE+ALLOCSIZE];
                memcpy(temp, data, count*sizeof(Data));
                delete[] data;
                data = temp;
            } else {
                data = new Data[DATASIZE+ALLOCSIZE];
            }
            DATASIZE += ALLOCSIZE;
        }

        data[count++] = element; //Insert data and increment
    };
    //Return the number of elements in the set
    int Set::size() {return count;};
    //Prints the data to cout
    void Set::print() const {
        for (int i = 0; i < count; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    };
    //Toggles whether new will "fail"
    bool Set::toggleFail() {
        fail = !fail;
        return fail;
    };
}