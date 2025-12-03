---
title: Individal Block Diagram
tags:
- tag1
- tag2
---

## Overview
The purpose of this block diagram is to highlight the components in my specific portion of the project. Given that our team selected the Hub and Spoke setup, this device will function more as a subsystem. Using a photoresistor to measure sunlight, and a moisture sensor to measure moisture levels, my Curiosity Nano will read this information, and then send it to the Hub board via the 8 pin connector.

This board will also have three LED lights, a green light to indicate that it is functioning properly, and a blue light to indicate measurements being sent back to the Hub board, and a yellow light for debuging.

Since there are no actuators or higher voltage components connected to this board, it can run entirely off of the 5V 1.5A regulated power supply.

## Block Diagram
![BlockDiagram](IndividualBlock.drawio(3).png)

## Meeting project requirements
The LED and button are required components for this project, so they had to be included. I decided to add 2 more additional LED's for debugging and astetic purposes, whihc did not contribute to meeting the project requirements. The project also required that each board had a analog sensor of some type, which is then altered in some way by an op-amp. In my block diagram the photoresistor and op-amp meet these requirements, by creating an analog signal with the photoresistor and then amplifying it with the op-amp to a 0-5V range. Additionally one of the project requirements is to sucessfully regulate a higher input voltage down to 5V to supply power to the board, this is accomplished by the L7805CV voltage regulator. The moisture sensor is not in any way required for the project, and was added simply as an additional goal to meet if there was enough time.
