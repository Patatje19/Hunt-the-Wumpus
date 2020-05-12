#include "wumpus.hpp"


std::vector<int> bottemless_pit_generator(int roomsize){
	std::vector<int> bottemless_pits = {};
	int max_amount = roomsize / 4;
	
	srand(time(NULL));
	
	int number_of_pits = rand() % max_amount + 1;
	
	for(unsigned int i=0; i <=number_of_pits; i++){
		srand(time(NULL));
		int pit_location = rand() % number_of_pits + 1;
		bottemless_pits.push_back(pit_location);
	}
	
	return bottemless_pits;
	
}


int wumpus_start_location(int roomsize){
	srand(time(NULL));
	
	return rand() % roomsize + 1;
	
}

std::vector<int> generate_room_bat(int room_size){
	std::vector<int> room_bat = {};
	int max_value			  = room_size / 10;
	
	srand(time(NULL));
	
	int number_bats = rand() % max_value + 1;
	
	for(int i = 0; i <= number_bats; i++){
		srand(time(NULL));
		
		int bat_location = rand() % number_bats + 1;
		
		room_bat.push_back(bat_location);
	}
	
	return room_bat;
	
}


int generate_random_room(std::vector<int> rooms){
	int max_value = rooms.size();
	
	srand(time(NULL));
	
	int random_room = rand() % max_value + 1;
	
	return random_room;
	
}


int player_start_location(std::vector<int> bottemless_pits, int wumpus_location, int roomsize, std::vector<int> room_bat){
	int player_location = 0;
	
	while(true){
		srand(time(NULL));
		player_location = rand() % roomsize + 1;
		bool check_pits = false;
		bool check_bats = false;
		for(unsigned i = 0; i < bottemless_pits.size(); i++){
			if(bottemless_pits[i] == player_location){
				check_pits = true;
			}
		}
		for(unsigned i = 0; i < room_bat.size(); i++){
			if(room_bat[i] == player_location){
				check_bats = true;
			}
		}
		if(player_location != wumpus_location && check_pits == false && check_bats == false){
			break;
		}
	}
	
	return player_location;
	
}
