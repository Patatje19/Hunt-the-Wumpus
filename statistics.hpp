#ifndef _STATISTICS_HPP
#define _STATISTICS_HPP


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <unistd.h>


std::string stats_line_finder(int line_to_find);

int read_stats();

void write_stats(int counter);


#endif /* _STATISTICS_HPP */