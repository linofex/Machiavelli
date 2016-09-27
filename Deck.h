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
	private:
		std::vector<Card> deck;
		bool pass;
	public:
		// Costruttore che legge il mazzo di default 
		Deck():pass(true){ 										  
			std::ifstream is("./Deck.txt");
			if(!is.good()){
				std::cerr << "ERROR! Impossibile trovare il mazzo Deck.txt\n";
				std::cerr << "Il gioco non puo' andare avanti!\n";
				pass = false;
				return;
			}
			std::string value;
			std::string suit;
			while(is >> value >> suit){
				Card card(value, suit);
				deck.push_back(card);
			}
		}
		
		// Costruttore che legge un mazzo personale
		Deck(const std::string& deck_):pass(true){ 										  
			std::ifstream is(deck_.c_str());
			if(!is.good()){
				std::cerr << "ERROR! Impossibile trovare il mazzo Deck.txt";
				std::cerr << "Il gioco non puo' andare avanti!\n";
				pass = false;
				return;
			}
			std::string value;
			std::string suit;
			while(is >> value >> suit){
				Card card(value, suit);
				deck.push_back(card);
			}
		}
		
		// Questo metodo mescola il mazzo 
		void Shuffle();	
		
		// Questo metodo toglie una carta dal mazzo e la ritorna 
		inline Card GetCard (){ 
			Card card = deck.back();
			deck.pop_back();
			return card;
		}
		inline bool Pass(){
			return pass;
		}
		// Questo metodo controlla se il mazzo é vuoto
		bool Empty() const;
};

#endif
