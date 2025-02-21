//
// Created by Riccardo on 20/02/2025.
//

#ifndef COLLEZIONI_H
#define COLLEZIONI_H
#include <list>
#include <memory>
#include <string>
#include "Note.h"
#include "Observer.h"
# include "NumNote.h"

using namespace std;

class Collezioni: public Subject {
    private:
    string name;
    list<shared_ptr<Note>> notes;
    list<shared_ptr<Note>> importantNotes;
    list<Observer*> observers;

    public:
    Collezioni(const string& n);
    ~Collezioni();

    string getName() const {
        return name;
    }
    list<shared_ptr<Note>> getNote() {
        return notes;
    }
    list<shared_ptr<Note>> getImportantNote() {
        return importantNotes;
    }

    void addNote(const shared_ptr<Note>& n) {
        notes.push_back(n);
        if (n->isImportant()) {
            importantNotes.push_back(n);
        }
        notifyObserver(this->name);
    }
    void removeNote(shared_ptr<Note>& n) {
        if (!n->isLocked()) {
            notes.remove(n);
            if (n->isImportant()) {
                importantNotes.remove(n);
            }
            notifyObserver(this->name);
        }
    }

    void setImportant(shared_ptr<Note>& n) {
        if (!n->isLocked()) {
            if (!n->isImportant()) {
                n->setImportant(true);
                importantNotes.push_back(n);
            }
        }
    }

    void notImportant(shared_ptr<Note>& n) {
        if (!n->isLocked()) {
            if (n->isImportant()) {
                n->setImportant(false);
                importantNotes.remove(n);
            }
        }
    }

    void notifyObserver(const string& c) override;

    void addObserver(Observer* o) override{
        observers.push_back(o);
    }

    void removeObserver(Observer* o) override {
        observers.remove(o);
    }

    void printNotes() const;
    int getNumNotes() const {
        return notes.size();
    }




};

#endif //COLLEZIONI_H
