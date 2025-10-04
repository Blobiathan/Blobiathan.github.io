---
title: Individal Block Diagram
tags:
- tag1
- tag2
---

## Overview
The purpose of this block diagram is to highlight the components in my specific portion of the project. Given that our team selected the Hub and Spoke setup, this device will function more as a subsystem. Using a thermalresistor to measure water temperature, and a IR sensor to detect user movement, my Curiosity Nano will read this information, and then send it to the Hub board via the 8 pin connector.
Each of our boards have the first pin on the connected setup as an input, to recive measurement requests from the Hub board, and my system also outputs a digital and analog signal. The digital signal is detemined by whether or not there was significant movemnet, and the analog signal sends temperature data back to the Hub board.
This board will also have two LED lights, a green light to indicate that it is functioning properly, and a blue light to indicate measurements being sent back to the Hub board.
Since there are no actuators or higher voltage components connected to this board, it can run entirely off of the 5V 1.5A regulated power supply.

## Block Diagram
![IndividualBlock](https://github.com/user-attachments/assets/c793b9ce-ea25-423a-843f-8d73f633c1c2)
