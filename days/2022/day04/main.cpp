#include <string>
#include <algorithm>
#include <SourceReader.h>
#include <Utilities.h>

const std::string path = "../../../days/2022/";

struct ElvesPair {

  struct Section {
    unsigned int start;
    unsigned int end;
  };

  Section firstElve;
  Section secondElve;

  bool OneContainOtherFirstStar() {

    if (firstElve.start >= secondElve.start && firstElve.end <= secondElve.end) {
      return true;
    }
    else if (firstElve.start <= secondElve.start && firstElve.end >= secondElve.end) {
      return true;
    }
    return false;

  }

  bool OneContainOtherSecondStar() {

    if (firstElve.start >= secondElve.start && firstElve.end <= secondElve.end) {
      return true;
    }
    else if (firstElve.start <= secondElve.start && firstElve.end >= secondElve.end) {
      return true;
    }
    

    if (firstElve.start >= secondElve.start && firstElve.end <= secondElve.start || firstElve.start >= secondElve.end && firstElve.end <= secondElve.end) {
      return true;
    }
    else if (firstElve.start <= secondElve.start && firstElve.end >= secondElve.start || firstElve.start <= secondElve.end && firstElve.end >= secondElve.end) {
      return true;
    }

    return false;

  }

};

class DayOfTodayAoC{
 public:

   SourceReader* src;
   std::vector<ElvesPair> elves;
  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);
    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {

      std::vector<std::string> elvesPairString = splitString(line,",");
      std::vector<int> firstSection = splitStringInToInts(elvesPairString[0], "-");
      std::vector<int> secondSection = splitStringInToInts(elvesPairString[1], "-");

      ElvesPair elvePair;
      elvePair.firstElve.start = firstSection[0];
      elvePair.firstElve.end = firstSection[1];
      elvePair.secondElve.start = secondSection[0];
      elvePair.secondElve.end = secondSection[1];

      elves.push_back(elvePair);
    });
  }

  int computeFirstStar() {
    unsigned int total = 0;

    std::for_each(elves.begin(), elves.end(), [&](ElvesPair pair) {

      if (pair.OneContainOtherFirstStar()) {
        total++;
      }

    });

    std::cout << "First Star "<<total << std::endl;
    return 0;
  }


  int computeSecondStar() {

    unsigned int total = 0;

    std::for_each(elves.begin(), elves.end(), [&](ElvesPair pair) {

      if (pair.OneContainOtherSecondStar()) {
        total++;
      }

      });

    std::cout << "Second Star "<<total << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day04/input.txt";
  std::string testInputFile = "day04/test.txt";
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
