#include <string>
#include <SourceReader.h>

const std::string path = "../../days/2021/";

class DayOfTodayAoC{
 public:

   std::vector<int> numbersOfBingoToGoOutInOrder;
   int numOfNumberGoOut = 0;


   struct bingoCard{
     int cardBoard[5][5];
     bool willBeErase = false;
   };

   std::vector<bingoCard> cards;


   SourceReader* src;

  DayOfTodayAoC(std::string file) {

    src = new SourceReader(path+file);

    std::string s = src->get_data(0);
    std::string delimiter = ",";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
      token = s.substr(0, pos);
      numbersOfBingoToGoOutInOrder.push_back(std::stoi(token));
      s.erase(0, pos + delimiter.length());
    }
    numbersOfBingoToGoOutInOrder.push_back(std::stoi(s));



    int i = 2;
    delimiter = " ";
    while (i < src->get_size()) {

      bingoCard cardBingo;
      for (int j = 0; j < 5; j++) {
        pos = 0;
        s = src->get_data(i + j);
        int k = 0;
        while (k < 5 && (pos = s.find(delimiter)) != std::string::npos) {


          token = s.substr(0, pos);
          //if(token == "")
           // cardBingo.cardBoard[j][k] = 0;
          //else
          if(token != ""){
            cardBingo.cardBoard[j][k] = std::stoi(token);
            k++;
          }

          s.erase(0, pos + delimiter.length());


        }
        cardBingo.cardBoard[j][k] = std::stoi(s);


      }
      //for (int j = 0; j < 5; j++) {

      //  for (int k = 0; k < 5; k++) {

      //    std::cout << cardBingo.cardBoard[j][k] << " ";


      //  }
      //  std::cout << std::endl;
      //}
      //std::cout << std::endl;

      cards.push_back(cardBingo);

      i += 6;
    }
  }

  int computeFirstStar() {

    for (int numbers = 0; numbers < numbersOfBingoToGoOutInOrder.size(); numbers++) {

      for (int cardboard = 0; cardboard < cards.size(); cardboard++) {

        for (int i = 0; i < 5; i++) {

          for (int j = 0; j < 5; j++) {

            if (numbersOfBingoToGoOutInOrder[numbers] == cards[cardboard].cardBoard[i][j]) {
              cards[cardboard].cardBoard[i][j] = -1;
            }

          }

        }

      }

      //Check if there is a winner

      for (int cardboard = 0; cardboard < cards.size(); cardboard++) {

        for (int i = 0; i < 5; i++) {
          int count = 0;
          for (int j = 0; j < 5; j++) {

            if (-1 == cards[cardboard].cardBoard[i][j]) {
              count++;
            }

          }
          if (count == 5) {

            int winnerSum = 0;

            for (int i = 0; i < 5; i++) {

              for (int j = 0; j < 5; j++) {

                std::cout << cards[cardboard].cardBoard[i][j] << " ";
                if(cards[cardboard].cardBoard[i][j] != -1)
                  winnerSum += cards[cardboard].cardBoard[i][j];

              }
              std::cout << std::endl;
            }
            std::cout << std::endl;
            std::cout << "WINNER  " << numbersOfBingoToGoOutInOrder[numbers] * winnerSum << std::endl;
          }




        }


        for (int i = 0; i < 5; i++) {
          int count = 0;
          for (int j = 0; j < 5; j++) {

            if (-1 == cards[cardboard].cardBoard[j][i]) {
              count++;
            }

          }
          if (count == 5) {
            int winnerSum = 0;
            for (int i = 0; i < 5; i++) {

              for (int j = 0; j < 5; j++) {

                std::cout << cards[cardboard].cardBoard[i][j] << " ";
                if (cards[cardboard].cardBoard[i][j] != -1)
                  winnerSum += cards[cardboard].cardBoard[i][j];

              }
              std::cout << std::endl;
            }
            std::cout << std::endl;
            std::cout << "WINNER  " << numbersOfBingoToGoOutInOrder[numbers] * winnerSum << std::endl;
          }

        }

      }


    }



    std::cout << "First star" << std::endl;
    return 0;
  }


  int computeSecondStar() {


    for (int numbers = 0; numbers < numbersOfBingoToGoOutInOrder.size(); numbers++) {

      for (int cardboard = 0; cardboard < cards.size(); cardboard++) {

        for (int i = 0; i < 5; i++) {

          for (int j = 0; j < 5; j++) {

            if (numbersOfBingoToGoOutInOrder[numbers] == cards[cardboard].cardBoard[i][j]) {
              cards[cardboard].cardBoard[i][j] = -1;
            }

          }

        }

      }

      //Check if there is a winner
      std::vector<int> cardboardsToErase;

      for (int cardboard = 0; cardboard < cards.size(); cardboard++) {

        for (int i = 0; i < 5; i++) {
          int count = 0;
          for (int j = 0; j < 5; j++) {

            if (-1 == cards[cardboard].cardBoard[i][j]) {
              count++;
            }

          }
          if (count == 5 && !cards[cardboard].willBeErase) {
            if (cards.size() == 1) {
              int winnerSum = 0;
              for (int i = 0; i < 5; i++) {

                for (int j = 0; j < 5; j++) {

                  std::cout << cards[cardboard].cardBoard[i][j] << " ";
                  if (cards[cardboard].cardBoard[i][j] != -1)
                    winnerSum += cards[cardboard].cardBoard[i][j];

                }
                std::cout << std::endl;
              }
              std::cout << std::endl;
              std::cout << "WINNER  " << numbersOfBingoToGoOutInOrder[numbers] * winnerSum << std::endl;
            }
            cardboardsToErase.push_back(cardboard);
            cards[cardboard].willBeErase = true;

          }




        }


        for (int i = 0; i < 5; i++) {
          int count = 0;
          for (int j = 0; j < 5; j++) {

            if (-1 == cards[cardboard].cardBoard[j][i]) {
              count++;
            }

          }
          if (count == 5 && !cards[cardboard].willBeErase) {
            if (cards.size() == 1) {
              int winnerSum = 0;
              for (int i = 0; i < 5; i++) {

                for (int j = 0; j < 5; j++) {

                  std::cout << cards[cardboard].cardBoard[i][j] << " ";
                  if (cards[cardboard].cardBoard[i][j] != -1)
                    winnerSum += cards[cardboard].cardBoard[i][j];

                }
                std::cout << std::endl;
              }
              std::cout << std::endl;
              std::cout << "WINNER  " << numbersOfBingoToGoOutInOrder[numbers] * winnerSum << std::endl;
            }

            cardboardsToErase.push_back(cardboard);
            cards[cardboard].willBeErase = true;
          }

        }

      }

      for (int i = cardboardsToErase.size() - 1; i > -1; i--) {
        std::vector<bingoCard>::iterator it = cards.begin();
        std::advance(it, cardboardsToErase[i]);
        cards.erase(it);
      }
      cardboardsToErase.clear();

    }



    std::cout << "Second star" << std::endl;
    return 0;
  }


};

int main() {

  std::string inputFile = "day04/input.txt";
  std::string testInputFile = "day04/test.txt";
  DayOfTodayAoC execute(inputFile);

  //execute.computeFirstStar();

  execute.computeSecondStar();

  std::cin;

}
