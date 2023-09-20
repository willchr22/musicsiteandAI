#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include"/usr/local/cs/cs251/react.h"

using namespace std;
//        /usr/local/dept/bin/sd start
//        g++ -g -Wall loginai.o /usr/local/cs/cs251/react.o -lcurl
//
// global variables
string text[34];
//int screen_num = 0;
const int limit = 34;  // final screens
bool react = true;
const int input_index = 2, prompt_index = 25;

string user;
string pass;
string name;
string email;
string add;

vector<vector<double>> matrix
    {
        
    /*Will C*/    {4.5, 3.0, 5.0, 4.8, 5.0, 4.7, 4.2, 4.0, 3.7, 4.0, 2.2, 4.8, 5.0, 4.7, 4.8},
    /*Will A*/    {0.0, 2.3, 0.0, 3.9, 0.0, 3.7, 3.5, 3.6, 2.0, 4.0, 1.0, 0.0, 0.0, 0.0, 0.0},
    /*Ethan*/     {0.0, 3.1, 4.3, 4.7, 0.0, 4.2, 0.0, 2.9, 0.0, 2.7, 1.8, 0.0, 4.8, 0.0, 3.2},
    /*Peter*/     {0.0, 1.3, 0.0, 0.0, 0.0, 3.1, 3.8, 3.5, 4.3, 4.1, 2.4, 4.1, 4.8, 0.0, 0.0},
    /*Marcy*/     {4.9, 3.5, 0.0, 4.5, 0.0, 0.0, 4.0, 3.9, 3.7, 2.5, 2.3, 0.0, 3.7, 4.7, 5.0},
    /*Yoni*/      {0.0, 3.0, 5.0, 0.0, 0.0, 0.0, 4.6, 4.7, 4.3, 4.5, 4.1, 4.8, 4.5, 0.0, 3.9},
    /*Evan*/      {0.0, 2.7, 0.0, 0.0, 0.0, 0.0, 3.8, 4.3, 2.5, 4.5, 4.0, 0.0, 0.0, 0.0, 0.0}
    };

vector<string> titles {"Heroes - David Bowie", "Party in the USA - Miley Cyrus", "The Blacker the Berry - Kendrick Lamar", "1979 - The Smashing Pumpkins", "All My Friends - LCD Soundsystem", "Hollywood Baby - 100 Gecs", "Come Together - The Beatles", "Billie Jean - Michael Jackson", "Imagine - John Lennon", "Smells Like Teen Spirit - Nirvana", "Sweet Child O'Mine - Guns N' Roses", "What's Going On - Marvin Gaye", "White Ferrari - Frank Ocean", "Andromeda - Weyes Blood", "Motion Sickness - Phoebe Bridgers"};


class Collection {
protected:
    vector<string> items;

public:
    Collection(istream& is) {
        int i;
        string st;
        is >> i;
        is.get();
        for (int j = 1; j <= i; j++) {
            getline(is, st);
            add_item(st);
        }
    }

    void add_item(string item) {
        items.push_back(item);
    }

    void write_to(ostream& os) const {
        os << items.size() << endl;
        for (unsigned int i = 0; i < items.size(); i++) {
            os << items[i] << endl;
        }
    }
    bool remove_item(string item) {
        for (vector<string>::iterator it = items.begin(); it != items.end(); ++it) {
            if (*it == item) {
                items.erase(it);
                return true;
            }
        }
        return false;
    }

    void print_records(ostream& os) const {
      os << "Number of items in collection: " << items.size() << endl;
        for (int i = items.size() - 1; i >= 0; i--) {
            os << items[i] << endl;
        }
    }
};

class Wishlist {
private:
    vector<string> wishes;
public:
    Wishlist(istream& is) {
        int j;
        string str;
        is >> j;
        is.get();
        for (int i = 1; i <= j; i++) {
            getline(is, str);
            add_wish(str);
        }
    }
    void add_wish(string wish) {
        wishes.push_back(wish);
    }
    void write_to(ostream& osi) const {
        osi << wishes.size() << endl;
        for (unsigned int i = 0; i < wishes.size(); i++) {
            osi << wishes[i] << endl;
        }
    }
    void print_wishes(ostream& os) const {
      os << "Number of items in wishlist: " << wishes.size() << endl;
        for (int i = wishes.size() - 1; i >= 0; i--) {
            os << wishes[i] << endl;
        }
    }
    bool remove_wish(string wish) {
        for (vector<string>::iterator it = wishes.begin(); it != wishes.end(); ++it) {
            if (*it == wish) {
                wishes.erase(it);
                return true;
            }
        }
        return false;
    }
};


