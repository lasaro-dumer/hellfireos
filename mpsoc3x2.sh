#!/bin/bash
cd usr/sim/mpsoc_sim/
make clean
make noc_3x2
cd ../../../platform/noc_3x2/
make clean
make images
cp code*.bin ../../usr/sim/mpsoc_sim/objects/
cd ../../usr/sim/mpsoc_sim
./mpsoc_sim $1 s
