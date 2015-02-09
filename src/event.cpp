/*
        Copyright 2012-2014 Infinitycoding all rights reserved
        This file is part of the HugeUniversalGameEngine.

        HUGE is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        any later version.

        HUGE Kernel is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with the Universe Kernel. If not, see <http://www.gnu.org/licenses/>.
*/

#include <SDL2/SDL.h>
#include <huge/event.h>

namespace huge
{

EventHandle::EventHandle()
{
    managers = List<EventManager*>();
}
bool EventHandle::check(const EventDevice *device)
{
    return true;
}

void EventHandle::handleDeviceAdded(const EventDevice *device, uint32_t timestamp) {}
void EventHandle::handleDeviceRemoved(const EventDevice *device, uint32_t timestamp) {}
void EventHandle::handleButtonUp(const EventDevice *device, uint32_t timestamp, scancode_t scancode) {}
void EventHandle::handleButtonDown(const EventDevice *device, uint32_t timestamp, scancode_t scancode) {}
void EventHandle::handleRelAxis(const EventDevice *device, uint32_t timestamp, uint32_t axis, int32_t value) {}
void EventHandle::handlePointAxis(const EventDevice *device, uint32_t timestamp, Vector2i abs, Vector2i rel) {}
void EventHandle::handleWindow(const EventDevice *device, uint32_t timestamp, WindowEventType type) {}
void EventHandle::handleQuit() {}


EventManager::EventManager(bool root)
{
    recipients = List<EventHandle*>();
    isroot = root;
}

void EventManager::fetchEvents()
{
    if(isroot)
    {
        SDL_Event event;
        while (SDL_PollEvent (&event))
        {
            EventDevice dev;

            switch (event.type)
            {
                case SDL_WINDOWEVENT:
                {
                    dev.id = event.window.windowID;
                    dev.name = SDL_GetWindowTitle(SDL_GetWindowFromID(dev.id));
                    dev.type = window;

                    foreach(&recipients,recipient,EventHandle*)
                    {
                        if(recipient->check(&dev))
                            recipient->handleWindow(&dev,event.window.timestamp,(WindowEventType)event.window.event);
                    }
                }
                break;

                case SDL_KEYDOWN:
                {
                    dev.id = 0;
                    dev.name = "default keyboard";
                    dev.type = keyboard;
                    foreach(&recipients,recipient,EventHandle*)
                    {
                        printf("sending to recipient\n");
                        if(recipient->check(&dev))
                        {
                            printf("sending to recipient\n");
                            recipient->handleButtonDown(&dev, event.key.timestamp, event.key.keysym.scancode);

                        }
                    }
                }
                break;

                case SDL_KEYUP:
                {
                    dev.id = 0;
                    dev.name = "default keyboard";
                    dev.type = keyboard;
                    foreach(&recipients,recipient,EventHandle*)
                    {
                        if(recipient->check(&dev))
                            recipient->handleButtonUp(&dev, event.key.timestamp, event.key.keysym.scancode);
                    }
                }
                break;

                case SDL_MOUSEMOTION:
                {
                    dev.id = event.motion.which;
                    dev.name = "default mouse";
                    dev.type = mouse;
                    foreach(&recipients,recipient,EventHandle*)
                    {
                        if(recipient->check(&dev))
                            recipient->handlePointAxis(&dev, event.motion.timestamp, Vector2i(event.motion.x,event.motion.y), Vector2i(event.motion.xrel,event.motion.yrel));
                    }
                }
                break;

                case SDL_MOUSEBUTTONDOWN:
                {
                    dev.id = event.button.which;
                    dev.name = "default mouse";
                    dev.type = mouse;
                    foreach(&recipients,recipient,EventHandle*)
                    {
                        if(recipient->check(&dev))
                            recipient->handleButtonDown(&dev, event.button.timestamp, event.button.button);
                    }
                }
                break;

                case SDL_MOUSEBUTTONUP:
                {
                    dev.id = event.button.which;
                    dev.name = "default mouse";
                    dev.type = mouse;
                    foreach(&recipients,recipient,EventHandle*)
                    {
                        if(recipient->check(&dev))
                            recipient->handleButtonUp(&dev, event.button.timestamp, event.button.button);
                    }
                }
                break;

                case SDL_MOUSEWHEEL:
                {
                    dev.id = event.wheel.which;
                    dev.name = "default mouse";
                    dev.type = mouse;
                    foreach(&recipients,recipient,EventHandle*)
                    {
                        if(recipient->check(&dev))
                        {
                            if(event.wheel.x)
                                recipient->handleRelAxis(&dev, event.wheel.timestamp, 0, event.wheel.x);
                            if(event.wheel.y)
                                recipient->handleRelAxis(&dev, event.wheel.timestamp, 1, event.wheel.y);
                        }
                    }
                }
                break;

                case SDL_JOYAXISMOTION:
                {
                    dev.id = event.jaxis.which;
                    dev.name = "default Joystick"; // todo: get namestrings from device manager
                    dev.type = joystick;
                    foreach(&recipients,recipient,EventHandle*)
                    {
                        if(recipient->check(&dev))
                            recipient->handleRelAxis(&dev, event.jaxis.timestamp, event.jaxis.axis, event.jaxis.value);
                    }
                }
                break;

                case SDL_JOYBALLMOTION:
                    dev.id = event.motion.which;
                    dev.name = "default Joystick"; // todo: get namestrings from device manager
                    dev.type = joystick;
                    foreach(&recipients,recipient,EventHandle*)
                    {
                        if(recipient->check(&dev))
                        {
                            if(event.jball.xrel)
                                recipient->handleRelAxis(&dev, event.jball.timestamp, 0, event.jball.xrel);
                            if(event.jball.yrel)
                                recipient->handleRelAxis(&dev, event.jball.timestamp, 1, event.jball.yrel);
                        }
                    }
                    break;


                    /* Todo:
                    case SDL_JOYBUTTONDOWN:
                    break;
                    case SDL_JOYBUTTONUP:
                    break;
                    case SDL_JOYDEVICEADDED:
                    break;
                    case SDL_JOYDEVICEREMOVED:
                    break;
                    case SDL_CONTROLLERAXISMOTION:
                    break;
                    case SDL_CONTROLLERBUTTONDOWN:
                    break;
                    case SDL_CONTROLLERBUTTONUP:
                    break;
                    case SDL_CONTROLLERDEVICEADDED:
                    break;
                    case SDL_CONTROLLERDEVICEREMOVED:
                    break;
                    case SDL_FINGERDOWN:
                    break;
                    case SDL_FINGERUP:
                    break;
                    case SDL_FINGERMOTION:
                    break;

                    */

            }
        }

    }
    else
    {
        ListIterator<EventManager*> it = ListIterator<EventManager*>(&managers);
        while(!it.isLast())
        {
            it.getCurrent()->fetchEvents();
            it.next();
        }
    }

}

void EventManager::registerHandle(EventHandle *handle)
{
    recipients.pushFront(handle);
}

void EventManager::registerHandle(EventManager *handle)
{
    recipients.pushFront(dynamic_cast<EventHandle *>(handle));
}

bool EventManager::removeHandle(EventHandle *handle)
{
    return recipients.remove(handle);
}

bool EventManager::removeHandle(EventManager *handle)
{
    return recipients.remove(dynamic_cast<EventHandle *>(handle));
}


void EventManager::handleDeviceAdded(const EventDevice *device, uint32_t timestamp)
{
    foreach(&recipients,recipient,EventHandle*)
    {
        if(recipient->check(device))
            recipient->handleDeviceAdded(device,timestamp);
    }
}

void EventManager::handleDeviceRemoved(const EventDevice *device, uint32_t timestamp)
{
    foreach(&recipients,recipient,EventHandle*)
    {
        if(recipient->check(device))
            recipient->handleDeviceRemoved(device, timestamp);
    }
}

void EventManager::handleButtonUp(const EventDevice *device, uint32_t timestamp, scancode_t scancode)
{
    foreach(&recipients,recipient,EventHandle*)
    {
        if(recipient->check(device))
            recipient->handleButtonUp(device, timestamp, scancode);
    }
}

void EventManager::handleButtonDown(const EventDevice *device, uint32_t timestamp, scancode_t scancode)
{
    foreach(&recipients,recipient,EventHandle*)
    {
        if(recipient->check(device))
            recipient->handleButtonDown(device, timestamp, scancode);
    }
}

void EventManager::handleRelAxis(const EventDevice *device, uint32_t timestamp, uint32_t axis, int32_t value)
{
    foreach(&recipients,recipient,EventHandle*)
    {
        if(recipient->check(device))
            recipient->handleRelAxis(device,timestamp, axis, value);
    }
}

void EventManager::handlePointAxis(const EventDevice *device, uint32_t timestamp, Vector2i abs, Vector2i rel)
{
    foreach(&recipients,recipient,EventHandle*)
    {
        if(recipient->check(device))
            recipient->handlePointAxis(device, timestamp, abs, rel);
    }
}

void EventManager::handleWindow(const EventDevice *device, uint32_t timestamp, WindowEventType type)
{
    foreach(&recipients,recipient,EventHandle*)
    {
        if(recipient->check(device))
            recipient->handleWindow(device, timestamp, type);
    }
}
void EventManager::handleQuit()
{
    foreach(&recipients,recipient,EventHandle*)
    {
        recipient->handleQuit();
    }
}

bool EventManager::check(const EventDevice *device)
{
    return true;
}

}; // namespace huge

