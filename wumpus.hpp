#ifndef _WUMPUS_HPP
#define _WUMPUS_HPP


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
#include <fstream>


int player_start_location(std::vector<int> bottemless_pits, int wumpus_location, int roomsize, std::vector<int> room_bat);

int left_chamber(int room, const std::vector<int> & rooms);

int right_chamber(int room, const std::vector<int> & rooms);

int opposite_chamber(int room, const std::vector<int> & rooms);

void print_start(int room);

void print_room_options(int room, const std::vector<int> & rooms);

void print_user_movement(int & room);

void print_current_room_true(int & room);

void print_wrong_input();

int user_movement(int & room, const std::vector<int> & rooms);

void print_load_config();

int read_config_room_number();

std::string line_finder(int line_to_find);

std::vector<int> room_generator(int roomsize);

bool config_file();

std::vector<int> bottemless_pit_generator(int roomsize);

std::vector<int> read_config_bottemless_pits();

void print_fell_in_pit();

void print_game_over();

void check_bottemless_pits(int player_location, const std::vector<int> & bottemless_pits);

int wumpus_start_location(int roomsize);

int read_config_wumpus_location();

void print_smell_wumpus();

bool smell_wumpus(int current_room, int wumpus_locatie, const std::vector<int> & rooms);

void print_gepakt_wumpus();

void check_wumpus(int player_location, int wumpus_location);

int read_config_player_location(const std::vector<int> & bottemless_pits, int wumpus_location, std::vector<int> room_bat);

int read_config_arrow_number();

bool user_shoot_or_move(int & room, const std::vector<int> & rooms, int & arrows, int & wumpus_location);

void print_shoot_or_move();

void user_shoot(int & room, const std::vector<int> & rooms, int & arrows, int & wumpus_location);

void print_user_shoot(int & room_shot);

void print_wumpus_hit();

void print_arrow_inventory(int arrows);

void hit_or_miss(int & room, int & arrows, int & wumpus_location, int roomsize);

void print_current_room(int & room);

void print_wumpus_miss();

std::vector<int> read_config_room_bat();

std::vector<int> generate_room_bat(int room_size);

int generate_random_room(std::vector<int> rooms);

bool check_bat(int player_location, std::vector<int> bat_location, std::vector<int> rooms);

bool smell_bat(int player_location, std::vector<int> bat_location, std::vector<int> rooms);

void print_pick_up_bat();

void print_smell_bat();


#endif /* _WUMPUS_HPP */
