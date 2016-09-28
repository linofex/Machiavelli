#include "Deck.h"
#include <algorithm>
#include <ctime>        // per time()
#include <cstdlib>      // persrand

Deck::Deck():pass(true){ 										  
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
		if(card.Exist()){
			deck.push_back(card);
		}
		else{
			std::cout << "Carta "<< card<< " non inserita nel mazzo\n";
		}
	}
}

Deck::Deck(const std::string& deck_):pass(true){ 										  
	std::ifstream is(deck_.c_str());
	if(!is.good()){
		std::cerr << "ERROR! Impossibile trovare il mazzo " << deck_ << std::endl;
		std::cerr << "Il gioco non puo' andare avanti!\n";
		pass = false;
		return;
	}
	std::string value;
	std::string suit;
	while(is >> value >> suit){
		Card card(value, suit);
		if(card.Exist()){
			deck.push_back(card);
		}
		else{
			std::cout << "Carta "<< card<< " non inserita nel mazzo\n";
		}
	}
}


void Deck::Shuffle(){
	std::srand ((std::time(0)));
	random_shuffle(deck.begin(), deck.end());
}
	
bool Deck::Empty () const{
	return deck.size() == 0;
}



