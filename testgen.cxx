/*
 * Itay Volk <ivolk@scu.edu>,
 * David Chousal Cantu <dchousal@scu.edu>,
 * Ding-Shiuan Yang <dyang2@scu.edu>,
 * Rushil Kumar <rkumar3@scu.edu>,
 * Alexander Anokhin <aanokhin@scu.edu>
 * Test data generation program
 */

#include <iostream>

using namespace std;

int main(void) {
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= 100; j++) {
            cout << "I " << i*100+j << endl;
        }
        cout << "S" << endl << "P" << endl;
    }
    cout << "Q" << endl;
}