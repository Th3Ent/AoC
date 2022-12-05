#include <string>
#include <algorithm>
#include <SourceReader.h>
#include <Utilities.h>  
#include <stack>

const std::string path = "../../../days/2022/";

struct Movements {

  unsigned int numOfCrates = 0;
  unsigned int origin = 0 ;
  unsigned int destiny = 0 ;

  void doMovementFirstStar(std::vector<std::stack<char>>& stacks) {

    for (int i = 0; i < numOfCrates; i++) {
      char crate = stacks[origin-1].top();
      stacks[origin-1].pop();
      stacks[destiny-1].push(crate);
    }

  }

  void doMovementSecondStar(std::vector<std::stack<char>>& stacks) {

    std::vector<char> cratesToMoved;

    for (int i = 0; i < numOfCrates; i++) {
      char crate = stacks[origin - 1].top();
      stacks[origin - 1].pop();
      cratesToMoved.push_back(crate);
    }
    std::reverse(cratesToMoved.begin(), cratesToMoved.end());
    for (int i = 0; i < cratesToMoved.size(); i++) {
      stacks[destiny - 1].push(cratesToMoved[i]);
    }

  }

};

class DayOfTodayAoC {
public:

  SourceReader* src;

  std::vector<std::stack<char>> stacksFirst;
  std::vector<std::stack<char>> stacksSecond;
  std::vector<std::vector<char>> vStacks;
  std::vector<Movements> movements;

  DayOfTodayAoC(std::string file, int numLines) {

    for (int i = 0; i < 9; i++) {
      stacksFirst.push_back(std::stack<char>());
      stacksSecond.push_back(std::stack<char>());
      vStacks.push_back(std::vector<char>());
    }

    src = new SourceReader(path + file);
    //std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {

    //});

    for (int i = 0; i < numLines; i++) {

      std::string line = src->get_data(i);

      int index = 0;
      int fixedIndex = 0;
      while (fixedIndex < line.size()) {

        if (line.at(fixedIndex) != ' ') {
          vStacks[index].push_back(line.at(fixedIndex+1));
        }

        index++;
        fixedIndex += 4;
      }

    }

    for (int i = 0; i < vStacks.size(); i++) {
      for (int j = vStacks[i].size()-1; j >= 0; j--) {
        stacksFirst[i].push(vStacks[i][j]);
        stacksSecond[i].push(vStacks[i][j]);
      }
    }

    for (int i = numLines+1; i < src->get_size(); i++) {

      std::string line = src->get_data(i);
      std::vector<std::string> movement = splitString(line, " ");
      Movements move;
      move.numOfCrates = std::stoi(movement[1]);
      move.origin = std::stoi(movement[3]);
      move.destiny = std::stoi(movement[5]);
      movements.push_back(move);
    }

  }

  int computeFirstStar() {

    unsigned int total = 0;

    std::for_each(movements.begin(), movements.end(), [&](Movements move) {

      move.doMovementFirstStar(stacksFirst);

    });

    std::for_each(stacksFirst.begin(), stacksFirst.end(), [&](std::stack<char> stack) {
      if(!stack.empty())
        std::cout << stack.top();

    });
    std::cout << std::endl;
    std::cout << "Primera estrella " << total << std::endl;
    return 0;
  }


  int computeSecondStar() {

    unsigned int total = 0;

    std::for_each(movements.begin(), movements.end(), [&](Movements move) {

      move.doMovementSecondStar(stacksSecond);

      });

    std::for_each(stacksSecond.begin(), stacksSecond.end(), [&](std::stack<char> stack) {
      if (!stack.empty())
      std::cout << stack.top();

      });
    std::cout << std::endl;

    std::cout << "Segunda estrella " << total << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day05/input.txt";
  std::string testInputFile = "day05/test.txt";


  std::cout << "Test" << std::endl;
  DayOfTodayAoC executeTest(testInputFile,4);
  executeTest.computeFirstStar();
  executeTest.computeSecondStar();

  std::cout << std::endl << std::endl << "Input" << std::endl;
  DayOfTodayAoC executeInput(inputFile,9);
  executeInput.computeFirstStar();
  executeInput.computeSecondStar();



  std::cin;

}
