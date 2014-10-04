#!/bin/bash

autoreconf
./configure --enable-sanitize --disable-lto --enable-packetver=20150000
#./configure --enable-static --disable-lto --enable-packetver=20150000
make
