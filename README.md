# Drip Photography

This is a collection of scripts and sketches used for taking photos at [twomushrooms.com](http://twomushrooms.com)

[![the-blurgle-monster](http://twomushrooms.com/media/W1siZmYiLCIuL3RtcC9nYWxsZXJ5L3RoZS1ibHVyZ2xlLW1vbnN0ZXIuanBnIl0sWyJwIiwidGh1bWIiLCIxMjAweDkwMCJdLFsicCIsIndhdGVybWFyayJdXQ/9f5eff9073c34f58/the-blurgle-monster.jpg)](http://twomushrooms.com/the-blurgle-monster)

e.g. [three dimensional splash](http://twomushrooms.com/three-dimensional-splash),
[space worm](http://twomushrooms.com/space-worm) and [a drop of sepia](http://twomushrooms.com/space-worm).

I was asked about the code so here it is. As is.

There are multiple iterations of the project:

## arduino-serial-trigger

The most recent version used.

  - controls valve, camera, and flash
  - set parameters via serial interface
  - trigger shot via serial interface
  - can control delays independently of each other

## lights-out-and-shoot

A ruby script that talks to arduino-serial-trigger and also turns out the
lights in the room automatically when taking shots.

## Archived

Old iterations and experiments.

### drip_and_shoot

Early iteration that triggered camera by programming an IR LED with the same
sequence as a Nikon infrared remote. It was used for taking pictures.

### serial_dripper

Early iteration that had control via serial interface for first time.
It was used for taking pictures.

### johnny-drip

Attempt at using Johnny 5 JS library. It never made it into the wild.
It was at a stage where I was trying to emulate the infrared signal.
The delay was too slow for this.

### raspberry-pi-shoot

Attempt at using Raspberry PI. It never was used because Arduino was more
practical.

### gphoto

Triggering camera with Ruby gphoto gem. This was never used.
The camera had to be turned off and on regularly and the delay was too large.

## License

MIT License

Copyright (c) 2016 Elliott Hilaire

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
