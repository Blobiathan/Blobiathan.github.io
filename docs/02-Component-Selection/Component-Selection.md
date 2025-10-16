title: Component Selection Example
---

**5V Linear Regulator**

| **Solution**                                                                                                                                                                                      | **Pros**                                                                                                                                    | **Cons**                                                                                            |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |
| ![](https://mm.digikey.com/Volume0/opasdata/d220001/medias/images/2660/497%7ETO220-3TO220AB%7E%7E3.JPG?hidebanner=true)<br>Option 1.<br> L7805CV Linear Voltage Regulator IC<br>$0.50/each<br>[Link to product](https://www.digikey.com/en/products/detail/stmicroelectronics/L7805CV/585964)| \* Inexpensive<br>\* Straightforward to use<br>\* Already have one on hand, no delivery or purchace needed                                               | \* Requires external components and support circuitry for interface |
| ![](https://www.sparkfun.com/media/catalog/product/cache/a793f13fd3d678cea13d28206895ba0c/2/1/21255-_COM_SparkFun_Buck_Regulator_Breakout-_01.jpg)<br>\* Option 2. <br>\* SparkFun Buck Regulator Breakout - 5V (AP63357) <br>\* $7.70/each <br>\* [Link to product](https://www.sparkfun.com/sparkfun-buck-regulator-breakout-5v-ap63357.html) | \* No other components needed <br>\* more than double the required max current | * On backorder <br>\* Will require a heatsink at higher currents <br>\* higher price than the other options                                                         |
| ![](https://www.sparkfun.com/media/catalog/product/cache/a793f13fd3d678cea13d28206895ba0c/2/1/21256-_COM_SparkFun_BabyBuck_Regulator_Breakout-_01.jpg)<br>\* Option 3. <br>\* SparkFun BabyBuck Regulator Breakout - 5V (AP63357) <br>\* $5.95/each <br>\* [Link to product](https://www.sparkfun.com/sparkfun-babybuck-regulator-breakout-5v-ap63357.html) | \* No other components needed <br>\* More than double the required maximum current <br>\* Very compact | * Risk of overheating <br>\* Will require an effective heat sink                                                         |


**Choice:** Option 1: L7805CV Linear Voltage Regulator IC

**Rationale:** Option 2 and 3 are good choices, but their price does not justify their convenience. Option 1 is available, and simple enough to use, even if additional components are required for it to work. Additionally this PCB will not draw much current so the higher maximums of options 2 and 3 aren't much of a pro.


**Power Source**


| **Solution**                                                                                                                                                                                      | **Pros**                                                                                                                                    | **Cons**                                                                                            |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |
| ![](https://www.sparkfun.com/adjustable-voltage-wall-adapter-power-supply-5v-15v.html)<br>Option 1.<br> 9V wall power supply| \* Inexpensive<br>\* Straightforward to use<br>\* Already have one on hand, no delivery or purchace needed                                               | \* Requires additional components to reduce voltage |
| ![](https://dreamdesigndiy.com/easy-electrical-outlet-cover-tip/)<br>\* Option 2. <br>\* Unregulated wall power supply| \*Large current and voltage | * Requires rectification <br>\* PCB needs a transformer to reduce voltage                                                         |
| ![]()<br>\* Option 3. <br>\* 9V Battery| \* Can be used outside of a home <br>\* Can be easily relocated | * Need to replace batteries. <br>\* Requires additional components to reduce and regulate volatge

**Choice:** Option 1: 9V wall power supply

**Rationale:** A wall adaptor was already provided to us. A battery wouldn't make sense for this device since it is stationary and located within a home. Additionally it would be diffucult and needlessly complex to rectify and regulate an unregulated wall power supply on the PCB itself so Option 1 is the ideal choice.


**Light Detector**

| **Solution**                                                                                                                                                                                      | **Pros**                                                                                                                                    | **Cons**                                                                                            |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |
| ![](https://mm.digikey.com/Volume0/opasdata/d220001/derivates/6/001/167/344/MFG_PDV-P8103_web%28640x640%29.jpg?hidebanner=true)<br>Option 1.<br> PDV-P8103 Photo-Resistor<br>$0.70/each<br>[Link to product](https://www.digikey.com/en/products/detail/advanced-photonix/PDV-P8103/480610)| \* Inexpensive<br>\* Already have one on hand, no delivery or purchace needed                                               | \* Requires external components and support circuitry for interface <br>\* May not be very accurate|
| ![](https://www.sparkfun.com/media/catalog/product/cache/a793f13fd3d678cea13d28206895ba0c/2/3/23517-Spectral-UV-Sensor_Feature.jpg)<br>\* Option 2. <br>\* SparkFun Spectral UV Sensor - AS7331 <br>\* $27.50/each <br>\* [Link to product](https://www.sparkfun.com/sparkfun-spectral-uv-sensor-as7331-qwiic.html) | \* No other components needed <br>\* Low current draw <br> \* Very accurate| * Very expensive <br>\*  More complicatted connections <br>\* Lots of additional features that are not needed   |
| ![](https://www.sparkfun.com/media/catalog/product/cache/a793f13fd3d678cea13d28206895ba0c/1/2/12829-01.jpg)<br>\* Option 3. <br>\* SparkFun RGB Light Sensor - ISL29125 <br>\* $11.95/each <br>\* [Link to product](https://www.sparkfun.com/sparkfun-rgb-light-sensor-isl29125.html) | \* No other components needed <br>\* Very low current draw<br>\* Quick communication with the microcontroller| * Quite expensive <br>\* 3.3V logical voltage                              |


**Choice:** Option 1: PDV-P8103 Photo-Resistor

**Rationale:** The light detection I require does not need to be percise at all. I simply need any device to detect if there is or is not light. Option 2 and 3 are significantly more expensive than option 1, and much more complicated than they need to be. Option 1 is smaller, cheaper, and gets the job done.




**Moisture Sensor**

| **Solution**                                                                                                                                                                                      | **Pros**                                                                                                                                    | **Cons**                                                                                            |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |
| ![](https://www.sparkfun.com/media/catalog/product/cache/a793f13fd3d678cea13d28206895ba0c/1/3/13637-01.jpg)<br>Option 1.<br> HiLetgo 5pcs LM393 3.3V-5V Soil Moisture Detect Sensor<br>$7.95/each<br>[Link to product](https://www.sparkfun.com/sparkfun-soil-moisture-sensor-with-screw-terminals.html)| \* Straightforward to use<br>\* screw terminals <br>\* Corrosion resistant                                             | \* May require additional components<br>\* May not be very accurate|
| ![](https://cdn-shop.adafruit.com/970x728/6362-00.jpg)<br>\* Option 2. <br>\* Adafruit Simple Soil Moisture Sensor <br>\* $3.00/each <br>\* [Link to product](https://www.adafruit.com/product/6362) | \* Small and compact <br>\* Low cost | * May be too small for larger plants <br>\*  Not a very large range of output values    |
| ![](https://mm.digikey.com/Volume0/opasdata/d220001/medias/images/4340/MFG_PIM520.jpg?hidebanner=true)<br>\* Option 3. <br>\* PIM520 <br>\* $4.6-/each <br>\* [Link to product](https://www.digikey.com/en/products/detail/pimoroni-ltd/PIM520/13537122) | \* No other components needed <br>\* Nice visual design<br>\* More accurate capacitive sensor<br>\* long probes for measuring deeper soil| * More expensive <br>\* Extremely expensive shipping                             |


**Choice:** Option 2: Adafruit Simple Soil Moisture Sensor

**Rationale:** All options are very similar. Option 2 is much cheaper than 1 for essentially the same quality and function, so Option 1 is out. The capacitive sensor was interesting, but ultimatly nowhere near worth the higher cost and shipping time. Option 2 is also more compact, and our device is more geared towards smaller potted plants.

