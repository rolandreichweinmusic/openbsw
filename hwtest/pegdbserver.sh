#!/bin/bash

set -e

cd /home/ernie/code/openbsw/s32k/plugins/lin

./pegdbserver_console -startserver -device=NXP_S32K1xx_S32K148F2M0M11
