#include <stdio.h>
#include "../../../lib/cutest-1.5/CuTest.h"

CuSuite* KeyPermissionClientSuite();

int main(void) {
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();

	CuSuiteAddSuite(suite, KeyPermissionClientSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}
