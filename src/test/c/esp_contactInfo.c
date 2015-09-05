#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "../../../lib/cutest-1.5/CuTest.h"
#include "../../../libraries/networking/esp8266/contactInfo.h"


void LeastRecent_ZeroLen(CuTest* tc) {
	const std::vector<ContactInfo> val;
	
	CuAssertTrue(tc, NULL == &determineWhoToSendKeyTo(val.begin(), val.end()));
}

void LeastRecent_OneLen(CuTest* tc) {
	const ContactInfo value(654321);
	const ContactInfo* const argv = &value;
	
	CuAssertTrue(tc, value == determineWhoToSendKeyTo(argv, argv + 1));
}

void LeastRecent_OneLen_2(CuTest* tc) {
	ContactInfo argv[10];
	argv[0].mostRecentKeyOwnTime = 654321;
	argv[1].mostRecentKeyOwnTime = 0;
	argv[2].mostRecentKeyOwnTime = 0;
	argv[3].mostRecentKeyOwnTime = 0;
	
	CuAssertTrue(tc, argv[0] == determineWhoToSendKeyTo(argv, argv + 1));
}

void LeastRecent_OneLen_vector(CuTest* tc) {
	std::vector<ContactInfo> argv;
	argv.push_back( ContactInfo(654321) );
	
	CuAssertTrue(tc, argv[0] == determineWhoToSendKeyTo(argv.begin(), argv.end()));
}

void LeastRecent_TwoLen_0(CuTest* tc) {
	std::vector<ContactInfo> argv;
	argv.push_back( ContactInfo(654321) );
	argv.push_back( ContactInfo(12345) );
	
	CuAssertTrue(tc, argv[1] == determineWhoToSendKeyTo(argv.begin(), argv.end()));
}

void LeastRecent_TwoLen_1(CuTest* tc) {
	ContactInfo* const argv = (ContactInfo*) malloc(2 * sizeof(ContactInfo));
	argv[0].mostRecentKeyOwnTime = 12345;
	argv[1].mostRecentKeyOwnTime = 654321;
	
	CuAssertTrue(tc, argv[0] == determineWhoToSendKeyTo(argv, argv + 2));
	
	free(argv);
}

void LeastRecent_TenLen_5(CuTest* tc) {
	int i;
	ContactInfo* const argv = (ContactInfo*) malloc(10 * sizeof(ContactInfo));
	for (i = 0; i < 10; i++) {
		argv[i].mostRecentKeyOwnTime = 100000 - i;
	}
	argv[5].mostRecentKeyOwnTime = 45;
	
	CuAssertTrue(tc, argv[5] == determineWhoToSendKeyTo(argv, argv + 10));
	
	free(argv);
}





CuSuite* ContactInfoSuite(void)
{
	CuSuite* suite = CuSuiteNew();
	
//	SUITE_ADD_TEST(suite, LeastRecent_ZeroLen);
	SUITE_ADD_TEST(suite, LeastRecent_OneLen);
	SUITE_ADD_TEST(suite, LeastRecent_OneLen_2);
	SUITE_ADD_TEST(suite, LeastRecent_OneLen_vector);
	SUITE_ADD_TEST(suite, LeastRecent_TwoLen_0);
	SUITE_ADD_TEST(suite, LeastRecent_TwoLen_1);
	SUITE_ADD_TEST(suite, LeastRecent_TenLen_5);
	
	return suite;
}
