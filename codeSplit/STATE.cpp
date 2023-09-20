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

    State::State(std::istream& is) : screen_num(0), wishlist(is), collection(is), rec(is)
    {
        is >> screen_num;
    }

    int State::get_screen_num() const {
        return screen_num;
    }

    void State::write_to(std::ostream& os) const {
        wishlist.write_to(os);
        collection.write_to(os);
        rec.write_to(os);
        os << screen_num << endl;
        
    }

    int State::size_in_bytes() const {
        return 4;
    }


    bool State::remove_item_from_collection(std::string item) {
        return collection.remove_item(item);
    }
    
    void State::update(std::string input, std::istream &is) {
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
        screen_num = 35; 
        }                    
    } else if (screen_num == 35){
        if ("1" == input_num) {
        screen_num = 3;
        } else if ("2" == input_num) {
        screen_num = 5;
        }
    } else if (screen_num == 5) {
        Register  account;
        user = input_num;
        if(user.length() > 3){
            bool userCheck = false;
            userCheck = account.checkUsername(user);
            if (userCheck){
                screen_num = 38;
            }
            account.setAccountUsername(user);
            screen_num = 6;
        } else {
            screen_num = 36;
        }
    } else if (screen_num == 36){
        user = input_num;
        if(user.length() > 3){
            /*bool userCheck = false;
            userCheck = account.checkUsername(user);            // was trying to make something
            if (userCheck){                                     // that checks if the username 
                screen_num = 38;                                // exists
            }*/
            account.setAccountUsername(user);
            screen_num = 6;
        } else {
            screen_num = 36;
        }
    } else if (screen_num == 6) {
        pass = input_num;
        if (pass.length() > 3){
            account.setAccountPassword(pass);
            screen_num = 7;
        } else {
            screen_num = 37;
        }
    } else if (screen_num == 37){
        pass = input_num;
        if (pass.length() > 3){
            account.setAccountPassword(pass);
            screen_num = 7;
        } else {
            screen_num = 37;
        }
    } else if (screen_num == 38){
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
        } else if ("8" == input_num){
            screen_num=1;
        } //else if (!"7" == input_num){ 
           // screen_num=38;
        /*user = input_num;
        if(user.length() > 3){
          /*  bool userCheck = false;
            userCheck = account.checkUsername(user);
            cout << userCheck << " is" << std::endl;        // original code for screen 38
            if (userCheck){
                screen_num = 38;
            }
            account.setAccountUsername(user);
            screen_num = 6;
        } else {
            screen_num = 36;*/
       // } 
        else {
            screen_num == 16;
        }

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
        } else if ("8" == input_num){
             screen_num=1;
       // }// else if (!"7" == input_num){
          //  screen_num = 38;
     //   } else if ("7" == input_num){
         //   screen_num == 16;
        //} 
        } else {
            screen_num=16;
        }
    } else if (screen_num == 10) {
        add = input_num;
        if  (input_num == "90"){
            screen_num = 9;
        } else {
            collection.add_item(add);
        //add "add" to a collection
        
        screen_num = 10;
        }
    } else if (screen_num == 11) {
        //collection.print_records(os);
        //print out the collection
        if ("1" == input_num) {
        //cout << "test" << endl;
        screen_num = 9;
        //cout << "test" << endl;
        } else {
        screen_num = 9;
        }
        
    //} else if (screen_num == 12) {
     //   add = input_num;
    } else if (screen_num == 12) {
        add = input_num;
        if (input_num == "90"){
            screen_num = 9;
        } else {
            wishlist.add_wish(add);
            screen_num = 12;
        }
        //add "add" to wishlist

    } else if (screen_num == 13) {
        if ("1" == input_num) {
        screen_num = 9;
        } else {
        screen_num = 9;
        }
    } else if(screen_num == 14){
        //string item;
        if (input_num == "90"){
        screen_num = 9;
        } else {
        collection.remove_item(input);
        screen_num = 14;
        }
    } else if(screen_num == 15){
        if (input_num == "90"){
            screen_num = 9;
        } else {
        wishlist.remove_wish(input);
        screen_num=15;
        }
    } else if (screen_num == 16){
        rec.userInput.clear();
        screen_num = 17;
    } else if (screen_num == 17) {
        if (input_num == "1") {
        screen_num = 18;
        } else screen_num = 9;
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
    
