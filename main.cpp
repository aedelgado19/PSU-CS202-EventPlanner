/* Author: Allison Delgado
   Class: CS 202 Summer 2021
   main.cpp is a testing site for beaches, shopping trips, and
   restaurants. For help with testing, type 0 in the main screen
   when you run it.

   Last updated July 16, 2021
 */

#include <iostream>
#include "Nodes.h"
#include <cstring>
#include <vector>
using namespace std;

void setup_b(vector<Beach> & b_vtr); //make new beach
void setup_s(Array & shop); //make new shopping
void setup_r(CLL & rest); //make new restaurant
void beach(Beach & b);
void manage_beach(vector<Beach> & b_vtr);
void shopping(Shopping & s);
void manage_shopping(Array & shop);
void restaurant(Restaurant & r);
void manage_restaurant(CLL & rest);

//vector functions:
void rm_vtr(vector<Beach> & b_vtr, char* name);
void rm_all(vector<Beach> & b_vtr);
void d_vtr(vector<Beach> & b_vtr);

int main(){
  cout << "Welcome to Event Planner!" << endl;
  char choice = 'a';
  char manage = 'a';
  vector<Beach> b_vtr;
  CLL rest;
  Array shop;
  
  do {
    cout << " " << endl;
    cout << "-----------------------" << endl;
    cout << "Select an event to plan." << endl;
    cout << "-----------------------" << endl;
    cout << "1 - Beach Trip" << endl;
    cout << "2 - Shopping Trip" << endl;
    cout << "3 - Restaurant" << endl;
    cout << " " << endl;
    cout << "OR" << endl;
    cout << "4 - Manage existing events (display all, delete, add, etc)" << endl;
    cout << "0 - Help: How to use this interface" << endl;
    cout << "q - quit program" << endl;
    cin >> choice;
    cin.ignore(1000, '\n');
    
    //beach
    if(choice == '1'){
      setup_b(b_vtr);
    }
    
    //shopping
    else if (choice == '2'){
      setup_s(shop);
    }

    //restaurant
    else if(choice == '3'){
      setup_r(rest);
    }
    //manage existing
    else if(choice == '4'){
      cout << "Manage which type of event?" << endl;
      cout << "1 - Beach" << endl;
      cout << "2 - Shopping" << endl;
      cout << "3 - Restaurant" << endl;
      cin >> manage;
      cin.ignore(1000, '\n');
      if(manage == '1'){
	if(b_vtr.size() == 0) {
	  cout << "You have not made any beaches yet." << endl;
	  break;
	}
	manage_beach(b_vtr);
      } else if (manage == '2'){
	if(shop.is_empty() == true) {
	  cout << "You have not made any shopping trips yet." << endl;
	  break;
	}
	manage_shopping(shop);
      } else if (manage == '3'){
	if(rest.is_empty() == true){
	  cout << "You have not made any restaurants yet." << endl;
	  break;
	}
	manage_restaurant(rest);
      } else {
	cout << "That was not one of the choices." << endl;
      }
    } else if(choice == '0'){
      cout << "Start by selecting one of the events to plan." << endl;
      cout << "After successfully making an event, you can choose (y/n) to " << endl;
      cout << "do specific operations on that event such as customize it " << endl;
      cout << "or change details." << endl;
      cout << " " << endl;
      cout << "From the main screen, you can also choose to manage" << endl;
      cout << "existing events. With this option, you can test the " << endl;
      cout << "data structures." << endl;
    } 
  } while(choice != 'q'); 
  return 0;
}

void setup_b(vector<Beach> & b_vtr){
  int a = 0;
  string word;
  char food[150];
  char dir[500];
  vector<string> vtr;
  char yn[5];
  cout << "Enter the amount of items you would like to " << endl;
  cout << "add to the list of things to bring to the beach" << endl;
  cout << "> ";
  cin >> a;
  cin.ignore(1000, '\n');
  cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

  for(int i = 0; i < a; i++){
    cout << "> ";
    getline(cin, word);
    vtr.push_back(word);
  }
  cout << "Please enter what you plan to do for food (go out, bring lunch, etc)." << endl;
  cout << "> ";
  cin.get(food, 150);
  cin.get();
  cout << "Enter the directions to the beach: " << endl;
  cout << "> ";
  cin.get(dir, 500);
  cin.get();

  Beach b(vtr, dir, food);

  b.read();
  b_vtr.push_back(b);
  while(strcmp(yn, "n") != 0){
    cout << " " << endl;
    cout << "Would you like to change any fields or look at more beach options? (y/n)" << endl;
    cout << "> ";
    cin.get(yn, 5);
    cin.get();
    if(strcmp(yn, "y") == 0){
      beach(b);
    }
  }
}

