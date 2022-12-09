#include <string>
#include <algorithm>
#include <set>
#include <SourceReader.h>
#include <Utilities.h>

const std::string path = "../../../days/2022/";

struct Pair {
  Pair(int x,int y) : x(x), y(y) {}
  int x;
  int y;

  int manhattan(Pair pair) {
    return abs(x - pair.x) + abs(y - pair.y);
  }

  bool inDiagonal(Pair pair) {
    Pair dummy(0, 0);
    dummy.x = x + 1;
    dummy.y = y + 1;
    if (dummy.x == pair.x && dummy.y == pair.y) {
      return true;
    }

    dummy.x = x - 1;
    dummy.y = y - 1;
    if (dummy.x == pair.x && dummy.y == pair.y) {
      return true;
    }

    dummy.x = x + 1;
    dummy.y = y - 1;
    if (dummy.x == pair.x && dummy.y == pair.y) {
      return true;
    }

    dummy.x = x - 1;
    dummy.y = y + 1;
    if (dummy.x == pair.x && dummy.y == pair.y) {
      return true;
    }

    return false;
  }

  bool jumpInDiagonal(Pair pair) {
    Pair dummy(0, 0);
    dummy.x = x + 2;
    dummy.y = y;
    if (dummy.x == pair.x && dummy.y == pair.y) {
      return false;
    }

    dummy.x = x - 2;
    dummy.y = y;
    if (dummy.x == pair.x && dummy.y == pair.y) {
      return false;
    }

    dummy.x = x;
    dummy.y = y + 2;
    if (dummy.x == pair.x && dummy.y == pair.y) {
      return false;
    }

    dummy.x = x;
    dummy.y = y - 2;
    if (dummy.x == pair.x && dummy.y == pair.y) {
      return false;
    }

    return true;
  }

  Pair whereToJumpInDiagonal(Pair pair) {
    Pair dummy(0, 0);
    dummy.x = x + 1;
    dummy.y = y + 1;
    unsigned int distance = dummy.manhattan(pair);
    if (dummy.manhattan(pair) == 1 || dummy.inDiagonal(pair)) {
      return dummy;
    }

    dummy.x = x - 1;
    dummy.y = y - 1;
    if (dummy.manhattan(pair) == 1 || dummy.inDiagonal(pair)) {
      return dummy;
    }

    dummy.x = x + 1;
    dummy.y = y - 1;
    if (dummy.manhattan(pair) == 1 || dummy.inDiagonal(pair)) {
      return dummy;
    }

    dummy.x = x - 1;
    dummy.y = y + 1;
    if (dummy.manhattan(pair) == 1 || dummy.inDiagonal(pair)) {
      return dummy;
    }

  }

  Pair whereToJumpNotDiagonal(Pair pair) {
    Pair dummy(0, 0);
    dummy.x = x + 2;
    dummy.y = y;
    if (dummy.x == pair.x && dummy.y == pair.y) {
      dummy.x--;
      return dummy;
    }

    dummy.x = x - 2;
    dummy.y = y;
    if (dummy.x == pair.x && dummy.y == pair.y) {
      dummy.x++;
      return dummy;
    }

    dummy.x = x;
    dummy.y = y + 2;
    if (dummy.x == pair.x && dummy.y == pair.y) {
      dummy.y--;
      return dummy;
    }

    dummy.x = x;
    dummy.y = y - 2;
    if (dummy.x == pair.x && dummy.y == pair.y) {
      dummy.y++;
      return dummy;
    }


  }

};

bool operator<(const Pair& left, const Pair& right) {
  return left.x + left.y * 1000 < right.x + right.y * 1000;
}

Pair operator-(const Pair& left, const Pair& right) {
  Pair result(0,0);
  result.x = left.x - right.x;
  result.y = left.y - right.y;
  return result;
}

Pair operator+(const Pair& left, const Pair& right) {
  Pair result(0, 0);
  result.x = left.x + right.x;
  result.y = left.y + right.y;
  return result;
}

std::ostream& operator<<(std::ostream& output, const Pair& c) {
  output << "X: " << c.x << " Y:" << c.y;
  return output;
}

struct Movement {
  std::string movement;
  unsigned int times;
};

class DayOfTodayAoC{
 public:

