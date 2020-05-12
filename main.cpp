#include "AI.hpp"
#include "calculations.hpp"
#include "config.hpp"
#include "gameplay.hpp"
#include "print.hpp"
#include "printInstructions.hpp"
#include "randomGenerate.hpp"
#include "statistics.hpp"


int main(){
	int locatie_wumpus  = {};
	int player_location = {};

	int arrows   = {};

	int turns    = 0;

	int treasure       = {};
	int treasure_opens = 0;

	std::vector<int> rooms           = {};
	std::vector<int> room_bat        = {};
	std::vector<int> bottemless_pits = {};

	bool approval = {};
	bool AI       = {};

	if(instructions() == 1){
		print_instructions();
	}

	approval = config_file();

	if(play_AI() == 1){
		approval = 0;
		AI = 1;
	}
	else{
		AI = 0;
	}

	if(approval == 1){
		int room_size = read_config_room_number();
		rooms		  = room_generator(room_size);
		
		bottemless_pits = read_config_bottemless_pits();
		room_bat		= read_config_room_bat();
		locatie_wumpus	= read_config_wumpus_location();
		player_location = read_config_player_location(bottemless_pits, locatie_wumpus, room_bat);
		treasure		= read_config_treasure_location();
		arrows			= read_config_arrow_number();
	}
	else{
		int room_size = 20;
		rooms		  = room_generator(room_size);
		
		bottemless_pits = bottemless_pit_generator(room_size);
		room_bat		= generate_room_bat(room_size);
		locatie_wumpus	= wumpus_start_location(room_size);
		player_location = player_start_location(bottemless_pits, locatie_wumpus, rooms[rooms.size()-1], room_bat);
		sleep(1);
		treasure		= treasure_location(room_size);
		arrows			= 5;
	}
    
	int current_room = player_location;

	print_start(player_location); 

	if(AI == 0){
		while(true){		
			if(check_bottemless_pits(current_room, bottemless_pits) == 1){
				break;
			}
			
			if(check_wumpus(current_room, locatie_wumpus) == 1){
				break;
			}
			
			if(check_bat(current_room, room_bat, rooms) == 1){
				current_room = generate_random_room(rooms);
				print_current_room(current_room);
			}
			
			if(check_treasure(current_room, treasure, treasure_opens) == 1 && treasure_opens == 0){
				int item_picker = open_treasure();
				
				treasure_opens++;
				
				if(item_picker == 1){
					arrows = arrows + 2;
					print_arrow_inventory(arrows);
				}
				else if(item_picker == 2){
					print_map(rooms, bottemless_pits, locatie_wumpus, room_bat);
				}
				else if(item_picker == 3){
					print_snake_bite();
					print_game_over();
					
					break;
				}
			}
			
			else{
				smell_wumpus(current_room, locatie_wumpus, rooms);
				smell_bat(current_room, room_bat, rooms);
				approval = user_shoot_or_move(current_room, rooms ,arrows, locatie_wumpus, turns);
				
				if(arrows == 0){
					print_game_over();
					break;
				}
				
				turns++;
				
				if(approval == 0){
					current_room = user_movement(current_room, rooms);
				}
			}
		}
		
		if(roadmap() == 1){
			print_map(rooms, bottemless_pits, locatie_wumpus, room_bat);
		}
		
	}
	else{
		while(true){
			if(check_bottemless_pits(current_room, bottemless_pits) == 1){
				break;
			}
			
			if(check_wumpus(current_room, locatie_wumpus) == 1){
				break;
			}
			
			bool wumpus_check = smell_wumpus(current_room, locatie_wumpus, rooms);
			bool bat_check	  = smell_bat(current_room, room_bat, rooms);
			
			approval = AI_shoot_or_move(current_room, rooms, arrows, locatie_wumpus, wumpus_check, bat_check, turns);
			
			turns++;
			
			print_AI_turn(turns);
			
			if(approval == 0){
				current_room = AI_movement(current_room, rooms);
			}
		}
	}

	return 0;

}
