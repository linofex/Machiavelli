#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "PlayerBase.h"

class PlayerBase;
class Deck{
	private:
		std::vector<std::string> deck;
	public:
		/* Default constructor fills the deck reading cards from the file deck.txt */
		Deck(){ 										  
			std::ifstream is("./deck.txt");
			if(!is.good()){
				std::cerr << "ERROR! Can not open the file.\n";
				return;
			}
			std::string card;
			while(is >> card){
				deck.push_back(card);
			}
		}
		/* Constructor fills the deck reading a different default deck file */
		Deck(const std::string& deck){ 										  
			std::ifstream is(deck.c_str());
			if(!is.good()){
				std::cerr << "ERROR! Can not open the file.\n";
				return;
			}
			std::string card;
			while(is >> card){
				deck.push_back(card);
			}
		}
		
		/* This method shuffles the deck */
		void Shuffle();	
		/* This method returns a card to a player */
		inline std::string GetCard () { 
			std::string card = deck.back();
			deck.pop_back();
			return card;
		}
		/* This method control if the deck is empty */
		bool Empty() const;
};

#endif
