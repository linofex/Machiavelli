#ifndef MACHIAVELLI_H
#define MACHIAVELLI_H

/* Questa classe realizza il gioco di carte Machiavelli (le regole si possono 
trovare nel README.md. La classe e' formata dagli ingredienti che servono per 
giocare. Il metodo Game() e' la partita vera e propria.

In questa classe l'owernship é interna, essa alloca e dealloca i giocatori internamente,
l'utente non fa niente*/


#include <vector>
#include "Deck.h"
#include "Table.h"
#include "PlayerBase.h"
#include "PlayerHuman.h"
#include "Card.h" 


class Machiavelli{
	friend class MachiavelliTest;
	private:
		std::vector<PlayerBase*> players;
		Deck deck;
		Table table;
		
		// Metodi privati che servono per la verifica della mossa
		bool CheckMove();
		bool IsTris(const std::vector<Card>& cards ) const ;
		bool IsStraight(const std::vector<Card>& cards ) const;
	public:
		// Costruttore che inizializza il gioco
		Machiavelli(const std::vector<PlayerBase*>& players_,const Deck& deck_, const Table& table_);
		Machiavelli(const Deck& deck_, const Table& table_);
		// Metodo che distribuisce le carte
		void DealCards();
		
		// Metodo che esegue la mossa, prendi in input il giocatore i-esimo
		bool Move(const int i);
		
		// Metodo che esegue il gioco.
		void Game();
		
		~Machiavelli();
};

// Funzioni esterne per alleggerire la lettura del codice
void PrintOp();
void PrintOp1();
int ChooseNum();
#endif
