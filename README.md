# Chiplet Network Sim

Chiplet Network Simulator (CNSim) is a cycle-accurate packet-parallel simulator supporting efficient simulation for large-scale chiplet-based networks.

If you use CNSim in your research, we would appreciate the following citation in any publications to which it has contributed:

Yinxiao Feng, Yuchen Wei, Dong Xiang and Kaisheng Ma. Evaluating Chiplet-based Large-Scale Interconnection Networks via Cycle-Accurate Packet-Parallel Simulation. In 2024 USENIX Annual Technical Conference (ATC), 2024.

### Features
- Hyper-threading
- Cycle-accurate
- Highly configurable and customizable in terms of topology, routing algorithms, and microarchitecture.

### Dependencies
- boost library
- netrace (optional, modified from https://github.com/booksim/netrace)
	- bzip2

### Ubuntu 22.04
```
sudo add-apt-repository ppa:xmake-io/xmake
sudo apt update
sudo apt install cmake ninja-build build-essential libboost-all-dev libbz2-dev git clang
sudo apt install xmake
cd chiplet-network-sim
xmake
xmake run -w `pwd` cnsim input/multiple_chip_mesh_4x4.ini
```

### Acknowledgement
 - Yuchen Wei, Tsinghua University
 - Dong Xiang and Kaisheng Ma, Tsinghua University
 - BookSim and Netrace (https://github.com/booksim)