#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

std::vector<std::string> readLines(const std::string& file_path){
  std::ifstream file(file_path);
  std::vector<std::string> file_lines;
  std::string line;

  if(!file)
    std::cerr << "file not found";

  while (std::getline(file,line))
    file_lines.push_back(line);

  return file_lines;
}

std::vector<std::string> split_string(const std::string& str,const std::string& delim){
  std::vector<std::string> tokens;
  size_t start =0;
  size_t end = str.find(delim);

  while(end != std::string::npos){
    tokens.push_back(str.substr(start,end - start));
    start = end + delim.length();
    end = str.find(delim,start);
  }
  tokens.push_back(str.substr(start));
  return tokens;
}

bool all(bool* arr,int size){
  for(int i=0;i<size;i++){
    if(!arr[i]){
      return false;
    }
  }
  return true;
}

bool is_report_safe(int* arr,int size){
  bool increasing[size-1];
  bool decreasing[size-1];
  for(int i=0;i<size;i++){
    increasing[i] = 1<=arr[i+1]-arr[i] && arr[i+1] - arr[i]<=3;
    decreasing[i] = 1<=arr[i]-arr[i+1] && arr[i]-arr[i+1]<=3;
  }
  return all(increasing,size-1) || all(decreasing,size-1);
}

bool check_level_removal(int* arr,int size){
  if(is_report_safe(arr,size))
    return true;
  for(int i=0;i<size;i++){
    std::vector<int> vec;
    for(int j=0;j<size;j++){
      if(i!=j){
	vec.push_back(arr[j]);
      }
    }
    int newArr[vec.size()];
    for(int k=0;k<vec.size();k++){
      newArr[k]=vec[k];
    }
    if(is_report_safe(newArr,size-1))
      return true;
  }
  return false;
}

int main(){
  int safe{};
  std::vector<std::string> puzzle=readLines("./foo.txt");
  std::vector<std::string> temp_str_report;
  for(std::string line:puzzle){
    temp_str_report = split_string(line," ");
    int sz = temp_str_report.size();
    int temp_int_report[sz];
    int ct=0;
    for(std::string lv:temp_str_report){
      temp_int_report[ct] = std::atoi(lv.c_str());
      ct++;
    }
    if(check_level_removal(temp_int_report,sz))
      safe+=1;
  }
  std::cout<<safe<<"\n";
}
