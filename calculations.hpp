#ifndef _CALCULATIONS_HPP
#define _CALCULATIONS_HPP


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <unistd.h>


int left_chamber(int room, const std::vector<int> & rooms);

int right_chamber(int room, const std::vector<int> & rooms);

int opposite_chamber(int room, const std::vector<int> & rooms);

std::vector<int> room_generator(int roomsize);

char map_calc(const std::vector<int> & rooms, const std::vector<int> & bottemless_pits, int locatie_wumpus, const std::vector<int> & room_bat, int room);


#endif /* _CALCULATIONS_HPP */
