//
// Created by Riccardo on 20/02/2025.
//

#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
    public:
    virtual void update(int numNote, const string& c) = 0;
    virtual ~Observer() {};
};

#endif //OBSERVER_H
