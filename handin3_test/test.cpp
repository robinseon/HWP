#include "gtest/gtest.h"

extern "C"
{
#include <avr/io.h>
#include "key/key_driver.h"
#include "led/led_driver.h"
}

class LEDDriverTest : public ::testing::Test
{
protected:
	void SetUp()
	{
		inits_leds();
		init_keys();
	}
	void TearDown()
	{}
};

TEST_F(LEDDriverTest, TestConfig) {
	EXPECT_EQ(0xff, DDRA);//check if DDRA is an output
	EXPECT_EQ(0x00, DDRC);//chick if DDRC is an input
	EXPECT_EQ(0x3f, PORTC);//check the pullup of PORTC
}


TEST_F(LEDDriverTest, TestLed) //Test the led_driver
{
	EXPECT_EQ(0b11111111, PORTA);//simulate all the led turn off
	set_led(1, 1);
	EXPECT_EQ(0b11111110, PORTA);// simulate led1 turn on
	set_led(6, 1);
	EXPECT_EQ(0b11011110, PORTA);// simulate led 1 and 6 turn on
	set_led(1, 0);
	EXPECT_EQ(0b11011111, PORTA);// simulate turn off of led 1
}

TEST_F(LEDDriverTest, TestKey) // test the key driver
{
	PINC = 0b011111;//test the switch6 is pressed (0 is pressed and 1 not)
	EXPECT_EQ(1, get_key(6)); 
}