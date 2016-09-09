CC=g++ # compilatore
LD=g++ # linker


#lista degli oggetti
Card.o: Card.cc
	${CC}-c Card.cc

Deck.o: Deck.cc Card.h PlayerBase.h
	${CC} -c Deck.cc

Machiavelli.o: Machiavelli.cc Deck.h Card.h PlayerBase.h PlayerHuman.h Table.h
	${CC} -c Machiavelli.cc

Table.o: Table.cc Card.h
	${CC} -c Table.cc

PlayerBase.o: PlayerBase.cc Card.h
	$[CC] -c PlayerBase.cc

main.o: main.cc Machiavelli.h PlayerHuman.h
	${CC} -c main.cc
	


machiavelli: Deck.o Card.o Machiavelli.o Table.o PlayerBase.cc main.o
	${LD} -o machiavelli Deck.o Card.o Machiavelli.o Table.o PlayerBase.cc main.o
	
clean :
	rm -f *.o machiavelli
