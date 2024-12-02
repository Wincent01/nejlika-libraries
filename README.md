# Nejlika Libraries
Nejlika is a general purpose modding solution for the game LEGO® Universe. This repostory contains libraries for working with a veriaty of different game files.

## This repostory
These libraries are part of a bigger effort to make modding LEGO® Universe easier. Documentation exists for individual classes but the big picture is missing. The hope is to extend this repostory to include more thorough documentation in the future.

Most of these libraries can be used in full or in part without nejlika modding being involved.

## What's here

### [core](core) — Modding solution
Contains the basis for the nejlika modding solution. Allows for the use of user defined structures to be interpreted and applied as deltas to the game.

### [templates](templates) — Predefined mod type templates
A collection of type templates for nejlika mods.

### [geometry](geometry) — Model and animations
Contains the file structure for nif, kfm and kf files. Only tested for LEGO® Universe files, but should work for other game built for Gamebyro.

### [gltf](gltf) — Converting model and animations
A small library for converting nif, kfm and kf files into glTF files.

### [world](world) — Zone, levels and terrain
Contains the file structure for working with luz, lvl and raw files. Also contains an extension that allows for editing of worlds with nejlika mods.

### [cli](cli) — Command line interface for modding
A work in progress tool for modding with nejlika from the command line.

### [common](common) — Shared utilities
Contains a binary reader and writer, shared by multiple other libraries.

### Third party libraries
This repostory makes use of the following third party libraries:
* tinyxml2
* sqlite3
* libbcrypt
* tiny_gltf with dependencies
* boost