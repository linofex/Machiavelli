#ifndef DECK_H
#define DECK_H

/*Questa classe realizza un mazzo di carte da gioco francesi.
La presenza di due costruttori é dovuta al fatto che magari un utente vuole
giocare con delle carte che rispettino il solito formato di una carta, ma che 
hanno un design diverso, magari con i semi in altre lingue. */

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "PlayerBase.h"
#include "Card.h"

class Deck{
	friend class TestDeck;
	private:
		std::vector<Card> deck;
		bool pass;
	public:
		// Costruttore che legge il mazzo di default 
		Deck();
		
		// Costruttore che legge un mazzo personale
		Deck(const std::string& deck_);
		
		// Questo metodo mescola il mazzo 
		void Shuffle();	
		
		// Questo metodo toglie una carta dal mazzo e la ritorna 
		inline Card GetCard (){ 
			Card card = deck.back();
			deck.pop_back();
			return card;
		}
		inline bool Pass() const{
			return pass;
		}
		// Questo metodo controlla se il mazzo é vuoto
		bool Empty() const;
		
};

#endif
