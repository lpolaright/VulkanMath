## Physical Device

The way I understand the concept of Physical Devices in Vulkan, is basically any kind of device that can do any one of the following
operations:
* Compute
* Data Transfer
* Graphics
* Binding (have absolutely no idea what that means yet)

So basically, any kind of a device that can run things to calculate. Whether it is a CPU or a GPU (Which is basically thousands of tiny CPUs anyway).

## Queues

However, it is not that simple, you might find multiple devices on your computer.
Lets say you have two GPUs plugged in, how does vulkan decide which device to get? **it doesn't**.

You have to decide what device you want to use, in future iterations of this program I will try to use multiple ones. 
But first I need to get the basics right.

Basically you need to make your own choice for what capabilities you want to run, I guess we are going for graphics here.
Also, we are going to cache the queues we found because we are going to need their identifiable index later to create new 
and exciting objects. (*So exciting...*)

## But what are queues?

Basically they are the way you interface with the device you have. You send **commands** through them. That's it, finito.
They are no more than regular queues. Like a queue in a bank. Only the people are the commands to the GPU, and ofcourse the
bank is the GPU, and the clerks are doing the work for the GPU.