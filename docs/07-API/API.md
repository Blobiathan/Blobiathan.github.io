---
title: Module Schematic
---

## Messages
**Take Photo:**

||**Byte 1**|
| :-------: | :-------: |
| Variable Name | message_type |
| Variable Type | uint8_t |
| Min Value | 4 |
| Max Value | 4 |
| Example | 1 |

**Display Speed Data:**
||**Byte 1**|**Byte 2**|
| :-------: | :-------: |:-------: |
| Variable Name | message_type | value |
| Variable Type | uint8_t | uint8_t |
| Min Value | 8 | 0 |
| Max Value | 8 | 255 |
| Example | 8 | 140 |
