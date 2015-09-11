#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <Arduino.h>

#include "../../../lib/cutest-1.5/CuTest.h"
#include "../../../libraries/networking/atmega/KeyPermissionClient.h"

/***** Mocks ******/

volatile uint8_t currentPinModes[20];
volatile uint8_t currentPinValues[20];
void pinMode(uint8_t index, uint8_t value) {
	currentPinModes[index] = value;
}
void digitalWrite(uint8_t index, uint8_t value) {
	currentPinValues[index] = value;
}
int digitalRead(uint8_t index) {
	return currentPinValues[index];
}

/****** setUp / tearDown ******/

void clearGlobals() {
	for (uint8_t i = 0; i < 20; i++) {
		currentPinModes[i] = -1;
		currentPinValues[i] = -1;
	}
}

/******* Tests ********/

void KeyPermissionClient_constructor(CuTest* tc) {
	clearGlobals();
	KeyPermissionClient dut(10, 12);
	
	CuAssertIntEquals(tc, INPUT, currentPinModes[10]);
	CuAssertIntEquals(tc, OUTPUT, currentPinModes[12]);
}

void KeyPermissionClient_hasKey_false(CuTest* tc) {
	clearGlobals();
	currentPinValues[3] = LOW;
	KeyPermissionClient dut(3, 4);
	
	CuAssertTrue(tc, ! dut.hasKey());
}

void KeyPermissionClient_hasKey_true(CuTest* tc) {
	clearGlobals();
	currentPinValues[3] = HIGH;
	KeyPermissionClient dut(3, 4);
	
	CuAssertTrue(tc, dut.hasKey());
}

volatile bool isCorrectAtDelay;
void delay(unsigned long) {
	isCorrectAtDelay = (HIGH == currentPinValues[4]);
	currentPinValues[3] = LOW;
}

void KeyPermissionClient_indicateDone(CuTest* tc) {
	clearGlobals();
	currentPinValues[3] = HIGH;
	KeyPermissionClient dut(3, 4);
	dut.indicateDone();
	
	CuAssertTrue(tc, isCorrectAtDelay);
	CuAssertTrue(tc, (LOW == currentPinValues[4]));
}



CuSuite* KeyPermissionClientSuite(void)
{
	CuSuite* suite = CuSuiteNew();
	
	SUITE_ADD_TEST(suite, KeyPermissionClient_constructor);
	SUITE_ADD_TEST(suite, KeyPermissionClient_hasKey_false);
	SUITE_ADD_TEST(suite, KeyPermissionClient_hasKey_true);
	SUITE_ADD_TEST(suite, KeyPermissionClient_indicateDone);
	
	return suite;
}