class Register {
private:
    string accountName;
    string accountUsername;
    string accountPassword;
    string accountEmail;

public:
    void setAccountName(string name) {
        accountName = name;
    }

    void setAccountUsername(string username) {
        accountUsername = username;
        ofstream outfile;
        outfile.open("users.txt", ios_base::app);
        outfile << accountUsername << " ";
        outfile.close();
    }

    void setAccountPassword(string password) {
        accountPassword = password;
        ofstream outfile;
        outfile.open("users.txt", ios_base::app);
        outfile << accountPassword << endl;
        outfile.close();
    }

    void setAccountEmail(string email) {
        accountEmail = email;
    }

    string getAccountName() const {
        return accountName;
    }

    string getAccountUsername() const {
        return accountUsername;
    }

    string getAccountPassword() const {
        return accountPassword;
    }

    string getAccountEmail() const {
        return accountEmail;
    }
};

class Login {
private:
    string accountUsername;
    string accountPassword;

public:
    void setAccountUsername(string username) {
        accountUsername = username;
    }

    void setAccountPassword(string password) {
        accountPassword = password;
    }

    string getAccountUsername() const {
        return accountUsername;
    }

    string getAccountPassword() const {
        return accountPassword;
    }
    bool checkAccount(Login accnt) {
        //cout << accnt.accountUsername << "-Username\n";
        //cout << accnt.accountPassword << "-Password\n";  
        bool hasAccount = false;
        string u, p;
        ifstream infile("users.txt");
        while (infile >> u >> p) {
        // cout << u << p << " ";
            if (u == accnt.getAccountUsername() && p == accnt.getAccountPassword()) {
                hasAccount = true;
            }
        }
      infile.close();
    
      return hasAccount;
    }
};

class Rec {
    private:
    
    public:
    vector<double> userInput;
        Rec(istream& is) {
            int i;
            string st;
            is >> i;
            is.get();
            for (int j = 1; j <= i; j++) {
                getline(is, st);
                userInput.push_back(stod(st));
            }
        }

        void add_item(double item) {
        userInput.push_back(item);
        }

    double cosine_similarity(vector<double> v1, vector<double> v2) const {
      double dot_product = 0.0;
      double norm1 = 0.0;
      double norm2 = 0.0;
      int n = v1.size();
      for (int i = 0; i < n; i++) {
          dot_product += v1[i] * v2[i];
          norm1 += v1[i] * v1[i];
          norm2 += v2[i] * v2[i];
      }
      return dot_product / (sqrt(norm1) * sqrt(norm2));
  }

int matchUser(vector<vector<double>> a, vector<double> b) const {
    double bestSim = -1.0;
    int bestSimIndex = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (cosine_similarity(a[i], b) > bestSim) {
            bestSim = cosine_similarity(a[i], b);
            bestSimIndex = i;
        }
    }
    return bestSimIndex;
}

int matchSong(vector<double> a, vector<double> b) const {
    int songIndex = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > 3.0 && b[i] == 0.0) {
            songIndex = i;
        }
    }
    return songIndex;
}


   void write_to(ostream& os) const {
        os << userInput.size() << endl;
        for (unsigned int i = 0; i < userInput.size(); i++) {
            os << userInput[i] << endl;
        }
        }

   void print_rec(ostream& os) const {
        
        
            os << titles[matchSong(matrix[(matchUser(matrix, userInput))], userInput)] << endl;
        
        }
    };

class State {
private:
    int screen_num;
    string input;
    Register account;
    Login login;

public:
Wishlist wishlist;
Collection collection;
Rec rec;
    State(istream& is) : screen_num(0), wishlist(is), collection(is), rec(is)
    {
        is >> screen_num;
    }

    int get_screen_num() const {
        return screen_num;
    }

    void write_to(ostream& os) const {
        wishlist.write_to(os);
        collection.write_to(os);
        rec.write_to(os);
        os << screen_num << endl;
        
    }

    int size_in_bytes() const {
        return 4;
    }

    void update(string input, istream& is);

    bool remove_item_from_collection(string item) {
        return collection.remove_item(item);
    }
};



