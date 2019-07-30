#include <vector>
#include "stack_gen.cpp"

int main(int argc, char *argv[]) {
  bool not_quit = true;
  int opp_code = 0;

  auto data = dataset();
  int[] test_data = {1,2,3,4,5,6,7,8,9};
  std::vector<int> test (test_data, test_data + sizeof(test_data) / sizeof(int));

  while (not_quit) {
    std::cout << "Mean & Median Age Census" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "1. Test Mean Class" << std::endl;
    std::cout << "2. Test Median Class" << std::endl;
    std::cout << "3. Mean ten data samples" << std::endl;
    std::cout << "4. Median ten data samples" << std::endl;
    std::cout << "5. Mean vs Median conclusion" << std::endl;
    std::cout << "6. Display latest Input set values" << std::endl;
    std::cout << "7. Credits" << std::endl;
    std::cout << "8. Exit" << std::endl << std::endl;

    std::cout << "Choice:" << std::endl;
    std::cin >> opp_code;
    if(!std::cin){
      std::cout << "Input failure, please enter an integer from 1-8" << std::endl;
      continue;
    }

    switch (opp_code) {
      case 1:
      // Generate a Test Mean Class???
      // Basically I'm gonna run the test Mean function
      break;

      case 2:
      // Generate a Test Median Class???
      break;

      case 3:
      // Mean ten data samples
      break;

      case 4:
      // Medain ten data samples
      break;

      case 5:
      // Mean vs Medain conclusion
      break;

      case 6:
      // Display latest input set values
      break;

      case 7:
      // Credits
        std::cout << "Welcome to the Credits:" << std::endl;

        std::cout << "Group 007:" << std::endl;
        std::cout << "Ahmad Hussain & Leo (Quancong) Ni" << std::endl;

        std::cout << "Group 008:" << std::endl;
        std::cout << "Nicholas Paquin & Kunal Chandan" << std::endl;

      break;

      case 8:
      // Exit
      std::cout << "Exiting mean, median program." << std::endl;
      not_quit = false;
      break;

      default:
        std::cout << "That is not one of the options I presented, you are not QA" << std::endl
      break;

    }
  }

  return 0;
}
