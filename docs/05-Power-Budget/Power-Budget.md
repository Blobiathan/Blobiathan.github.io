title: Power Budget
---

## Overview
The power budget was created to ensure that the PCB design has adequate amounts of power. This is done by totalling up each of the components current draw and comparing it to the maximum current output from the voltage regulator. Then the voltage regulator's current draw is compared to the power supply's max current. If the math works out, your power supply should be able to deliver enough current, and the regulator should be able to regulate enough current with an additional margin of 25%

![PowerBudget](LeviPowerBudgetV2.png)

[Link to xlsx](LeviPowerBudgetV2.xlsx)

## Conclusions

From the prepared Power Budget, it was determined that the selected regulator does indeed have enough output to easily power all the components on the PCB. The current required is very low.

## Power budget uses
The power budget was only used for selecting a fuse. Given that my board drew around 700mA (with safety margin), I selected a 1A fuse. The fuse should allow plenty of current without breaking and is still close enough that it will likely be able to break quickly in the result of some error. So far it has worked without issue. The conclusion I've come to about the power budget is that it works for what it was intended to do, it gives a good estimate of a fuse to use, and the fuse works.
