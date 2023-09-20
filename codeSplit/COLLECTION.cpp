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

    Collection::Collection(istream& is) {
        int i;
        string st;
        is >> i;
        is.get();
        for (int j = 1; j <= i; j++) {
            getline(is, st);
            add_item(st);
        }
    }

    void Collection::add_item(string item) {
        items.push_back(item);
    }

    void Collection::write_to(ostream& os) const {
        os << items.size() << endl;
        for (unsigned int i = 0; i < items.size(); i++) {
            os << items[i] << endl;
        }
    }
    bool Collection::remove_item(string item) {
        for (vector<string>::iterator it = items.begin(); it != items.end(); ++it) {
            if (*it == item) {
                items.erase(it);
                return true;
            }
        }
        return false;
    }

    void Collection::print_records(ostream& os) const {
      os << "Number of items in collection: " << items.size() << endl;
        for (int i = items.size() - 1; i >= 0; i--) {
            os << items[i] << endl;
        }
    }