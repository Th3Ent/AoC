#include <string>
#include <algorithm>
#include <SourceReader.h>
#include <Utilities.h>
#include <map>

const std::string path = "../../../days/2021/";

struct PolymerRule {
  std::string pair;
  std::string insertion;
  std::string result;
};

class DayOfTodayAoC{
 public:

   SourceReader* src;


   std::string initialPolimer;
   std::map<std::string, PolymerRule> rules;
  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);

    initialPolimer = src->get_data(0);

    std::for_each(src->getVector().begin() + 2, src->getVector().end(), [&](std::string line) {
      std::vector<std::string> rulesSplit = splitString(line," -> ");

      PolymerRule rule;
      rule.pair = rulesSplit[0];
      rule.insertion = rulesSplit[1];
      //rule.result = rulesSplit[0];
      //rule.result.insert(1, rulesSplit[1]);
      rules.insert_or_assign(rulesSplit[0], rule);
    });
  }

  int computeFirstStar() {

    unsigned long long total = 0;

    std::string actualTemplate = initialPolimer;
    std::map<std::string, unsigned long long> pairs;
    for (unsigned long long j = 0; j + 1 < actualTemplate.size(); j++) {
      std::string pair = actualTemplate.substr(j, 2);
      std::map<std::string, unsigned long long>::iterator it = pairs.find(pair);
      if (it == pairs.end()) {
        pairs.insert_or_assign(pair,1);
      }
      else {
        pairs.insert_or_assign(pair, it->second + 1);
      }
    }

    for (int i = 0 ; i < 40 ; i++) {

      std::map<std::string, unsigned long long> newPairs;
      for (std::map<std::string, unsigned long long>::iterator it = pairs.begin(); it != pairs.end(); it++) {
        unsigned long long times = it->second;
        std::string newPair1 = it->first.at(0)+rules.find(it->first)->second.insertion;
        std::string newPair2 = rules.find(it->first)->second.insertion + it->first.at(1);

        std::map<std::string, unsigned long long>::iterator itNewPair1 = newPairs.find(newPair1);
        if (itNewPair1 == newPairs.end()) {
          newPairs.insert_or_assign(newPair1,times);
        }
        else {
          newPairs.insert_or_assign(newPair1,itNewPair1->second+ times);
        }

        std::map<std::string, unsigned long long>::iterator itNewPair2 = newPairs.find(newPair2);
        if (itNewPair2 == newPairs.end()) {
          newPairs.insert_or_assign(newPair2, times);
        }
        else {
          newPairs.insert_or_assign(newPair2, itNewPair2->second + times);
        }

      }
      pairs = newPairs;

    }

    std::map<char, unsigned long long> letterCount;
    for (std::map<std::string, unsigned long long>::iterator it = pairs.begin(); it != pairs.end(); it++) {

      char letter1 = it->first.at(0);
      std::map<char, unsigned long long>::iterator iteratorChar1 = letterCount.find(letter1);

      if (iteratorChar1 == letterCount.end()) {
        letterCount.insert_or_assign(letter1, it->second);
      }
      else {
        letterCount.insert_or_assign(letter1, it->second + iteratorChar1->second);
      }

      char letter2 = it->first.at(1);
      std::map<char, unsigned long long>::iterator iteratorChar2 = letterCount.find(letter2);

      if (iteratorChar2 == letterCount.end()) {
        letterCount.insert_or_assign(letter2, it->second);
      }
      else {
        letterCount.insert_or_assign(letter2, it->second + iteratorChar2->second);
      }

    }

    unsigned long long max = letterCount.begin()->second;
    unsigned long long min = letterCount.begin()->second;

    for (std::map<char, unsigned long long>::iterator iterator = letterCount.begin(); iterator != letterCount.end(); iterator++) {

      if (iterator->second > max) {
        max = iterator->second;
      }

      if (iterator->second < min) {
        min = iterator->second;
      }

    }
   
   
   total = (max/2) - (min/2) - 1;

    std::cout << "Primera estrella " << total << std::endl;


    return 0;
  }


  int computeSecondStar() {

    unsigned int total = 0;



    std::cout << "Segunda estrella "<<total << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day14/input.txt";
  std::string testInputFile = "day14/test.txt";


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
