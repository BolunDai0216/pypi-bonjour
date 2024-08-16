#!/bin/bash

set -e

# install Eigen (see https://stackoverflow.com/questions/74345206/centos-7-docker-yum-installation-gets-stuck)
ulimit -n 1024 && yum -q update -y && yum -q install -y epel-release
ulimit -n 1024 && yum -q install -y eigen3-devel