#ifndef __TEST_UTILS_

#define __TEST_UTILS_

typedef bool(*test_func)(void);

#define fail(testName, message) \
	std::cout << "%TEST_FAILED% time=0 testname=" << testName << " (to_xml) message="  << message << std::endl;\
	return false;

#endif