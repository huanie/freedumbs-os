# Configure Toolchain
```sh
xmake f -p cross -a cross --sdk=$CROSS_TOOLCHAIN
# or if the tools are just prefixed
xmake f -p cross -a cross --cross=arm-none-eabi-
```
# Build
```sh
xmake
```
# Run
```sh
qemu-system-arm -nographic -M portux920t -m 64M -kernel build/cross/arm/release/kernel
```
