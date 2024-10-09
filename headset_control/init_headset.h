#include "includes.h"

using namespace std;
int cb_init_headset(int& initialise_headset, libusb_device_handle* &dev_handle, libusb_context* &ctx){
	cout << "Initialising Headset" << endl;
    //We don't know what these do so we will ignore returned data for now.
    // Send the control transfer 1
	unsigned char data_control_1[92];
    int control_r1 = libusb_control_transfer(dev_handle, 0xc2, 1, 0x0081, 0, data_control_1, 92, 1000);
    if (control_r1 < 0) {
        printf("Control transfer failed: %s\n", libusb_error_name(control_r1));
    } else {
        printf("Received %d bytes from control transfer 1\n", control_r1);
        // Process the data (e.g., print the descriptor)
    }
    // Send the control transfer 2
	unsigned char data_control_2[12];
    int control_r2 = libusb_control_transfer(dev_handle, 0xc2, 1, 0x00a1, 0, data_control_2, 12, 1000);
    if (control_r2 < 0) {
        printf("Control transfer failed: %s\n", libusb_error_name(control_r2));
    } else {
        printf("Received %d bytes from control transfer 2\n", control_r2);
        // Process the data (e.g., print the descriptor)
    }
    // Send the control transfer 3
	unsigned char data_control_3[264];
    int control_r3 = libusb_control_transfer(dev_handle, 0xc2, 1, 0x008f, 0, data_control_3, 264, 1000);
    if (control_r3 < 0) {
        printf("Control transfer failed: %s\n", libusb_error_name(control_r3));
    } else {
        printf("Received %d bytes from control transfer 3\n", control_r3);
        // Process the data (e.g., print the descriptor)
    }

    int r = 0;
	    r = libusb_claim_interface(dev_handle, 7);
	    if (r < 0) {
	        fprintf(stderr, "Cannot claim PSVR interface %d\n", 7);
	        libusb_close(dev_handle);
	        libusb_exit(ctx);
	        return -1;
	    }

    cout << "Set Interface 7 to Interrupt Mode" << endl;
    int alt_r = libusb_set_interface_alt_setting(dev_handle, 7, 1);
    if (alt_r < 0) {
        fprintf(stderr, "Failed to set interface alternate setting: %s\n", libusb_strerror(alt_r));
    } else {
        printf("Successfully set interface %d to alternate setting %d.\n", 7, 1);
    }
	cout << "Control Packets Sent. Headset" << endl;
return 1;
}

int cb_activate_internal_view(int &state, libusb_device_handle* &dev_handle, libusb_context* &ctx){
	if (state == 0){
		cout << "Activating Unknown Mode" << endl;
		unsigned char activate_code[24] = {0x14, 0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00, 0x55, 0x00, 0x00, 0x00, 0xf4, 0x01, 0x00, 0x00, 0x01, 0x00, 0x80, 0x24, 0x00, 0x00, 0x00, 0x00};
    	int ctl_r = libusb_control_transfer(dev_handle, 0x42, 0x09, 0x0000, 0x0000, activate_code, sizeof(activate_code), 1000);  // 1000 ms timeout
    	if (ctl_r < 0) {
    	    fprintf(stderr, "Last Control transfer failed\n");
    	}
	state = 1;
	}
	return 1;
}

int cb_activate_external_view(int &state, libusb_device_handle* &dev_handle, libusb_context* &ctx){
	if (state == 0){
		cout << "Activating External Camera" << endl;
		unsigned char activate_code[10] = {0x17, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x03};
    	int ctl_r = libusb_control_transfer(dev_handle, 0x42, 0x09, 0x0000, 0x0000, activate_code, sizeof(activate_code), 1000);  // 1000 ms timeout
    	if (ctl_r < 0) {
    	    fprintf(stderr, "Last Control transfer failed\n");
    	}
	state = 1;
	}
	return 1;
}
