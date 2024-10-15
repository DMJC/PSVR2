#include "includes.h"
#include "init_headset.h"
#include "interrupts.h"
#include "config.h"
#include "transfers.h"

using namespace std;

int main() {
    libusb_context *ctx = NULL;
    libusb_device_handle *dev_handle = NULL;
    int r;

    cout << "USB VR Testing App!" << endl;

    r = 0;
    r = libusb_init(&ctx);
    if (r < 0) {
        fprintf(stderr, "Failed to initialize libusb\n");
        return -1;
    }

    dev_handle = libusb_open_device_with_vid_pid(ctx, 0x054c, 0x0cde);
    if (dev_handle == NULL) {
        fprintf(stderr, "Cannot open PSVR2, is it plugged in/turned on?\nHave you got permission to access the device?\n");
        libusb_exit(ctx);
        return -1;
    }

    //Free Interfaces
    // Check if a kernel driver is active, if so, detach it
    int i = 0;
    while (i < 13){
        if (libusb_kernel_driver_active(dev_handle, i)) {
    	    int d = libusb_detach_kernel_driver(dev_handle, i);
            if (d != i) {
                printf("Failed to detach kernel driver: %s %s\n", &i, libusb_error_name(d));
            }
        }
    i++;
    }

	//set configuration
    int re = 0;
    re = libusb_set_configuration(dev_handle, 1);  // Select configuration 1
	r = libusb_claim_interface(dev_handle, 1);
    if (re < 0) {
        printf("Failed to set configuration: %s\n", libusb_error_name(re));
    } else {
        printf("Configuration set successfully\n");
    }

	if (r < 0) {
	    fprintf(stderr, "Cannot claim PSVR interface %d\n", 1);
	    libusb_close(dev_handle);
	    libusb_exit(ctx);
	    return -1;
	}

	int initialise_headset = 0;
	int trigger_exit = 0;
	bool state = false;
	while (trigger_exit != 1){
		if (initialise_headset == 0 ){
			initialise_headset = cb_init_headset(initialise_headset, dev_handle, ctx);
		}
		usleep(1000);
		state = cb_get_gyro_data(state, dev_handle, ctx);
//		cb_transfer_ep5(dev_handle, ctx);
//		cb_transfer_ep9(dev_handle, ctx);
//		cb_transfer_ep10(dev_handle, ctx); //Probably Camera Data
//		cb_transfer_ep11(dev_handle, ctx);
//		cb_transfer_ep13(dev_handle, ctx);
		if (state == true){
			printf ("Activating Cam\n");
			cb_activate_external_view(dev_handle, ctx);
//			cb_activate_external_view_mode_2(state, dev_handle, ctx);
		}
		int int_view = 0;
		printf ("\nint view: %d and initialise Headset: %d", int_view, initialise_headset );
/*		if (int_view == 0 && initialise_headset == true){
		}*/
		cb_transfer_get_video(dev_handle, ctx);
	}
	return 0;
}

