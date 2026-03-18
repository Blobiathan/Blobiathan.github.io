---
title: Module Schematic
---
## Overview
My board will only be acting when it recieves the "Take Photo" message, all other messages this board recieves will be passed along downstream. Beneath are all posible messages that this board will be able to receive, any other invalid or misformed messages will be discarded.
## Messages
**Take Photo:**

||**Byte 1-2**|
| :-------: | :-------: |
| Variable Name | message_type |
| Variable Type | uint8_t |
| Min Value | 4 |
| Max Value | 4 |
| Example | 4 |

**Display Speed Data:**

||**Byte 1-2**|**Byte 3**|
| :-------: | :-------: |:-------: |
| Variable Name | message_type | value |
| Variable Type | uint8_t | uint8_t |
| Min Value | 8 | 0 |
| Max Value | 8 | 255 |
| Example | 8 | 140 |

**Get Distance:**

||**Byte 1-2**|
| :-------: | :-------: |
| Variable Name | message_type |
| Variable Type | uint8_t |
| Min Value | 6 |
| Max Value | 6 |
| Example | 6 |

**Get Temperature:**

||**Byte 1-2**|
| :-------: | :-------: |
| Variable Name | message_type |
| Variable Type | uint8_t |
| Min Value | 7 |
| Max Value | 7 |
| Example | 7 |
