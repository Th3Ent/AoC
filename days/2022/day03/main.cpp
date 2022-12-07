#include <string>
#include <algorithm>
#include <SourceReader.h>

const std::string path = "../../../days/2022/";

struct Rucksack {
  std::string firstPocket = "";
  std::string secondPocket = "";
  std::string bothPockets = "";
  char getCommonLetter() {
    for (int i = 0; i < firstPocket.size(); i++) {
      char letterToCheckFirst = firstPocket.at(i);
      for (int j = 0; j < secondPocket.size(); j++) {
        char letterToCheckSecond = secondPocket.at(j);

        if (letterToCheckFirst == letterToCheckSecond) {
          return letterToCheckFirst;
        }
      }
    }

    return 0;
  }

  unsigned int getPriority(char letter){
  
    if (letter >= 65 && letter <= 90) { // Upper
      return letter - 65 + 27;
    }
    else {
      return letter - 96;
    }
  
  }

};

class DayOfTodayAoC{
 public:

   SourceReader* src;

   std::vector<Rucksack> sacks;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);

    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {
      Rucksack sack;
    sack.bothPockets = line;
      sack.firstPocket = line.substr(0,line.size()/2);
      sack.secondPocket = line.substr(line.size() / 2, line.size());
      sacks.push_back(sack);
    });

  }

  int computeFirstStar() {

    unsigned int total = 0;

    std::for_each(sacks.begin(), sacks.end(), [&](Rucksack sack) {

      total += sack.getPriority(sack.getCommonLetter());
      
    });

    std::cout << "First Star "<<total << std::endl;
    return 0;
  }

  unsigned int getPriority(int i) {
    for (int first = 0; first < sacks[i].bothPockets.size(); first++) {
      char letterFirst = sacks[i].bothPockets.at(first);
      for (int second = 0; second < sacks[i + 1].bothPockets.size(); second++) {
        char letterSecond = sacks[i + 1].bothPockets.at(second);
        for (int third = 0; third < sacks[i + 2].bothPockets.size(); third++) {
          char letterThird = sacks[i + 2].bothPockets.at(third);

          if (letterFirst == letterSecond && letterSecond == letterThird) {
            return sacks[i].getPriority(letterFirst);
          }

        }
      }
    }
    return 0;
  }

  int computeSecondStar() {
    unsigned int total = 0;
    for (int i = 0; i < sacks.size(); i+=3) {


      total += getPriority(i);

    }

    std::cout << "Second Star "<<total << std::endl;
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
