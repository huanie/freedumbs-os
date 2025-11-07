# Build
```sh
# configure the toolchain
xmake f -p cross -a cross --sdk=$CROSS_TOOLCHAIN
xmake
```
# Run
```sh
qemu-system-arm -nographic -M portux920t -m 64M -kernel build/cross/arm/release/kernel
```
