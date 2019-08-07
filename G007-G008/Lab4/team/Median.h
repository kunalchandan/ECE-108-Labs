//code for ece108 final project
#include <vector>
using std::vector;

class Median{
public:

    Median();

    ~Median();

    float evaluate( vector<int> data_set);

    float get_median();

    unsigned int get_size();

private:

    float median = 0.0;

    unsigned int input_size;


};
