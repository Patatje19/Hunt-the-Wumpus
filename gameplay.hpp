#ifndef _GAMEPLAY_HPP
#define _GAMEPLAY_HPP


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <unistd.h>


bool user_shoot_or_move(int room, const std::vector<int> rooms, int & arrows, int & wumpus_location, int turns);

void user_shoot(int room, const std::vector<int> & rooms, int & arrows, int & wumpus_location, int turns);

int user_movement(int room, const std::vector<int> & rooms);

bool check_bottemless_pits(int player_location, const std::vector<int> & bottemless_pits);

bool check_wumpus(int player_location, int wumpus_location);

bool smell_wumpus(int current_room, int wumpus_locatie, const std::vector<int> & rooms);

bool config_file();

void hit_or_miss(int room, int & arrows, int & wumpus_location, int roomsize, int turns);

bool check_bat(int player_location, const std::vector<int> & bat_location, const std::vector<int> & rooms);

bool smell_bat(int player_location, const std::vector<int> & bat_location, const std::vector<int> & rooms);

bool roadmap();

bool instructions();

bool statistics();

bool check_treasure(int player_location, int treasure_location, int treasure_opens);

int open_treasure();


#endif /* _GAMEPLAY_HPP */
