a.out:  LOGIN.o REGISTER.o STATE.o WISHLIST.o REC.o FUNCTIONS.o COLLECTION.o GLOBALVAR.o
	g++ -Wall LOGIN.o REGISTER.o STATE.o WISHLIST.o REC.o FUNCTIONS.o COLLECTION.o GLOBALVAR.o MWTDriver.o /usr/local/cs/cs251/react.o -lcurl -o a.out
MWTDriver.o: MWTDriver.cpp
	g++ -Wall -c MWTDriver.cpp
REGISTER.o:  REGISTER.cpp REGISTER.h
	g++ -Wall -c REGISTER.cpp
LOGIN.o:  LOGIN.cpp LOGIN.h
	g++ -Wall -c LOGIN.cpp
WISHLIST.o: WISHLIST.cpp WISHLIST.h
	g++ -Wall -c WISHLIST.cpp
REC.o:  REC.cpp REC.h
	g++ -Wall -c REC.cpp
FUNCTIONS.o: FUNCTIONS.cpp FUNCTIONS.h
	g++ -Wall -c FUNCTIONS.cpp
COLLECTION.o: COLLECTION.cpp COLLECTION.h
	g++ -Wall -c COLLECTION.cpp
GLOBALVAR.o: GLOBALVAR.cpp GLOBALVAR.h
	g++ -Wall -c GLOBALVAR.cpp
STATE.o:  STATE.cpp STATE.h
	g++ -Wall -c STATE.cpp


