#include "callbacks.h"
#include "includes.h"
using namespace std;

int cb_interrupt_headset_port_0(bool &state, libusb_device_handle* &dev_handle, libusb_context* &ctx){
//    cout << "\nSending Interrupt to Headset" << endl;
	int res = 0;
	unsigned char data[64];
	int actual_length = 0;
	int r = 0;
	    r = libusb_claim_interface(dev_handle, 0);
	    if (r < 0) {
	        fprintf(stderr, "Cannot claim PSVR interface %d\n", 0);
	        libusb_close(dev_handle);
	        libusb_exit(ctx);
	        return -1;
	    }

	    res = libusb_interrupt_transfer(dev_handle, 0x81, data, sizeof(data), &actual_length, 1000); // Timeout in milliseconds
	    if (res < 0) {
	        fprintf(stderr, "Interrupt transfer failed to endpoint 0: %s\n", libusb_error_name(res));
	    } else {
	        for (int i = 0; i < actual_length; i++) { //something is here
	            printf("%02X", data[i]);
	        }
		}
	return 0;
}

int cb_interrupt_headset_port_1(bool &state, libusb_device_handle* &dev_handle, libusb_context* &ctx){
//    cout << "\nSending Interrupt to Headset" << endl;
	int res = 0;
	unsigned char data[64];
	int actual_length = 0;
	int r = 0;
	    r = libusb_claim_interface(dev_handle, 7);
	    if (r < 0) {
	        fprintf(stderr, "Cannot claim PSVR interface %d\n", 7);
	        libusb_close(dev_handle);
	        libusb_exit(ctx);
	        return -1;
	    }

	    res = libusb_interrupt_transfer(dev_handle, 0x01, data, sizeof(data), &actual_length, 1000); // Timeout in milliseconds
	    if (res < 0) {
	        fprintf(stderr, "Interrupt transfer failed to endpoint 1: %s\n", libusb_error_name(res));
	    } else {
	        for (int i = 0; i < actual_length; i++) { //something is here
	            printf("%02X", data[i]);
	        }
		}
	return 0;
}


int cb_interrupt_headset_port_5(bool &state, libusb_device_handle* &dev_handle, libusb_context* &ctx){
//    cout << "\nSending Interrupt to Headset" << endl;
	int res = 0;
	unsigned char data[1024];
	int actual_length = 0;
	int r = 0;
	    r = libusb_claim_interface(dev_handle, 5);
	    if (r < 0) {
	        fprintf(stderr, "Cannot claim PSVR interface %d\n", 5);
	        libusb_close(dev_handle);
	        libusb_exit(ctx);
	        return -1;
	    }

	    res = libusb_interrupt_transfer(dev_handle, 0x86, data, sizeof(data), &actual_length, 1000); // Timeout in milliseconds
	    if (res < 0) {
	        fprintf(stderr, "Interrupt transfer failed to endpoint 5: %s\n", libusb_error_name(res));
	    } else {
	        for (int i = 0; i < actual_length; i++) { //something is here
	            printf("%02X", data[i]);
	        }
		}
	return 0;
}

