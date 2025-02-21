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

class Subject {
    public:
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObserver(const string& c) = 0;
    virtual ~Subject() {};
};

#endif //OBSERVER_H
