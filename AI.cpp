#include "AI.hpp"
#include "calculations.hpp"
#include "config.hpp"
#include "gameplay.hpp"
#include "print.hpp"
#include "printInstructions.hpp"
#include "randomGenerate.hpp"
#include "statistics.hpp"


int close_wumpus             = 0;
int pointer_counter          = 0;
int pointer_counter_opposite = 0;

char direction_pointer = 'R';

std::vector<int> tried_rooms = {};

bool play_AI(){
	char approval_config = {};
	
	print_AI();
	
	while(true){
		std::cin >> approval_config;
		if(approval_config == 'j' || approval_config == 'J'){
			return true;
		}
		else if(approval_config == 'n' || approval_config == 'N'){
			return false;
		}
		else{
			print_wrong_input();
		}
	}
	
}


bool AI_shoot_or_move(int room, const std::vector<int> rooms, int & arrows, int & wumpus_location, 
bool wumpus, bool bats, int turns){
	print_room_options(room, rooms); 
	print_shoot_or_move(); 
	
	char AI_option = {};
	
	while(true){
		if(wumpus == 1){
			close_wumpus++;
			AI_option =	 AI_dicesion_m_or_s(room, rooms, arrows, wumpus_location, wumpus, bats, close_wumpus);
		}
		else{
			close_wumpus = 0;
			AI_option =	 AI_dicesion_m_or_s(room, rooms, arrows, wumpus_location, wumpus, bats, 0);
		}
		if(AI_option == 's' || AI_option == 'S'){
			AI_shoot(room, rooms, arrows, wumpus_location, turns);
			break;
		}
		else if(AI_option == 'b' || AI_option == 'B'){
			return false;
		}
		else{
			print_wrong_input();
		}
	}
	
	return 0;
	
}


char AI_dicesion_m_or_s(int room, const std::vector<int> rooms, int & arrows, int & wumpus_location, 
bool wumpus, bool bats, int close_wumpus){
	if(close_wumpus == 2){
		std::cout << "s" << std::endl; 
		return 's';
	}
	else if(close_wumpus == 1){
		std::cout << "b" << std::endl; 
		return 'b';
	}
	else{
		std::cout << "b" << std::endl; 
		return 'b';
	}
	
}


int AI_movement(int room, const std::vector<int> & rooms){
	print_room_options(room, rooms);

	tried_rooms.push_back(room);
	
	int right	 = right_chamber(room, rooms);
	int left	 = left_chamber(room, rooms);
	int opposite = opposite_chamber(room, rooms);
	int direction = {};
	
	direction = AI_direction(right, left, opposite);
	
	if(direction == right || direction == left || direction == opposite){
		print_current_room_true(room);
	}
	
	std::cout << direction << std::endl;
	
	return direction;
	
}


int AI_direction(int right, int left, int opposite){
	std::vector<int> possibilities = {right, left, opposite};
	
	for(unsigned int i = 0; i < tried_rooms.size(); i++){
		if(tried_rooms[i] == right){
			possibilities.erase(std::remove(possibilities.begin(), possibilities.end(), right), possibilities.end());
		}
		if(tried_rooms[i] == opposite){
			possibilities.erase(std::remove(possibilities.begin(), possibilities.end(), opposite), possibilities.end());
		}
		if(tried_rooms[i] == left){
			possibilities.erase(std::remove(possibilities.begin(), possibilities.end(), left), possibilities.end());
		}
	}
	sleep(1);
	
	if(direction_pointer == 'R'){
		if(pointer_counter == 2){
			direction_pointer = 'O';
		}
		pointer_counter++;
		
		return right;
	}
	else if(direction_pointer == 'O'){
		direction_pointer = 'R';
		pointer_counter = 0;
		return opposite;
	}
	
	return 0;
	
}


void AI_shoot(int room, const std::vector<int> & rooms, int & arrows, int & wumpus_location, int turns){
	int room_shot = {}; 
	int hit		  = false;
	
	int right	 = right_chamber(room, rooms);
	int left	 = left_chamber(room, rooms);
	int opposite = opposite_chamber(room, rooms);
	
	std::cout << "SCHIET NAAR KAMER: ";
	
	room_shot = AI_shoot_room(right, left, opposite);
	
	std::cout << room_shot << std::endl;
	
	if(room_shot == wumpus_location){
		print_wumpus_hit();
		write_stats(turns);
		
		print_turns(turns);
		print_average();
		
		exit(0);
	}
	else{
		print_wumpus_miss();
		arrows = arrows -1;
		if(arrows == 0){
			print_game_over();
			exit(0);
		}
		print_arrow_inventory(arrows);
		wumpus_location = wumpus_start_location(rooms[rooms.size()-1]);
		tried_rooms = {};
	}
	
	print_current_room(room);
 
}


int AI_shoot_room(int right, int left, int opposite){
	std::vector<int> possibilities = {right, left, opposite};

	for(unsigned int i = 0; i < tried_rooms.size(); i++){
		if(tried_rooms[i] == right){
			possibilities.erase(std::remove(possibilities.begin(), possibilities.end(), right), possibilities.end());
		}
		if(tried_rooms[i] == opposite){
			possibilities.erase(std::remove(possibilities.begin(), possibilities.end(), opposite), possibilities.end());
		}
		if(tried_rooms[i] == left){
			possibilities.erase(std::remove(possibilities.begin(), possibilities.end(), left), possibilities.end());
		}
	}
	
	sleep(1);
	
	return possibilities[0];
	
}
