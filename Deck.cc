#include "Deck.h"
#include <algorithm>
#include <ctime>        // for time()
#include <cstdlib>      // std::rand, std::srand

void Deck::Shuffle(){
	std::srand (unsigned (std::time(0)));
	random_shuffle(deck.begin(), deck.end());
}
	
bool Deck::Empty () const{
	return deck.size() == 0;
}

//commento :)



