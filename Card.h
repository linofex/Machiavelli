#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include <sstream>
class Card{
	private:
		std::string value;
		std::string suit;
		int val;
	public:
		Card(const std::string& value_, const std::string& suit_):
			value(value_), suit(suit_){
			if (value.compare("A") == 0) val = 1;
			else if (value.compare("K") == 0) val = 13;
			else if (value.compare("Q") == 0) val = 12;
			else if (value.compare("J") == 0) val = 11;
			else {
				std::stringstream stoi(value);
				stoi >> val;
			}
		}
		inline std::string GetValue() const {return value;}
		inline std::string GetSuit() const {return suit;}
		inline int GetIntValue() const {return val;}
		static bool CompareValue(const Card& left, const Card& right);
		static bool CompareSuit(const Card& left, const Card& right);
		
};

bool operator==(const Card& left, const Card& right);
std::ostream& operator<<(std::ostream& out, const Card& card);
bool operator<(const Card& left, const Card& right);
#endif
