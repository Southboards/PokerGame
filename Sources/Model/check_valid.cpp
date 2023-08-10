#include "../../Headers/Model/Check_Valid.h"

Check_Valid::Check_Valid()
{

}

bool Check_Valid::Check_Valid_Username(std::string account)
{
    bool valid = false;
    if ( (account.length() >= MIN_STRINGS_USERNAME) && (account.length() <= MAX_STRINGS_USERNAME))
    {
        valid = true;
    }
    return valid;
}

bool Check_Valid::Check_Valid_Password(std::string password)
{
    bool valid = false;
    if ( (password.length() >= MIN_STRINGS_PASSWORD) && (password.length() <= MAX_STRINGS_PASSWORD))
    {
        valid = true;
    }
    return valid;
}

bool Check_Valid::Check_Valid_Account(std::string account, std::string password)
{
    bool valid = true;
    valid &= Check_Valid_Username(account);
    valid &= Check_Valid_Password(password);
    return valid;
}



