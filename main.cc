#include "Machiavelli.h"

int main(){
	Deck deck;
	Table table;
	std::vector<PlayerBase*> players;
	PlayerBase* p1 = new PlayerBase("Ale");
	PlayerBase* p2 = new PlayerBase("Ile");
	players.push_back(p1);
	players.push_back(p2); 
	Machiavelli Game(players, deck, table);
	Game.Game();
}

