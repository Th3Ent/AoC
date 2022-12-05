#include <string>
#include <algorithm>
#include <SourceReader.h>

const std::string path = "../../../days/2020/";

class DayOfTodayAoC{
 public:

   SourceReader* src;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);

    //std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {



    //});

  }

  unsigned long long checkSlope(unsigned int downIncrement, unsigned int rightIncrement) {
    unsigned int right = 0;
    unsigned int down = 0;
    unsigned int tree = 0;
    for (down = 0; down < src->get_size(); down+= downIncrement) {

      if (src->get_data(down).at(right) == '#') {
        tree++;
      }

      right += rightIncrement;
      right = right % src->get_data(0).size();
    }
    return tree;
  }

  int computeFirstStar() {

    unsigned int tree = checkSlope(1,3);

    std::cout << "Primera estrella "<<tree << std::endl;
    return 0;
  }


  int computeSecondStar() {

    unsigned long long tree13 = checkSlope(1, 3);
    unsigned long long tree11 = checkSlope(1, 1);
    unsigned long long tree15 = checkSlope(1, 5);
    unsigned long long tree17 = checkSlope(1, 7);
    unsigned long long tree21 = checkSlope(2, 1);

    unsigned long long result = tree11 * tree13 * tree15 * tree17 * tree21;

    std::cout << "Segunda estrella "<< result << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day03/input.txt";
  std::string testInputFile = "day03/test.txt";
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
