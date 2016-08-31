#ifndef MACHIAVELLI_H
#define MACHIAVELLI_H

#include <vector>
#include "Deck.h"
#include "Table.h"
#include "PlayerBase.h"
#include "Card.h" 

class Machiavelli{
	private:
		std::vector<PlayerBase*> players;
		Deck deck;
		Table table;
		bool CheckMove(const t_map& table)const;
		bool IsTris(const std::vector<Card>& cards ) const ;
		bool IsStraight(const std::vector<Card>& cards ) const;
	public:
		Machiavelli(const std::vector<PlayerBase*>& players_,const Deck& deck_, const Table& table_ ):players(players_), deck(deck_), table(table_){}
		void DealCards();
		//bool CheckMove(const Table& table);
		bool Move(PlayerBase* player_);
		void Game();
};
//Machiavelli1
void PrintOp();
void PrintOp1();
#endif
