#ifndef MACHIAVELLI_H
#define MACHIAVELLI_H

#include <vector>
#include <string>
#include "Deck.h"
#include "Table.h"
#include "PlayerBase.h" 

class Machiavelli{
	private:
		std::vector<PlayerBase*> players;
		Deck deck;
		Table table;
	public:
		Machiavelli(const std::vector<PlayerBase*>& players_):players(players_){}
		void DealCards();
		bool CheckMove(const std::string& mosse);
};

#endif
