/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Lab: 11B

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

class Network
{
private:
 static const int MAX_USERS = 20; // max number of user profiles
 int numUsers;                    // number of registered users
 Profile profiles[MAX_USERS];     // user profiles array: mapping integer ID -> Profile
 int findID(string usrn)          // Returns user ID (index in the 'profiles' array) by their username, -1 if is not found
 {
  int answer = -1;
  for (int i = 0; i < numUsers; i++)
  {
   if (profiles[i].getUsername() == usrn)
   {
    return i;
   }
  }
  return answer;
 }

public:
 Network();                              // Constructor, makes an empty network (numUsers = 0)
 bool addUser(string usrn, string dspn); // Attempts to sign up a new user with specified username and displayname
                                         // return true if the operation was successful, otherwise return false
};

Network::Network()
{
 numUsers = 0;
}

bool Network::addUser(string usrn, string dspn)
{
 // when putting <= MAX_USERS --> it gave a segmentation fault!!
 if ((numUsers < MAX_USERS) && (findID(usrn) == -1))
 {
  for (int i = 0; i < usrn.length(); i++)
  {
   if (!(isalnum(usrn[i])))
   {
    return false;
   }
  }

  // successfully adding the new user
  Profile newUser(usrn, dspn);
  profiles[numUsers] = newUser;
  numUsers++;
  return true;
 }
 else
 {
  return false;
 }
}

int main()
{
 Network nw;
 cout << nw.addUser("mario", "Mario") << endl; // true (1)
 cout << nw.addUser("luigi", "Luigi") << endl; // true (1)

 cout << nw.addUser("mario", "Mario2") << endl;   // false (0)
 cout << nw.addUser("mario 2", "Mario2") << endl; // false (0)
 cout << nw.addUser("mario-2", "Mario2") << endl; // false (0)

 for (int i = 2; i < 20; i++)
   cout << nw.addUser("mario" + to_string(i),
                      "Mario" + to_string(i))
        << endl; // true (1)

 cout << nw.addUser("yoshi", "Yoshi") << endl; // false (0)
}