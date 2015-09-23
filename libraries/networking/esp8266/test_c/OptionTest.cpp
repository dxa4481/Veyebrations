#include <cutest-1.5/CuTest.h> /** http://cutest.sourceforge.net/ */
#include "../Option.h"


void constructor_null(CuTest* tc) {
	const StringOption res;
	CuAssertTrue(tc, res.isNone());
}

void constructor_str(CuTest* tc) {
	const StringOption res("1");
	CuAssertTrue(tc, !res.isNone());
	CuAssertStrEquals(tc, "1", res.getValue());
}

void constructor_str2(CuTest* tc) {
	const StringOption res("abc");
	CuAssertTrue(tc, !res.isNone());
	CuAssertStrEquals(tc, "abc", res.getValue());
}



CuSuite* OptionSuite(void)
{
	CuSuite* suite = CuSuiteNew();
	
	SUITE_ADD_TEST(suite, constructor_null);
	SUITE_ADD_TEST(suite, constructor_str);
	SUITE_ADD_TEST(suite, constructor_str2);
	
	return suite;
}
