/*
 * Itay Volk <ivolk@scu.edu>,
 * David Chousal Cantu <dchousal@scu.edu>,
 * Ding-Shiuan Yang <dyang2@scu.edu>,
 * Rushil Kumar <rkumar3@scu.edu>,
 * Alexander Anokhin <aanokhin@scu.edu>
 * recipe for containers using pointers
 */
#ifndef SET_H
#define SET_H
namespace csen79 {

class Set {
public:
    size_t const ALLOCSIZE = 200;
    using Data = int;   // create an alias for the data
    Set(): data{nullptr}, count{0}, DATASIZE{0}, fail{false} {}

    // rule of 5
    ~Set();
    Set(const Set &);
    Set(Set &&);
    Set &operator=(const Set &);
    Set &operator=(Set &&rhs);

    // access functions
    void insert(const Data &);
    int size();
    void print() const;
    bool toggleFail();

private:
    // data storage
    bool fail;
    int count;
    size_t DATASIZE;    // array size
    Data* data;
};

}
#endif // SET_H