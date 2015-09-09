#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "../../../lib/cutest-1.5/CuTest.h"
#include "../../../libraries/networking/esp8266/Contact.h"
#include "../../../libraries/networking/esp8266/ContactList.h"


void getKeyTime_constructor(CuTest* tc) {
	const Contact res(123, 456);
	CuAssertTrue(tc, 123 == res.getKeyTime());
}

void getKeyTime_setter(CuTest* tc) {
	Contact res;
	res.setKeyTime(456);
	CuAssertTrue(tc, 456 == res.getKeyTime());
}

void isStale_constructor_1(CuTest* tc) {
	const Contact res(123, 456);
	CuAssertTrue(tc, !res.isStale(0));
}

void isStale_constructor_2(CuTest* tc) {
	const Contact res(123, 456);
	CuAssertTrue(tc, !res.isStale(100456));
}

void isStale_constructor_3(CuTest* tc) {
	const Contact res(123, 456);
	CuAssertTrue(tc, res.isStale(100457));
}

void isStale_constructor_4(CuTest* tc) {
	const Contact res(123, 456);
	CuAssertTrue(tc, res.isStale(300000));
}

void isStale_setter_2(CuTest* tc) {
	Contact res;
	res.setPingTime(456);
	CuAssertTrue(tc, !res.isStale(100456));
}

void isStale_setter_3(CuTest* tc) {
	Contact res;
	res.setPingTime(456);
	CuAssertTrue(tc, res.isStale(100457));
}


void LeastRecent_ZeroLen(CuTest* tc) {
	const std::vector<Contact> val;
	
	CuAssertTrue(tc, NULL == &determineWhoToSendKeyTo(val.begin(), val.end()));
}

void LeastRecent_OneLen(CuTest* tc) {
	const Contact value(654321, 0);
	const Contact* const argv = &value;
	
	CuAssertTrue(tc, value == determineWhoToSendKeyTo(argv, argv + 1));
}

void LeastRecent_OneLen_2(CuTest* tc) {
	Contact argv[10];
	argv[0].setKeyTime(654321);
	argv[1].setKeyTime(0);
	argv[2].setKeyTime(0);
	argv[3].setKeyTime(0);
	
	CuAssertTrue(tc, argv[0] == determineWhoToSendKeyTo(argv, argv + 1));
}

void LeastRecent_OneLen_heap(CuTest* tc) {
	Contact* const argv((Contact*) malloc(1 * sizeof(Contact)));
	argv[0].setKeyTime(654321);
	
	CuAssertTrue(tc, argv[0] == determineWhoToSendKeyTo(argv, argv + 1));
	
	free(argv);
}


void LeastRecent_OneLen_vector(CuTest* tc) {
	std::vector<Contact> argv;
	argv.push_back( Contact(654321, 0) );
	
	CuAssertTrue(tc, argv[0] == determineWhoToSendKeyTo(argv.begin(), argv.end()));
}

void LeastRecent_TwoLen_0(CuTest* tc) {
	std::vector<Contact> argv;
	argv.push_back( Contact(654321, 0) );
	argv.push_back( Contact(12345, 2) );
	
	CuAssertTrue(tc, argv[1] == determineWhoToSendKeyTo(argv.begin(), argv.end()));
}

void LeastRecent_TwoLen_1(CuTest* tc) {
	Contact* const argv = (Contact*) malloc(2 * sizeof(Contact));
	argv[0].setKeyTime(12345);
	argv[1].setKeyTime(654321);
	
	CuAssertTrue(tc, argv[0] == determineWhoToSendKeyTo(argv, argv + 2));
	
	free(argv);
}

void LeastRecent_TenLen_5(CuTest* tc) {
	int i;
	Contact* const argv = (Contact*) malloc(10 * sizeof(Contact));
	for (i = 0; i < 10; i++) {
		argv[i].setKeyTime(100000 - i);
	}
	argv[5].setKeyTime(45);
	
	CuAssertTrue(tc, argv[5] == determineWhoToSendKeyTo(argv, argv + 10));
	
	free(argv);
}





CuSuite* ContactSuite(void)
{
	CuSuite* suite = CuSuiteNew();
	
	SUITE_ADD_TEST(suite, getKeyTime_constructor);
	SUITE_ADD_TEST(suite, getKeyTime_setter);
	
	SUITE_ADD_TEST(suite, isStale_constructor_1);
	SUITE_ADD_TEST(suite, isStale_constructor_2);
	SUITE_ADD_TEST(suite, isStale_constructor_3);
	SUITE_ADD_TEST(suite, isStale_constructor_4);
	SUITE_ADD_TEST(suite, isStale_setter_2);
	SUITE_ADD_TEST(suite, isStale_setter_3);
	
//	SUITE_ADD_TEST(suite, LeastRecent_ZeroLen);
	SUITE_ADD_TEST(suite, LeastRecent_OneLen);
	SUITE_ADD_TEST(suite, LeastRecent_OneLen_2);
	SUITE_ADD_TEST(suite, LeastRecent_OneLen_heap);
	SUITE_ADD_TEST(suite, LeastRecent_OneLen_vector);
	SUITE_ADD_TEST(suite, LeastRecent_TwoLen_0);
	SUITE_ADD_TEST(suite, LeastRecent_TwoLen_1);
	SUITE_ADD_TEST(suite, LeastRecent_TenLen_5);
	
	return suite;
}
