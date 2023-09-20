#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include"/usr/local/cs/cs251/react.h"
#include "WISHLIST.h"
#include "COLLECTION.h"
#include "FUNCTIONS.h"
#include "REC.h"
#include "REGISTER.h"
#include "LOGIN.h"
#include "GLOBALVAR.h"

void read_text_data() {
  ifstream fs("ai.txt");
  string comment;
  for (int i = 0; i < 39; ++i) {
	getline(fs, text[i], '#');
	text[i].pop_back();
	getline(fs, comment);
  }
}

void display(const State &state, ostream &os) {
  int n = state.get_screen_num();
  cerr << n << endl;
  if (react) {
    _add_yaml("mwt1.yaml", {{"prompt_index", prompt_index},
		             {"input_index", input_index}});
    os << "~~~~~~~~~~~~~~~~~~~~~~~~~";  // 25 bytes of filler
  }// else os << "\033c";

  os << "                   "
     << "[screen " << n << "]" << endl
     << text[n];

     int screen_num = state.get_screen_num();
     /*
  os << "                   "
     << "[screen " << screen_num << "]" << endl
     << text[screen_num - 1];
*/
  
   

   if(screen_num == 11) {
    state.collection.print_records(os);
  }
  else if(screen_num == 13){
    state.wishlist.print_wishes(os);
  } 
  else if(screen_num == 33) {
     state.rec.print_rec(os);
  }
  
  if (react) os << '\0'; // Add null byte if running in react mode
  else if (n >= limit) exit(0);
}