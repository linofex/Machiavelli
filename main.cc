#include "Machiavelli.h"

int main(){
	Deck deck;
	if(!deck.Pass()){
		return 1;
	}
	Table table;
	Machiavelli game(deck, table);
	std::cout << "\033[2J\033[1;1H";	
	game.Game();
	return 0;
}

