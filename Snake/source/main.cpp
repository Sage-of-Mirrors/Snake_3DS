#if __INTELLISENSE__
typedef unsigned int __SIZE_TYPE__;
typedef unsigned long __PTRDIFF_TYPE__;
#define __attribute__(q)
#define __builtin_strcmp(a,b) 0
#define __builtin_strlen(a) 0
#define __builtin_memcpy(a,b) 0
#define __builtin_va_list void*
#define __builtin_va_start(a,b)
#define __extension__
#endif

#if defined(_MSC_VER)
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#endif

#include <3ds.h>
#include <sf2d.h>
#include <stdio.h>
#include "StateMachine.h"
#include "TitleState.h"
#include "image.h"

int main()
{
	// Initialize the services
	sf2d_init();
	romfsInit();
	//consoleInit(GFX_BOTTOM, NULL);

	sf2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));
	sf2d_set_3D(0);

	StateMachine m_machine;
	TitleState* m_title = new TitleState();
	m_machine.ChangeState(m_title);

	//Main loop
	while (aptMainLoop())
	{
		hidScanInput();

		m_machine.Update();
		m_machine.Render();

		// If Start button is pressed, we exit
		//if (hidKeysDown() & KEY_START)
		//{
			//break;
		//}

		sf2d_swapbuffers();
	}

	if (m_machine.GetCurrentState())
		delete m_machine.GetCurrentState();

	// Exit the services
	romfsExit();
	sf2d_fini();

	return 0;
}