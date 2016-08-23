#include "Card.h"

bool Card::CompareValue(const Card& left, const Card& right) {
	if(left.GetValue().compare(right.GetValue()) == 0) 
		return 1;
return 0;
}

bool Card::CompareSuit(const Card& left, const Card& right){
	if(left.GetSuit().compare(right.GetSuit()) == 0) 
		return 1;
return 0;
}

bool operator==(const Card& left, const Card& right){
	if(left.GetValue().compare(right.GetValue()) == 0 &&
	   left.GetSuit().compare(right.GetSuit()) == 0) return 1;
	return 0;
}

std::ostream& operator<<(std::ostream& out, const Card& card){
	out << "Card: " << card.GetValue()<< " " << card.GetSuit() << std::endl;
	return out;
}


bool operator<(const Card& left, const Card& right){
	return left.GetIntValue() < right.GetIntValue();
}



