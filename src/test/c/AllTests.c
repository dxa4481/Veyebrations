#include <stdio.h>
#include "../../../lib/cutest-1.5/CuTest.h"

CuSuite* ContactSuite();

int main(void) {
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();

	CuSuiteAddSuite(suite, ContactSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}
