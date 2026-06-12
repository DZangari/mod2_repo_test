#include <gtest/gtest.h>
#include "shopping_cart.h"

// ESEMPIO PROFESSORE:
TEST(ShoppingCartTest, StartsEmptyAndAddsSuccessfully) {
    ShoppingCart cart;
    EXPECT_EQ(cart.GetItemCount(), 0);
    EXPECT_EQ(cart.GetTotalCents(), 0);
    
    cart.AddItem("Mela", 150); // 1.50 euro
    EXPECT_EQ(cart.GetItemCount(), 1);
    EXPECT_EQ(cart.GetTotalCents(), 150);
}

// TODO STUDENTE 1: Aggiungi tre prodotti diversi al carrello.
// Usa EXPECT_EQ per verificare il conteggio totale e il prezzo totale.
// Usa messaggi personalizzati << se l'asserzione fallisce.
TEST(ShoppingCartTest, CalculatesTotalForMultipleItems) {
    // IL TUO CODICE QUI    
    ShoppingCart cart;
    cart.AddItem("Mela", 150); // 1.50 euro 
    cart.AddItem("Banana", 100); // 1.00 euro
    cart.AddItem("Arancia", 200); // 2.00 euro
    EXPECT_EQ(cart.GetItemCount(), 3) <<"Il conteggio degli articoli dovrebbe essere 3 dopo aver aggiunto tre prodotti";
    EXPECT_EQ(cart.GetTotalCents(), 450) <<"Il totale in centesimi dovrebbe essere 450 dopo aver aggiunto tre prodotti (150 + 100 + 200)";
}

// TODO STUDENTE 2: Testa l'estrazione di un prodotto esistente.
// Ricorda di controllare che il puntatore restituito da ExtractItem NON sia nullptr 
// usando ASSERT_NE prima di verificarne il nome e il prezzo.
// Dopo averlo estratto, verifica che il totale e il conteggio del carrello siano diminuiti.
// Ricordati di fare delete del puntatore estratto!
TEST(ShoppingCartTest, ExtractsExistingItemCorrectly) {
    // IL TUO CODICE QUI
    ShoppingCart cart;
    cart.AddItem("Mela", 150); // 1.50 euro
    Item* item = cart.ExtractItem("Mela");
    ASSERT_NE(item, nullptr) << "L'estrazione di un prodotto esistente non deve restituire nullptr";
    EXPECT_EQ(item->name, "Mela") << "Il nome del prodotto estratto dovrebbe essere 'Mela'";
    EXPECT_EQ(item->price_cents, 150) << "Il prezzo del prodotto estratto dovrebbe essere 150 centesimi";
    delete item; // Clean-up dopo il test
    EXPECT_EQ(cart.GetItemCount(), 0) <<"Il conteggio degli articoli dovrebbe essere 0 dopo aver estratto l'unico prodotto presente";
    EXPECT_EQ(cart.GetTotalCents(), 0) <<"Il totale in centesimi dovrebbe essere 0 dopo aver estratto l'unico prodotto presente";
}

// TODO STUDENTE 3: Testa l'estrazione di un prodotto NON esistente.
// Verifica che ExtractItem restituisca nullptr.
TEST(ShoppingCartTest, ExtractNonExistingItemReturnsNull) {
    // IL TUO CODICE QUI
    ShoppingCart cart;
    cart.AddItem("Mela", 150); // 1.50 euro
    Item* item = cart.ExtractItem("NonEsistente"); // Prova ad estrarre un prodotto che non è stato aggiunto
    EXPECT_EQ(item, nullptr) << "L'estrazione di un prodotto non esistente dovrebbe restituire nullptr";
}