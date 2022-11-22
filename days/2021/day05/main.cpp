#include <string>
#include <SourceReader.h>
#include <Utilities.h>

const std::string path = "../../days/2021/";

class DayOfTodayAoC{
 public:

   SourceReader* src;

   struct Point
   {
     int x1, y1;
     int x2, y2;
   };

   std::vector<Point> pointsStartToEnd;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path+file);

      std::vector<int> intPoints;
    for (int i = 0; i < src->get_size(); i++) {

      std::vector<std::string> stringPoints = splitString(src->get_data(i), " -> ");

      for (int j = 0; j < stringPoints.size(); j++) {

        splitStringInToInts(stringPoints[j], ",", intPoints);

      }

    }

    for (int j = 0; j < intPoints.size(); j += 4) {

      Point point;
      point.x1 = intPoints[j];
      point.y1 = intPoints[j + 1];
      point.x2 = intPoints[j + 2];
      point.y2 = intPoints[j + 3];
      pointsStartToEnd.push_back(point);
    }

  }

  int computeFirstStar() {

    std::vector<Point> pointsToWorkWith;

    for (int i = 0; i < pointsStartToEnd.size(); i++) {
      if (pointsStartToEnd[i].x1 == pointsStartToEnd[i].x2 || pointsStartToEnd[i].y1 == pointsStartToEnd[i].y2) {
        pointsToWorkWith.push_back(pointsStartToEnd[i]);
      }
    }

    uint8_t grid[1000 * 1000];

    for (int i = 0; i < 1000*1000; i++) {

      grid[i] = 0;

    }

    for (int i = 0; i < pointsToWorkWith.size(); i++) {

      if (pointsToWorkWith[i].x1 == pointsToWorkWith[i].x2) {
        int y1 = pointsToWorkWith[i].y1;
        int y2 = pointsToWorkWith[i].y2;
        if (pointsToWorkWith[i].y2 < pointsToWorkWith[i].y1) {
  
          y1 = pointsToWorkWith[i].y2;
          y2 = pointsToWorkWith[i].y1;

        }

        for (int j = y1; j <= y2 ; j++) {
          int index = 0;
          rowAndColToIndex(index,1000,1000, j, pointsToWorkWith[i].x1);
          grid[index]++;

        }

      }else if (pointsToWorkWith[i].y1 == pointsToWorkWith[i].y2) {
        int x1 = pointsToWorkWith[i].x1;
        int x2 = pointsToWorkWith[i].x2;
        if (pointsToWorkWith[i].x2 < pointsToWorkWith[i].x1) {

          x1 = pointsToWorkWith[i].x2;
          x2 = pointsToWorkWith[i].x1;

        }

        for (int j = x1; j <= x2; j++) {
          int index = 0;
          rowAndColToIndex(index, 1000, 1000, pointsToWorkWith[i].y1, j);
          grid[index]++;

        }

      }

    }

    //for (int i = 0; i < 10; i++) {

    //  for (int j = 0; j < 10; j++) {
    //    int index;
    //    rowAndColToIndex(index, 1000, 1000, i, j);
    //    
    //    std::cout << (int)grid[index] << " ";
    //  }
    //  std::cout << std::endl;

    //}

    int countMoreThaTwice = 0;
    for (int i = 0; i < 1000 * 1000; i++) {
      if (grid[i] > 1 ) {
        countMoreThaTwice++;
      }


    }

    std::cout << "Primera estrella  " <<countMoreThaTwice<< std::endl;
    return 0;
  }


  int computeSecondStar() {

    uint8_t grid[1000 * 1000];

    for (int i = 0; i < 1000 * 1000; i++) {

      grid[i] = 0;

    }

    for (int i = 0; i < pointsStartToEnd.size(); i++) {

      if (pointsStartToEnd[i].x1 == pointsStartToEnd[i].x2) {
        int y1 = pointsStartToEnd[i].y1;
        int y2 = pointsStartToEnd[i].y2;
        if (pointsStartToEnd[i].y2 < pointsStartToEnd[i].y1) {

          y1 = pointsStartToEnd[i].y2;
          y2 = pointsStartToEnd[i].y1;

        }

        for (int j = y1; j <= y2; j++) {
          int index = 0;
          rowAndColToIndex(index, 1000, 1000, j, pointsStartToEnd[i].x1);
          grid[index]++;

        }

      }
      else if (pointsStartToEnd[i].y1 == pointsStartToEnd[i].y2) {
        int x1 = pointsStartToEnd[i].x1;
        int x2 = pointsStartToEnd[i].x2;
        if (pointsStartToEnd[i].x2 < pointsStartToEnd[i].x1) {

          x1 = pointsStartToEnd[i].x2;
          x2 = pointsStartToEnd[i].x1;

        }

        for (int j = x1; j <= x2; j++) {
          int index = 0;
          rowAndColToIndex(index, 1000, 1000, pointsStartToEnd[i].y1, j);
          grid[index]++;

        }

      }
      else {

        int x1 = pointsStartToEnd[i].x1;
        int x2 = pointsStartToEnd[i].x2;
        int y1 = pointsStartToEnd[i].y1;
        int y2 = pointsStartToEnd[i].y2;

        if (pointsStartToEnd[i].x2 < pointsStartToEnd[i].x1) {

          x1 = pointsStartToEnd[i].x2;
          y1 = pointsStartToEnd[i].y2;
          x2 = pointsStartToEnd[i].x1;
          y2 = pointsStartToEnd[i].y1;

        }

        for (int j = x1; j <= x2; j++) {

          int index = 0;
          rowAndColToIndex(index, 1000, 1000, y1, j);
          grid[index]++;

          if (y1 < y2) {
            y1++;
          }
          else {
            y1--;
          }
        }

      }

    }

    //for (int i = 0; i < 10; i++) {

    //  for (int j = 0; j < 10; j++) {
    //    int index;
    //    rowAndColToIndex(index, 1000, 1000, i, j);
    //
    //    std::cout << (int)grid[index] << " ";
    //  }
    //  std::cout << std::endl;

    //}

    int countMoreThaTwice = 0;
    for (int i = 0; i < 1000 * 1000; i++) {
      if (grid[i] > 1) {
        countMoreThaTwice++;
      }


    }

    std::cout << "Segunda estrella  " << countMoreThaTwice << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day05/input.txt";
  std::string testFile = "day05/test.txt";
  DayOfTodayAoC execute(inputFile);

  execute.computeFirstStar();

  execute.computeSecondStar();

  std::cin;

}
