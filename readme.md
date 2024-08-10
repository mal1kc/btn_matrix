# btn_matrix code for ardiuno

arduino btn_matrix example

## pinout

| btn_pin | mode | 
| ------------- | -------------- |
| 4 | INPUT_PULLUP |
| 5 | INPUT_PULLUP |
| 7 | OUTPUT |
| 6 | OUTPUT |

  > have 4 buttons
  bt1 bt2 bt3 bt4
  
  > have 4 lines
  line1 line2 line3 line4

  bt1-leg1 connected to bt2-leg1 (line1)

  bt1-leg2 connected to bt4-leg2 (line2)

  bt2-leg2 connected to bt3-leg2 (line3)

  bt3-leg1 connected to bt4-leg1 (line4)

  > line to pin

  line1 -> 4
  line2 -> 6
  line3 -> 5
  line3 -> 7

