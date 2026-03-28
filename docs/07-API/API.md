---
title: Module Schematic
---
## Overview
My board will only be acting when it recieves the "Take Photo" message, and "Rolecall" message. All other messages this board recieves will be passed along downstream. Beneath are all posible messages that this board will be able to receive, any other invalid or misformed messages will be discarded.
## Messages
**Take picture:**

||**Byte 1** |**Byte 2**|**Byte 3**|
| :-------: | :-------: | :-------: | :-------: |
| Variable Name | Sender_ID | Reciever_ID | Message_Type |
| Variable Type | char | char | uint8_t |
| Min Value | A | A |4 |
| Max Value | J | J | 4|
| Example | A | F |4 |

**Send speed data in m/s:**

||**Byte 1** |**Byte 2**|**Byte 3**|**Byte 4**|
| :-------: | :-------: | :-------: | :-------: | :-------: |
| Variable Name | Sender_ID | Reciever_ID | Message_Type | Speed |
| Variable Type | char | char | uint8_t | uint8_t |
| Min Value | H | A |5 | 0 |
| Max Value | H | A | 5| 255|
| Example | H | A |5 | 125 | 

**RoleCall**

||**Byte 1** |**Byte 2**|**Byte 3**|
| :-------: | :-------: | :-------: | :-------: |
| Variable Name | Sender_ID | Reciever_ID | Message_Type |
| Variable Type | char | char | uint8_t |
| Min Value | A | X |12 |
| Max Value | J | X | 12|
| Example | A | J |12 |
