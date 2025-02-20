//
// Created by Riccardo on 20/02/2025.
//

#ifndef NOTE_H
#define NOTE_H

#include <list>
#include <string>
#include "Observer.h"

using namespace std;

class Note: public Subject{
    private:
    string title;
    string text;
    bool locked;
    string collection;
    bool important;
    list<Observer*> observers;

    public:
    Note(const string& tl, const string& txt, const string& c, bool lck=false, bool i=false);
    ~Note();

    string getTitle() const {
        return title;
    }
    string getText() const {
        return text;
    }
    bool isLocked() const {
        return locked;
    }
    string getCollection() const {
        return collection;
    }
    bool isImportant() const {
        return important;
    }

    void setTitle(string tl) {
        title = tl;
    }
    void changeText(string txt) {
        if (!locked) {
            text = txt;
        }
    }
    void setLocked(bool lck) {
        locked = lck;
    }
    void setCollection(string c) {
        if (!locked) {
            collection = c;
        }
    }
    void setImportant(bool i) {
        if (!locked) {
            important = i;
        }
    }
    void delNote() {
        if (!locked) {
            delete this;
        }
    }

    void printNote() const;

    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notifyObserver() override;
};

#endif //NOTE_H
