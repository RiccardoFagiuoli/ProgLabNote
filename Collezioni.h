//
// Created by Riccardo on 20/02/2025.
//

#ifndef COLLEZIONI_H
#define COLLEZIONI_H
#include <list>
#include <string>
#include "Observer.h"
#include "Note.h"

using namespace std;

class Note;

class Collezioni: public Subject {
    private:
    string name;
    list<Note*> notes;
    list<Observer*> observers;

    public:
    Collezioni(const string& n);
    ~Collezioni();

    string getName() const {
        return name;
    }

    void addNote(Note *n);

    void removeNote(Note *n);

    void printNotes() const;

    int getNumNotes() const {
        return notes.size();
    }

    //getNote list
    list<Note*> getNotes() const {
        return notes;
    }

    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notifyObserver() override;


};

#endif //COLLEZIONI_H
