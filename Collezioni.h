//
// Created by Riccardo on 20/02/2025.
//

#ifndef COLLEZIONI_H
#define COLLEZIONI_H
#include <list>
#include <string>
#include "Observer.h"

using namespace std;

class Note;

class Collezioni: public Subject {
    private:
    list<Note*> notes;
    list<Observer*> observers;
    protected:
    string name;
    public:

    Collezioni(const string& n);
    virtual ~Collezioni();

    string getName() const {
        return name;
    }
    list<Note*> getNotes() const {
        return notes;
    }

    virtual void addNote(Note *n);
    virtual void removeNote(Note *n);

    int getNumNotes() const {
        return notes.size();
    }

    void printCollezione() const;
    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notifyObserver(bool a,const string& n) override;
};

#endif //COLLEZIONI_H