int cb_interrupt_headset_port_8(bool &state, libusb_device_handle* &dev_handle, libusb_context* &ctx){
//    cout << "\nSending Interrupt to Headset" << endl;
	int res = 0;
	unsigned char data[1024];
	int actual_length = 0;
	int r = 0;
	    r = libusb_claim_interface(dev_handle, 7);
	    if (r < 0) {
	        fprintf(stderr, "Cannot claim PSVR Status interface %d\n", 7);
	        libusb_close(dev_handle);
	        libusb_exit(ctx);
	        return -1;
	    }

	    res = libusb_interrupt_transfer(dev_handle, 0x88, data, sizeof(data), &actual_length, 1000); // Timeout in milliseconds
	    if (res < 0) {
	        fprintf(stderr, "Interrupt failed for PSVR Status: %s\n", libusb_error_name(res));
	    } else {
		int16_t value = 0;
	        printf("\nReceived %d bytes: \n", actual_length);
//	        for (int i = 0; i < actual_length; i++) {
		printf("Data:\n");
				//Timer Value
/*				value = (data[34] | (data[35] << 8));
				printf("Timer Val: %d ", value);*/
				value = (data[36] | (data[37] << 8));
				printf("Pitch Up/Down: %d ", value);
				value = (data[38] | (data[39] << 8));
				printf("Roll Left/Right: %d ", value);
				value = (data[40] | (data[41] << 8));
				//Zero Value
				printf("Roll or Pitch?: %d ", value);

				//Acceleration Values
/*				value = (data[42] | (data[43] << 8));
				printf("Accel Roll: %d ", value);
				value = (data[44] | (data[45] << 8));
				printf("Accel Pitch Up/Down: %d ", value);
				value = (data[46] | (data[47] << 8));
				printf("Accel Left/Right: %d ", value);
*/
				//Counter Value
/*				value = (data[48] | (data[49] << 8));
				printf("-ve Counter: %d ", value);
				value = (data[50] | (data[51] << 8));
				printf("Val: %d ", value);
				value = (data[52] | (data[53] << 8));
				printf("Unknown Func Val: %d ", value);
				//Static Value of 1.
				value = (data[54] | (data[55] << 8));
				printf("Val: %d ", value);
				value = (data[56] | (data[57] << 8));
				printf("Val: %d ", value);*/

				//Counter Value
/*				value = (data[58] | (data[59] << 8));
				printf("-ve Counter: %d ", value);*/

/*				value = (data[60] | (data[61] << 8));
				printf("Pitch Up/Down: %d ", value);
				value = (data[62] | (data[63] << 8));
				printf("Roll Left/Right: %d ", value);
				value = (data[64] | (data[65] << 8));
				printf("Looking Up Forward/Back: %d", value);
				value = (data[66] | (data[67] << 8));*/

				//Zero Value
/*				printf("Zero: %d ", value);
				value = (data[68] | (data[69] << 8));*/

/*				printf("Accel Pitch %d ", value);
				value = (data[70] | (data[71] << 8));
				printf("Accel Yaw Left/Right%d ", value);
*/
				//Counter
/*				value = (data[72] | (data[73] << 8));
				printf("Counter%d ", value);*/

				//Zero Value
/*				value = (data[74] | (data[75] << 8));
				printf("Zero: %d ", value);*/
				//Counter Fast
/*				value = (data[76] | (data[77] << 8));
				printf("Val: %d ", value);*/
				//Zero Value
/*				value = (data[78] | (data[79] << 8));
				printf("Val: %d ", value);
				value = (data[80] | (data[81] << 8));
				printf("Val: %d ", value);
				value = (data[82] | (data[83] << 8));
				printf("Val: %d ", value);*/
/*				value = (data[84] | (data[85] << 8));
				printf("Pitch Up/Down: %d ", value);
				value = (data[86] | (data[87] << 8));
				printf("Roll Left/Right: %d ", value);
				value = (data[88] | (data[89] << 8));
				printf("Roll Upside/Down: %d ", value);
				value = (data[90] | (data[91] << 8));
				printf("Roll Accel: %d ", value);
				value = (data[92] | (data[93] << 8));
				printf("Pitch Accel: %d ", value);
				value = (data[94] | (data[95] << 8));
				printf("Yaw Accel: %d ", value);
				value = (data[96] | (data[97] << 8));
				printf("Unk Val:  %d ", value);
				value = (data[98] | (data[99] << 8));
				printf("Unk Val: %d ", value);
				value = (data[100] | (data[101] << 8));
				printf("Unk Val: %d ", value);
				value = (data[102] | (data[103] << 8));
				printf("Unk Val: %d ", value);
				value = (data[104] | (data[105] << 8));
				printf("Unk Val: %d ", value);
				value = (data[106] | (data[107] << 8));
				printf("Unk Val: %d ", value);
				value = (data[108] | (data[109] << 8));
				printf("Pitch Val: %d ", value);
				value = (data[110] | (data[111] << 8));
				printf("Roll Val: %d ", value);
				value = (data[112] | (data[113] << 8));
				printf("Roll Val: %d ", value);
				value = (data[114] | (data[115] << 8));
				printf("Accel Val: %d ", value);
				value = (data[116] | (data[117] << 8));
				printf("Accell Val: %d ", value);
				value = (data[118] | (data[119] << 8));
				printf("Accel Val:%d ", value);*/
				//Possibly Incrementer
/*				value = (data[120] | (data[121] << 8));
				printf("%d ", value);
				value = (data[122] | (data[123] << 8));
				printf("%d ", value);
				value = (data[124] | (data[125] << 8));
				printf("%d ", value);*/
		if (data[0] == 0 ){
//	        	printf("\nHeadset is Not Drawing! Connect DisplayPort Data!!");
		}
		if (data[1] == 0){
//	        	printf("\nHeadset Has been Removed!!!"); //is headset on head
		}
//	        printf("Button: %02X ", data[2]); //button.
		if (data[2] == 1){
//			printf ("\nToggling\n");
			state = !state;
		}
	        if (state == true) { return true; }
		if (state == false) { return false; }
		printf("\n");
	    }
	return false;
}



