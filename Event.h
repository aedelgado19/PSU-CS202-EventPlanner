/* Author: Allison Delgado
   Class: CS202 Summer 2021
   The Event class has information pertaining to 
   where the event takes place and who is going.
   It inherits Time, which manages when an event
   will occur. This file also contains the 3 classes
   that directly inherit Event:
   Beach, Shopping, and Restaurant.
   Last updated: July 13, 2021
 */
#include <vector>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
class Time {
public:
  Time();
  void read();
  void display() const;
  int compare(std::string input_time, bool input_is_pm) const;
protected:
  std::string date; //represented in 6 digits
  std::string event_time; //represented in 4 digits (hours and mins)
  bool is_pm;
};


class Event : public Time {
public:
  Event();
  ~Event();
  Event(const Event & source); //copy constructor
  
  //read location of event:
  void read();
  void fun_fact(); //a function to print out a made up fun fact about the address
  void display() const;
protected:
  //pieces of an address:
  int street_num;
  char* street;
  char* city;
  char* state;
  char* name; //name of event
  char* people_going; //who is going
};
class Beach : public Event {
public:
  Beach(); //constructor
  Beach(const Beach & source); //copy constructor
  ~Beach(); //destructor
  Beach(std::vector<std::string> &items, char* dir, char* f);
  void add_items(std::vector<std::string>& new_items); //add items to a vector of what to bring
  void remove_items(std::vector<std::string>& to_remove); //remove items from the vector
  void display(); //display beach plan info
  void check_weather(); //displays a pretend weather forecast
  bool compare(std::string n);
protected:
  std::vector<std::string> items_to_bring; //what to bring
  char* directions; //directions to the beach
  char* food_plans; //what you are going to do for food
};

class Shopping : public Event {
public:
  Shopping(); //constructor
  Shopping(std::vector<std::string>& stores, std::vector<std::string>& buy_list, int budget);
  void add_stores(std::vector<std::string> &to_add); //add stores to the list
  void remove_stores(std::vector<std::string>& to_remove); //remove stores from the list
  void add_items(std::vector<std::string>& to_add); //add items to the list
  void remove_items(std::vector<std::string>& to_remove); //remove items from the list
  void display(); //display shopping details
  bool compare(std::string n);
  int hash(int size);
 protected:
   std::vector<std::string> stores; //what stores to visit
   std::vector<std::string> what_to_buy; //shopping list
   int budget; //how much you want to spend
 };

 class Restaurant : public Event {
 public:
   Restaurant(); //constructor
   void read();
   void display(); //display restaurant details
   void contact_info(); //displays restaurant's phone number (made up)
   void write_yelp_review(); //allows user to write a yelp review
   bool compare(std::string n);
 protected:
   std::string cuisine_type; //type of restaurant
   std::string name; //name of restaurant
   int budget; //how much you want to spend
   int stars; // how many stars the yelp review has
   std::string yelp_review;
   bool reviewed; //whether or not a yelp review has been written
 };
