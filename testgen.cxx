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
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= 200; j++) {
            cout << "I " << i*200+j << endl;
        }
        cout << "S" << endl << "P" << endl;
    }
    cout << "F" << endl;
    for (int i = 601; i <= 610; i++) {
        cout << "I " << i << endl;
    }
    cout << "S" << endl << "P" << endl << "F" << endl;
    for (int i = 611; i <= 800; i++) {
        cout << "I " << i << endl;
    }
    cout << "S" << endl << "P" << endl << "Q" << endl;
}