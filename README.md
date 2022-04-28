# Hands On Perception

### Lab : ArUco Markers

&nbsp;
*To generate ArUco Marker and ArUco Board, please execute the follwing commands*

```
./generate_marker 16 25 200 marker.png
```

```
./generate_board 2 4 16 200 80 board.png
```
*For detecting markers*

```
./detect_marker
```

*For calibration*

```
./calibration -w=4 -h=2 -l=0.2, -s=80 -d=16 --dp=detector_params.yml ../../calibration_params.yml
```

*For pose estimation and draw cube*

```
./pose_estimation -l=0.2
```
```
./draw_cube -l=0.2
```
