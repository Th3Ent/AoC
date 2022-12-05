#include <string>
#include <map>
#include <algorithm>
#include <SourceReader.h>
#include <Utilities.h>

const std::string path = "../../../days/2021/";

class DayOfTodayAoC{
 public:

   SourceReader* src;

   struct Cave {

     std::string caveName;

     bool smallCave;

     std::vector<Cave*> connections;
     std::vector<std::string> stringConnections;

   };

   std::map<std::string, Cave> mapCave;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path+file);

    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {
      std::vector<std::string> stringCaves = splitString(line,"-");

    if (mapCave.find(stringCaves[0]) == mapCave.end()) {
      Cave cave;
      mapCave.insert_or_assign(stringCaves[0], cave);

    }


    if (mapCave.find(stringCaves[1]) == mapCave.end()) {
      Cave cave;
      mapCave.insert_or_assign(stringCaves[1], cave);
    }

    Cave* firstCave = &mapCave.find(stringCaves[0])->second;
    Cave* secondCave = &mapCave.find(stringCaves[1])->second;

    firstCave->caveName = stringCaves[0];
    secondCave->caveName = stringCaves[1];

    firstCave->connections.push_back(secondCave);
    secondCave->connections.push_back(firstCave);

    if (stringCaves[0].at(0) >= 97 && stringCaves[0].at(0) <= 122 ) {
      firstCave->smallCave = true;
    }
    else {
      firstCave->smallCave = false;
    }

    if (stringCaves[1].at(0) >= 97 && stringCaves[1].at(0) <= 122 ) {
      secondCave->smallCave = true;
    }
    else {
      secondCave->smallCave = false;
    }

    });



  }

  unsigned int PosiblePaths(Cave* actualCave, std::map<std::string, bool> smallCavesVisited) {

    if (actualCave->smallCave) {
      if (smallCavesVisited.find(actualCave->caveName) != smallCavesVisited.end()) {
        return 0;
      }
      smallCavesVisited.insert_or_assign(actualCave->caveName,true);
    }

    if (actualCave->caveName == "end") {
      return 1;
    }
    unsigned int total = 0;
    for (Cave* cave : actualCave->connections) {
      //if (cave->smallCave) {
      //  if (smallCavesVisited.find(cave->caveName) != smallCavesVisited.end()) {
      //    continue;
      //  }
      //  smallCavesVisited.insert_or_assign(cave->caveName, true);
      //}

      total += PosiblePaths(cave, smallCavesVisited);
    }
    return total;
  }

  unsigned int PosiblePathsSecond(Cave* actualCave, std::map<std::string, int> smallCavesVisited, bool smallCaveTwice,std::string cavesString) {

    cavesString += actualCave->caveName + " ";

    if (actualCave->smallCave) {
    std::map<std::string, int>::const_iterator it = smallCavesVisited.find(actualCave->caveName);
      if (it == smallCavesVisited.end()) {
        smallCavesVisited.insert_or_assign(actualCave->caveName, 1);
      }
      else if (!smallCaveTwice && actualCave->caveName != "start") {
        smallCaveTwice = true;
      }
      else {
        return 0;
      }
    }

    if (actualCave->caveName == "end") {
      return 1;
    }
    unsigned int total = 0;
    for (Cave* cave : actualCave->connections) {

      total += PosiblePathsSecond(cave, smallCavesVisited, smallCaveTwice,cavesString);
    }
    return total;
  }

  int computeFirstStar() {

    unsigned int total = 0;
    std::map<std::string, bool> smallCavesVisited;
    total = PosiblePaths(&mapCave.find("start")->second, smallCavesVisited);

    std::cout << "Primera estrella "<<total << std::endl;



    return 0;
  }


  int computeSecondStar() {

    unsigned int total = 0;
    std::string cavesString = "";
    std::map<std::string, int> smallCavesVisited;
    total = PosiblePathsSecond(&mapCave.find("start")->second, smallCavesVisited, false, cavesString);


    std::cout << "Segunda estrella "<<total << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day12/input.txt";
  std::string testInputFile = "day12/test.txt";
  DayOfTodayAoC execute(inputFile);

  execute.computeFirstStar();

  execute.computeSecondStar();

  std::cin;

}
