#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class SourceReader {
 public:

  SourceReader(std::string file);

  std::string get_data(int i);

  void set_data(std::string data, int i);

  int get_size();

  std::vector<std::string>& getVector();

 private:

   std::vector<std::string> myvector;

};