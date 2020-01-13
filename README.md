# xrdb-get
xrdb-get is a utility that allows easy access to values from X Resources (xrdb) from the command line without need for complex command chains with unforeseen bugs.

## Usage
To get a value from X Resources, simply run `xrdb-get <key-name>` (eg. `xrdb-get background`) and the value will be printed to stdout.

## Example

~/.Xresources
```
*.color0 					#2E3440
dmenu.font:	                SFMono:size=12
```


```
$ xrdb-get dmenu.color0
#2E3440
$ xrdb-get termite.color0
#2E3440
$ xrdb-get dmenu.font
SFMono:size=12
$ xrdb-get termite.font # (no value)

$
```

## Installation
### Arch Linux
This repo can be installed with pacman on Arch Linux. Clone this repo, cd into the directory and run `makepkg -si` to build and install a package.

### Other Distributions
On other distros, clone the repo, cd into the directory, run `make` to compile the program followed by `sudo make install` to install it to /usr/local/bin


