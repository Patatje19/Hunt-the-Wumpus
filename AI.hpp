#ifndef _AI_HPP
#define _AI_HPP


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <unistd.h>


bool play_AI();

char AI_dicesion_m_or_s(int room, const std::vector<int> rooms, int & arrows, int & wumpus_location, 
bool wumpus, bool bats, int d_counter = 0);

bool AI_shoot_or_move(int room, const std::vector<int> rooms, int & arrows, int & wumpus_location, 
bool wumpus, bool bats, int turns);

int AI_direction(int right, int left, int opposite);

int AI_movement(int room, const std::vector<int> & rooms);

void AI_shoot(int room, const std::vector<int> & rooms, int & arrows, int & wumpus_location, int turns);

int AI_shoot_room(int right, int left, int opposite);


#endif /* _AI_HPP */