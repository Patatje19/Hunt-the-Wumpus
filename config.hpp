#ifndef _CONFIG_HPP
#define _CONFIG_HPP


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <unistd.h>


std::string line_finder(int line_to_find);

int read_config_room_number();

std::vector<int> read_config_bottemless_pits();

int read_config_wumpus_location();

int read_config_player_location(const std::vector<int> & bottemless_pits, int wumpus_location, const std::vector<int> & room_bat);

int read_config_arrow_number();

std::vector<int> read_config_room_bat();

int read_config_treasure_location();


#endif /* _CONFIG_HPP */