   SourceReader* src;
   std::vector<Movement> movements;
  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);
    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {
      Movement move;
      std::vector<std::string> lineSplit = splitString(line, " ");
      move.movement = lineSplit[0];
      move.times = std::stoi(lineSplit[1]);
      movements.push_back(move);
    });
  }

  int computeFirstStar() {

    unsigned int total = 0;
    Pair head(0,0);
    Pair oldHead(0,0);
    Pair tail(0,0);
    std::set<Pair> positionsOfTheTail;
    std::for_each(movements.begin(), movements.end(), [&](Movement move) {

      for (int i = 0; i < move.times; i++) {

        if ("R" == move.movement) {
          head.x++;
        }
        else if ("U" == move.movement) {
          head.y++;
        }
        else if ("L" == move.movement) {
          head.x--;
        }
        else if ("D" == move.movement) {
          head.y--;
        }

        unsigned int distanceTailHead = head.manhattan(tail);

        if (distanceTailHead > 1 && !head.inDiagonal(tail)) {
          if (tail.jumpInDiagonal(head)) {
            Pair newTail = tail.whereToJumpInDiagonal(head);
            tail = newTail;
          }
          else {
            Pair newTail = tail.whereToJumpNotDiagonal(head);
            tail = newTail;
          }
        }
        positionsOfTheTail.insert(tail);

        oldHead = head;
      }
      
    });

    std::cout << "First Star "<< positionsOfTheTail.size() << std::endl;
    return 0;
  }


  int computeSecondStar(bool debug) {

    unsigned int total = 0;
    Pair head(0, 0);
    Pair tails[9] = { Pair(0,0), Pair(0,0), Pair(0,0), Pair(0,0), Pair(0,0), Pair(0,0), Pair(0,0), Pair(0,0), Pair(0,0) };
    Pair oldHeads[9] = { Pair(0,0), Pair(0,0), Pair(0,0), Pair(0,0), Pair(0,0), Pair(0,0), Pair(0,0), Pair(0,0), Pair(0,0) };
    std::set<Pair> positionsOfTheTail;
    std::for_each(movements.begin(), movements.end(), [&](Movement move) {

      for (int j = 0; j < move.times; j++) {

        if ("R" == move.movement) {
          head.x++;
        }
        else if ("U" == move.movement) {
          head.y++;
        }
        else if ("L" == move.movement) {
          head.x--;
        }
        else if ("D" == move.movement) {
          head.y--;
        }

        Pair actualHead = head;
        for (unsigned int i = 0; i < 9; i++) {
          Pair actualTail = tails[i];

          unsigned int distanceTailHead = actualHead.manhattan(actualTail);

          if (distanceTailHead > 1 && !actualHead.inDiagonal(actualTail)) {
            if (actualTail.jumpInDiagonal(actualHead)) {
              Pair newTail = actualTail.whereToJumpInDiagonal(actualHead);
              actualTail = newTail;
            }
            else {
              Pair newTail = actualTail.whereToJumpNotDiagonal(actualHead);
              actualTail = newTail;
            }
          }

          oldHeads[i] = actualHead;
          tails[i] = actualTail;
          actualHead = actualTail;

        }
        positionsOfTheTail.insert(tails[8]);

        if (debug) {
          for (int y = 15; y > -6; y--) {
            for (int x = -10; x < 11; x++) {

              bool noDraw = true;
              bool alreadyDraw = false;


              if (x == head.x && y == head.y && !alreadyDraw) {
                std::cout << "h ";
                noDraw = false;
                alreadyDraw = true;
              }
              for (int t = 0; t < 9; t++) {
                if (x == tails[t].x && y == tails[t].y && !alreadyDraw) {
                  std::cout << t + 1 << " ";
                  noDraw = false;
                  alreadyDraw = true;
                }
              }
              if (x == 0 && y == 0 && !alreadyDraw) {
                std::cout << "s ";
                noDraw = false;
                alreadyDraw = true;
              }


              if (noDraw)
                std::cout << ". ";

            }
            std::cout << std::endl;

          }

          std::cout << std::endl;
          std::cout << std::endl;
        }
      }

      });

    std::cout << "Second Star " << positionsOfTheTail.size() << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day09/input.txt";
  std::string testInputFile = "day09/test.txt";


  std::cout << "Test" << std::endl;
  DayOfTodayAoC executeTest(testInputFile);
  executeTest.computeFirstStar();
  executeTest.computeSecondStar(false);

  std::cout << std::endl<< std::endl<< "Input" << std::endl;
  DayOfTodayAoC executeInput(inputFile);
  executeInput.computeFirstStar();
  executeInput.computeSecondStar(false);



  std::cin;

}
