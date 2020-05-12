#ifndef _PRINT_HPP
#define _PRINT_HPP


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <unistd.h>

void print_start(int room);

void print_room_options(int room, const std::vector<int> & rooms);

void print_user_movement(int & room);

void print_current_room_true(int room);

void print_wrong_input();

void print_load_config();

void print_fell_in_pit();

void print_game_over();

void print_smell_wumpus();

void print_gepakt_wumpus();

void print_shoot_or_move();

void print_user_shoot(int & room_shot);

void print_wumpus_hit();

void print_arrow_inventory(int arrows);

void print_current_room(int room);

void print_wumpus_miss();

void print_pick_up_bat();

void print_smell_bat();

void print_map(const std::vector<int> & rooms, const std::vector<int> & bottemless_pits, 
int locatie_wumpus, const std::vector<int> & room_bat);

void print_roadmap();

void print_instructions_menu();

void print_AI();

void print_stats_menu();

void print_turns(int turns);

void print_average();

void print_AI_turn(int turns);

void treasure_open();

void print_snake_bite();


#endif /* _PRINT_HPP */
