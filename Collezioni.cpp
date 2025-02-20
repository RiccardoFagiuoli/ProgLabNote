//
// Created by Riccardo on 20/02/2025.
//

#include "Collezioni.h"
#include "Note.h"
#include <iostream>

using namespace std;

Collezioni::Collezioni(const string& n): name(n){};
Collezioni::~Collezioni() {};

void Collezioni::printNotes() const {
    cout << "Collection: " << name << endl;
    for (auto n : notes) {
        cout << "Note " << n << ": " << n->getTitle() << endl;
    }
}

void Collezioni::update() {
    cout << "Collection " << this->getName() << " has " << this->getNumNotes() << " notes." << endl;
};