#include <string>
#include <algorithm>
#include <SourceReader.h>
#include <Utilities.h> 

const std::string path = "../../../days/2021/";

class DayOfTodayAoC{
 public:

   SourceReader* src;


   std::vector<std::vector<char>> map;
   unsigned int foldIntructionsLine;

   unsigned int maxX = 0;
   unsigned int maxY = 0;

  DayOfTodayAoC(std::string file) {



    src = new SourceReader(path + file);
    //std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {

    //});

    unsigned int index = 0;

    while (src->get_data(index) != "") {

      std::vector<int> points = splitStringInToInts(src->get_data(index), ",");

      if (points[0] > maxX)
        maxX = points[0];

      if (points[1] > maxY)
        maxY = points[1];


      index++;
    }

    maxX++;
    maxY++;

    for (int i = 0; i < maxX; i++) {
      map.push_back(std::vector<char>(maxY, '.'));
    }

    index = 0;
    while (src->get_data(index) != "") {

      std::vector<int> points = splitStringInToInts(src->get_data(index),",");

      map[points[0]][points[1]] = '#';

      index++;
    }
    foldIntructionsLine = index + 1;



  }

  void showMap() {
    for (int i = 0; i < maxY; i++) {
      for (int j = 0; j < maxX; j++) {
        std::cout << map[j][i]<<" ";
      }
      std::cout << std::endl;
    }
  }

  unsigned int countDots() {
    unsigned int total = 0;
    for (int i = 0; i < maxY; i++) {
      for (int j = 0; j < maxX; j++) {
        if (map[j][i] == '#')
          total++;

      }
    }
    return total;
  }

  void fold(bool isX, int foldAlong,std::vector<std::vector<char>>& map) {

    //if (isX) {

    //  for (int i = 0; i < maxY; i++) {
    //    for (int j = 0; j < foldAlong; j++) {
    //      if (map[maxX - 1 - j][i] == '#') {
    //        map[j][i] = map[maxX - 1 - j][i];
    //      }
    //    }
    //  }


    //  maxX = foldAlong;

    //}
    //else {
    //  for (int i = 0; i < foldAlong; i++) {
    //    for (int j = 0; j < maxX; j++) {
    //      if (map[j][maxY - 1 - i] == '#') {
    //        unsigned int increment = foldAlong % 2;
    //        increment = increment == 1 ? 0 : 1;
    //        map[j][i+increment] = map[j][maxY - 1 - i];
    //      }
    //    }
    //  }

    //  maxY = foldAlong;
    //}


    if (isX) {

      for (int i = 0; i < maxY; i++) {
        for (int j = 1; j+foldAlong < maxX ; j++) {
          if (map[j+foldAlong][i] == '#') {
            map[foldAlong-j][i] = map[j+foldAlong][i];
          }
        }
      }


      maxX = foldAlong;

    }
    else {
      for (int i = 1; i+foldAlong < maxY; i++) {
        for (int j = 0; j < maxX; j++) {
          if (map[j][i+ foldAlong] == '#') {
            map[j][foldAlong-i] = map[j][i+ foldAlong];
          }
        }
      }

      maxY = foldAlong;
    }

  }

  int computeFirstStar() {

    unsigned int total = 0;
    for (int i = foldIntructionsLine; i < src->get_size(); i++) {

      std::vector<std::string> folding = splitString(src->get_data(i), " ");
      std::vector<std::string> foldingLines = splitString(folding[2], "=");
      bool isX = true;
      if (foldingLines[0].at(0) == 'y') {
        isX = false;
      }
      fold(isX, std::stoi(foldingLines[1]), map);

    }
    showMap();
    //std::cout << "First star "<< total << std::endl;
    return 0;
  }


  int computeSecondStar() {

    unsigned int total = 0;



    //std::cout << "Second star "<<total << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day13/input.txt";
  std::string testInputFile = "day13/test.txt";


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