void read_text_data() {
  ifstream fs("ai.txt");
  string comment;
  for (int i = 0; i < 34; ++i) {
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
  } else os << "\033c";

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


void State::update(string input, istream &is) {
    Login accnt;
     if (react && _received_event()) {
    // get input from the stream
    is.get(); is.get();  // skip first two characters
    if ('~' != is.peek()) getline(is, input, '\0');
  }
  if (0 == screen_num) screen_num = 1;
  else if (1 == screen_num) screen_num = 2;
  else {
	string input_num = input;
	if (2 == screen_num) {
  	  if ("1" == input_num) {

        //cout << "test" << endl;
        screen_num = 3;
       // cout << "test" << endl;
      } 
      else {
       // cout << "test" << endl;
        screen_num = 5;
      //  cout << "test" << endl;
      }
  } else if (screen_num == 3) {
    //accnt.get_username();
      //cout << accnt.accountUsername << endl;
      user = input_num;                             
      screen_num = 4;      
  } else if (screen_num == 4) {
      accnt.setAccountPassword(input_num);
      // cout << accnt.accountUsername << endl;
      accnt.setAccountUsername(user);
      pass = input_num;
      bool has_account = accnt.checkAccount(accnt);
      if (has_account) {
      screen_num = 9;
      }                                         // Move to Options
      else {                                     // or login/ register screen based on if it's in file
      screen_num = 2; 
      }                    
  } else if (screen_num == 5) {
    //account.getAccountUsername;
    user = input_num;
    screen_num = 6;
  } else if (screen_num == 6) {
    //account.getAccountPassword();
    pass = input_num;
    screen_num = 7;
  } else if (screen_num == 7) {
    //account.getAccountName();
    name = input_num;
    screen_num = 8;
  } else if (screen_num == 8) {
   // account.getAccountEmail();
    email = input_num;
    screen_num = 9;
  } else if (screen_num == 9) {
    if ("1" == input_num) {
      screen_num = 10;
    } else if ("2" == input_num) {
      screen_num = 11;
    } else if ("3" == input_num) {
      screen_num = 12;
    } else if ("4" == input_num){
      screen_num = 13;
    } else if ("5" == input_num){
        screen_num = 14;
    } else if ("6" == input_num){
        screen_num = 15;
    } else if ("7" == input_num){
      screen_num=1;
    } else screen_num=16;
  } else if (screen_num == 10) {

    add = input_num;
    collection.add_item(add);
    //add "add" to a collection
    screen_num = 9;
  } else if (screen_num == 11) {
    //collection.print_records(os);
    //print out the collection
    if ("1" == input_num) {
      //cout << "test" << endl;
      screen_num = 9;
      //cout << "test" << endl;
    } else {
      screen_num = 13;
    }
    
  } else if (screen_num == 12) {
    add = input_num;
    wishlist.add_wish(add);
    screen_num = 9;
  } else if (screen_num == 12) {
    add = input_num;
    //add "add" to wishlist
    screen_num = 9;
  } else if (screen_num == 13) {
    if ("1" == input_num) {
      screen_num = 9;
    } else {
      screen_num = 14;
    }
  } else if(screen_num == 14){
    //string item;
    collection.remove_item(input);
    screen_num = 9;
  } else if(screen_num == 15){
    wishlist.remove_wish(input);
    screen_num=9;
  } else if (screen_num == 16){
    screen_num = 17;
  } else if (screen_num == 17) {
    if (input_num == "1") {
      screen_num = 18;
    } else screen_num = 1;
  } else if (screen_num == 18) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 19;
  } else if (screen_num == 19) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 20;
  } else if (screen_num == 20) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 21;
  } else if (screen_num == 21) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 22;
  } else if (screen_num == 22) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 23;
  } else if (screen_num == 23) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 24;
  } else if (screen_num == 24) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 25;
  } else if (screen_num == 25) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 26;
  } else if (screen_num == 26) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 27;
  } else if (screen_num == 27) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 28;
  } else if (screen_num == 28) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 29;
  } else if (screen_num == 29) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 30;
  } else if (screen_num == 30) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 31;
  } else if (screen_num == 31) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 32;
  } else if (screen_num == 32) {
    rec.userInput.push_back(stod(input_num));
    screen_num = 33;
  } else if (screen_num == 33) {
    if (input_num == "1") {
      screen_num = 9;
    } else screen_num = 0;
  }
    
  
  
  /*
   if (screen_num == 16){
    if (input_num == "1"){
      screen_num = 9;
   //   ifstream curr("curr_state");            I thought this is how to change it to current. 
  //    State current(curr);                    however when it's uncommented it sets curr_state file
  //    curr.close();                           to be 15 instantly. Then if you hit "I want to continue it just loads 15 over and over"
    } else if (input_num == "2") {
      screen_num = 2;
    }
}
*/
}
}


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
