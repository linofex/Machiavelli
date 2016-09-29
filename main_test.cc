#include "Machiavelli.h"

int main(){
	Deck deck("./Deck_test.txt");
	if(!deck.Pass()){
		return 0;
	}
	std::cout << "\033[2J\033[1;1H";	
	Table table;
	Machiavelli Game(deck, table);
	Game.Game();
	return 0;
}

