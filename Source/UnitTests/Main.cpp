#include "../UnitTest++/UnitTest++.h"
#include "../UnitTest++/TestReporterStdout.h"

#include <iostream>
#include <limits>

int main(int, char const *[])
{
	UnitTest::RunAllTests();

	std::cout << "Press ENTER to continue... " << std::flush;
	std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
	return 0;
}
