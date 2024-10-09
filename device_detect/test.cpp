#include <libudev.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <libudev.h>
#include <vector>

using namespace std;

int main () {
        struct udev *udev;
        struct udev_device *dev;
        struct udev_enumerate *enumerate;
        struct udev_list_entry *devices, *dev_list_entry;

        /* create udev object */
        udev = udev_new();
        if (!udev) {
                fprintf(stderr, "Cannot create udev context.\n");
        }

        /* create enumerate object */
        enumerate = udev_enumerate_new(udev);
        if (!enumerate) {
                fprintf(stderr, "Cannot create enumerate context.\n");
        }

        udev_enumerate_add_match_sysattr(enumerate, "id/vendor" , "054c");
        udev_enumerate_scan_devices(enumerate);

        /* fillup device list */
        devices = udev_enumerate_get_list_entry(enumerate);
      	if (!devices) {
                fprintf(stderr, "Failed to get device list.\n");
                fprintf(stderr, "Re-run after connecting at least one supported device.\n");
                exit(1);
        }

        int i = -1;
        udev_list_entry_foreach(dev_list_entry, devices)
        {
                i++;
        }

	cout << "Value of i: " << i << endl;
}
