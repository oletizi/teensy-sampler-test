# Teensy Sampler Test
Experiment creating a sampler with teensy. 

Uses platformio to sort out the toolchain.

## Testing

The project is set up to use googletest (b/c that's the only one I could get to work).

The following command will run the tests for the native environment:

`pio test -vvv -e native`