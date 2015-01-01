#ifndef _huge_event_h_
#define _huge_event_h_
/*
        Copyright 2012-2014 Infinitycoding all rights reserved
        This file is part of the HugeUniversalGameEngine.

        HUGE is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        any later version.

        The Universe Kernel is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with the Universe Kernel. If not, see <http://www.gnu.org/licenses/>.
*/

#include <math/vector.h>
#include <SDL2/SDL.h>
#include <list.h>

namespace huge
{
	
	typedef uint32_t scancode_t;
	typedef uint32_t deviceId_t;


	enum EventDeviceType
	{
		keyboard,
		joystick,
		gamecontroller,
		mouse,
		touchscreen,
		window
	};

	enum WindowEventType
	{
		shown 				= 	SDL_WINDOWEVENT_SHOWN,
		hidden 				= 	SDL_WINDOWEVENT_HIDDEN,
		exposed 			= 	SDL_WINDOWEVENT_EXPOSED,
		moved 				= 	SDL_WINDOWEVENT_MOVED,
		externResized 		= 	SDL_WINDOWEVENT_RESIZED,
		resized 			= 	SDL_WINDOWEVENT_SIZE_CHANGED,
		minimized 			= 	SDL_WINDOWEVENT_MINIMIZED,
		maximized 			= 	SDL_WINDOWEVENT_MAXIMIZED,
		restored 			= 	SDL_WINDOWEVENT_RESTORED,
		mouseFocused 		= 	SDL_WINDOWEVENT_ENTER,
		mouseUnfocused 		= 	SDL_WINDOWEVENT_LEAVE,
		keyboardFocused 	= 	SDL_WINDOWEVENT_FOCUS_GAINED,
		keyboardUnfocused 	= 	SDL_WINDOWEVENT_FOCUS_LOST,
		closed 				= 	SDL_WINDOWEVENT_CLOSE
	};

	struct EventDevice
	{
		deviceId_t id;
		const char *name;
		EventDeviceType type;
	};
	

	class EventManager;
	class EventHandle;
	
	class EventHandle
	{
		public:
			EventHandle();
			virtual void handleDeviceAdded(const EventDevice *device, uint32_t timestamp);
			virtual void handleDeviceRemoved(const EventDevice *device, uint32_t timestamp);
			virtual void handleButtonUp(const EventDevice *device, uint32_t timestamp, scancode_t scancode);
			virtual void handleButtonDown(const EventDevice *device, uint32_t timestamp, scancode_t scancode);
			virtual void handleRelAxis(const EventDevice *device, uint32_t timestamp, uint32_t axis, int32_t value);
			virtual void handlePointAxis(const EventDevice *device, uint32_t timestamp, Vector2i abs, Vector2i rel);
 			virtual void handleWindow(const EventDevice *device,uint32_t timestamp, WindowEventType type);
			virtual void handleQuit();
			
			virtual bool check(const EventDevice *device);
			
		protected:
			
			List<EventManager> managers;
	};
	
	class EventManager : EventHandle
	{
		public:
			EventManager(bool root);
			
			void fechtEvents();
			void registerHandle(EventHandle *handle);
			void registerHandle(EventManager *handle);
			
			bool removeHandle(EventHandle *handle);
			bool removeHandle(EventManager *handle);
			
			virtual void handleDeviceAdded(const EventDevice *device, uint32_t timestamp);
			virtual void handleDeviceRemoved(const EventDevice *device, uint32_t timestamp);
			virtual void handleButtonUp(const EventDevice *device, uint32_t timestamp, scancode_t scancode);
			virtual void handleButtonDown(const EventDevice *device, uint32_t timestamp, scancode_t scancode);
			virtual void handleRelAxis(const EventDevice *device, uint32_t timestamp, uint32_t axis, int32_t value);
			virtual void handlePointAxis(const EventDevice *device, uint32_t timestamp, Vector2i abs, Vector2i rel);
 			virtual void handleWindow(const EventDevice *device,uint32_t timestamp, WindowEventType type);
			virtual void handleQuit();
			
			virtual bool check(const EventDevice *device);
	
			
		private:
			bool isroot;
			List<EventHandle> recipients;
	};
	
	class UserHandle : EventHandle
	{
	public:
		void handleQuit();
	};
};

#endif