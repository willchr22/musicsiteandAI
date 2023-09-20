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

    Wishlist::Wishlist(istream& is) {
        int j;
        string str;
        is >> j;
        is.get();
        for (int i = 1; i <= j; i++) {
            getline(is, str);
            add_wish(str);
        }
    }
    void Wishlist::add_wish(string wish) {
        wishes.push_back(wish);
    }
    void Wishlist::write_to(ostream& osi) const {
        osi << wishes.size() << endl;
        for (unsigned int i = 0; i < wishes.size(); i++) {
            osi << wishes[i] << endl;
        }
    }
    void Wishlist::print_wishes(ostream& os) const {
      os << "Number of items in wishlist: " << wishes.size() << endl;
        for (int i = wishes.size() - 1; i >= 0; i--) {
            os << wishes[i] << endl;
        }
    }
    bool Wishlist::remove_wish(string wish) {
        for (vector<string>::iterator it = wishes.begin(); it != wishes.end(); ++it) {
            if (*it == wish) {
                wishes.erase(it);
                return true;
            }
        }
        return false;
    }
