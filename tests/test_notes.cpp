//
// Created by Riccardo on 19/11/2025.
//

#include <gtest/gtest.h>
#include "Note.h"
#include "Collezioni.h"
#include "Importanti.h"
#include "ConcreteObserver.h"

// Test per la classe Note
TEST(NoteTest, SetTitleAndText) {
    Collezioni c("Work");
    Note n("Titolo", "Testo", &c);

    n.setTitle("Nuovo Titolo");
    n.setText("Nuovo Testo");

    EXPECT_EQ(n.getTitle(), "Nuovo Titolo");
    EXPECT_EQ(n.getText(), "Nuovo Testo");
}

TEST(NoteTest, LockedNoteCannotBeModified) {
    Collezioni c("Work");
    Note n("Titolo", "Testo", &c);
    n.setLocked(true);

    n.setTitle("Prova");
    n.setText("Prova");

    EXPECT_EQ(n.getTitle(), "Titolo");
    EXPECT_EQ(n.getText(), "Testo");
}

// Test per Collezioni
TEST(CollezioneTest, AddAndRemoveNote) {
    Collezioni c("Work");
    Note n1("T1","Txt1",&c);
    Note n2("T2","Txt2",&c);

    EXPECT_EQ(c.getNumNotes(), 2);

    c.removeNote(&n2);
    EXPECT_EQ(c.getNumNotes(), 1);

    c.removeNote(&n2);
    EXPECT_EQ(c.getNumNotes(), 0);
}

// Test per Importanti
TEST(ImportantiTest, AddImportantNote) {
    Importanti imp("Importanti");
    Note n("Titolo", "Testo");
    imp.addNote(&n);

    EXPECT_TRUE(n.getImportance());
    EXPECT_EQ(imp.getNumImportantNotes(), 1);

    imp.removeNote(&n);
    EXPECT_FALSE(n.getImportance());
    EXPECT_EQ(imp.getNumImportantNotes(), 0);
}

// Test Observer
TEST(ObserverTest, CountUpdates) {
    Collezioni c("Work");
    ConcreteObserver obs;
    c.addObserver(&obs);

    Note n1("T1","Txt1",&c);
    EXPECT_EQ(obs.getCount(), 1);

    Note n2("T2","Txt2",&c);
    EXPECT_EQ(obs.getCount(), 2);

    c.removeNote(&n1);
    EXPECT_EQ(obs.getCount(), 1);
}
