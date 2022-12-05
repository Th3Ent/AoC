#include <string>
#include <algorithm>    // std::sort
#include <SourceReader.h>

const std::string path = "../../../days/2022/";


class DayOfTodayAoC{
 public:

   SourceReader* src;
   std::vector<unsigned int> jolts;
  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);

    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {
      jolts.push_back(std::stoi(line));
      });
    jolts.push_back(0);
    std::sort(jolts.begin(), jolts.end());
    jolts.push_back(jolts[jolts.size()-1] + 3);

  }

  int computeFirstStar() {

    std::cout << "Primera estrella" << std::endl;

    unsigned int diference3 = 0;
    unsigned int diference1 = 0;
    unsigned int previus = jolts[0];
    std::for_each(jolts.begin() + 1, jolts.end(), [&](unsigned int jolt) {

      unsigned int difference = jolt - previus;

      if (1 == difference) {
        diference1++;
      }else if(3 == difference){
        diference3++;
      }

      previus = jolt;
    });

    printf("Difference of 1 %d, difference of 3 %d, solution %d\n", diference1, diference3, diference1*diference3);

    return 0;
  }


  unsigned long long getTotalDistinction(int i, std::vector<unsigned int> input, std::vector<unsigned long long> &cheatSheat) {

    if (i == input.size()-1) {
      return 1;
    }

    if (cheatSheat[i] != 0) {
      return cheatSheat[i];
    }

    long long total = 0;

    for (unsigned int j = i + 1; j < input.size(); j++) {
      if (input[j] - input[i] < 4) {
        total += getTotalDistinction(j, input, cheatSheat);
      }
    }
    cheatSheat[i] = total;
    return total;

  }

  int computeSecondStar() {
    std::vector<unsigned long long> cheatSheat(jolts.size());
    unsigned long long sol = getTotalDistinction(0, jolts, cheatSheat);

    std::cout << "Segunda estrella  "<<sol << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day02/input.txt";
  std::string testInputFile = "day02/test.txt";
  DayOfTodayAoC execute(inputFile);

  execute.computeFirstStar();

  execute.computeSecondStar();

  std::cin;

}
