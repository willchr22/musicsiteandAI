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

    void Register::setAccountName(string name) {
        accountName = name;
    }

    void Register::setAccountUsername(string username) {
        accountUsername = username;
        ofstream outfile;
        outfile.open("users.txt", ios_base::app);
        outfile << accountUsername << " ";
        outfile.close();
    }

    void Register::setAccountPassword(string password) {
        accountPassword = password;
        ofstream outfile;
        outfile.open("users.txt", ios_base::app); 
        outfile << accountPassword << std::endl;
        outfile.close();
    }

    void Register::setAccountEmail(string email) {
        accountEmail = email;
    }

    string Register::getAccountName() const {
        return accountName;
    }

    string Register::getAccountUsername() const {
        return accountUsername;
    }

    string Register::getAccountPassword() const {
        return accountPassword;
    }

    string Register::getAccountEmail() const {
        return accountEmail;
    }

    bool Register::checkUsername(std::string username){
        bool hasAccount = false;
        string u, p;
        ifstream infile("users.txt");
        while (infile >> u >> p) {
        cout << u << p << std::endl;
            if (u == username) {
                hasAccount = true;
            }
        }
      infile.close();
    
      return hasAccount;
    }
