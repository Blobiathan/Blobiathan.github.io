---
title: Module Schematic
---
## Overview
My board will only be acting when it recieves the "Take Photo" message, and "Rolecall" message. All other messages this board recieves will be passed along downstream. Beneath are all posible messages that this board will be able to receive, any other invalid or misformed messages will be discarded.
## Messages
**Take picture:**

||**Byte 1-2**|
| :-------: | :-------: |
| Variable Name | message_type |
| Variable Type | uint16_t |
| Min Value | 4 |
| Max Value | 4 |
| Example | 4 |

**Send speed data in m/s:**

||**Byte 1-2**|**Byte 3**|
| :-------: | :-------: |:-------: |
| Variable Name | message_type | value |
| Variable Type | uint16_t | uint8_t |
| Min Value | 5 | 0 |
| Max Value | 5 | 255 |
| Example | 5 | 140 |

**RoleCall**

||**Byte 1-2**|
| :-------: | :-------: |
| Variable Name | message_type |
| Variable Type | uint16_t |
| Min Value | 11 |
| Max Value | 11 |
| Example | 11 |
