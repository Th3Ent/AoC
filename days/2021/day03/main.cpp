#include <string>
#include <SourceReader.h>

const std::string path = "../../days/2021/";

class DayOfTodayAoC{
 public:

   SourceReader* src;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(file);

  }

  int computeFirstStar() {
    using namespace std;
    
    vector<int> numOfOnes;

    for (int j = 0; j < src->get_data(0).length(); j++) {

      numOfOnes.push_back(0);

    }

    for (int i = 0; i < src->get_size(); i++) {

      for (int j = 0; j < src->get_data(i).length(); j++) {

        if ('1' == src->get_data(i).at(j)) {
          numOfOnes[j]++;
        }

      }

    }


    for (int j = 0; j < src->get_data(0).length(); j++) {

      if (numOfOnes[j] > 500) {
        cout << 1 << "  ";
      }    //784
      else {
        cout << 0 << "  ";
      }

    }

    for (int j = 0; j < src->get_data(0).length(); j++) {

      if (numOfOnes[j] > 500) {
        cout << 0 << "  ";
      } //3311
      else {
        cout << 1 << "  ";
      }

    }

    cout << endl;

    std::cout << "Primera estrella" << std::endl;
    return 0;
  }


  int computeSecondStar() {
    int numOfOnes = 0;
    int numOfCeros = 0;
    char mostCommon = ' ';

    std::vector<std::string> numsRemaning = src->getVector();

    

    int indexComprobation = 0;
    std::vector<int> numsToErase;
    while (numsRemaning.size() > 1) {
      numOfOnes = 0;
      numOfCeros = 0;
      for (int i = 0; i < numsRemaning.size(); i++) {
          if ('1' == numsRemaning[i].at(indexComprobation)) {
            numOfOnes++;
          }
          else {
            numOfCeros++;
          }
      }

      
      if (numOfOnes >= numOfCeros) {
        mostCommon = '1';
      }  
      else {
        mostCommon = '0';
      }

      for (int i = 0; i < numsRemaning.size(); i++) {
        if (numsRemaning[i].at(indexComprobation) != mostCommon) {
          numsToErase.push_back(i);
        }
      }

      for (int i = numsToErase.size()-1; i > -1 ; i--) {
        std::vector<std::string>::iterator it = numsRemaning.begin();
        std::advance(it, numsToErase[i]);
        numsRemaning.erase(it);
      }

      numsToErase.clear();
      indexComprobation++;

    }

    std::cout << "Segunda estrella" << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day03/input.txt";
  DayOfTodayAoC execute(path+inputFile);

  execute.computeFirstStar();

  execute.computeSecondStar();

  std::cin;

}
