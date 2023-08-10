#ifndef CHECKINVALID_H
#define CHECKINVALID_H

#include <string>

#define     MAX_STRINGS_USERNAME    16
#define     MIN_STRINGS_USERNAME    3

#define     MAX_STRINGS_PASSWORD   16
#define     MIN_STRINGS_PASSWORD    6

class Check_Valid
{
public:
    Check_Valid();

    static bool Check_Valid_Username(std::string account);

    static bool Check_Valid_Password(std::string password);

    static bool Check_Valid_Account(std::string account, std::string password);

};

#endif // CHECKINVALID_H
