#include <SourceReader.h>


SourceReader::SourceReader(std::string file){
  std::string line;
  std::ifstream myfile (file);
        if (myfile.is_open()){
            while ( getline (myfile,line) ){
                myvector.push_back(line);
            }
            myfile.close();
        }
        else {
          std::cout << "Something goes wrong, the file could not be opened" << std::endl;
        }
}

std::string SourceReader::get_data(int i){
    return myvector[i];
}

void SourceReader::set_data(std::string data, int i){
    myvector[i] = data; 
}

int SourceReader::get_size(){
    return myvector.size();
}

std::vector<std::string>& SourceReader::getVector(){
  return myvector;
}



