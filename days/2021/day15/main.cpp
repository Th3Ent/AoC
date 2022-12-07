#include <string>
#include <algorithm>
#include <SourceReader.h>
#include <set>
#include <map>


const std::string path = "../../../days/2021/";

struct Pair {
  Pair() :x(0), y(0) {}
  Pair(int x, int y) :x(x), y(y) {}
  int x;
  int y;

  bool operator== (const Pair& right) {
    return x == right.x && y == right.y;
  }

  bool operator!= (const Pair& right) {
    return x != right.x || y != right.y;
  }

  //bool operator> (const Pair& right) {
  //  return x + y > right.x + right.y;
  //}
};

bool operator<(const Pair& left, const Pair& right) {
  return left.x + left.y*1000 < right.x + right.y*1000;
}

std::ostream& operator<<(std::ostream& output, const Pair& c) {
  output << c.x << " " << c.y;
  return output;
}

struct Node {

  Node() :pos({ 0,0 }), parent(0, 0), f(0.0f), g(0.0f), h(0.0f) {}
  Node(Pair pos, float f) :pos(pos.x, pos.y), parent(0, 0), f(f), g(0.0f), h(0.0f) {}

  Pair pos;
  Pair parent;

  float f;
  float g;
  float h;

  //unsigned int riskOnThatPoint;

  bool operator< (const Node& right) {
    return f < right.f;
  }

};

class DayOfTodayAoC {
public:

  SourceReader* src;

