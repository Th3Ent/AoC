#include <string>
#include <algorithm>    // std::sort
#include <SourceReader.h>
#include <Utilities.h>

const std::string path = "../../../days/2022/";

struct Battle {
  int myChoose;
  int myOponnentChoose;
  
  int points;

  void recalculate(){
  
    if (myChoose == 1) {
      if (myOponnentChoose == 1) {
        myChoose = 3;
      }
      else if (myOponnentChoose == 2) {
        myChoose = 1;
      }
      else {
        myChoose = 2;
      }
    }
    else if (myChoose == 2) {
      if (myOponnentChoose == 1) {
        myChoose = 1;
      }
      else if (myOponnentChoose == 2) {
        myChoose = 2;
      }
      else {
        myChoose = 3;
      }
    }
    else {
      if (myOponnentChoose == 1) {
        myChoose = 2;
      }
      else if (myOponnentChoose == 2) {
        myChoose = 3;
      }
      else {
        myChoose = 1;
      }
    }
  
  }

  void fight() {
    int result = myChoose - myOponnentChoose;
    if (result == -1 ||result == 2) {
      result = 0;
    }
    else if (result == 1 || result == -2) {
      result = 6;
    }
    else {
      result = 3;
    }

    points = myChoose + result;
  }
};

class DayOfTodayAoC{
 public:

   SourceReader* src;
   std::vector<Battle> battles;
  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);

    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {

      std::vector<std::string> options = splitString(line, " ");


      Battle battle;
      if (options[0] == "A") {
        battle.myOponnentChoose = 1;
      }
      else if (options[0] == "B") {
        battle.myOponnentChoose = 2;
      }
      else {
        battle.myOponnentChoose = 3;
      }

      if (options[1] == "X") {
        battle.myChoose = 1;
      }
      else if (options[1] == "Y") {
        battle.myChoose = 2;
      }
      else {
        battle.myChoose = 3;
      }

      battle.fight();

      battles.push_back(battle);
    });

  }

  int computeFirstStar() {

    unsigned int totalScore = 0;

    std::for_each(battles.begin(), battles.end(), [&](Battle b) {

      totalScore += b.points;
      
    });


    std::cout << "First Star " << totalScore << std::endl;
    return 0;
  }


  int computeSecondStar() {

    unsigned int totalScore = 0;

    std::for_each(battles.begin(), battles.end(), [&](Battle b) {
      b.recalculate();
      b.fight();
      totalScore += b.points;

      });

    std::cout << "Second Star " <<totalScore<< std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day02/input.txt";
  std::string testInputFile = "day02/test.txt";
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