void setup_s(Array & shop){
  int a = 0;
  int b = 0;
  string word;
  string item;
  vector<string> shops;
  vector<string> items;
  int bg;
  char yn[5];
  cout << "Enter the amount of stores you would like to visit." << endl;
  cin >> a;
  cin.get();
  cout << "Enter each store in 1 at a time, separated by a newline." << endl;
  for(int i = 0; i < a; i++){
    cout << "> ";
    getline(cin, word);
    shops.push_back(word);
  }
  cout << "Enter how many items you would like to add to your shopping list" << endl;
  cin >> b;
  cin.get();
  cout << "Enter each item in 1 at a time, separated by a newline." << endl;
  for(int j = 0; j < b; j++){
    cout << "> ";
    getline(cin, item);
    items.push_back(item);
  }

  cout << "What is your budget for this shopping trip?" << endl;
  cout << "> ";
  cin >> bg;
  cin.get();

  Shopping s(shops, items, bg);
  s.read();
  while(strcmp(yn, "n") != 0){
    cout << " " << endl;
    cout << "Would you like to change any fields or look at more shopping options? (y/n)" << endl;
    cout << "> ";
    cin.get(yn, 5);
    cin.get();
    if(strcmp(yn, "y") == 0){
      shopping(s);
    }
  }
  shop.insert(s);
}

void setup_r(CLL & rest){
  Restaurant r;
  char yn[5];
  r.read();

  while(strcmp(yn, "n") != 0){
    cout << " " << endl;
    cout << "Would you like to change or view more restaurant options? (y/n)" << endl;
    cout << "> ";
    cin.get(yn, 5);
    cin.get();
    if(strcmp(yn, "y") == 0){
      restaurant(r);
    }
  }
  rest.insert(r);
}


// ******************************** BEACH SELECTIONS *************************************

void beach(Beach & b){
  char choice;
  string word;
  int amount;
  vector<string> to_add;
  vector<string> to_remove;

  cout << "Select an option." << endl;
  cout << "1 - add items to bring to the beach " << endl;
  cout << "2 - remove from the list of items to bring" << endl;
  cout << "3 - display your current beach trip details" << endl;
  cout << "4 - check the weather at the beach" << endl;
  cout << "5 - hear a fun fact about this beach" << endl;
  cin >> choice;
  cin.ignore(1000, '\n');

  //add items
  if (choice == '1'){
    cout << "how many items would you like to add?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_add.push_back(word);
    }
    b.add_items(to_add);
  }

  //remove items
  else if (choice == '2'){
    cout << "how many items would you like to remove?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_remove.push_back(word);
    }
    b.remove_items(to_remove);
  }

  //display
  else if (choice == '3'){
    b.display();
  }

  //check weather
  else if (choice == '4'){
    b.check_weather();
  } 

  //fun fact
  else if (choice == '5'){
    b.fun_fact();
  }

  else {
    cout << "That was not one of the options." << endl;
  }
}

// ******************************** SHOPPING SELECTIONS *************************************
void shopping(Shopping & s){
  char i;
  vector<string> to_add1;
  vector<string> to_remove1;
  vector<string> to_add2;
  vector<string> to_remove2;
  int amount;
  string word;
  
  cout << "Select an option." << endl;
  cout << "1 - Add stores to the list. " << endl;
  cout << "2 - Remove stores from the list." << endl;
  cout << "3 - Add items to your shopping list. " << endl;
  cout << "4 - Remove items from your shopping list." << endl;
  cout << "5 - Display all details of your shopping trip." << endl;
  cout << "> ";
  cin >> i;
  cin.get();

  if(i == '1'){
    cout << "how many stores would you like to add?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each store (1 at a time, separated by a newline)" << endl;
    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_add1.push_back(word);
    }    
    s.add_stores(to_add1);
  }

  else if(i == '2'){
    cout << "how many stores would you like to remove?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each store (1 at a time, separated by a newline)" << endl;
    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_remove1.push_back(word);
    }    
    s.remove_stores(to_remove1);
  }

  else if(i == '3'){
    cout << "how many items would you like to add?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_add2.push_back(word);
    }
    s.add_items(to_add2);
  }

  else if(i == '4'){
    cout << "how many items would you like to remove?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;
    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_remove2.push_back(word);
    }    
    s.remove_items(to_remove2);
  }

  else if(i == '5'){
    s.display();
  }
}

