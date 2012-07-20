GIMP
====

Generic Instrumental Music Platform

The general idea is to provide a framework for building electronic music instrument
controllers based on Arduino or Teensy hardware. Provide a set of useful C++ classes
that make writing controller firmware easier.

Some ideas:

- Read analog inputs at a maximum sampling rate
- Read analog inputs, with range mapping
- Register for callback when a digital input changes state
- Register for callback when an analog input changes by some amount
- Smoothed analog inputs
- Automatically send MIDI continuous controller data at a maximum rate,
  tracking an analog input

I'm still not sure how this will end up looking, e.g. what still lives in the arduino loop()
function. Perhaps only a periodic call to a method that causes the instrument to recompute
its state. But I doubt it, given how complicated the code I've written for previous controllers
ends up being. IIRC, the following were complicated:

- Tracking note-on state, so that appropriate note-off messages can be sent.
- Only sending CC data when a note is sounding.
- Coordinating note-on messages driven by continuous controllers, e.g. a breath controller.
  It's important to send the CC value before the note-on, to avoid an unwanted spike
  in volume.
- Using pitch bend messages to implement a trombone slide also requires that the
  pitch bend value be sent before the note on event, so that a pitch discontinuity
  is avoided.

It's also the case that I've only thought about a narrow range of instrument types,
most of which are wind controllers.