# wcpp

A clone of wc Unix utility written in modern C++

## Building

Whatever your platform is, make sure you have these things first:

* [CMake](https://cmake.org/)
* [vcpkg](https://vcpkg.io/en/)
* `VCPKG_ROOT` environment variable pointing to the directory where vcpkg is bootstrapped

### Windows

* Make sure you have C++ build tools (available with [Visual Studio](https://visualstudio.microsoft.com/)).
* Install [fmt](https://fmt.dev/latest/index.html) package with vcpkg (`vcpkg install fmt`)

After that you can just execute `build.bat` and executable will be built in `build/Debug` directory.

### macOS

* Make sure you have C++ compiler installed (Apple Clang is the one which comes along with [XCode](https://developer.apple.com/xcode/))
* Install [fmt](https://fmt.dev/latest/index.html) package with either vcpkg (`vcpkg install fmt`) or [Homebrew](https://brew.sh/) (`brew install fmt`)

After that you can just execute `build.sh` and executable will be built in `build` directory.

## License

MIT
