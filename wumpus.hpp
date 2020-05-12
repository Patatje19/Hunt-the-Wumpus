#ifndef _WUMPUS_HPP
#define _WUMPUS_HPP


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>


int random_room();

int left_chamber(int room, const std::vector<int> & rooms);

int right_chamber(int room);

int opposite_chamber(int room, const std::vector<int> & rooms);

void print_start(int room);

void print_room_options(int room, const std::vector<int> & rooms);

void print_user_movement(int & room);

void print_current_room_true(int & room);

void print_current_room_false();

void user_movement(int & room, const std::vector<int> & rooms);


#endif /* _WUMPUS_HPP */
