# include "HistogramField.hpp"
# include <unistd.h>
void _test_histogramfield()
{
	HistogramField hf;
	for(int i = 0; i < 10; i++)
	{
		hf.push_back((i * 100) % 7);
		sleep(i % 3);
		std::cout << "wait :" << 10 - i << std::endl;

	}
	hf.show();
}