  std::vector<std::vector<unsigned int>> riskMap;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);
    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {
      std::vector<unsigned int> lineMap;

    for (int i = 0; i < line.size(); i++) {
      lineMap.push_back(std::stoi(line.substr(i, 1)));
    }
    riskMap.push_back(lineMap);
      });
  }

  bool isValid(Pair pos) {

    return pos.x >= 0 && pos.y >= 0 && pos.x < riskMap[0].size() && pos.y < riskMap.size();

  }

  bool isValidSecondStar(Pair pos) {

    return pos.x >= 0 && pos.y >= 0 && pos.x < riskMap[0].size() * 5 && pos.y < riskMap.size() * 5;

  }

  unsigned int heuristic(Pair actual, Pair final) {

    return (final.x - actual.x) + (final.y - actual.y);

  }

  Node aStar(std::vector<Node>& closeList) {
    Pair final(riskMap.size() - 1, riskMap[0].size() - 1);

    unsigned int total = 0;
    std::vector<Node> openList;
    openList.push_back(Node(Pair(0, 0), 0));
    std::map<Pair, bool> closeListMap;
    Node actualNode;
    while (!openList.empty()) {
      actualNode = *openList.begin();

      if (actualNode.pos == final) {
        break;
      }
      openList.erase(openList.begin());
      closeList.push_back(actualNode);
      closeListMap.insert_or_assign(actualNode.pos, true);
      //Check neigbour

      for (int newX = -1; newX <= 1; newX++) {
        for (int newY = -1; newY <= 1; newY++) {

          if (newX == -1 && newY == -1 || newX == -1 && newY == 1 ||
            newX == 1 && newY == -1 || newX == 1 && newY == 1)
            continue;

          Pair newPair(actualNode.pos.x + newX, actualNode.pos.y + newY);
          Node newNode;
          newNode.pos = newPair;
          if (isValid(newPair)) {

            newNode.g = actualNode.g + riskMap[newNode.pos.x][newNode.pos.y];
            newNode.h = heuristic(newNode.pos, final);
            newNode.f = newNode.g + newNode.h;
            newNode.parent = actualNode.pos;

            if (newPair == final) {
              return newNode;
            }

            bool isActualNodeInCloseList = false;
            if (closeListMap.find(newNode.pos) != closeListMap.end()) {
              isActualNodeInCloseList = true;
            }

            if (!isActualNodeInCloseList) {

              int openListNodePosition = -1;
              for (int i = 0; i < openList.size() && openListNodePosition == -1; i++) {
                if (openList[i].pos == newNode.pos)
                  openListNodePosition = i;
              }

              if (openListNodePosition == -1) {
                openList.push_back(newNode);
              }
              else if (openList[openListNodePosition].f > newNode.f) {
                openList[openListNodePosition] = newNode;
              }

            }

          }
        }
      }

      std::sort(openList.begin(), openList.end());

    }
  }

  Node aStarSecondStar(std::vector<Node>& closeList) {
    Pair final(riskMap.size() * 5 - 1, riskMap[0].size() * 5 - 1);

    unsigned int total = 0;
    std::vector<Node> openList;
    openList.push_back(Node(Pair(0, 0), 0));
    Node actualNode;
    std::map<Pair, bool> closeListMap;
    while (!openList.empty()) {
      actualNode = *openList.begin();

      if (actualNode.pos == final) {
        break;
      }
      openList.erase(openList.begin());
      closeList.push_back(actualNode);
      closeListMap.insert_or_assign(actualNode.pos, true);

      //Check neigbour

      for (int newX = -1; newX <= 1; newX++) {
        for (int newY = -1; newY <= 1; newY++) {

          if (newX == -1 && newY == -1 || newX == -1 && newY == 1 ||
            newX == 1 && newY == -1 || newX == 1 && newY == 1)
            continue;


          Pair newPair(actualNode.pos.x + newX, actualNode.pos.y + newY);
          Node newNode;
          newNode.pos = newPair;
          if (isValidSecondStar(newPair)) {
            unsigned int riskPlus = std::floor((float)(newPair.x) / (float)(riskMap.size())) + std::floor((float)(newPair.y) / (float)(riskMap[0].size()));
            Pair origialPosition;
            origialPosition.x = newPair.x % riskMap.size();
            origialPosition.y = newPair.y % riskMap[0].size();
            unsigned int riskNewPair = riskMap[origialPosition.x][origialPosition.y];
            riskNewPair = riskNewPair + riskPlus;
            riskNewPair = riskNewPair > 10 ? riskNewPair + 1 : riskNewPair;
            riskNewPair %= 10;
            riskNewPair = riskNewPair == 0 ? 1 : riskNewPair;
            newNode.g = actualNode.g + riskNewPair;
            newNode.h = heuristic(newNode.pos, final);
            newNode.f = newNode.g + newNode.h;
            newNode.parent = actualNode.pos;
            //newNode.riskOnThatPoint = riskNewPair;

            if (newPair == final) {
              return newNode;
            }

            bool isActualNodeInCloseList = false;

            if (closeListMap.find(newNode.pos) != closeListMap.end()) {
              isActualNodeInCloseList = true;
            }

            if (!isActualNodeInCloseList) {

              int openListNodePosition = -1;
              for (int i = 0; i < openList.size() && openListNodePosition == -1; i++) {
                if (openList[i].pos == newNode.pos)
                  openListNodePosition = i;
              }

              if (openListNodePosition == -1) {
                openList.push_back(newNode);
              }
              else if (openList[openListNodePosition].f > newNode.f) {
                openList[openListNodePosition] = newNode;
              }

            }

          }
        }
      }

      std::sort(openList.begin(), openList.end());

    }
  }

  int computeFirstStar() {


    std::vector<Node> closeList;

    Node finalNode = aStar(closeList);

    std::cout << "Primera estrella " << finalNode.g << std::endl;
    return 0;
  }


  int computeSecondStar() {

    //unsigned int total = 0;
    std::vector<Node> closeList;

    Node finalNode = aStarSecondStar(closeList);

    //Node actualNode = finalNode;
    //Pair initialPos;
    //unsigned int total = 0;
    //while (actualNode.pos != initialPos) {
    //  for (int i = 0; i < closeList.size(); i++) {
    //    Pair posToCheck = closeList[i].pos;
    //    if (posToCheck == actualNode.parent) {
    //      //unsigned int risk = riskMap[closeList[i].pos.x][closeList[i].pos.y];
    //      //total += risk;
    //      actualNode = closeList[i];
    //      break;
    //    }
    //  }
    //
    //}

    std::cout << "Segunda estrella " << finalNode.g << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day15/input.txt";
  std::string testInputFile = "day15/test.txt";


  std::cout << "Test" << std::endl;
  DayOfTodayAoC executeTest(testInputFile);
  executeTest.computeFirstStar();
  executeTest.computeSecondStar();

  std::cout << std::endl << std::endl << "Input" << std::endl;
  DayOfTodayAoC executeInput(inputFile);
  executeInput.computeFirstStar();
  executeInput.computeSecondStar();



  std::cin;

}
