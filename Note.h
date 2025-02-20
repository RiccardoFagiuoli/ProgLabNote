//
// Created by Riccardo on 20/02/2025.
//

#ifndef NOTE_H
#define NOTE_H
#include <list>
#include "Observer.h"
#include <string>

using namespace std;

class Note: public Subject {
    private:
        string title;
        string text;
        bool locked;
        string collection;
        bool important;
        list<Observer*> observers;

    public:
        Note(string tl, string txt, string c, bool lck=false, bool i=false);
        ~Note();

        string getTitle() const;
        string getText() const;
        bool isLocked() const;
        string getCollection() const;
        bool isImportant() const;

        void setTitle(string tl);
        void setText(string txt);
        void setLocked(bool lck);
        void setCollection(string c);
        void setImportant(bool i);

        void printNote() const;

        void addObserver(Observer *o);
        void removeObserver(Observer *o);
        void notifyObserver();
};
#endif //NOTE_H
