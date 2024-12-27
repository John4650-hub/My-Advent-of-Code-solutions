#include <iostream>
#include <fstream>
#include <string>
#include <sstring>
#include <vector>

using namespace std;

vector<string> split(const string& str, const string& delimiter) {
    vector<string> tokens;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }
    
    // Add the last token
    tokens.push_back(stio(str.substr(start)));

    return tokens;
}

int main()
{
ifstream file("../../../input/testInput.txt");

  if(!file.is_open()){
    cerr << "Unable to open file" << endl;
    return 1;
  }

  string line;
  while(getline(file , line)) {
    cout << line << endl;
    line.pop_back(); //remove newline character

  }
  return 0;
}
