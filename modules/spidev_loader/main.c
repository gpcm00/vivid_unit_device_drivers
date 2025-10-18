/* 
 * A simple module that binds spidev to the SPI controller
 * at bus 2.
 * 
 */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/spi/spi.h>

static struct spi_device *spidev;

static int __init load_spidev_init(void)
{
    struct spi_master *master;
    struct spi_board_info spi_info = {
        .modalias = "spidev",
        .max_speed_hz = 10000000,
        .bus_num = 2,
        .chip_select = 0,
        .mode = SPI_MODE_0,
    };

    master = spi_busnum_to_master(spi_info.bus_num);
    if (!master) {
        printk(KERN_ERR "SPI master %d not found\n", spi_info.bus_num);
        return -ENODEV;
    }

    spidev = spi_new_device(master, &spi_info);
    if (!spidev) {
        printk(KERN_ERR "Failed to create SPI device\n");
        return -ENODEV;
    }

    printk(KERN_INFO "SPI device added\n");
    return 0;
}

static void __exit load_spidev_exit(void)
{
    if (spidev)
        spi_unregister_device(spidev);
    printk(KERN_INFO "SPI device removed\n");
}

module_init(load_spidev_init);
module_exit(load_spidev_exit);

MODULE_AUTHOR("gpcm00");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Loads spidev dynamically");
