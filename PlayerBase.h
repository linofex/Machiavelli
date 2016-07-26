#ifndef PLAYERBASE_H
#define PLAYERBASE_H

#include <string>
#include <vector>
#include <sstream>

class PlayerBase{
	private:
		std::string name;
		std::vector<std::string> cards;
		static int n_player;
		
	public:
		PlayerBase(){
			std::string name_;
			std::stringstream int2string;
			int2string << n_players;
			name_ = int2string.str();
			name = name_;
			n_players ++;
		}
		
		/* Constructor */
		PlayerBase(const std::string& name_):name(name_){n_players ++;}
		
		/* This method add a card, picked from the deck (in Machiavelli's class)*/
		virtual void AddCard(const std::string& card);
		
		/* This method prints the cards */
		virtual void SeeCards();
		
		/* This method do the move */
		virtual void Move() = 0;
		
		/* This method look if the player hasn't got cards */
		virtual bool Empty();
		
		/* Destructor */
		// virtual ~PlayerBase(){}
};

#endif
