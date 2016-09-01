#include "Machiavelli.h"

int main(){
	Deck deck;
	Table table;
	std::vector<PlayerBase*> players;
	PlayerBase* p1 = new PlayerBase();
	PlayerBase* p2 = new PlayerBase();
	players.push_back(p1);
	players.push_back(p2);
	Machiavelli Game(players, deck, table);
	Game.Game();
	delete p1;
	delete p2;
}