// ******************************** RESTAURANT SELECTIONS *************************************
void restaurant(Restaurant & r){
  char c;
  char d;
  
  cout << "Select an option." << endl;
  cout << "1 - Get the contact info of the restaurant." << endl;
  cout << "2 - Write a yelp review of this restaurant." << endl;
  cout << "3 - Display all restaurant details." << endl;
  cout << "> ";
  cin >> c;
  cin.get();
  if(c == '1'){
    r.contact_info();
  } else if (c == '2'){
    r.write_yelp_review();
  } else if (c == '3'){
    r.display();
  } else {
    cout << "That was not one of the options." << endl;
  }
}


//manage beaches
void manage_beach(vector<Beach> & b_vtr){
  char c;
  char name[50];
  
  cout << "Select an option. " << endl;
  cout << "1 - add another beach trip" << endl;
  cout << "2 - remove a beach trip" << endl;
  cout << "3 - display all beach trips" << endl;
  cout << "4 - remove all beach trips" << endl;
  cin >> c;
  cin.ignore(1000, '\n');

  if(c == '1'){
    setup_b(b_vtr);
  } else if (c == '2'){
    cout << "What is the name of the beach event you would like to remove?" << endl;
    cin.get(name, 50);
    cin.get();
    rm_vtr(b_vtr, name);
  } else if(c == '3'){
    d_vtr(b_vtr);
  }
}

//remove a specific beach
void rm_vtr(vector<Beach> & b_vtr, char* name){
  string str(name);
  
  for(vector<Beach>::iterator it = b_vtr.begin(); it!=b_vtr.end(); ++it){
    if((*it).compare(str)){
      b_vtr.erase(it);
      break;
    }
  }
 
}

//display all beaches
void d_vtr(vector<Beach> & b_vtr){
  for(vector<Beach>::iterator i = b_vtr.begin(); i!=b_vtr.end(); ++i){
    (*i).display();
  }
}

//remove all beaches
void rm_all(vector<Beach> & b_vtr){
  for(vector<Beach>::iterator i = b_vtr.begin(); i!=b_vtr.end(); ++i){
    b_vtr.erase(i);
  }
}



//manage shopping
void manage_shopping(Array & shop){
  char c;
  char name[50];
  
  cout << "Select an option. " << endl;
  cout << "1 - add another shopping trip" << endl;
  cout << "2 - remove a shopping trip" << endl;
  cout << "3 - display all shopping trips" << endl;
  cout << "4 - remove all shopping trips" << endl;
  cin >> c;
  cin.ignore(1000, '\n');

  if(c == '1'){
    setup_s(shop);
  } else if (c == '2'){
    cout << "What is the name of the shopping event you would like to remove?" << endl;
    cin.get(name, 50);
    cin.get();
    A_Node * found = shop.find_shop(name);
    if(found) shop.remove(found);
    else {
      cout << "Could not find a Shopping event by that name." << endl;
    }
  } else if(c == '3'){
    shop.display();
  } else if(c == '4'){
    shop.remove_all();
  }
}

//manage restaurants
void manage_restaurant(CLL & rest){
  char c;
  char name[50];
  
  cout << "Select an option. " << endl;
  cout << "1 - add another restaurant" << endl;
  cout << "2 - remove a restaurant" << endl;
  cout << "3 - display all restaurants" << endl;
  cout << "4 - remove all restaurants" << endl;
  cin >> c;
  cin.ignore(1000, '\n');

  if(c == '1'){
    Restaurant n;
    n.read();
    rest.insert(n);
  }

  else if(c == '2'){
    cout << "Enter the name of the restaurant you would like to remove." << endl;
    cout << "> ";
    cin.get(name, 50);
    cin.get();
    rest.remove(name);
  }

  else if(c == '3'){
    rest.display();
  }

  else if(c == '4'){
    rest.remove_all();
  }
}
