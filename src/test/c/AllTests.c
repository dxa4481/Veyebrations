#include <stdio.h>
#include "../../../lib/cutest-1.5/CuTest.h"

CuSuite* ContactInfoSuite();

int main(void) {
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();

	CuSuiteAddSuite(suite, ContactInfoSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}
