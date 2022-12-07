#include <string>
#include <algorithm>
#include <set>
#include <SourceReader.h>

const std::string path = "../../../days/2022/";

class DayOfTodayAoC{
 public:

   SourceReader* src;

   std::string dataStream;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);
    
    dataStream = src->get_data(0);
    
    //std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {
    //
    //});
  }

  bool checkAllDiferent(std::string line) {
    std::set<char> characters;
    unsigned int lineSize = line.size();

    for (int i = 0; i < lineSize; i++) {
      characters.insert(line.at(i));
    }

    return characters.size() == lineSize;
  }

  unsigned int findMarker(std::string dataStream, unsigned int markerLenght) {

    for (unsigned int i = 0; i + markerLenght < dataStream.size(); i++) {

      std::string posibleMarker = dataStream.substr(i, markerLenght);
      if (checkAllDiferent(posibleMarker)) {
        return i+markerLenght;
      }

    }

    return 0;

  }

  int computeFirstStar() {

    std::cout << "First Star "<< findMarker(dataStream,4) << std::endl;
    return 0;

  }


  int computeSecondStar() {

    std::cout << "Second Star "<< findMarker(dataStream, 14) << std::endl;
    return 0;

  }


};

int main() {

  std::string inputFile = "day06/input.txt";
  std::string testInputFile = "day06/test.txt";


  std::cout << "Test" << std::endl;
  DayOfTodayAoC executeTest(testInputFile);
  executeTest.computeFirstStar();
  executeTest.computeSecondStar();

  std::cout << std::endl<< std::endl<< "Input" << std::endl;
  DayOfTodayAoC executeInput(inputFile);
  executeInput.computeFirstStar();
  executeInput.computeSecondStar();



  std::cin;

}
