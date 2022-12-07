#include <string>
#include <algorithm>
#include <SourceReader.h>

const std::string path = "../../../days/2022/";

class DayOfTodayAoC{
 public:

   SourceReader* src;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);
    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {

    });
  }

  int computeFirstStar() {

    unsigned int total = 0;



    std::cout << "First star "<< total << std::endl;
    return 0;
  }


  int computeSecondStar() {

    unsigned int total = 0;



    std::cout << "Second star "<<total << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day05/input.txt";
  std::string testInputFile = "day05/test.txt";


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
