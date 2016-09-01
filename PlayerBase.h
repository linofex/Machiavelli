#ifndef PLAYERBASE_H
#define PLAYERBASE_H

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
			std::string name_;
			std::stringstream int2string;
			int2string << n_player;
			name_ = int2string.str();
			name = name_;
			n_player++;
		}
		
		/* Constructor */
		PlayerBase(const std::string& name_):name(name_){n_player ++;}
		
		/* This method add a card, picked from the deck (in Machiavelli's class)*/
		virtual void AddCard(const Card& card);
		
		/* This method remove a card*/
		virtual void RemoveCard(const Card& card);

		/* This method sort the cards*/
		virtual void SortCard();

		/* This method return the name of the player */
		virtual std::string GetName() const;
		
		/* This method set a deck of cards*/
		virtual void SetCards(const std::vector<Card>& cards);
		
		/*This method return the deck of cards*/
		virtual std::vector<Card> GetCards() const;
		
		/* This method prints the cards */
		virtual void SeeCards() const;
				
		/* This method look if the player hasn't got cards */
		virtual bool Empty() const;
		
		/* This method search if you have the card */
		virtual bool FindCard(const Card& card) const;
		/* Destructor */
		// virtual ~PlayerBase(){}
};

#endif
