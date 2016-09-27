#!/bin/bash
cd platform/single_core/
make clean
make image
cd ../../
./usr/sim/hf_risc_sim/hf_risc_sim platform/single_core/image.bin $1
