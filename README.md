# c_trial


Append `/etc/network/interfaces`:
```
auto can0
    iface can0 inet manual
    pre-up /sbin/ip link set can0 type can bitrate 1000000
    up /sbin/ifconfig can0 up
    down /sbin/ifconfig can0 down

auto can1 
    iface can1 inet manual
    pre-up /sbin/ip link set can1 type can bitrate 1000000
    up /sbin/ifconfig can1 up
    down /sbin/ifconfig can1 down
```


ref:  
[https://www.beyondlogic.org/example-c-socketcan-code/](https://www.beyondlogic.org/example-c-socketcan-code/)  
[https://github.com/craigpeacock/CAN-Examples](https://github.com/craigpeacock/CAN-Examples)
