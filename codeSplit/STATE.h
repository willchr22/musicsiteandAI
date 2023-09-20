#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>
#include "WISHLIST.h"
#include "COLLECTION.h"
#include "REC.h"
#include "REGISTER.h"
#include "LOGIN.h"
#include "GLOBALVAR.h"
#include <cstring>

class State {
private:
    int screen_num;
    std::string input;
    Register account;
    Login login;

public:
    Wishlist wishlist;
    Collection collection;
    Rec rec;
    State(std::istream& is);
    int get_screen_num() const;
    void write_to(std::ostream& os) const;
    int size_in_bytes() const;
    bool remove_item_from_collection(std::string item);
    void update(std::string input, std::istream& is);
};

#endif // STATE_H
