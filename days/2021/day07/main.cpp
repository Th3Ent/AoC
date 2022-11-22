#include <string>
#include <SourceReader.h>
#include <Utilities.h>
#include <unordered_map>
#include <cmath>

const std::string path = "../../days/2021/";

class DayOfTodayAoC {
public:

  SourceReader* src;

  std::vector<int> horizontal;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);

    splitStringInToInts(src->get_data(0), ",", horizontal);

  }

  int computeFirstStar() {

    int minHorizontal = 100000000;
    int maxHorizontal = -100000000;

    for (int i = 0; i < horizontal.size(); i++) {

      if (horizontal[i] < minHorizontal) {
        minHorizontal = horizontal[i];
      }

      if (horizontal[i] > maxHorizontal) {
        maxHorizontal = horizontal[i];
      }

    }

    int minFuel = 1000000;
    for (int i = minHorizontal; i <= maxHorizontal; i++) {

      int fuelNeeded = 0;
      for (int j = 0; j < horizontal.size(); j++) {
        fuelNeeded += abs(i - horizontal[j]);
      }

      if (fuelNeeded < minFuel) {
        minFuel = fuelNeeded;
      }
    }


    std::cout << "Primera estrella  " <<" Min Fuel Needed: "<<minFuel<<std::endl;
    return 0;
  }


  int computeSecondStar() {


    int minHorizontal = 100000000;
    int maxHorizontal = -100000000;

    for (int i = 0; i < horizontal.size(); i++) {

      if (horizontal[i] < minHorizontal) {
        minHorizontal = horizontal[i];
      }

      if (horizontal[i] > maxHorizontal) {
        maxHorizontal = horizontal[i];
      }

    }

    long int minFuel = 206680454000;
    for (int i = minHorizontal; i <= maxHorizontal; i++) {

      long int fuelNeeded = 0;
      for (int j = 0; j < horizontal.size(); j++) {
        long int n = abs(i - horizontal[j]);
        fuelNeeded += (pow(n, 2) + n) / 2;
      }

      if (fuelNeeded < minFuel) {
        minFuel = fuelNeeded;
      }
    }

    std::cout << "Segunda estrella  Min Fuel:   " <<minFuel<< std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day07/input.txt";
  std::string testFile = "day07/test.txt";
  DayOfTodayAoC execute(inputFile);

  execute.computeFirstStar();

  execute.computeSecondStar();

  std::cin;

}
