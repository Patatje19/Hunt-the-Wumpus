#ifndef _RANDOMGENERATE_HPP
#define _RANDOMGENERATE_HPP


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <unistd.h>


std::vector<int> bottemless_pit_generator(int roomsize);

int wumpus_start_location(int roomsize);

int treasure_location(int roomsize);

std::vector<int> generate_room_bat(int room_size);

int generate_random_room(const std::vector<int> & rooms);

int player_start_location(const std::vector<int> & bottemless_pits, int wumpus_location, 
int roomsize, const std::vector<int> & room_bat);


#endif /* _RANDOM-GENERATE_HPP */
