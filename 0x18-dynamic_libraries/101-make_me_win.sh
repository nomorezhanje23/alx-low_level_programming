#!/bin/bash
wget -P ../ https://github.com/nomorezhanje23/alx-low_level_programming/blob/master/0x18-dynamic_libraries/libtest_hack.so
export LD_PRELOAD=../libtest_hack.so
