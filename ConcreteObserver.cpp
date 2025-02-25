//
// Created by Riccardo on 25/02/2025.
//
#include <iostream>
#include "ConcreteObserver.h"

void ConcreteObserver::update(bool op, const string& n) {
    if (op) {
        count++;
    }
    else {
        count--;
    }
    cout << "La collezione " << n << " ha " << count << " note." << endl;
}