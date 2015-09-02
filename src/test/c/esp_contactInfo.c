#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../../lib/cutest-1.5/CuTest.h"
#include "../../esp8266/c/contactInfo.h"


void LeastRecent_ZeroLen(CuTest* tc) {
	CuAssertPtrEquals(tc, NULL, findLeastRecentTime(0, NULL));
}

void LeastRecent_OneLen(CuTest* tc) {
	const contactInfo value = { 654321 };
	const contactInfo* const argv = &value;
	
	CuAssertPtrEquals(tc, argv, findLeastRecentTime(1, argv));
}

void LeastRecent_OneLen_2(CuTest* tc) {
	contactInfo argv[10];
	argv[0].mostRecentKeyOwnTime = 654321;
	argv[1].mostRecentKeyOwnTime = 0;
	argv[2].mostRecentKeyOwnTime = 0;
	argv[3].mostRecentKeyOwnTime = 0;
	
	CuAssertPtrEquals(tc, argv, findLeastRecentTime(1, argv));
}

void LeastRecent_TwoLen_0(CuTest* tc) {
	contactInfo* const argv = (contactInfo*) malloc(2 * sizeof(contactInfo));
	argv[0].mostRecentKeyOwnTime = 654321;
	argv[1].mostRecentKeyOwnTime = 12345;
	
	CuAssertPtrEquals(tc, argv + 1, findLeastRecentTime(2, argv));
	
	free(argv);
}

void LeastRecent_TwoLen_1(CuTest* tc) {
	contactInfo* const argv = (contactInfo*) malloc(2 * sizeof(contactInfo));
	argv[0].mostRecentKeyOwnTime = 12345;
	argv[1].mostRecentKeyOwnTime = 654321;
	
	CuAssertPtrEquals(tc, argv, findLeastRecentTime(2, argv));
	
	free(argv);
}

void LeastRecent_TenLen_5(CuTest* tc) {
	int i;
	contactInfo* const argv = (contactInfo*) malloc(10 * sizeof(contactInfo));
	for (i = 0; i < 10; i++) {
		argv[i].mostRecentKeyOwnTime = 100000 - i;
	}
	argv[5].mostRecentKeyOwnTime = 45;
	
	CuAssertPtrEquals(tc, argv + 5, findLeastRecentTime(10, argv));
	
	free(argv);
}





CuSuite* ContactInfoSuite(void)
{
	CuSuite* suite = CuSuiteNew();
	
	SUITE_ADD_TEST(suite, LeastRecent_ZeroLen);
	SUITE_ADD_TEST(suite, LeastRecent_OneLen);
	SUITE_ADD_TEST(suite, LeastRecent_OneLen_2);
	SUITE_ADD_TEST(suite, LeastRecent_TwoLen_0);
	SUITE_ADD_TEST(suite, LeastRecent_TwoLen_1);
	SUITE_ADD_TEST(suite, LeastRecent_TenLen_5);
	
	return suite;
}
