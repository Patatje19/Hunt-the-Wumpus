#include "AI.hpp"
#include "calculations.hpp"
#include "config.hpp"
#include "gameplay.hpp"
#include "print.hpp"
#include "printInstructions.hpp"
#include "randomGenerate.hpp"
#include "statistics.hpp"


std::string stats_line_finder(int line_to_find){
	std::ifstream stats ("stats.txt");
	std::string line = "";
	
	if(stats.is_open()){
		for(unsigned i=0; i < line_to_find; i++){
			getline(stats, line);
		}
		
		stats.close();
		
		return line;
	}
	else{
		return line;
	}
	
}


int read_stats(){
	std::string line = stats_line_finder(1);
	std::vector<int> number_of_attempts = {};
	
	if(!line.empty()){
		for(unsigned i = 0; i < line.size(); i++){
			std::string room_number = "";
			if(line[i] == ':' || line[i] == ','){
				for(unsigned j = i+1; j < line.size(); j++){
					if(line[j] == ',' || line[j] == '.'){
						int room = std::stoi (room_number);
						number_of_attempts.push_back(room);
						break;
					}
					room_number += line[j];
				}
			}
		}
		
		float average_number_attempts = 0.0;
		
		for(unsigned int i = 0; i < number_of_attempts.size(); i++){
			average_number_attempts += number_of_attempts[i];
		}
		
		return average_number_attempts/number_of_attempts.size();
		
	}
	else{
		return -99;
	
	}
	
}


void write_stats(int counter){
	std::string line        = stats_line_finder(1);
	std::string delete_line = line;
	std::string turns       = {};
	std::string text        = {};
	
	line[line.size()-1] = ',';
	
	turns = std::to_string(counter);
	
	line.append(turns);
	line.append(".");
	
	std::ofstream ostats ("stats.txt");
	std::ifstream istats ("stats.txt");
	
	while (getline(istats, text)) {
		text.replace(text.find(delete_line), delete_line.length(), "");
		ostats << text << std::endl;
	}
	
	ostats << line << std::endl;
	
	ostats.close();
	istats.close();
	
}
