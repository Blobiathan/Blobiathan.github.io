---
title: Module's Requirements
---

## Module Requirements
The following table shows the requirements for this module. For the project I have been tasked with creating a visual inspection module for the device. It should be able to record visual data, and either save or send it to the controller. Ideally this sensor will be a camera, but if that turns out not to be viable, a basic color sensor or lidar will have to suffice. This table also contains the basic requirements, such as power, the use of a microcontroller, and connectors to send data between boards.

| **Requirement Description** | **Measure of<br> Threshold** | **Target<br>Measure** |**Stretch<br>Requirement<br>(Y-N)**|
|-----------------------------| ----------------- | ----------------- | :-----: |
| Surface mounted, 3.3V switching power regulator | 3.2 Volts | 3.3 Volts | No |
| Surface mounted microcontroller | 1 PIC or ESP | ESP | No |
| Connector to receive power | Barrel jack connector | Connection to other teammember's boards for power | NO |
| Optical sensor | Basic color or lidar sensor | Camera | No |
| Connection to other boards to send camera data | Send image data | Send video data | Yes |
| SD card slot to save images to | Save image data | Save image and video data | Yes |
