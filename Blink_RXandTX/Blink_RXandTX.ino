/*
  Quite an ugly code using the Renesas API to blink
  manually the RX/TX pins on a Arduino UNO R4 Minima.

  This might break things when the official Arduino repository
  will fix the pin assignment.
*/

void setup() {
  R_IOPORT_PinCfg(NULL, TX_LED, IOPORT_CFG_PORT_DIRECTION_OUTPUT);
  R_IOPORT_PinCfg(NULL, BSP_IO_PORT_00_PIN_13, IOPORT_CFG_PORT_DIRECTION_OUTPUT |
                                              (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW);
}

void loop() {
  R_IOPORT_PinWrite(NULL, TX_LED, BSP_IO_LEVEL_HIGH);
  delay(100);
  R_IOPORT_PinWrite(NULL, TX_LED, BSP_IO_LEVEL_LOW);
  delay(100);
  R_IOPORT_PinWrite(NULL, BSP_IO_PORT_00_PIN_13, BSP_IO_LEVEL_HIGH);
  delay(100);
  R_IOPORT_PinWrite(NULL, BSP_IO_PORT_00_PIN_13, BSP_IO_LEVEL_LOW);
  delay(100);
}
