# Device creation and Graphics Queue

## Device

So a device is basically how you tell a physical device on your computer how to do stuff. Things like understanding what kind
of queues there are (Queue Families) and based on that create multiple queues for that family.

Or furthermore, if you have multiple physical devices, that belong to the same physical device group - you could create one
device interfacing them all! (Pretty neat, right? But it seems like the limitations are pretty problematic, because they need
to be the same)

## Graphics

There isn't much information about the graphics queue and the capabilities, there is much later some information about
how to setup the graphics pipeline, but not about the queue itself. So I assume I will understand it better later.

What I do understand is that all the commands sent here will most likely end up in the GPU to create graphical objects.
Hence the name.