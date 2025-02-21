//
// Created by Riccardo on 21/02/2025.
//

#ifndef NUMNOTE_H
#define NUMNOTE_H
#include "Observer.h"
#include <iostream>


class NumNote:public Observer{
public:
    virtual void update(int numNote, const string& c) override {
        cout << "Ci sono "<< numNote << " note in " << c <<  endl;
    }
    virtual ~NumNote() {};
};



#endif //NUMNOTE_H
