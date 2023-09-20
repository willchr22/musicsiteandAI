#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <fstream>

class Login {
private:
    std::string accountUsername;
    std::string accountPassword;

public:
    void setAccountUsername(std::string username);
    void setAccountPassword(std::string password);

    std::string getAccountUsername() const;
    std::string getAccountPassword() const;

    bool checkAccount(Login accnt);
 //   bool checkUsername(Login accnt);
};

#endif 
