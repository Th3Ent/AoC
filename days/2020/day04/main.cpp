#include <string>
#include <algorithm>
#include <SourceReader.h>
#include <Utilities.h>

const std::string path = "../../../days/2020/";


struct Passport {

  std::string byr = "";
  std::string iyr = "";
  std::string eyr = "";
  std::string hgt = "";
  std::string hcl = "";
  std::string ecl = "";
  std::string pid = "";
  std::string cid = ""; // Optional

  bool checkIfValid() {

    if(byr == "") return false;
    if(iyr == "") return false;
    if(eyr == "") return false;
    if(hgt == "") return false;
    if(hcl == "") return false;
    if(ecl == "") return false;
    if(pid == "") return false;
    //if(cid == "") valid = false;

    unsigned int byrNum = std::stoi(byr);
    if (byrNum < 1920 || byrNum > 2002) return false;
    
    unsigned int iyrNum = std::stoi(iyr);
    if (iyrNum < 2010 || iyrNum > 2020) return false;
    
    unsigned int eyrNum = std::stoi(eyr);
    if (eyrNum < 2020 || eyrNum > 2030) return false;

    if (hgt.size() < 4) return false;
    if (hgt.at(3) == 'c') {
    
      std::vector<std::string> height = splitString(hgt,"cm");
      unsigned int numHeight = std::stoi(height[0]);
      if (numHeight > 193 || numHeight < 150) return false;
    
    }
    else if(hgt.at(2) == 'i'){
      std::vector<std::string> height = splitString(hgt, "in");
      unsigned int numHeight = std::stoi(height[0]);
      if (numHeight > 76 || numHeight < 59) return false;
    }
    else {
      return false;
    }

    if (hcl.at(0) != '#') return false;
    std::vector<std::string> hairColor = splitString(hcl, "#");
    if(hairColor[1].size() != 6) return false;
    for (int i = 0; i < hairColor[1].size(); i++) {
    
      char letter = hairColor[1].at(i);
      
      if (!((letter <= 102 && letter >= 97) || (letter <= 57 && letter >= 48))) return false;
    }

    if (ecl == "amb") {}
    else if (ecl == "blu") {}
    else if (ecl == "brn") {}
    else if (ecl == "gry") {}
    else if (ecl == "grn") {}
    else if (ecl == "hzl") {}
    else if (ecl == "oth") {}
    else { return false; }

    if (pid.size() != 9) return false;
    for (int i = 0; i < pid.size(); i++) {
      char letter = pid.at(i);
      if (letter > 57 || letter < 48) return false;
    }

    return true;

  }

};

class DayOfTodayAoC{
 public:

   SourceReader* src;

   std::vector<Passport> passports;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);

    passports.emplace_back();

    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {

      if (line=="") {
        passports.emplace_back();
      }
      else {
        Passport* pass = &passports.back();

        std::vector<std::string> passportsOptions = splitString(line," ");
        std::for_each(passportsOptions.begin(), passportsOptions.end(), [&](std::string line) {
        
          std::vector<std::string> option = splitString(line, ":");

          if (option[0] == "byr") {
            pass->byr = option[1];
          }else if (option[0] == "iyr") {
            pass->iyr = option[1];
          }
          else if (option[0] == "eyr") {
            pass->eyr = option[1];
          }
          else if (option[0] == "hgt") {
            pass->hgt = option[1];
          }
          else if (option[0] == "hcl") {
            pass->hcl = option[1];
          }
          else if (option[0] == "ecl") {
            pass->ecl = option[1];
          }
          else if (option[0] == "pid") {
            pass->pid = option[1];
          }
          else if (option[0] == "cid") {
            pass->cid = option[1];
          }
          
        });
      }

    });

  }

  int computeFirstStar() {

    unsigned int total = 0;

    std::for_each(passports.begin(), passports.end(), [&](Passport pass) {

      if(pass.checkIfValid()) {
        total++;
      }
      
    });

    std::cout << "Primera estrella "<<total << std::endl;
    return 0;
  }


  int computeSecondStar() {



    std::cout << "Segunda estrella" << std::endl;
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
