title: Hardware V2
---

## Hardware design V2
My hardware worked properly first try and there were no errors. Because of this the only real changes I would make to the board are relativly minor changes that could improve the board. The following are a few of these possible improvements.

- Flipping the pic 180 degrees:
By mistake the pic was oriented in a way that prevented it's cable from being plugged in while the ribbon cable was connected. This means that you could not uploaded new code to the board while the ribbon cable was plugged in, without removing the pic. This was a bit inconveneint, and flipping the board around and rerouting all the traces could solve this problem. The ribbon cables position could also be moved, but it would likely be better to just flip the pic.

- Changing the test points for the sensors:
The test points used on the board were both a single female connector. Unfortunatly these were not very durable and the plastic casing came off both of them, so replacing them with a better type of test point would help to improve the board.

- Moving the jumper near the ribbon cable connector:
There is a jumper near where the ribbon cable connects, it doesn't block the ribbon cable, but it rubs up against it and make the cable more difficult to connect, moving it a few milimeters further away would be an easy fix.

- Drill size changes:
Some of the drill holes were slightly larger than they should have been, specifically the fuse holder and extra jumpers. Making these drill holes slightly smaller would make it easier to solder the components to the board and help them stay connected.

- Photoresitor connector:
To connect the photoresistor two female connectors were used. If these were replaced with two screw terminals it would be able to hold the photoresistor more securly and avoid it slipping out, which it did a few times during testing.

- Moving the jumpers near the pic:
There are several jumpers next to the pic for debugging purposes, they are close enough to the pic that it makes it difficult to attach and detach them. Moving these jumpers a few more milimeters away from the pic would make it easier.

- Resistor for green LED:
The green LED on the board was dim compared to the other two LEDs, a different resistor value could have helped with this.

- Adding a silkscreen:
The silkscreen was not used during manufacturing because our team was worried about time constraints and there were a few errors on most of our silkscreens. Adding the silkscreen would help identify parts on the board, and would have made solding on the components much more straightforward.
---
These are all the possible hardware improvements that could be identified for my board. With these improvements the board would be easier to use and manufacture.
