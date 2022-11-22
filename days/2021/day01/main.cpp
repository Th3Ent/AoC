#include <string>
#include <SourceReader.cpp>


class DayOfTodayAoC{
 public:

   SourceReader* src;

  DayOfTodayAoC(string file) {

    src = new SourceReader(file);

  }

  int computeFirstStar() {
    using namespace std;
    
    cout << src->get_size() << "  Es el tamanio del input" << endl;

    std::cout << "Primera estrella" << std::endl;
    return 0;
  }


  int computeSecondStar() {



    std::cout << "Segunda estrella" << std::endl;
    return 0;
  }


};

int main() {

  string inputFile = "input.txt";
  DayOfTodayAoC execute(inputFile);

  execute.computeFirstStar();

  execute.computeSecondStar();

  std::cin;

}
