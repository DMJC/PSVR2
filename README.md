# PSVR2
Attempt at making the PSVR2 work under Linux

I was able to activate the headset with X11, I haven't been able to activate it using Wayland. The headset already detects as a DRM lease device under Linux (a special X11/Wayland mode for rendering to VR headsets). By bringing up the headset in X11 you can reconfigure it to be another monitor. This is a lot easier to test with.

I've got an AMD 5700XT GPU (which I haven't had work on Linux with the PSVR2.) I have got an Intel Alder Lake-UP3 GT2 GPU which can bring up the headset with a USB-C -> DP adapter (Astrotek USB-C to DisplayPort DP Male to Male Cable). The headset comes up automatically in VR mode with the two views overlapping. You can open Youtube 3D movies on the headset and watch in full 3D without doing anything extra.

## Reverse Engineering ##
For Reverse Engineering I'm using Wireshark to sniff the USB traffic under windows. This got me the activation code for the External pass-through cameras. I'm now trying to decode the headset tracking data. On this I'm stuck. I've thrown Ghidra at the PSVR2 windows driver to see if I can find how the USB traffic is formed. The headset gets interrupts on interface 8 and returns 131,155,179,203 byte data streams, mostly 155 byte. I assume this is the headset tracking data.

## Activation Instructions: ##
To activate the headset under Linux/X11 I turn it on so the headset light goes white.

xrandr shows:
DP-1 disconnected (normal left inverted right x axis y axis)
4000x2040 119.88 + 89.91
1920x1080 60.00 + 120.00 119.88 50.00 59.94 24.00 23.98

Run: xrandr --output DP-1 --set non-desktop 0;

xrandr then shows:
DP-1 connected (normal left inverted right x axis y axis)
4000x2040 119.88 + 89.91
1920x1080 60.00 + 120.00 119.88 50.00 59.94 24.00 23.98

Run: xrandr --output DP-1 --auto;
This sets the headset into 4K output mode.

xrandr then shows:
DP-1 connected 4000x2040+0+0 (normal left inverted right x axis y axis) 800mm x 450mm
4000x2040 119.88*+ 89.91
1920x1080 60.00 + 120.00 119.88 50.00 59.94 24.00 23.98

The headset will be displaying a picture at this point and you can drag/drop windows onto it.
On AMD I've had the headset detect as a 2560xsomething device which is wrong. I think it's an EDID error on the AMD drivers but I haven't confirmed it. Under wayland xrandr was showing a dp-lease device biut I couldn't activate it. Wayland didn't list a device at all under wdisplays or wayfire config manager.

Intention:
I love space flight/combat games, think Wing Commander and Freespace 2, would like to use a PSVR2 as a cheap VR headset of decent visual quality under Linux.

## Hardware I'm using for this: ##
- AMD 5700XT
- NVIDIA T550U
- Intel Alder Lake-UP3 GT2
- Intel 12th Gen i7-1265U
- Astrotek USB-C to DisplayPort DP Male to Male Cable
- PSVR2 updated to latest firmware on PS5
- PSVR to PC Adapter

## Objectives and priority: ##
- Find howto switch PSVR2 into VR Mode - Done Headset automatically starts in VR mode once a picture is going to it.
- Find howto engage inside out tracking - High
- Read Gyroscopic Data - High
- Find howto switch PSVR2 between VR and Real World Mode - Done
- Bluetooth controllers/controller tracking - Low

Controllers for the PSVR2 auto-create on Linux as /dev/input/js devices. No further configuration is necessary.
HP Z-Book built in Intel Bluetooth works really well.

## Bluetooth Controllers Tested: ##
- 8087:0033 Intel Corp. AX211 Bluetooth - Working
