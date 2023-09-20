#ifndef REGISTER_H
#define REGISTER_H

#include <string>
#include <fstream>

class Register {
private:
    std::string accountName;
    std::string accountUsername;
    std::string accountPassword;
    std::string accountEmail;

public:
    void setAccountName(std::string name);
    void setAccountUsername(std::string username);
    void setAccountPassword(std::string password);
    void setAccountEmail(std::string email);

    std::string getAccountName() const;
    std::string getAccountUsername() const;
    std::string getAccountPassword() const;
    std::string getAccountEmail() const;
    bool checkUsername(std::string username);
};

#endif