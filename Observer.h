//
// Created by Riccardo on 20/02/2025.
//

#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
    public:
        virtual void update() = 0;
        virtual ~Observer() {};
};

class Subject {
    public:
    virtual ~Subject() {}

    virtual void addObserver(Observer* o) = 0;

    virtual void removeObserver(Observer* o) = 0;

    virtual void notifyObservers() = 0;
};

#endif //OBSERVER_H
