#ifndef MACHIAVELLI_H
#define MACHIAVELLI_H

/* Questa classe realizza il gioco di carte Machiavelli (le regole si possono 
trovare nel README.md. La classe e' formata dagli ingredienti che servono per 
giocare. Il metodo Game() e' la partita vera e propria.*/


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
		
		// Metodi provati che servono per la verifica della mossa
		bool CheckMove(const t_map& table)const;
		bool IsTris(const std::vector<Card>& cards ) const ;
		bool IsStraight(const std::vector<Card>& cards ) const;
	public:
		// Costruttore che inizializza il gioco
		Machiavelli(const std::vector<PlayerBase*>& players_,const Deck& deck_, const Table& table_ ):
								players(players_), deck(deck_), table(table_){}
		
		// Metodo che distribuisce le carte
		void DealCards();
		
		// Metodo che esegue la mossa
		bool Move(PlayerBase* player_);
		
		// Metodo che esegue il gioco.
		void Game();
};
//Machiavelli1
void PrintOp();
void PrintOp1();
#endif
