#include "Machiavelli.h"
#include "PlayerHuman.h"

int main(){
	Deck deck("./Deck_test.txt");
	if(!deck.Pass()){
		return 0;
	}
	std::vector<PlayerBase*> players;
	players.push_back(new PlayerHuman("Ale"));
	players.push_back(new PlayerHuman("Sere"));
	std::cout << "\033[2J\033[1;1H";	
	Table table;
	Machiavelli Game(players, deck, table);
	Game.Game();
	delete players[0];
	delete players[1];
}

