---
title: Individal Block Diagram
tags:
- tag1
- tag2
---

## Overview
The purpose of this block diagram is to highlight the components in my specific portion of the project. Given that our team selected the Hub and Spoke setup, this device will function more as a subsystem. Using a photoresistor to measure sunlight, and a moisture sensor to measure moisture levels, my Curiosity Nano will read this information, and then send it to the Hub board via the 8 pin connector.

Each of our boards have the first pin on the connected setup as an input, to recive measurement requests from the Hub board, and my system also outputs two analog signals, one for sunlight levels as a percentage and one for moisture levels as a percentage.
This board will also have three LED lights, a green light to indicate that it is functioning properly, and a blue light to indicate measurements being sent back to the Hub board, and a yellow light for debuging.

Since there are no actuators or higher voltage components connected to this board, it can run entirely off of the 5V 1.5A regulated power supply.

## Block Diagram
<img width="701" height="651" alt="IndividualBlock drawio" src="https://github.com/user-attachments/assets/07fb3371-7b62-4cf8-9394-3b5502d91758" />
