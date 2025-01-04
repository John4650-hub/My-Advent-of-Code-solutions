#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

/**
 * takes the file path 
 * and reads file line by line
 * returns a vector containing each line
 **/
std::vector<std::string> readlines(const std::string& file_path){
  std::ifstream file(file_path);
  std::vector<std::string> text_lines;
  if(!file){
    std::cerr << "Unable to open file";
  }
  std::string line;
  while(std::getline(file,line)){
    text_lines.push_back(line);
  }
  return text_lines;
}

std::vector<std::string> splitString(const std::string& str ,const std::string& delim){
  std::vector<std::string> tokens;
  size_t start = 0;
  size_t end = str.find(delim);

  while(end != std::string::npos){
    tokens.push_back(str.substr(start,end - start));
    start = end + delim.length();
    end = str.find(delim, start);
  }
  tokens.push_back(str.substr(start));
  return tokens;
}

int main() {
  std::vector<std::string> data = readlines("./testInput.txt");
  std::vector<int> col1;
  std::vector<int> col2;
  std::vector<std::string> temp_list;
  int total_distance{};

  for(std::string data_point : data){
    temp_list = splitString(data_point,"   ");
    col1.push_back(std::stoi(temp_list[0]));
    col2.push_back(std::stoi(temp_list[1]));
  }
  std::sort(col1.begin(),col1.end());
  std::sort(col2.begin(),col2.end());

  int index=0;
  for(int i:col1){
    total_distance += abs(i-col2[index]);
    index+=1;
  }
  std::cout << total_distance<<"\n";
  return 0;
}
