#include "Deck.h"
#include <algorithm>
#include <ctime>        // per time()
#include <cstdlib>      // persrand

void Deck::Shuffle(){
	std::srand ((std::time(0)));
	random_shuffle(deck.begin(), deck.end());
}
	
bool Deck::Empty () const{
	return deck.size() == 0;
}



