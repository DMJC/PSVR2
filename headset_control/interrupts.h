#include "includes.h"
using namespace std;

int cb_interrupt_headset(libusb_device_handle* &dev_handle, libusb_context* &ctx){
    cout << "Sending Interrupt to Headset" << endl;
	int res = 0;
	unsigned char data[1024];
	int actual_length = 0;
    int r = 0;
	    r = libusb_claim_interface(dev_handle, 7);
	    if (r < 0) {
	        fprintf(stderr, "Cannot claim PSVR interface %d\n", 7);
	        libusb_close(dev_handle);
	        libusb_exit(ctx);
	        return -1;
	    }

	    res = libusb_interrupt_transfer(dev_handle, 0x88, data, sizeof(data), &actual_length, 1000); // Timeout in milliseconds
	    if (res < 0) {
	        fprintf(stderr, "Interrupt transfer failed to endpoint 8: %s\n", libusb_error_name(res));
	    } else {
//	        printf("Received %d bytes: ", actual_length);
	        for (int i = 0; i < actual_length; i++) {
	            printf("%02X", data[i]);
	        }
	        printf("\n");
	    }
	return 1;
}



