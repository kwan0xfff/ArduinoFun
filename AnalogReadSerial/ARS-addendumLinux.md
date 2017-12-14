# Addendum to AnalogReadSerial

This code is based on the Arduino bundled example
01.Basics/AnalogReadSerial".

These notes are written for use with recent Linux distributions.  In this
case, it is Ubuntu 16.04.  The kernel is based on Linux kernel v4.4.0.

## General Modifications

The original program specified a delay of 1 millisecond.  This does not
mean the potentiometer was read 1000 times/second.  The serial console
rate of 9600 bits/sec adds roughly 3 to 5 milliseconds to the delay.
(Each character consists of a start bit + 7 or 8 data bits + a stop bit,
and possibly more. There are 3 or 4 characters plus newline or linefeed
(or both) per read.)

The delay time and port speed can be adjusted to one's taste.
Taste includes: What does the system need? What can the user read?

The original program used a delay of 1 millisecond between reads "for
stability"; it has been modified to 10 ms (i.e., 1/100th second delay)
for more stability and perhaps a little less power consumption. (This
may be used up in the faster read.)

The serial port has been sped up from 9600 to 57600 bits/sec, a factor
of 6x.  This reduces the amount of time that the device is blocked
on read.  At 57,600 bits/sec, this is roughly 0.5 to 0.8 milliseconds.

## Permissions

When the Arduino is plugged into USB and powered up, the device shows as
"/dev/ttyACM0"; on some systems this may be "/dev/ttyUSB0".  When looking
at permissions on the device, they look something like:

    $ ls -l /dev/ttyUSB0
    crw-rw---- 1 root dialout 166, 0 Sep 25 21:00 /dev/ttyUSB0

The loading phase will fail with messages like:

    avrdude: ser_open(): can't open device "/dev/ttyUSB0": Device or resource busy
    An error occurred while uploading the sketchAttempt

This is because the user does not have permission to access or write
the device.

While the user could become "root" (the superuser), this is the wrong
approach and *strongly* discouraged.  (Running as "root" increases the
likelihood of the user doing accidental damage to the system.)

The right approach is to set the device to accept members of group
"dialout", and add the user to the group.

### Set device group permissions

    $ sudo chmod g+s /dev/ttyUSB0
    $ ls -l /dev/ttyUSB0
    crw-rwS--- 1 root dialout 166, 0 Sep 25 21:42 /dev/ttyUSB0

Note the "S" after "rw" for the group.  The "sgid" (set-groupID) bit has
been set for the device.

### Add user to "dialout" group

Check to see if who is already in the group.

    $ grep dialout /etc/group
    dialout:x:20:someuserID

The only user in the group is "someuserID"; that user should be able to
successfully upload the compiled Arduino code and execute it.

Otherwise use a tool such as "addgroup" to add the user to the group.

### Serial console program

[MORE TO WRITE BELOW]

stty 9600 or stty 57600
stty -a

minicom, picocom, screen
First find out how to exit.

possibly 'cat'.

[MORE TO WRITE ABOVE]

Now Play
========

[MORE TO WRITE BELOW]

:-)
Turn the pot.

[MORE TO WRITE ABOVE]
