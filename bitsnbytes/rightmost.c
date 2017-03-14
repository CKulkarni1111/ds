#include <stdio.h>
#include <inttypes.h>

void turn_off_rightmost_1(void)
{
	uint32_t x = 0xFFFF;

	printf("Turn off right most one x = 0x%X -> 0x%X\n", x, x & (x - 1));
}

void turn_on_rightmost_1(void)
{
	uint32_t x = 0xFFFE;

	printf("Turn on right most one x = 0x%X -> 0x%X\n", x, x | (x + 1));
}

void turn_off_trailing_1s(void)
{
	uint32_t x = 0xFF0F;

	printf("Turn off trailing ones x = 0x%X -> 0x%X\n", x, x & (x + 1));
}

void turn_on_trailing_0s(void)
{
	uint32_t x = 0xFFF0;

	printf("Turn on trailing ones x = 0x%X -> 0x%X\n", x, x | (x - 1));
}

void turn_on_rightmost_0_turn_off_all(void)
{
	uint32_t x = 0xFFF7;

	printf("Turn on rightmost 0 turn off all x = 0x%X -> 0x%X\n", x, ~x & (x + 1));
}

void turn_off_rightmost_1_turn_on_all(void)
{
	uint32_t x = 0xF0F8;

	printf("Turn off rightmost 1 turn on all x = 0x%X -> 0x%X\n", x, ~x | (x - 1));
}

int main(int argc, char *argv[])
{
	turn_off_rightmost_1();
	turn_on_rightmost_1();
	turn_off_trailing_1s();
	turn_on_trailing_0s();
    turn_on_rightmost_0_turn_off_all();
	turn_off_rightmost_1_turn_on_all();

	return 0;
}
