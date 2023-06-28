#!/bin/sh
norminette src | grep -v 'OK!' > norm_output
