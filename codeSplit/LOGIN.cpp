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
    
    void Login::setAccountUsername(string username) {
        accountUsername = username;
    }

    void Login::setAccountPassword(string password) {
        accountPassword = password;
    }

    string Login::getAccountUsername() const {
        return accountUsername;
    }

    string Login::getAccountPassword() const {
        return accountPassword;
    }
    bool Login::checkAccount(Login accnt) {
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
    
