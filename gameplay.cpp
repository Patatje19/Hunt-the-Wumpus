#include "wumpus.hpp"


bool user_shoot_or_move(int & room, const std::vector<int> & rooms, int & arrows, int & wumpus_location){
	print_room_options(room, rooms); 
	print_shoot_or_move(); 
	
	char user_option = ' ';
 
	while(true){
		std::cin >> user_option;
		if(user_option == 's' || user_option == 'S'){
			user_shoot(room, rooms, arrows, wumpus_location);
			break;
		}
		else if(user_option == 'b' || user_option == 'B'){
			return false;
		}
		else{
			print_wrong_input();
		}
	}
	
}


void user_shoot(int & room, const std::vector<int> & rooms, int & arrows, int & wumpus_location){
	int room_shot = 0; 
	int hit		  = false;
	
	int rechts	 = right_chamber(room, rooms);
	int links	 = left_chamber(room, rooms);
	int opposite = opposite_chamber(room, rooms);
	
	while(true){
		print_user_shoot(room_shot);
	
		if(room_shot == rechts || room_shot == links || room_shot == opposite){
			hit_or_miss(room_shot, arrows, wumpus_location, rooms[rooms.size()-1]);
			
			print_current_room(room); 
			break;
		}
		else{
			print_wrong_input();
		}
	}
	
}


int user_movement(int & room, const std::vector<int> & rooms){
	print_room_options(room, rooms);

	int rechts	 = right_chamber(room, rooms);
	int links	 = left_chamber(room, rooms);
	int opposite = opposite_chamber(room, rooms);
	
	while(true){
		print_user_movement(room);
	
		if(room == rechts || room == links || room == opposite){
			print_current_room_true(room);
			break;
		}
		else{
			print_wrong_input();
		}
	}
	
	return room;
	
}


void check_bottemless_pits(int player_location, const std::vector<int> & bottemless_pits){
	for(unsigned i = 0; i < bottemless_pits.size(); i++){
		if(player_location == bottemless_pits[i]){
			print_fell_in_pit();
			print_game_over();
			exit(0);
		}
	}
	
}


void check_wumpus(int player_location, int wumpus_location){
	if(player_location == wumpus_location){
		print_gepakt_wumpus();
		print_game_over();
		exit(0);
	}
	
}


bool smell_wumpus(int current_room, int wumpus_locatie, const std::vector<int> & rooms){
	if(wumpus_locatie == right_chamber(current_room, rooms) || wumpus_locatie == right_chamber(right_chamber(current_room, rooms), rooms)){
		print_smell_wumpus();
		return true;
	}
	else if(wumpus_locatie == left_chamber(current_room, rooms) || wumpus_locatie == left_chamber(left_chamber(current_room, rooms), rooms)){
		print_smell_wumpus();
		return true;
	}
	else if(wumpus_locatie == opposite_chamber(current_room, rooms) || wumpus_locatie == opposite_chamber(opposite_chamber(current_room, rooms), rooms)){
		print_smell_wumpus();
		return true;
	}
	else{
		return false;
	}
	
}


bool config_file(){
	char approval_config = ' ';
	print_load_config();
	
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


void hit_or_miss(int & room, int & arrows, int & wumpus_location, int roomsize){
	if(room == wumpus_location){
		print_wumpus_hit();
		exit(0); 
	}
	else{
		print_wumpus_miss();
		arrows = arrows - 1;
		if(arrows == 0){
			print_game_over();
			exit(0);
		}
		print_arrow_inventory(arrows);
		wumpus_location = wumpus_start_location(roomsize);
	}
	
}


bool check_bat(int player_location, std::vector<int> bat_location, std::vector<int> rooms){
	for(int i = 0; i < bat_location.size(); i++){
		if(player_location == bat_location[i]){
			print_pick_up_bat();
			
			int new_room = generate_random_room(rooms);
			return true;
		}
	}
	
	return false;

}


bool smell_bat(int player_location, std::vector<int> bat_location, std::vector<int> rooms){
	for(int i = 0; i < bat_location.size(); i++){
		if(bat_location[i] == right_chamber(player_location, rooms)){
			print_smell_bat();
			return true;
		}
		else if(bat_location[i] == left_chamber(player_location, rooms)){
			print_smell_bat();
			return true;
		}
		else if(bat_location[i] == opposite_chamber(player_location, rooms)){
			print_smell_bat();
			return true;
		}
		else{
			return false;
		}
	}
	
}
