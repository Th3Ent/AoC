#include <string>
#include <SourceReader.h>
#include <Utilities.h>
#include <unordered_map>

const std::string path = "../../days/2021/";

class DayOfTodayAoC {
public:

  SourceReader* src;


  std::unordered_map<int, unsigned long unsigned long int> fishMap;
  std::vector<int> daysToGrown;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);

    splitStringInToInts(src->getVector()[0], ",", daysToGrown);

    for (int i = 0; i < daysToGrown.size(); i++) {

      if (fishMap.end() ==  fishMap.find(daysToGrown[i])) {

        fishMap.insert_or_assign(daysToGrown[i], 1L);
      }
      else {
        unsigned long unsigned long int numberOfFish = fishMap.at(daysToGrown[i]);
        fishMap.erase(daysToGrown[i]);
        fishMap.insert_or_assign(daysToGrown[i], ++numberOfFish);
      }

    }
  }

  int computeFirstStar() {

    for (int j = 0; j < 256;j++)
    {
      std::unordered_map<int,unsigned long unsigned long int> copy;
      unsigned long unsigned long int howManyFishToAdd = 0;
      for (int i = 8; i >= 0; i--) {
        if (fishMap.end() != fishMap.find(i)) {

          if (i > 0) {
            copy.insert_or_assign(i - 1, fishMap.at(i));
          }
          else {
            if (copy.end() != copy.find(6)) {
               unsigned long unsigned long int numberOfFishInStage6 = copy.at(6) + fishMap.at(0);
              copy.erase(6);
              copy.insert_or_assign(6, numberOfFishInStage6);
              howManyFishToAdd = fishMap.at(0);
            
            }
            else {
              copy.insert_or_assign(6, fishMap.at(0));
              howManyFishToAdd = fishMap.at(0);
            }
          }
        }
      }
      if(howManyFishToAdd != 0)
        copy.insert_or_assign(8, howManyFishToAdd);

      //for (int i = 0; i < daysToGrown.size(); i++) {

     //   std::cout << j << " ";

      //}
      //std::cout << std::endl;

      fishMap = copy;
    }

    unsigned long unsigned long int numOfFish = 0UL;
    for (int i = 8; i >= 0; i--) {
      if (fishMap.end() != fishMap.find(i)) {
        numOfFish += fishMap.at(i);

      }
    }
    std::cout << "First star  "<< numOfFish << std::endl;
    return 0;
  }


  int computeSecondStar() {


    std::cout << "Second star  "  << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day06/input.txt";
  std::string testFile = "day06/test.txt";
  DayOfTodayAoC execute(inputFile);

  execute.computeFirstStar();

  execute.computeSecondStar();

  std::cin;

}
