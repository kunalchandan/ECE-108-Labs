//Mean class declaration 
#include <vector>
using std::vector;

class Mean{
	public:
		
		Mean();
		
		~Mean();S
		
		float evaluate( vector<int> input_set);
		
		float get_mean();
		
		unsigned int get_size();
		
	private:
	
		float mean = 0;
		
		unsigned int input_size;
		
};