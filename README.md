# ray_tracer

![alt text](https://github.com/jpceia/ray_tracer/blob/master/examples/cube.bmp?raw=true)

Simple c++ raytracer, built from scratch using only C++98 Standard Library.

Takes a config file (.rt) and generates a BMP image.

## Examples

### Cube
(first image)
```
A 0.4 255,255,255
C 0,0,-20 0,-0.05,1 70
sp 0,-2,0 2.5 255,255,120 .2 .2 .5 50 .2 0.1
sp 3,-4,-5 1 25,50,250 0 0 0 1 .5
sp -3,-4,-5 0.5 120,255,220 .7
cy 2,2,-2 0,.1,-1 1 4 10,255,20 1 2
co -3,1.5,-2 0,1,-1 1.5 3 220,160,220 .7 .9 .5 50
tr -4,-5,-8 0,-4.8,-8 -4,-4.8,-1 220,220,20 .3 .3 .5 50 .8
l 4,4,-20 .6 255,255,255
l -4,4,-10 .4 255,255,255
pl 0,0,0 0,0,1 50,50,50 .5
pl 0,5,0 0,1,0 250,50,50 .7
pl 0,-5,0 0,1,0 250,50,50 .7
pl -5,0,0 1,0,0 50,50,250 .9
pl 5,0,0 1,0,0 50,50,250 .9
```

### Columns
![alt text](https://github.com/jpceia/ray_tracer/blob/master/examples/columns.bmp?raw=true)
```
A 0.2   255,255,255
C 0,5,-20  0,0,1  70
l -12,7,-10 0.5   255,255,255
l 12,7,-10 0.5   255,255,255
l 0,7,-10  0.5   255,255,255
sp 0,1,-1  0.6   125,125,25
cy -5,0,-2  0,1,0 1.4 10   140,140,140 1 1 0.9 30
cy -5,0,10  0,1,0 1.4 10   140,140,140 1 1 0.9 30
cy 5,0,-2  0,1,0 1.4  10   140,140,140 1 1 0.9 30
cy 5,0,10  0,1,0 1.4 10   140,140,140  1 1 0.9 30
sp -5,0,10  2.1   140,140,140  1 1 0.9 30
sp 5,0,10  2.1   140,140,140  1 1 0.9 30
sp -5,0,-2  2.1   140,140,140  1 1 0.9 30
sp 5,0,-2  2.1   140,140,140  1 1 0.9 30
sp -5,10,10 2.1   140,140,140  1 1 0.9 30
sp 5,10,10  2.1   140,140,140  1 1 0.9 30
sp -5,10,-2 2.1   140,140,140  1 1 0.9 30
sp 5,10,-2  2.1   140,140,140  1 1 0.9 30
pl 0,0,0  0,1,0  104,104,104 1 0.3 0 1 .1 0
pl 0,0,16  0,0,-1  25,25,178 0 0.1 0 1 .9 0
pl 0,10,0  0,-1,0  128,0,0   1 0.3 0 1 .1 0
```
