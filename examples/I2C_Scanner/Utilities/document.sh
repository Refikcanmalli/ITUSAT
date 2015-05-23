#!/bin/bash

#
# embedXcode
# ----------------------------------
# Embedded Computing on Xcode
#
# Copyright © Rei VILO, 2010-2015
# http://embedxcode.weebly.com
# All rights reserved
#
#
# Last update: May 06, 2015 release 286

export PATH=$PATH:/Applications/Xcode.app/Contents/Developer/usr/bin
export PATH=$PATH:/usr/local/texlive/2013/bin/x86_64-darwin
export PATH=$PATH:/usr/local/texlive/2012/bin/x86_64-darwin
export PATH=$PATH:/usr/local/texlive/2014/bin/x86_64-darwin
cd Utilities/latex
make
cd ../..
