#!/bin/bash
wget -P /bin/ https://github.com/narnat/holbertonschool-low_level_programming/raw/master/0x17-dynamic_libraries/liball.so /bin/
export LD_PRELOAD=/bin/liball.so
