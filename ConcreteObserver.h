//
// Created by Riccardo on 25/02/2025.
//

#ifndef CONCRETEOBSERVER_H
#define CONCRETEOBSERVER_H
#include <string>
#include "Observer.h"

using namespace std;

class ConcreteObserver: public Observer {
    private:
    int count;
    public:
    ConcreteObserver() {count = 0;};
    ~ConcreteObserver() {};
    void update(bool a,const string& n) override;
};



#endif //CONCRETEOBSERVER_H
