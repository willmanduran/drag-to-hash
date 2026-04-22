# Drag-to-Hash — Willman’s Toolbox

## What it is

Drag-to-Hash is a small desktop utility that computes SHA-256 hashes for one or more files and writes the results to a text file.  
You can drag files into the window or browse for them, set an output path, and choose whether to include filenames alongside the hashes.

## Build from source

### Linux / macOS

Requires **Qt 6 (Widgets)** and **CMake ≥ 3.16**.

```bash
# Clone
git clone https://github.com/willmanstoolbox/hashdrop
cd hashdrop

# Configure + build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j

# Run
./build/dragtohash
```


## Support & Contact
If you find any bugs, have any ideas to improve this or just want to chat about C in general feel free to email me.

**Email:** ticuette@gmail.com

**More Tools:** You can support my work or check out other tools at [willmanstoolbox.com](https://willmanstoolbox.com)
