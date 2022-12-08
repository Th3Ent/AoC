#include <string>
#include <algorithm>
#include <set>
#include <SourceReader.h>

const std::string path = "../../../days/2022/";

struct Pair {
  Pair(unsigned int x, unsigned int y) : x(x), y(y),score(0){}
  unsigned int x;
  unsigned int y;

  unsigned int score;
};

bool operator<(const Pair& left, const Pair& right) {
  return left.x + left.y * 1000 < right.x + right.y * 1000;
}

std::ostream& operator<<(std::ostream& output, const Pair& c) {
  output <<"X: " << c.x << " Y:" << c.y;
  return output;
}

class DayOfTodayAoC{
 public:

   SourceReader* src;

   std::vector<std::vector<unsigned int>> treeMap;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);
    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {
      std::vector<unsigned int> trees;
      for (int i = 0; i < line.size(); i++) {
        trees.push_back(std::stoi(line.substr(i,1)));
      }
      treeMap.push_back(trees);
    });
  }



  unsigned int countVisibleTrees() {

    unsigned int total = treeMap.size() * 2 + (treeMap[0].size()-2)*2;

    std::set<Pair> visibleTree;


    //Static y moving x
    for (int y = 1; y < treeMap.size()-1; y++) {
      unsigned int tallestAtTheMoment = treeMap[y][0];
      for (int x = 1; x < treeMap[y].size()-1; x++) {
        if (tallestAtTheMoment < treeMap[y][x]) {
          visibleTree.insert(Pair(x,y));
          tallestAtTheMoment = treeMap[y][x];
        }

      }

      tallestAtTheMoment = treeMap[y][treeMap[y].size()-1];
      for (int x = treeMap[y].size() - 2; x > 0 ; x--) {
        if (tallestAtTheMoment < treeMap[y][x]) {
          visibleTree.insert(Pair(x, y));
          tallestAtTheMoment = treeMap[y][x];
        }

      }

    }


    //Static x moving y
    for (int x = 1; x < treeMap[0].size() - 1; x++) {
      unsigned int tallestAtTheMoment = treeMap[0][x];
      for (int y = 1; y < treeMap.size() - 1; y++) {
        if (tallestAtTheMoment < treeMap[y][x]) {
          visibleTree.insert(Pair(x, y));
          tallestAtTheMoment = treeMap[y][x];
        }

      }

      tallestAtTheMoment = treeMap[treeMap.size() - 1][x];
      for (int y = treeMap.size() - 2; y > 0; y--) {
        if (tallestAtTheMoment < treeMap[y][x]) {
          visibleTree.insert(Pair(x, y));
          tallestAtTheMoment = treeMap[y][x];
        }

      }

    }

    return total + visibleTree.size();
  }

  Pair findBestSpot() {

    Pair actualBestSpot = Pair(0, 0);
    //Static y moving x
    for (int y = 1; y < treeMap.size() - 1; y++) {
      for (int x = 1; x < treeMap[y].size() - 1; x++) {
        unsigned int totalTreesAtSight[4] = { 0 };

        unsigned int actualTreeHeigth = treeMap[y][x];
        unsigned int actualTallestTree = actualTreeHeigth;
        unsigned int treesAtSight = 0;
        for (int newX = x + 1; newX < treeMap[y].size(); newX++) {
          if (actualTallestTree > treeMap[y][newX]) {
            treesAtSight++;
          }
          else {
            treesAtSight++;
            break;
          }
        }
        totalTreesAtSight[3] = treesAtSight;

        actualTallestTree = actualTreeHeigth;
        treesAtSight = 0;
        for (int newX = x - 1; newX >= 0 ; newX--) {
          if (actualTallestTree > treeMap[y][newX]) {
            treesAtSight++;
          }
          else {
            treesAtSight++;
            break;
          }
        }
        totalTreesAtSight[1] = treesAtSight;

        actualTallestTree = actualTreeHeigth;
        treesAtSight = 0;
        for (int newY = y + 1; newY < treeMap.size(); newY++) {
          if (actualTallestTree > treeMap[newY][x]) {
            treesAtSight++;
          }
          else {
            treesAtSight++;
            break;
          }
        }
        totalTreesAtSight[2] =  treesAtSight;

        actualTallestTree = actualTreeHeigth;
        treesAtSight = 0;
        for (int newY = y - 1; newY >= 0; newY--) {
          if (actualTallestTree > treeMap[newY][x]) {
            treesAtSight++;
          }
          else {
            treesAtSight++;
            break;
          }
        }
        totalTreesAtSight[0] = treesAtSight;


        unsigned int totalScore = totalTreesAtSight[0] * totalTreesAtSight[1] * totalTreesAtSight[2] * totalTreesAtSight[3];

        if (totalScore > actualBestSpot.score) {
          Pair newPair(x, y);
          newPair.score = totalScore;
          actualBestSpot = newPair;
        }
      }


    }




    return actualBestSpot;
  }

  int computeFirstStar() {

    unsigned int total = countVisibleTrees();



    std::cout << "First Star "<< total << std::endl;
    return 0;
  }


  int computeSecondStar() {

    unsigned int total = findBestSpot().score;



    std::cout << "Second Star "<<total << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day08/input.txt";
  std::string testInputFile = "day08/test.txt";


  std::cout << "Test" << std::endl;
  DayOfTodayAoC executeTest(testInputFile);
  executeTest.computeFirstStar();
  executeTest.computeSecondStar();

  std::cout << std::endl<< std::endl<< "Input" << std::endl;
  DayOfTodayAoC executeInput(inputFile);
  executeInput.computeFirstStar();
  executeInput.computeSecondStar();



  std::cin;

}
