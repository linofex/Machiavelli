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
		/* Default constructor fill the deck reading cards from the file deck.txt */
		Deck(){ 										  
			std::ifstream is("./deck.txt");
			if(!is.good()){
				std::cerr < "ERROR! Can not open the file.\n";
				return;
			}
			std::string card;
			while(is >> card){
				deck.push_back(card);
			}
		}
		
		/* This method shuffles the deck */
		void Mescola();	
		/* This method returns a card to a player */
		inline std::string GetCard(){ 
			std::string card = deck[deck.size()-1];
			deck.pop_back();
			return card;
		}
		/* This method control if the deck is empty */
		bool Empty();
};

#endif
