#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include "WISHLIST.h"
#include "COLLECTION.h"
#include "FUNCTIONS.h"
#include "REC.h"
#include "REGISTER.h"
#include "LOGIN.h"
#include "GLOBALVAR.h"
#include "/usr/local/cs/cs251/react.h"

int main(int argc, char **argv) {
  react = (argc > 1);
  read_text_data();

  bool just_starting = react ? _read_event_info() : true;
  while(1) {
	ifstream fs1(just_starting ? "initial_state" : "curr_state");
	State state(fs1);
	fs1.close();

	string input;
	if (just_starting) just_starting = false;
	else if (!react) getline(cin, input);

	ifstream fs2("incoming_text");
	state.update(input, fs2);

	ofstream fs3("outgoing_text"), fs4(react ? "end_state" : "curr_state");
	display(state, react ? fs3 : cout);
	state.write_to(fs4);

	if (react) {
  	_write_react_yaml();
  	break;
	}
  }
}