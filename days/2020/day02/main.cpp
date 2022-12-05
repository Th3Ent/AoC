#include <string>
#include <algorithm>
#include <SourceReader.h>
#include <Utilities.h>

const std::string path = "../../../days/2020/";

struct Password {

  unsigned int minTimes;
  unsigned int maxTimes;
  char letter;
  std::string password;

  bool checkIfValidFirstStar() {
    unsigned int timesRep = 0;
    for (int i = 0; i < password.length();i++) {
      if (password.at(i) == letter) {
        timesRep++;
      }
    }
    if (timesRep >= minTimes && timesRep <= maxTimes) {
      return true;
    }
    return false;
  }

  bool checkIfValidSecondStar() {


    bool firstIsSame = password.at(minTimes-1) == letter;
    bool secondIsSame = password.at(maxTimes-1) == letter;
    if (firstIsSame != secondIsSame) {
      return true;
    }

    return false;

  }
};

class DayOfTodayAoC{
 public:

   SourceReader* src;
   std::vector<Password> passwords;
  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);

    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {

      Password pass;

      std::vector<std::string> firstSplit = splitString(line," ");
      std::vector<std::string> minAndMaxSplit = splitString(firstSplit[0], "-");

      pass.minTimes = std::stoi(minAndMaxSplit[0]);
      pass.maxTimes = std::stoi(minAndMaxSplit[1]);
      pass.letter = firstSplit[1].at(0);
      pass.password = firstSplit[2];

      passwords.push_back(pass);
    });

  }

  int computeFirstStar() {
    unsigned int validPasswords = 0;

    std::for_each(passwords.begin(), passwords.end(), [&](Password pass) {

      if (pass.checkIfValidFirstStar()) {
        validPasswords++;
      }

    });

    std::cout << "Primera estrella "<< validPasswords << std::endl;
    return 0;
  }


  int computeSecondStar() {

    unsigned int validPasswords = 0;

    std::for_each(passwords.begin(), passwords.end(), [&](Password pass) {

      if (pass.checkIfValidSecondStar()) {
        validPasswords++;
      }

      });

    std::cout << "Segunda estrella "<<validPasswords << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day03/input.txt";
  std::string testInputFile = "day03/test.txt";
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
