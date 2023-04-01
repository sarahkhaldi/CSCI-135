/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 10E

This program prints movies screening schedule, schedules movies after one finishes, and checks if two movies overlap with eachother.
*/

#include <iostream>
using namespace std;

class Time
{
public:
 int h;
 int m;
};

// function to calculate num of mins from 00:00AM until time
int minutesSinceMidnight(Time time)
{
 int answer, mins, hours;
 mins = time.m;
 hours = time.h * 60; // converting hours to mins
 answer = mins + hours;
 return answer;
}

void printTime(Time time)
{
 cout << time.h << ":" << time.m;
}

// function to calculate the difference between two moments
int minutesUntil(Time earlier, Time later)
{
 int initialTime = minutesSinceMidnight(earlier);
 int finalTime = minutesSinceMidnight(later);
 int answer = finalTime - initialTime;
 return answer;
}

// function to create a new moment of time
Time addMinutes(Time time0, int min)
{
 Time time1;
 int oldMoment = minutesSinceMidnight(time0);
 int newMomentMins = oldMoment + min; // the new moment created, in minutes
 time1.h = (newMomentMins / 60);
 time1.m = (newMomentMins % 60);
 return time1;
}

enum Genre
{
 ACTION,
 COMEDY,
 DRAMA,
 ROMANCE,
 THRILLER,
 FANTASY
};

class Movie
{
public:
 string title;
 Genre genre;  // only one genre per movie
 int duration; // in minutes
};

class TimeSlot
{
public:
 Movie movie;    // what movie
 Time startTime; // when it starts
};

void printMovie(Movie mv)
{
 string g;
 switch (mv.genre)
 {
 case ACTION:
  g = "ACTION";
  break;
 case COMEDY:
  g = "COMEDY";
  break;
 case DRAMA:
  g = "DRAMA";
  break;
 case ROMANCE:
  g = "ROMANCE";
  break;
 case THRILLER:
  g = "THRILLER";
  break;
 case FANTASY:
  g = "FANTASY";
 }
 cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts)
{
 Time endTime = addMinutes(ts.startTime, ts.movie.duration);
 printMovie(ts.movie);
 cout << " [starts at ";
 printTime(ts.startTime);
 cout << ", ends by ";
 printTime(addMinutes(ts.startTime, ts.movie.duration));
 cout << "]" << endl;
}

// this function adds nextMovie, scheduled immediately after the time slot ts.
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
 TimeSlot addedMovie;
 addedMovie.startTime = addMinutes(ts.startTime, ts.movie.duration);
 addedMovie.movie.title = nextMovie.title;
 addedMovie.movie.genre = nextMovie.genre;
 addedMovie.movie.duration = nextMovie.duration;
 return addedMovie;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
 TimeSlot earlier, later;
 // finding out which movie starts first
 // they overlap if the movie duration is greater than the interval between the time slots’ starting times.
 if ((minutesUntil(ts1.startTime, ts2.startTime)) > (minutesUntil(ts2.startTime, ts1.startTime)))
 {
  earlier = ts1;
  later = ts2;
  if ((earlier.movie.duration) > minutesUntil(earlier.startTime, later.startTime))
  {
   return true;
  }
  else
  {
   return false;
  }
 }
 else
 {
  earlier = ts2;
  later = ts1;
  if ((earlier.movie.duration) > minutesUntil(earlier.startTime, later.startTime))
  {
   return true;
  }
  else
  {
   return false;
  }
 }
}

int main()
{
 Movie movie1 = {"Back to the Future", COMEDY, 116};
 Movie movie2 = {"Black Panther", ACTION, 134};
 Movie movie3 = {"Howl's Moving Castle", FANTASY, 119};
 Movie movie4 = {"The Wind Rises", ROMANCE, 126};
 Movie movie5 = {"Spider-Man: Into the Spider-Verse", ACTION, 117};
 Movie movie6 = {"Ponyo", FANTASY, 101};
 Movie movie7 = {"The Wolf of Wall Street", COMEDY, 180};
 Movie movie8 = {"5 Centimeters Per Second", DRAMA, 63};

 TimeSlot morning = {movie1, {10, 15}};
 TimeSlot daytime = {movie2, {13, 15}};
 TimeSlot evening = {movie3, {16, 45}};
 TimeSlot afternoon = {movie4, {14, 30}};
 TimeSlot evening1 = {movie5, {19, 00}};

 printTimeSlot(morning);
 printTimeSlot(daytime);
 printTimeSlot(afternoon);
 printTimeSlot(evening);
 printTimeSlot(evening1);

 return 0;
}