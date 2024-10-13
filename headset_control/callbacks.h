#include "includes.h"

using namespace std;
int cb_activate_external_view(libusb_device_handle* &dev_handle, libusb_context* &ctx){
                cout << "Activating External Camera Now!" << endl;
                unsigned char activate_code[10] = {0x17, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x03};
        int ctl_r = libusb_control_transfer(dev_handle, 0x42, 0x09, 0x0000, 0x0000, activate_code, sizeof(activate_code), 1000);
        if (ctl_r < 0) {
            fprintf(stderr, "Last Control transfer failed\n");
        }
        return 1;
}
