#include "Card.h"

Card::Card(const std::string& value_, const std::string& suit_):
	value(value_), suit(suit_){			
	if (value == "A") val = 1;
	else if (value == "K") val = 13;
	else if (value == "Q") val = 12;
	else if (value == "J") val = 11;
	else {
		// Conversione da string a int (c++11 ha stoi), 
		// ma credo ci sia un bug
		std::stringstream stoi(value);
		stoi >> val;
	}
	if (val < 1 || val > 14 || (suit != "c" && suit != "p" && 
				suit != "q" && suit != "f" )) {
		std::cout << "La carta " << value << suit << " non esiste." << std::endl;
		val = -1;
		}
}

bool Card::CompareValue(const Card& left, const Card& right) {
	return (left.GetValue() == right.GetValue());
}

bool Card::CompareSuit(const Card& left, const Card& right){
	return(left.GetSuit() == right.GetSuit());
}

void Card::SetIntValue(const int& val_){
	val = val_;
}

bool Card::Exist() const {
	if (this->val == -1) {
		return false;
	}
	return true;
}

bool operator==(const Card& left, const Card& right){
	if(Card::CompareValue(left, right) && Card::CompareSuit(left, right)) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Card& card){
	std::string utf8;
	if(card.GetSuit() == "f"){ utf8 = "\u2663";}
	else if(card.GetSuit() == "p") {utf8 = "\u2660";}
	else if(card.GetSuit() == "c") {utf8 = "\u2665";}
	else if(card.GetSuit() == "q"){utf8 = "\u2666";}
	else {utf8 = card.GetSuit();}
	out << card.GetValue() << utf8 << " ";
	return out;
}


bool operator<(const Card& left, const Card& right){
	if(left.GetIntValue() == right.GetIntValue()){
		return (left.GetSuit() < right.GetSuit());
	}
	else{
		return left.GetIntValue() < right.GetIntValue();
	}
}



