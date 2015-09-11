#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <Arduino.h>

#include "../../../lib/cutest-1.5/CuTest.h"
#include "../../../libraries/networking/atmega/KeyPermissionClient.h"

uint8_t currentPinModes[20];
void pinMode(uint8_t index, uint8_t value) {
	currentPinModes[index] = value;
}

void clearGlobals() {
	for (uint8_t i = 0; i < 20; i++) {
		currentPinModes[i] = -1;
	}
}

void KeyPermissionClient_constructor(CuTest* tc) {
	clearGlobals();
	KeyPermissionClient dut(10, 12, -1, 0);
	
	CuAssertIntEquals(tc, INPUT, currentPinModes[10]);
	CuAssertIntEquals(tc, OUTPUT, currentPinModes[12]);
}




CuSuite* KeyPermissionClientSuite(void)
{
	CuSuite* suite = CuSuiteNew();
	
	SUITE_ADD_TEST(suite, KeyPermissionClient_constructor);
	
	return suite;
}
