

#include "m_console.h"
#include <zephyr/kernel.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/sys/printk.h>


#define CONSOLE_MODE	DT_CHOSEN(zephyr_console)
BUILD_ASSERT(DT_NODE_HAS_COMPAT(CONSOLE_MODE, zephyr_cdc_acm_uart),
	"Console device is not ACM CDC UART");

const struct device *const dev = DEVICE_DT_GET(CONSOLE_MODE);

int console_init(void)
{
	uint32_t dtr = 0;
	/* Poll if the DTR flag was set */
	while (!dtr) {
		uart_line_ctrl_get(dev, UART_LINE_CTRL_DTR, &dtr);
		/* Give CPU resources to low priority threads. */
		k_sleep(K_MSEC(100));
	}	 
	return 0;
}