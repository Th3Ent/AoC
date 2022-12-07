#include <string>
#include <list>
#include <algorithm>
#include <SourceReader.h>
#include <Utilities.h>

const std::string path = "../../../days/2022/";

struct File {
  std::string fileName;
  unsigned int size;

};

struct Directory {
  Directory* parent = nullptr;
  std::string dirName = "";
  unsigned int folderSize = 0;


  std::list<Directory> subDirectorys;
  std::vector<File> files;
};


class DayOfTodayAoC{
 public:

   SourceReader* src;

  Directory rootDir;
  Directory* actualDir;
  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path + file);

    rootDir.dirName = "/";
    actualDir = &rootDir;
    std::for_each(src->getVector().begin(), src->getVector().end(), [&](std::string line) {

      std::vector<std::string> lineSplit = splitString(line," ");

      if(lineSplit[0] == "$") {

        if(lineSplit[1] == "cd") {
          if (".." == lineSplit[2]) {
            actualDir = actualDir->parent;
          }
          else{
            for (auto i = actualDir->subDirectorys.begin(); i != actualDir->subDirectorys.end(); i++) {
              if (i->dirName == lineSplit[2]) {
                actualDir = &*i;
                break;
              }
            }
          }
        }

      }
      else if (lineSplit[0] == "dir") {
        Directory dir;
        dir.dirName = lineSplit[1];
        dir.parent = actualDir;
        actualDir->subDirectorys.push_back(dir);
      }
      else {
        File file;
        file.fileName = lineSplit[1];
        file.size = std::stoi(lineSplit[0]);
        actualDir->files.push_back(file);
      }

    });
  }

  unsigned int setFolderSizes(Directory& actualDir) {
    unsigned int size = 0;

    for (File file : actualDir.files) {
      size += file.size;
    }

    if (actualDir.subDirectorys.size() == 0) {
      actualDir.folderSize = size;
      return size;
    }

    for (auto i = actualDir.subDirectorys.begin(); i != actualDir.subDirectorys.end(); i++) {
      size += setFolderSizes(*i);
    }

    actualDir.folderSize = size;
    return size;
  }

  void setSumFolderSizes(Directory& actualDir, unsigned int& totalSum, unsigned int sumIfLessThan) {


    if (actualDir.subDirectorys.size() == 0) {
      if (actualDir.folderSize <= sumIfLessThan)
        totalSum += actualDir.folderSize;
      return;
    }

    for (auto i = actualDir.subDirectorys.begin(); i != actualDir.subDirectorys.end(); i++) {
      setSumFolderSizes(*i,totalSum,sumIfLessThan);
    }

    if (actualDir.folderSize <= sumIfLessThan)
      totalSum += actualDir.folderSize;

    return ;
  }

  int computeFirstStar() {

    unsigned int total = 0;
    setFolderSizes(rootDir);

    setSumFolderSizes(rootDir, total, 100000);
    std::cout << "First Star "<< total << std::endl;
    return 0;
  }

  void setSumFolderSizes(Directory& actualDir, std::vector<unsigned int>& spacesOfFolder, unsigned int spaceRequired) {


    if (actualDir.subDirectorys.size() == 0) {
      if (actualDir.folderSize >= spaceRequired)
        spacesOfFolder.push_back(actualDir.folderSize);
      return;
    }

    for (auto i = actualDir.subDirectorys.begin(); i != actualDir.subDirectorys.end(); i++) {
      setSumFolderSizes(*i, spacesOfFolder, spaceRequired);
    }

    if (actualDir.folderSize >= spaceRequired)
      spacesOfFolder.push_back(actualDir.folderSize);

    return;
  }

  int computeSecondStar() {

    unsigned int total = 0;
    unsigned int freeSpace = 70000000 - rootDir.folderSize ;
    unsigned int spaceRequired = 30000000 - freeSpace;

    std::vector<unsigned int> spacesOfFolder;

    setSumFolderSizes(rootDir, spacesOfFolder, spaceRequired);

    std::sort(spacesOfFolder.begin(), spacesOfFolder.end());

    std::cout << "Second Star "<< spacesOfFolder[0] << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day07/input.txt";
  std::string testInputFile = "day07/test.txt";


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
