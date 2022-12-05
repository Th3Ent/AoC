#include <string>
#include <algorithm>
#include <SourceReader.h>

const std::string path = "../../../days/2020/";

class DayOfTodayAoC{
 public:

   SourceReader* src;
   std::vector<unsigned int> data;
  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);

    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {

      data.push_back(std::stoi(line));
      
    });

  }

  int computeFirstStar() {

    for (int i = 0; i < data.size(); i++) {
      for (int j = 0; j < data.size(); j++) {
        if (data[i] + data[j] == 2020) {
          std::cout << "Primera estrella "<<data[i]*data[j] << std::endl;
          return 0;
        }
      }
    }

    return 0;
  }


  int computeSecondStar() {



    for (int i = 0; i < data.size(); i++) {
      for (int j = 0; j < data.size(); j++) {
        for (int k = 0; k < data.size(); k++) {
          if (data[i] + data[j] + data[k] == 2020) {
            std::cout << "Segunda estrella " << data[i] * data[j] * data[k] << std::endl;
            return 0;
          }
        }
      }
    }
    return 0;
  }


};

int main() {

  std::string inputFile = "day01/input.txt";
  std::string testInputFile = "day01/test.txt";
#if 0
  DayOfTodayAoC executeTest(testInputFile);
  executeTest.computeFirstStar();
  executeTest.computeSecondStar();
#else
  DayOfTodayAoC executeInput(inputFile);
  executeInput.computeFirstStar();
  executeInput.computeSecondStar();
#endif


  std::cin;

}
