#include "Machiavelli.h"

int main(){
	Deck deck;
	if(!deck.Pass()){
		return 0;
	}
	Table table;
	Machiavelli Game(deck, table);
	std::cout << "\033[2J\033[1;1H";	
	Game.Game();
}

