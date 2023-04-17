/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Lab: 11A

This program implements the class Profile that can store the info about a user of the network.
*/

#include <iostream>
using namespace std;

class Profile
{
private:
 string username;
 string displayname;

public:
 Profile(string usrn, string dspn); // Profile constructor for a user (initializing private variables 
                                    //  username = usrn, displayname = dspn)
 Profile();                         // Default Profile constructor (username = "", displayname = "")
 string getUsername();              // Return username
 string getFullName();              // Return name in the format: "displayname (@username)"
 void setDisplayName(string dspn);  // Change display name
};

string Profile::getUsername()
{
 return username;
}

string Profile::getFullName()
{
 displayname = displayname + " (@" + username + ")";
 return displayname;
}

void Profile::setDisplayName(string dspn)
{
 displayname = dspn;
}

Profile::Profile(string usrn, string dspn) // also a constructor, but this one has parameters 
{
 username = usrn;
 displayname = dspn;
}

Profile::Profile() // constructor --> has the same name as the class & has no return value
{
 username = "";
 displayname = "";
}

int main()
{
 Profile p1("marco", "Marco");
 cout << p1.getUsername() << endl; // marco
 cout << p1.getFullName() << endl; // Marco (@marco)

 p1.setDisplayName("Marco Rossi");
 cout << p1.getUsername() << endl; // marco
 cout << p1.getFullName() << endl; // Marco Rossi (@marco)

 Profile p2("tarma1", "Tarma Roving");
 cout << p2.getUsername() << endl; // tarma1
 cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}