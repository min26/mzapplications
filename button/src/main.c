
#include <stdio.h>
//#include <inttypes.h>
#include <zephyr/kernel.h>
//#include <zephyr/device.h>
//#include <zephyr/sys/util.h>
#include <zephyr/sys/printk.h>
#include "m_button.h"
#include "m_console.h"

#define MY_TIME_1000MS	1000

int main(void)
{
	console_init();

	button_init();
	led_init();

	printk("main() start\n");
	while(1){
		k_msleep(MY_TIME_1000MS);
	}
	return 0;
}