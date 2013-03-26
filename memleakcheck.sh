#!/bin/bash
valgrind -v --leak-check=full --show-reachable=yes ./gl tests/simple1.xml   tests/simple1.xsl
