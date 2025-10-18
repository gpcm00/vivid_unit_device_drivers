# About
Device Drivers for the [Vivid Unit SBC](https://www.vividunit.com/Main_Page)

# Dependecies

    sudo apt install gcc-aarch64-linux-gnu

    # if you are using python3
    sudo apt install python3-is-python 

# Install

    git clone https://github.com/gpcm00/vivid_unit_device_drivers.git

    cd vivid_unit_device_drivers

    git submodule update --init --recursive

## Prepare the kernel

    export CROSS_COMPILE=aarch64-linux-gnu-

    export ARCH=arm64

    cd external/kernel

    cp arch/arm64/configs/vivid_unit_defconfig .config

    make olddefconfig

    make modules_prepare

    make modules -j$(nproc)

Now you are ready to compile kernel code for the vivid unit.
Check hello_module for a minimalistic setup.