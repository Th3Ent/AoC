#include <string>
#include <algorithm>    // std::sort
#include <SourceReader.h>

const std::string path = "../../../days/2022/";

class DayOfTodayAoC{
 public:

   SourceReader* src;
   std::vector<unsigned int> calories;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);

    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line){
        if ("" == line) {
          calories.push_back(0);
        }
        else {
          calories.push_back(std::stoi(line));
        }
      });


  }

  int computeFirstStar() {

    std::cout << "Primera estrella" << std::endl;

    unsigned int max = 0;
    unsigned int counter = 0;

    std::for_each(calories.begin(), calories.end(), [&](unsigned int i) {
      if (0 == i) {
        if (max < counter) {
          max = counter;
        }
        counter = 0;
      }

      counter += i;

    });

    if (max < counter) {
      max = counter;
    }

    printf("Solution First Star %d \n", max);

    return 0;
  }


  int computeSecondStar() {

    std::cout << "Segunda estrella" << std::endl;

    std::vector<int> totalCalories;

    unsigned int counter = 0;

    std::for_each(calories.begin(), calories.end(), [&](unsigned int i) {
      
      if (0 == i) {
        totalCalories.push_back(counter);
        counter = 0;
      }

      counter += i;

    });

    totalCalories.push_back(counter);
    
    std::sort(totalCalories.begin(), totalCalories.end(), std::greater<unsigned int>());

    unsigned int totalSum = totalCalories[0] + totalCalories[1] + totalCalories[2];

    printf("Solution Second Star %d \n", totalSum);


    return 0;
  }


};

int main() {


  std::string inputFile = "day01/input.txt";
  std::string testInputFile = "day01/test.txt";
  DayOfTodayAoC execute(inputFile);

  execute.computeFirstStar();

  execute.computeSecondStar();

  std::cin;

}
