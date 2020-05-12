#include "wumpus.hpp"


std::string line_finder(int line_to_find){
	std::ifstream config ("config.txt");
	std::string line = "";
	
	if(config.is_open()){
		for(unsigned i=0; i < line_to_find; i++){
			getline(config, line);
		}
		
		config.close();
		
		return line;
	}
	else{
		return line;
	}
	
}


int read_config_room_number(){
	std::string line = line_finder(1);
	std::string room_number = "";
	
	if(!line.empty()){
		for(unsigned i = 0; i < line.size(); i++){
			if(line[i] == ':'){
				for(unsigned j = i+1; j < line.size(); j++){
					room_number += line[j];
				}
			}
		}
		
		int room = std::stoi (room_number);
		
		return room;
	}
	else{
		return 20;
	}
	
}

std::vector<int> read_config_bottemless_pits(){
	std::string line = line_finder(2);
	std::vector<int> bottemless_pits ={};
	
	if(!line.empty()){
		for(unsigned i = 0; i < line.size(); i++){
			std::string room_number = "";
			if(line[i] == ':' || line[i] == ','){
				for(unsigned j = i+1; j < line.size(); j++){
					if(line[j] == ',' || line[j] == '.'){
						int room = std::stoi (room_number);
						bottemless_pits.push_back(room);
						break;
					}
					room_number += line[j];
				}
			}
		}
		
		return bottemless_pits;
	}
	else{
		return bottemless_pit_generator(20);
	}
	
}


int read_config_wumpus_location(){
	std::string line = line_finder(3);
	std::string room_number = "";
	
	if(!line.empty()){
		for(unsigned i = 0; i < line.size(); i++){
			if(line[i] == ':'){
				for(unsigned j = i+1; j < line.size(); j++){
					room_number += line[j];
				}
			}
		}
		
		int room = std::stoi (room_number);
		
		return room;
	}
	else{
		return wumpus_start_location(20);
	}
	
}


int read_config_player_location(const std::vector<int> & bottemless_pits, int wumpus_location, std::vector<int> room_bat){
	std::string line = line_finder(4);
	std::string room_number = "";
	
	if(!line.empty()){
		for(unsigned i = 0; i < line.size(); i++){
			if(line[i] == ':'){
				for(unsigned j = i+1; j < line.size(); j++){
					room_number += line[j];
				}
			}
		}
		
		int room = std::stoi (room_number);
		
		return room;
		
	}
	else{
		return player_start_location(bottemless_pits, wumpus_location, 20, room_bat);
	}
	
}


int read_config_arrow_number(){
	std::string line = line_finder(5);
	std::string arrow_number = "";
	
	if(!line.empty()){
		for(unsigned i = 0; i < line.size(); i++){
			if(line[i] == ':'){
				for(unsigned j = i+1; j < line.size(); j++){
					arrow_number += line[j];
				}
			}
		}
		
		int arrow = std::stoi (arrow_number);
		
		return arrow;
	}
	else{
		return 5;
	}
	
}

std::vector<int> read_config_room_bat(){
	std::string line = line_finder(6);
	std::vector<int> room_bat = {};
	
	if(!line.empty()){
		for(unsigned i = 0; i < line.size(); i++){
			std::string room_number = "";
			if(line[i] == ':' || line[i] == ','){
				for(unsigned j = i+1; j < line.size(); j++){
					if(line[j] == ',' || line[j] == '.'){
						int room = std::stoi (room_number);
						room_bat.push_back(room);
						break;
					}
					room_number += line[j];
				}
			}
		}
		
		return room_bat;
	}
	else{
		return generate_room_bat(20);
		
	}
	
}
