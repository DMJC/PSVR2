#include "includes.h"

using namespace std;
int cb_activate_external_view(libusb_device_handle* &dev_handle, libusb_context* &ctx){
    cout << "Activating External Camera!" << endl;
    unsigned char activate_code[10] = {0x17, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x03};
    int ctl_r = libusb_control_transfer(dev_handle, 0x42, 0x09, 0x0000, 0x0000, activate_code, sizeof(activate_code), 1000);
    if (ctl_r < 0) {
        fprintf(stderr, "Camera Activation failed!\n");
    }
    return 1;
}

int unknown_func_1(libusb_device_handle* &dev_handle, libusb_context* &ctx){
	cout << "Activating Function 1" << endl; 
	unsigned char activate_code[9] = {0x22, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00};
    int ctl_r = libusb_control_transfer(dev_handle, 0x42, 0x09, 0x0000, 0x0000, activate_code, sizeof(activate_code), 1000);
    if (ctl_r < 0) {
        fprintf(stderr, "Last Control transfer failed\n");
    }
    return 1;
}

int unknown_func_2(libusb_device_handle* &dev_handle, libusb_context* &ctx){
	cout << "Activating Function 2" << endl; 
    unsigned char activate_code[9]= {0x12, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x1f};
    int ctl_r = libusb_control_transfer(dev_handle, 0x42, 0x09, 0x0000, 0x0000, activate_code, sizeof(activate_code), 1000);
    if (ctl_r < 0) {
        fprintf(stderr, "Last Control transfer failed\n");
    }
    return 1;
}

bool cb_activate_external_view_mode_2(bool &state, libusb_device_handle* &dev_handle, libusb_context* &ctx){
	if (state == 0){
		cout << "Activating External Camera Mode 2!" << endl;
		unsigned char activate_code[24] = {0x14, 0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00, 0x55, 0x00, 0x00, 0x00, 0xf4, 0x01, 0x00, 0x00, 0x01, 0x00, 0x80, 0x24, 0x00, 0x00, 0x00, 0x00};
    	int ctl_r = libusb_control_transfer(dev_handle, 0x42, 0x09, 0x0000, 0x0000, activate_code, sizeof(activate_code), 1000);  // 1000 ms timeout
    	if (ctl_r < 0) {
    	    fprintf(stderr, "Last Control transfer failed\n");
    	}
	state = 1;
	}
	return 1;
}
