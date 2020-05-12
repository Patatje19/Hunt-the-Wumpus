#include "wumpus.hpp"


int main(){
	int locatie_wumpus  = -99;
	int player_location = -99;
	
	int arrows = -99;
	
	std::vector<int> rooms           = {};
	std::vector<int> room_bat        = {};
	std::vector<int> bottemless_pits = {};
	
	bool approval = config_file();
	
	if(approval == 1){
		int room_size = read_config_room_number();
		rooms         = room_generator(room_size);
		
		bottemless_pits = read_config_bottemless_pits();
		room_bat        = read_config_room_bat();
		locatie_wumpus  = read_config_wumpus_location();
		player_location = read_config_player_location(bottemless_pits, locatie_wumpus, room_bat);
		arrows          = read_config_arrow_number();
	}
	else{
		int room_size = 20;
		rooms         = room_generator(room_size);
		
		bottemless_pits = bottemless_pit_generator(room_size);
		room_bat        = generate_room_bat(room_size);
		locatie_wumpus  = wumpus_start_location(room_size);
		player_location = player_start_location(bottemless_pits, locatie_wumpus, rooms[rooms.size()-1], room_bat);
		arrows          = 5;
	}
	
	int current_room = player_location;
	
	print_start(player_location); 
	
	while(true){
		check_bottemless_pits(current_room, bottemless_pits);
		check_wumpus(current_room, locatie_wumpus);
		
		if(check_bat(current_room, room_bat, rooms) == 1){
			current_room = generate_random_room(rooms);
			print_current_room(current_room);
		}
		else{
			smell_wumpus(current_room, locatie_wumpus, rooms);
			smell_bat(current_room, room_bat, rooms);
			approval = user_shoot_or_move(current_room, rooms ,arrows, locatie_wumpus);
			
			if(approval == 0){
				current_room = user_movement(current_room, rooms);
			}
		}
	}

	return 0;
	
}
