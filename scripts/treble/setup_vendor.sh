#!/bin/bash

# Setup script for vendor partition

# Create necessary directories
mkdir -p vendor/bin/hw
mkdir -p vendor/lib/hw
mkdir -p vendor/lib64/hw
mkdir -p vendor/etc/vintf
mkdir -p vendor/etc/permissions

# Copy HAL implementations
cp out/target/product/hawaiip/vendor/lib/hw/audio.primary.mt6765.so vendor/lib/hw/
cp out/target/product/hawaiip/vendor/lib/hw/camera.mt6765.so vendor/lib/hw/
cp out/target/product/hawaiip/vendor/lib64/hw/audio.primary.mt6765.so vendor/lib64/hw/
cp out/target/product/hawaiip/vendor/lib64/hw/camera.mt6765.so vendor/lib64/hw/

# Copy VINTF manifest
cp vendor/etc/vintf/manifest.xml vendor/etc/vintf/

# Set permissions
chmod 755 vendor/bin/hw/*
chmod 644 vendor/lib/hw/*
chmod 644 vendor/lib64/hw/*
chmod 644 vendor/etc/vintf/* 