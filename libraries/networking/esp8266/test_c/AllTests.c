#include <stdio.h>
#include <cutest-1.5/CuTest.h> /** http://cutest.sourceforge.net/ */

CuSuite* ContactSuite();

int main(void) {
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();

	CuSuiteAddSuite(suite, ContactSuite());
	CuSuiteAddSuite(suite, OptionSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}
