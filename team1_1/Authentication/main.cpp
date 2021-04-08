#include <iostream>
#include "authentication.h"

using namespace std;

int main()
{
    Authentication auth = Authentication();
    if(auth.logIn("user1","password1")) cout << "Access Granted" << endl;
}
