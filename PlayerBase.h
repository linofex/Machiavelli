#ifndef PLAYERBASE_H
#define PLAYERBASE_H

/* Questa classe realizza un giocatore base, cioe' una classe astratta che e' padre
di una classe giocatore umano e una classe giocatore CPU. Un giocatore ha un nome
e le carte nella propria mano. E' possibile inserire, rimuovere, mesolarle, vederle */

#include <string>
#include <vector>
#include <sstream>
#include "Card.h"

class PlayerBase{
	private:
		std::string name;
		std::vector<Card> cards;
		static int n_player;
		
	public:
		PlayerBase(){
			//std::string name_;
			std::stringstream int2string;
			int2string << n_player;
			//name_ = int2string.str();
			name = int2string.str();
			n_player++;
		}
		
		/* Costruttore */
		PlayerBase(const std::string& name_):name(name_){n_player ++;}
		
		/* Metodo che aggiunge una carta al giocatore*/
		virtual void AddCard(const Card& card);
		
		/* Metodo che rimuove un carta */
		virtual void RemoveCard(const Card& card);

		/* Metodo che ordina le carte in mano */
		virtual void SortCard();

		/* This method return the name of the player */
		virtual std::string GetName() const;
		
		/* Metodo che inserisce un insieme di carte preciso */
		virtual void SetCards(const std::vector<Card>& cards);
		
		/* Metodo che ritorna il mazzetto di carte */
		virtual const std::vector<Card>& GetCards() const;
		
		/* Metodo che stampa le carte */
		virtual void SeeCards() const;
				
		/* Metodo che controlla se il giocatore ha ancora carte */
		virtual bool Empty() const;
		
		/*  Metodo che cerca una carta */
		virtual bool FindCard(const Card& card) const;
		/* Distruttore */
		// virtual ~PlayerBase(){}
};

#endif
