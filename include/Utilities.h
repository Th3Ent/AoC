#include <string>
#include <vector>

inline std::vector<std::string> splitString(std::string stringToSplit, std::string delimiter) {

  size_t pos = 0;
  std::string token;
  std::vector<std::string> outVector;

  while ((pos = stringToSplit.find(delimiter)) != std::string::npos) {
    token = stringToSplit.substr(0, pos);
    outVector.push_back(token);
    stringToSplit.erase(0, pos + delimiter.length());
  }
  outVector.push_back(stringToSplit);


  return outVector;
}

inline void splitString(std::string stringToSplit, std::string delimiter, std::vector<std::string> out) {

  size_t pos = 0;
  std::string token;
 

  while ((pos = stringToSplit.find(delimiter)) != std::string::npos) {
    token = stringToSplit.substr(0, pos);
    out.push_back(token);
    stringToSplit.erase(0, pos + delimiter.length());
  }
  out.push_back(stringToSplit);

}

inline std::vector<int> splitStringInToInts(std::string stringToSplit, std::string delimiter) {

  size_t pos = 0;
  std::string token;
  std::vector<int> outVector;

  while ((pos = stringToSplit.find(delimiter)) != std::string::npos) {
    token = stringToSplit.substr(0, pos);
    outVector.push_back(std::stoi(token));
    stringToSplit.erase(0, pos + delimiter.length());
  }
  outVector.push_back(std::stoi(stringToSplit));


  return outVector;
}



inline void splitStringInToInts(std::string stringToSplit, std::string delimiter, std::vector<int> &out) {

  size_t pos = 0;
  std::string token;

  while ((pos = stringToSplit.find(delimiter)) != std::string::npos) {
    token = stringToSplit.substr(0, pos);
    out.push_back(std::stoi(token));
    stringToSplit.erase(0, pos + delimiter.length());
  }
  out.push_back(std::stoi(stringToSplit));

}

inline void indexToRowAndCol(int index, int width, int height, int &row, int &col) {



}

inline void rowAndColToIndex(int& index, int width, int height, int row, int col) {

  index = width * row + col;

}