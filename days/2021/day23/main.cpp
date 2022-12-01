#include <string>
#include <SourceReader.h>


class DayOfTodayAoC{
 public:

   SourceReader* src;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(file);

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

  std::string inputFile = "input.txt";
  DayOfTodayAoC execute(inputFile);

  execute.computeFirstStar();

  execute.computeSecondStar();

  std::cin;

}
