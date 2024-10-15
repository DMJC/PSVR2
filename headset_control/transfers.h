#include "includes.h"

using namespace std;

int cb_transfer_get_video(libusb_device_handle* &dev_handle, libusb_context* &ctx){
    cout << "\nTransferring data to Headset" << endl;
	int res = 0;
	unsigned char data[1024];
	int actual_length = 0;
    int r = 0;
	    r = libusb_claim_interface(dev_handle, 6);
	    if (r < 0) {
	        fprintf(stderr, "Cannot claim PSVR interface %d\n", 6);
	        libusb_close(dev_handle);
	        libusb_exit(ctx);
	        return -1;
	    }

	    res = libusb_bulk_transfer(dev_handle, 0x87, data, sizeof(data), &actual_length, 1000); // Timeout in milliseconds
	    if (res < 0) {	
	        fprintf(stderr, "Transfer failed to endpoint 7: %s\n", libusb_error_name(res));
	    } else {
//	        printf("From EP 7 RXd %d bytes ", actual_length);
	        for (int i = 0; i < actual_length; i++) {
	            printf("%02X ", data[i]);
	        }
	        printf("\n");
	    }
	return 1;
}

int cb_transfer_ep5(libusb_device_handle* &dev_handle, libusb_context* &ctx){
    cout << "\nTransferring data to Headset" << endl;
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

	    res = libusb_bulk_transfer(dev_handle, 0x85, data, sizeof(data), &actual_length, 5000); // Timeout in milliseconds
	    if (res < 0) {	
	        fprintf(stderr, "Transfer failed to endpoint 5: %s\n", libusb_error_name(res));
	    } else {
	        printf("From EP5 RX: %d bytes\n", actual_length);
	        for (int i = 0; i < actual_length; i++) {
	            printf("%02X ", data[i]);
	        }
	        printf("\n");
	    }
	return 1;
}

int cb_transfer_ep9(libusb_device_handle* &dev_handle, libusb_context* &ctx){
    cout << "\nTransferring data to Headset" << endl;
	int res = 0;
	unsigned char data[1024];
	int actual_length = 0;
    int r = 0;
	    r = libusb_claim_interface(dev_handle, 9);
	    if (r < 0) {
	        fprintf(stderr, "Cannot claim PSVR interface %d\n", 9);
	        libusb_close(dev_handle);
	        libusb_exit(ctx);
	        return -1;
	    }

	    res = libusb_bulk_transfer(dev_handle, 0x89, data, sizeof(data), &actual_length, 1000); // Timeout in milliseconds
	    if (res < 0) {	
	        fprintf(stderr, "Transfer failed to endpoint 9: %s\n", libusb_error_name(res));
	    } else {
	        printf("From EP9 RX: %d bytes\n", actual_length);
	        for (int i = 0; i < actual_length; i++) {
	            printf("%02X ", data[i]);
	        }
	        printf("\n");
	    }
	return 1;
}
int cb_transfer_ep10(libusb_device_handle* &dev_handle, libusb_context* &ctx){
//    cout << "\nTransferring data to Headset" << endl;
	int res = 0;
	unsigned char data[820224];
	int actual_length = 0;
    int r = 0;
	    r = libusb_claim_interface(dev_handle, 10);
	    if (r < 0) {
	        fprintf(stderr, "Cannot claim PSVR interface %d\n", 10);
	        libusb_close(dev_handle);
	        libusb_exit(ctx);
	        return -1;
	    }

	    res = libusb_bulk_transfer(dev_handle, 0x8a, data, sizeof(data), &actual_length, 1000); // Timeout in milliseconds
	    if (res < 0) {	
	        fprintf(stderr, "Transfer failed to endpoint 10: %s\n", libusb_error_name(res));
	    } else {
	        printf("From EP10 RX: %d bytes", actual_length);
	        for (int i = 0; i < actual_length; i++) {
	            printf("%02X ", data[i]);
	        }
	        printf("\n");
	    }
	return 1;
}
int cb_transfer_ep11(libusb_device_handle* &dev_handle, libusb_context* &ctx){
	int res = 0;
	unsigned char data[1024];
	int actual_length = 0;
    int r = 0;
	    r = libusb_claim_interface(dev_handle, 11);
	    if (r < 0) {
	        fprintf(stderr, "Cannot claim PSVR interface %d\n", 11);
	        libusb_close(dev_handle);
	        libusb_exit(ctx);
	        return -1;
	    }

	    res = libusb_bulk_transfer(dev_handle, 0x8b, data, sizeof(data), &actual_length, 1000); // Timeout in milliseconds
	    if (res < 0) {	
	        fprintf(stderr, "Transfer failed to endpoint 11: %s\n", libusb_error_name(res));
	    } else {
	        printf("From EP11 RX: %d bytes", actual_length);
	        for (int i = 0; i < actual_length; i++) {
	            printf("%02X ", data[i]);
	        }
	        printf("\n");
	    }
	return 1;
}

int cb_transfer_ep13(libusb_device_handle* &dev_handle, libusb_context* &ctx){
    cout << "\nTransferring data to Headset" << endl;
	int res = 0;
	unsigned char data[1024];
	int actual_length = 0;
    int r = 0;
	    r = libusb_claim_interface(dev_handle, 13);
	    if (r < 0) {
	        fprintf(stderr, "Cannot claim interface %d\n", 13);
	        libusb_close(dev_handle);
	        libusb_exit(ctx);
	        return -1;
	    }

	    res = libusb_bulk_transfer(dev_handle, 0x8d, data, sizeof(data), &actual_length, 1000); // Timeout in milliseconds
	    if (res < 0) {	
	        fprintf(stderr, "Transfer failed to endpoint 13: %s\n", libusb_error_name(res));
	    } else {
	        printf("From EP13 RX: %d bytes", actual_length);
	        for (int i = 0; i < actual_length; i++) {
	            printf("%02X ", data[i]);
	        }
	        printf("\n");
	    }
	return 1;
}

