sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0
sudo ip link add dev vcan1 type vcan
sudo ip link set up vcan1

sudo modprobe can-gw
sudo cangw -A -s vcan0 -d vcan1 -e
sudo cangw -A -s vcan1 -d vcan0 -e