#include "wumpus.hpp"


void print_start(int room){
	std::cout << "HUNT THE WUMPUS" << std::endl;
	std::cout << "JE BENT IN KAMER " << room << std::endl;
	
}


void print_room_options(int room, const std::vector<int> & rooms){
	std::cout << "TUNNELS LEIDEN NAAR ";
	std::cout << left_chamber(room, rooms) << " ";
	std::cout << right_chamber(room) << " ";
	std::cout << opposite_chamber(room, rooms) << std::endl;
	
}


void print_user_movement(int & room){
	std::cout << "WAARHEEN? ";
	std::cin >> room;
	
}


void print_current_room_true(int & room){
	std::cout << "JE BENT IN KAMER " << room << std::endl;
	
}


void print_current_room_false(){
	std::cout << "NIET MOGELIJK!!!" << std::endl;
	
}
