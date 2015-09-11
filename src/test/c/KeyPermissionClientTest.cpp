#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "../../../lib/cutest-1.5/CuTest.h"
#include "../../../libraries/networking/atmega/KeyPermissionClient.h"


void KeyPermissionClient_thingy(CuTest* tc) {
	CuAssertTrue(tc, true);
}




CuSuite* KeyPermissionClientSuite(void)
{
	CuSuite* suite = CuSuiteNew();
	
//	SUITE_ADD_TEST(suite, getKeyTime_constructor);
	
	return suite;
}
