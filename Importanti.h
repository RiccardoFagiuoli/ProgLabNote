//
// Created by Riccardo on 24/02/2025.
//

#ifndef IMPORTANTI_H
#define IMPORTANTI_H
#include "Collezioni.h"


class Importanti: public Collezioni{
    private:
    list<Note*> importantNotes;
    public:
    Importanti(const string& n);
    //distruttore
    ~Importanti() {
        /*
        for (auto it: importantNotes) {
            removeNote(it);
        }
        */
    }
    //getter e setter
    Importanti* getImportant();

    void printImportantNotes() const;
    void addImportant(Note * n);
    void removeImportant(Note * n);

};



#endif //IMPORTANTI_H
