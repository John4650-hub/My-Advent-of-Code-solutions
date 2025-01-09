#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <cstdlib>

std::vector<std::string> split_str(const std::string& str,const std::string& delim){
	std::vector<std::string> tokens;
	size_t start = 0;
	size_t end = str.find(delim);
	while(end != std::string::npos){
		tokens.push_back(str.substr(start,end-start));
		start = end+delim.length();
		end = str.find(delim,start);
	}
	tokens.push_back(str.substr(start));
	return tokens;
}

int get_prod_sum(std::vector<std::string> cmds){
	std::regex pattern("\\d{1,3},\\d{1,3}");
	std::smatch matches;
	int total{};
	for(std::string cmd:cmds){
		std::sregex_iterator it(cmd.begin(),cmd.end(),pattern);
		std::sregex_iterator end;
		while(it!=end){
			std::vector<std::string> num = split_str(it->str(),",");
			total += std::atoi(num[0].c_str()) * std::atoi(num[1].c_str());
			++it;
		}
	}
	return total;
}

std::vector<std::string> read_lines(const std::string& file_path){
	std::ifstream file(file_path);
	std::vector<std::string> file_lines;
	std::string line;
	if(!file)
		std::cerr << "file not found";
	while(std::getline(file,line))
		file_lines.push_back(line);
	return file_lines;
}

int main(){
	std::regex pattern("mul\\(\\d{1,3},\\d{1,3}\\)");
	std::smatch matches;
	std::vector<std::string> cmds; //for commands
	std::vector<std::string> puzzle=read_lines("./foo.txt");
	std::string data="";
	for(std::string str:puzzle){
		data+=str;
	}
	std::sregex_iterator it(data.begin(),data.end(),pattern);
	std::sregex_iterator end;
	while(it != end){
		cmds.push_back(it->str());
		++it;
	}
	int sum = get_prod_sum(cmds);
	std::cout<<sum<<"\n";
}
