/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Lab: 11C

The class Network should be changed to keep the friendship (following) relation between the users.
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
 static const int MAX_USERS = 20;      // max number of user profiles
 int numUsers;                         // number of registered users
 Profile profiles[MAX_USERS];          // user profiles array: mapping integer ID -> Profile
 int findID(string usrn);              // Returns user ID (index in the 'profiles' array) by their username, -1 if is not found
 bool following[MAX_USERS][MAX_USERS]; // friendship matrix: following[id1][id2] == true when id1 is following id2

public:
 Network();                               // Constructor, makes an empty network (numUsers = 0)
 bool addUser(string usrn, string dspn);  // Attempts to sign up a new user with specified username and displayname
                                          // return true if the operation was successful, otherwise return false
 bool follow(string usrn1, string usrn2); // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
                                          // return true if success (if both usernames exist), otherwise return false
 void printDot();                         // Print Dot file (graphical representation of the network)
};

Network::Network()
{
 numUsers = 0;
 for (int i = 0; i < MAX_USERS; i++)
 {
  for (int j = 0; j < MAX_USERS; j++)
  {
   following[i][j] = false;
  }
 }
}

int Network::findID(string usrn)
{
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
}

bool Network::addUser(string usrn, string dspn)
{
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

bool Network::follow(string usrn1, string usrn2)
{
 // checkign that both users are in the network
 if ((findID(usrn1) != -1) && (findID(usrn2) != -1) && (findID(usrn1) != findID(usrn2)))
 {
  // making usrn1 follow usrn2
  following[(findID(usrn1))][(findID(usrn2))] = true;
  return true;
 }
 else
 {
  return false;
 }
}

void Network::printDot()
{
 cout << "digraph {" << endl;
 for (int i = 0; i < numUsers; i++)
 {
  cout << "\"@" << profiles[i].getUsername() << "\"" << endl;
 }
 cout << "\n";
 for (int i = 0; i < MAX_USERS; i++)
 {
  for (int j = 0; j < MAX_USERS; j++)
  {
   if (following[i][j] == true) // only printing users who follow each other
   {
    cout << "\"@" << profiles[i].getUsername() << "\" -> \"@" << profiles[j].getUsername() << "\"" << endl;
   }
  }
 }
 cout << "}" << endl;
}

int main()
{
 Network nw;
 // add three users
 nw.addUser("mario", "Mario");
 nw.addUser("luigi", "Luigi");
 nw.addUser("yoshi", "Yoshi");

 // make them follow each other
 nw.follow("mario", "luigi");
 nw.follow("mario", "yoshi");
 nw.follow("luigi", "mario");
 nw.follow("luigi", "yoshi");
 nw.follow("yoshi", "mario");
 nw.follow("yoshi", "luigi");

 // add a user who does not follow others
 nw.addUser("wario", "Wario");

 // add clone users who follow @mario
 for (int i = 2; i < 6; i++)
 {
  string usrn = "mario" + to_string(i);
  string dspn = "Mario " + to_string(i);
  nw.addUser(usrn, dspn);
  nw.follow(usrn, "mario");
 }
 // additionally, make @mario2 follow @luigi
 nw.follow("mario2", "luigi");

 nw.printDot();
}
