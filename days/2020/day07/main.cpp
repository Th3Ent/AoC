#include <string>
#include <SourceReader.h>

const std::string path = "../../../days/2022/";

class DayOfTodayAoC{
 public:

   SourceReader* src;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);

  }

  int computeFirstStar() {

    std::cout << "Primera estrella" << std::endl;
    return 0;
  }


  int computeSecondStar() {



    std::cout << "Segunda estrella" << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day01/input.txt";
  std::string testInputFile = "day01/test.txt";
#if 1
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
