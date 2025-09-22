# Drag-to-Hash — Willman’s Toolbox

> Drop files to compute SHA-256 hashes. Free and open.

- **Website:** https://www.willmanstoolbox.com  
- **Downloads page:** https://www.willmanstoolbox.com/dragtohash/  
- **Repo:** https://github.com/willmanstoolbox/hashdrop  
- **Donate:** https://www.willmanstoolbox.com/donate  

---

## What it is

Drag-to-Hash is a small desktop utility that computes SHA-256 hashes for one or more files and writes the results to a text file.  
You can drag files into the window or browse for them, set an output path, and choose whether to include filenames alongside the hashes.

---

## Key features

- Drag-and-drop files or use the file picker.  
- Configurable output path (defaults to `~/Documents/output-hash.txt`).  
- Optionally include the original file name in each line.  
- Efficient hashing with 1 MB chunks.  
- Cross-platform builds for Windows and Linux.  
- Simple, minimal Qt6-based UI.  

---

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
