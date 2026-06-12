#include <gtest/gtest.h>
#include "mock_database.h"

// TODO STUDENTE 0: Crea la Test Fixture "DatabaseTest".
class DatabaseTest : public testing::Test {
protected:
    MockDatabase db;

    void SetUp() override {
        // Prima di ogni test, connettiamo il database e aggiungiamo alcuni utenti di test.
        db.Connect();
        db.InsertUser("admin", 1, "adminpass");
        db.InsertUser("guest", 2, "guestpass");

    }

    void TearDown() override {
        // Dopo ogni test, disconnettiamo il database per pulire lo stato.
        db.Disconnect();
    }
};


// TODO STUDENTE 1: Usando TEST_F, scrivi un test che verifichi l'utente "admin".
TEST_F(DatabaseTest, RetrievesExistingAdmin) {
    UserRecord* admin = db.GetUser("admin");
    ASSERT_NE(admin, nullptr) << "Il database dovrebbe restituire un record valido per l'utente 'admin'";
    EXPECT_EQ(admin->id, 1) << "L'ID dell'utente 'admin' dovrebbe essere 1";
    EXPECT_EQ(admin->role, "adminpass") << "Il ruolo dell'utente 'admin' dovrebbe essere 'adminpass'";
}

// TODO STUDENTE 2: Usando TEST_F, scrivi un test che verifichi l'utente "guest".
TEST_F(DatabaseTest, RetrievesExistingGuest) {  
    UserRecord* guest = db.GetUser("guest");
    ASSERT_NE(guest, nullptr) << "Il database dovrebbe restituire un record valido per l'utente 'guest'";
    EXPECT_EQ(guest->id, 2) << "L'ID dell'utente 'guest' dovrebbe essere 2";
    EXPECT_EQ(guest->role, "guestpass") << "Il ruolo dell'utente 'guest' dovrebbe essere 'guestpass'";
}

// TODO STUDENTE 3: Usando TEST_F, scrivi un test che prova a recuperare un utente 
// non esistente (es. "hacker") e verifica che il risultato sia nullptr.
TEST_F(DatabaseTest, UnknownUserReturnsNull) {
    UserRecord* hacker = db.GetUser("hacker");
    EXPECT_EQ(hacker, nullptr) << "Il database dovrebbe restituire nullptr per un utente non esistente come 'hacker'";
}

// TODO STUDENTE 4: Usando TEST_F, disconnetti esplicitamente il DB all'interno 
// del test (chiamando Disconnect()) e verifica che chiamare GetUser("admin") 
// restituisca nullptr (il DB non deve rispondere se non e' connesso).
TEST_F(DatabaseTest, GetUserFailsWhenDisconnected) {
    db.Disconnect();
    UserRecord* admin = db.GetUser("admin");
    EXPECT_EQ(admin, nullptr) << "Il database dovrebbe restituire nullptr per l'utente 'admin' quando non è connesso";
}